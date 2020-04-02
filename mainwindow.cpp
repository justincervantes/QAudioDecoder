#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Test() {
    QSound::play("evangeline-matthew_sweet.wav");
//    QAudioFormat desiredFormat;
//    desiredFormat.setChannelCount(2);
//    desiredFormat.setCodec("audio/x-wav");
//    desiredFormat.setSampleType(QAudioFormat::UnSignedInt);
//    desiredFormat.setSampleRate(48000);
//    desiredFormat.setSampleSize(32);
//    decoder->setAudioFormat(desiredFormat);
    qDebug("3");
    decoder->setSourceFilename("evangeline-matthew_sweet.wav");
    qDebug("2");
    connect(decoder, SIGNAL(bufferReady()), this, SLOT(read_decoder()));
    connect(decoder, SIGNAL(finished()), this, SLOT(read_buffer()));
    connect(decoder, QOverload<QAudioDecoder::Error>::of(&QAudioDecoder::error),
            [=](QAudioDecoder::Error error){ std::cout <<"Error: " + error; });
    qDebug("1");
    decoder->start();

    //fflush(stdout);
}


void MainWindow::read_decoder() {
    //qDebug("Buffer Ready - Slot has been hit");
    buf = decoder->read();
    const quint32 *data = buf.data<quint32>(); // May cause deep copy
    std::cout << data;
}

void MainWindow::read_buffer() {
    qDebug("Finished - slot has been hit");
    //QAudioBuffer buf = decoder->read();
    //std::cout << buf.frameCount();
}

void MainWindow::read_error() {
    qDebug("Error - slot has been hit");
    QString a = decoder->errorString();
    qDebug() << a;
}
