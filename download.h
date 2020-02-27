#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QDialog>
#include <QSettings>
#include <QProgressBar>
#include <QMessageBox>
#include <QCloseEvent>
#include "MyNetwork.h"

namespace Ui {
class Download;
}

class Download : public QDialog
{
    Q_OBJECT

public:
    explicit Download(QString fileName=nullptr, QString path=nullptr, QString url=nullptr, QWidget *parent = 0);
    ~Download();

protected:
    void closeEvent(QCloseEvent *event);

public slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_DownloadFinish();

signals:
    void returnDownloadFinish();

private:
    Ui::Download *ui;

    MyNetwork myNetwork;
    MyFile myFile;

    QSettings *settings;

    QString url;
    QString fileName;
    QString path;

    bool isDownloading=false;
};

#endif // DOWNLOAD_H
