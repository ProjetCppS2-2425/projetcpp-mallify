#include "VoiceReceiver.h"

#include <QAudioDevice>
#include <QMediaDevices>
#include <QAudioSink>
#include <QUdpSocket>
#include <QByteArray>
#include <QDebug>

VoiceReceiver::VoiceReceiver(QObject *parent)
    : QObject(parent),
    m_audioSink(nullptr),
    m_outputDevice(nullptr),
    m_udpSocket(new QUdpSocket(this))
{
    // Set the desired audio format.
    m_format.setSampleRate(44100);
    m_format.setChannelCount(1);
    m_format.setSampleFormat(QAudioFormat::Int16);
}

VoiceReceiver::~VoiceReceiver()
{
    stop();
}

void VoiceReceiver::start(quint16 port)
{
    QAudioDevice outputDevice = QMediaDevices::defaultAudioOutput();
    if (!outputDevice.isFormatSupported(m_format)) {
        qWarning() << "Requested audio format not supported on output; using preferred format.";
        m_format = outputDevice.preferredFormat();
    }
    // Create QAudioSink with the chosen output device and format.
    m_audioSink = new QAudioSink(outputDevice, m_format, this);
    m_outputDevice = m_audioSink->start();

    // Bind the UDP socket to any address on the given port.
    if (!m_udpSocket->bind(QHostAddress::Any, port)) {
        qWarning() << "Failed to bind UDP socket on port" << port;
    }
    connect(m_udpSocket, &QUdpSocket::readyRead, this, &VoiceReceiver::processDatagrams);
}

void VoiceReceiver::processDatagrams()
{
    while (m_udpSocket->hasPendingDatagrams()) {
        QByteArray buffer;
        buffer.resize(static_cast<int>(m_udpSocket->pendingDatagramSize()));
        m_udpSocket->readDatagram(buffer.data(), buffer.size());
        if (m_outputDevice) {
            m_outputDevice->write(buffer);
        }
    }
}

void VoiceReceiver::stop()
{
    if (m_audioSink) {
        m_audioSink->stop();
        m_audioSink->deleteLater();
        m_audioSink = nullptr;
        m_outputDevice = nullptr;
    }
    m_udpSocket->close();
}
