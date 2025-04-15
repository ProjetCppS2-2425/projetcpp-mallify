#include "VoiceTransmitter.h"

#include <QAudioDevice>
#include <QMediaDevices>
#include <QAudioSource>
#include <QUdpSocket>
#include <QByteArray>
#include <QDebug>

#include <QDesktopServices>
#include <QUrl>

VoiceTransmitter::VoiceTransmitter(QObject *parent)
    : QObject(parent),
    m_audioSource(nullptr),
    m_inputDevice(nullptr),
    m_udpSocket(new QUdpSocket(this))
{
    // Set up the desired audio format.
    m_format.setSampleRate(44100);
    m_format.setChannelCount(1);
    m_format.setSampleFormat(QAudioFormat::Int16);
}

VoiceTransmitter::~VoiceTransmitter()
{
    stop();
}

void VoiceTransmitter::start(const QList<QHostAddress> &targets, quint16 port)
{
    m_targetAddresses = targets;
    m_targetPort = port;

    QAudioDevice inputDevice = QMediaDevices::defaultAudioInput();
    if (!inputDevice.isFormatSupported(m_format)) {
        qWarning() << "Requested audio format not supported on input; using preferred format.";
        m_format = inputDevice.preferredFormat();
    }
    // Create QAudioSource with the chosen input device and format.
    m_audioSource = new QAudioSource(inputDevice, m_format, this);
    m_inputDevice = m_audioSource->start();

    // Whenever new audio data is available, send it over the UDP socket.
    connect(m_inputDevice, &QIODevice::readyRead, this, &VoiceTransmitter::sendAudioData);
}

void VoiceTransmitter::sendAudioData()
{
    if (!m_inputDevice)
        return;

    QByteArray audioData = m_inputDevice->readAll();
    for (const QHostAddress &addr : m_targetAddresses) {
        m_udpSocket->writeDatagram(audioData, addr, m_targetPort);
    }
}

void VoiceTransmitter::stop()
{
    if (m_audioSource) {
        m_audioSource->stop();
        m_audioSource->deleteLater();
        m_audioSource = nullptr;
        m_inputDevice = nullptr;
    }
}

