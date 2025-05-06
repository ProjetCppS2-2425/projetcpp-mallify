#ifndef SPEECHRECOGNIZER_H
#define SPEECHRECOGNIZER_H

#include <QObject>
#include <QBuffer>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QAudioFormat>
#include <QAudioDevice>
#include <QMediaDevices>
#include <QAudioSource>

class SpeechRecognizer : public QObject
{
    Q_OBJECT
public:
    explicit SpeechRecognizer(QObject *parent = nullptr);
    ~SpeechRecognizer();

    // Starts capturing audio
    void startRecording();

    // Stops capturing audio and uploads the recorded data
    void stopRecording();
    void saveAudioToFile(const QString &filePath);
    void transcribeAudioFile(const QString &filePath);


signals:
    void transcriptionReceived(const QString &transcription);
    void errorOccurred(const QString &errorString);

private slots:
    // Slot for handling available audio data
    void onReadyRead();

    // Slot for processing the network reply from the speech-to-text service.
    void onNetworkReplyFinished(QNetworkReply *reply);

private:
    // QAudioSource is the new class in Qt 6 for audio input.
    QAudioSource *audioSource;

    // QIODevice pointer to read the streaming audio data.
    QIODevice *audioIODevice;

    // Container for storing recorded audio data.
    QByteArray recordedData;

    // Network manager for uploading audio.
    QNetworkAccessManager networkManager;

    // Internal method to send the recorded audio data to the online API.
    void uploadAudioData(const QByteArray &audioData);


};

#endif // SPEECHRECOGNIZER_H
