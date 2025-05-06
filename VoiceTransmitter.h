#ifndef VOICETRANSMITTER_H
#define VOICETRANSMITTER_H

#include <QObject>
#include <QHostAddress>
#include <QList>
#include <QAudioFormat>

class QAudioSource;
class QUdpSocket;

class VoiceTransmitter : public QObject
{
    Q_OBJECT
public:
    explicit VoiceTransmitter(QObject *parent = nullptr);
    ~VoiceTransmitter();

    // Start audio capture and sending to the list of target addresses on the specified port.
    void start(const QList<QHostAddress> &targets, quint16 port);
    void stop();
    void callNumber(const QString &number);

private slots:
    // Slot to send any ready audio data.
    void sendAudioData();

private:
    QAudioFormat m_format;
    QAudioSource *m_audioSource;
    QIODevice *m_inputDevice;
    QUdpSocket *m_udpSocket;
    QList<QHostAddress> m_targetAddresses;
    quint16 m_targetPort;
};

#endif // VOICETRANSMITTER_H
