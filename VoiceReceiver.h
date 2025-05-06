#ifndef VOICERECEIVER_H
#define VOICERECEIVER_H

#include <QObject>
#include <QAudioFormat>

class QAudioSink;
class QUdpSocket;

class VoiceReceiver : public QObject
{
    Q_OBJECT
public:
    explicit VoiceReceiver(QObject *parent = nullptr);
    ~VoiceReceiver();

    // Begin listening on the specified port.
    void start(quint16 port);
    void stop();

private slots:
    // Called when UDP datagrams are available.
    void processDatagrams();

private:
    QAudioFormat m_format;
    QAudioSink *m_audioSink;
    QIODevice *m_outputDevice;
    QUdpSocket *m_udpSocket;
};

#endif // VOICERECEIVER_H
