#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAudioDecoder>
#include <iostream>
#include <QSound>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Test();
    QAudioBuffer buf;
    QAudioDecoder *decoder = new QAudioDecoder(this);
        QAudioFormat desiredFormat;
private:
    Ui::MainWindow *ui;
private slots:
    void read_decoder();
    void read_buffer();
    void read_error();
};

#endif // MAINWINDOW_H
