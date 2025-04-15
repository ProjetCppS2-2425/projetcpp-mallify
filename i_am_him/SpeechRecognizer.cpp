#include <SpeechRecognizer.h>
#include <QUrl>
#include <QNetworkRequest>
#include <QHttpMultiPart>
#include <QJsonDocument>
#include <QJsonObject>

#include <QDataStream>
#include <QByteArray>

#include <QFile>
#include <QDataStream>
#include <QStandardPaths>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>


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
        audioSource->stop();
        disconnect(audioIODevice, &QIODevice::readyRead, this, &SpeechRecognizer::onReadyRead);
        qDebug() << "stopRecording(): Audio recording stopped. Total recorded data:" << recordedData.size() << "bytes";
        // NO! don’t upload raw PCM
        //uploadAudioData(recordedData);
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
    // Log HTTP status for debugging
    int status = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << "[onNetworkReplyFinished] HTTP status code:" << status;

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        qDebug() << "onNetworkReplyFinished(): API response received:" << responseData;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        QJsonObject  jsonObj = jsonDoc.object();

        // Deepgram returns: { results: { channels: [ { alternatives: [ { transcript: "..."} ] } ] } }
        QJsonObject resultsObj = jsonObj.value("results").toObject();
        QJsonArray  channels   = resultsObj.value("channels").toArray();
        if (!channels.isEmpty()) {
            QJsonObject ch0 = channels.at(0).toObject();
            QJsonArray  alts = ch0.value("alternatives").toArray();
            if (!alts.isEmpty()) {
                QString transcript = alts.at(0).toObject().value("transcript").toString();
                qDebug() << "[onNetworkReplyFinished] Parsed transcript:" << transcript;
                emit transcriptionReceived(transcript);
                reply->deleteLater();
                return;
            }
        }

        // No transcript found
        emit transcriptionReceived(QString());
    }
    else {
        QString err = reply->errorString();
        qDebug() << "[onNetworkReplyFinished] ERROR:" << err;
        emit errorOccurred(err);
    }

    reply->deleteLater();
}

void SpeechRecognizer::saveAudioToFile(const QString &filePath)
{
    qDebug() << "[saveAudioToFile] Attempting to open" << filePath;
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        QString err = "Failed to open file for writing: " + file.errorString();
        qDebug() << "[saveAudioToFile] ERROR:" << err;
        emit errorOccurred(err);
        return;
    }

    // Prepare WAV header
    QDataStream out(&file);
    out.setByteOrder(QDataStream::LittleEndian);

    quint32 dataSize    = static_cast<quint32>(recordedData.size());
    quint32 fileSize    = 36 + dataSize;
    quint16 audioFormat = 1;    // PCM
    quint16 channels    = 1;
    quint32 sampleRate  = 16000;
    quint16 bitsPerSample = 16;
    quint32 byteRate    = sampleRate * channels * bitsPerSample / 8;
    quint16 blockAlign  = channels * bitsPerSample / 8;

    qDebug() << "[saveAudioToFile] Writing WAV header:"
             << "dataSize=" << dataSize
             << "fileSize=" << fileSize;

    // RIFF chunk
    out.writeRawData("RIFF", 4);
    out << fileSize;
    out.writeRawData("WAVE", 4);

    // fmt subchunk
    out.writeRawData("fmt ", 4);
    out << (quint32)16;         // Subchunk1Size
    out << audioFormat;
    out << channels;
    out << sampleRate;
    out << byteRate;
    out << blockAlign;
    out << bitsPerSample;

    // data subchunk
    out.writeRawData("data", 4);
    out << dataSize;

    qint64 written = file.write(recordedData);
    qDebug() << "[saveAudioToFile] Wrote" << written << "bytes of audio data";

    file.close();
    qDebug() << "[saveAudioToFile] File closed successfully.";
}

void SpeechRecognizer::transcribeAudioFile(const QString &filePath)
{
    qDebug() << "[transcribeAudioFile] Opening file:" << filePath;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QString err = "Cannot open audio file for transcription: " + file.errorString();
        qDebug() << "[transcribeAudioFile] ERROR:" << err;
        emit errorOccurred(err);
        return;
    }

    QByteArray audioData = file.readAll();
    file.close();
    qDebug() << "[transcribeAudioFile] Read" << audioData.size() << "bytes from file";

    // Reuse your existing uploader
    uploadAudioData(audioData);
}
