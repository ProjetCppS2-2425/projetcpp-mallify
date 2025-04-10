#include <SpeechRecognizer.h>
#include <QUrl>
#include <QNetworkRequest>
#include <QHttpMultiPart>
#include <QJsonDocument>
#include <QJsonObject>

#include <QDataStream>
#include <QByteArray>

SpeechRecognizer::SpeechRecognizer(QObject *parent)
    : QObject(parent),
    audioSource(nullptr),
    audioIODevice(nullptr)
{
}

SpeechRecognizer::~SpeechRecognizer()
{
    // Clean up audioSource if still allocated.
    delete audioSource;
}

void SpeechRecognizer::startRecording()
{
    // Configure the desired audio format.
    QAudioFormat format;
    format.setSampleRate(16000);
    format.setChannelCount(1);
    format.setSampleFormat(QAudioFormat::Int16);

    // Get the default input device.
    QAudioDevice inputDevice = QMediaDevices::defaultAudioInput();

    // Create a QAudioSource with the default input device and audio format.
    audioSource = new QAudioSource(inputDevice, format, this);

    // Start capturing audio; this returns a QIODevice* to access the streamed audio data.
    audioIODevice = audioSource->start();
    if (!audioIODevice) {
        emit errorOccurred("Unable to start audio recording");
        return;
    }

    // Connect the QIODevice signal so we read audio data as it becomes available.
    connect(audioIODevice, &QIODevice::readyRead, this, &SpeechRecognizer::onReadyRead);

    // Clear any previously recorded data.
    recordedData.clear();
}

void SpeechRecognizer::stopRecording()
{
    if (audioSource) {
        // Stop the audio capture.
        audioSource->stop();

        // Disconnect the readyRead signal.
        disconnect(audioIODevice, &QIODevice::readyRead, this, &SpeechRecognizer::onReadyRead);

        // Debug: Log that stopRecording has been triggered and the size of recorded data.
        qDebug() << "stopRecording(): Audio recording stopped. Total recorded data:" << recordedData.size() << "bytes";

        // Now, send the recorded audio data to the online speech-to-text service.
        uploadAudioData(recordedData);
    }
}


void SpeechRecognizer::onReadyRead()
{
    if (audioIODevice) {
        QByteArray data = audioIODevice->readAll();
        recordedData.append(data);
        qDebug() << "Captured audio data:" << data.size() << "bytes";
    }
}


void SpeechRecognizer::uploadAudioData(const QByteArray &audioData)
{
    // Use Deepgram's API endpoint.
    QUrl url("https://api.deepgram.com/v1/listen");
    QNetworkRequest request(url);

    // Set the content type (assumes a WAV file, but if using raw PCM, adjust accordingly).
    request.setHeader(QNetworkRequest::ContentTypeHeader, "audio/wav");

    // Set the API key in the authorization header.
    request.setRawHeader("Authorization", "Token e15d0fae6c3a24b231c34811999eaad0f65095ab");

    // Debug: Log that the upload is about to be initiated.
    qDebug() << "uploadAudioData(): Uploading audio data of size:" << audioData.size() << "bytes";

    // Post the audio data.
    QNetworkReply *reply = networkManager.post(request, audioData);

    // Ensure multiPart cleanup if you revert to that approach; here we're using raw audio data.
    connect(reply, &QNetworkReply::finished, this, [this, reply]() { onNetworkReplyFinished(reply); });
}





void SpeechRecognizer::onNetworkReplyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();

        // Debug: Log the full API response.
        qDebug() << "onNetworkReplyFinished(): API response received:" << responseData;

        // Convert the received data into a JSON document.
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObj = jsonDoc.object();

        // Extract the transcription text. Adjust the key ("transcription") as needed.
        QString transcription = jsonObj["transcription"].toString();
        emit transcriptionReceived(transcription);
    } else {
        // Debug: Log the error string for troubleshooting.
        qDebug() << "onNetworkReplyFinished(): API error occurred:" << reply->errorString();
        emit errorOccurred(reply->errorString());
    }

    reply->deleteLater();
}

