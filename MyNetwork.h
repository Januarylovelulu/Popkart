#ifndef MYNETWORK_H
#define MYNETWORK_H

#include <QObject>
#include <QTime>
#include <QTimer>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QHostInfo>
#include <QtMath>
#include <QNetworkProxy>
#include "MyFile.h"

class MyNetwork : public QObject
{
    Q_OBJECT

public:
    MyNetwork(QString url=nullptr);
    ~MyNetwork();

    QStringList getIp();//返回当前存在的IPv4地址

    //获取链接地址的文件信息
    //绑定名为returnUrlInfo的signal，或在等待一段时间后使用getUrlFIleInfo读取信息(可能会出现异步的问题)
    void getDownloadFileInfo(QString url=nullptr);

    bool getIsDownloading();//是否正在下载

    //可以使用returnDownload开头的signal，传输下载的情况
    void init();//初始化参数，重置参数
    void download(QString fileName=nullptr, QString path=nullptr, QString url=nullptr);//下载文件的接口
    void stopDownload(); //停止下载

    //获取json,或者页面内容
    QString getHtmlContent(QString url=nullptr);//以阻塞的方法返回Json数据，或者是HTML页面的内容，实际上调用的getJson(url)函数
    QString getJson(QString url=nullptr);//以阻塞的方法返回Json数据，或者是HTML页面的内容
    void getJson(QString url, int time);//获取链接返回的Json数据，绑定名为returnJson的signal，获取结果
    void setProxy(QString IP, quint16 port, QNetworkProxy::ProxyType type= QNetworkProxy::HttpProxy);//设置代理，避免被封IP
    void setProxy(QString IP_Port, QNetworkProxy::ProxyType type= QNetworkProxy::HttpProxy);//重载函数，IP_Port参数为"0.0.0.1:8080"

    void setUrl(QString url);
    void setFileName(QString fileName);
    void setPath(QString path);
    QString getFileName();
    QString getUrl();
    QString getPath();
    QStringList getUrlFIleInfo();
    qint64 getFileSize();

public slots:

protected:
    void run();

private slots:
    void on_updateDataReadProgress(qint64 now, qint64 all); //更新下载速度，进度条和下载进度
    void on_getFileSize(qint64 now, qint64 all);//getDownloadFileInfo()调用，获取文件大小

    void on_getJson(QNetworkReply *reply);//getJson()调用，获取网页返回的Json数据
    void on_getJsonTimer();//获取Json超时

signals:
    void returnUrlInfo(QStringList msgs);//返回给定Url地址的相关信息

    void returnJson(QString msg);

    void returnDownloadProgressBarValue(int num);//返回进度条当前的下载值,最大为100
    void returnDownloadStatute(QString str);//返回当前下载的 “下载值and文件大小”
    void returnDownloadSpeedAndTime(QString time);//返回当前下载的 “速度and剩余时间”
    void returnDownloadFinish();//返回下载完成的信号
    void returnDownloadError(QString msg);//返回错误

private:
    MyFile myFile;

    QStringList ip;
    QString url=nullptr;
    QString downloadFileName=nullptr;
    QString downloadFilePath=nullptr;

    //以下是下载相关的参数和函数
    const QString DOWNLOAD_FILE_SUFFIX=".lulu";
    const QString DOWNLOAD_FILE_Temporary_SUFFIX=".love";

    void httpFinished();  //完成下载后的处理
    void startRequest(QUrl url); //请求链接
    bool isDownloading=false;
    QNetworkAccessManager *managerDownload;
    QUrl urlDownload;   //存储网络地址
    QNetworkReply *replyDownload;
    QFile *fileDownload;  //文件指针
    QTime timeDownloadSpeed;
    qint64 lastData=0;
    qint64 nowData=0;
    qint64 allData=0;
    qint64 savedData=0;
    qint64 downedData=0;//已经下载好的数据
    int timerTime=1000;//显示下载速度的间隔时间

    //获取json
    bool isGetJson=false;
    bool isHasProxy=false;
    QNetworkAccessManager* network_manager;
    QNetworkRequest* network_request;
    //https://www.kuaidaili.com/free/inha/
    QNetworkProxy proxy;//容易被封IP，所以加上代理
    QTimer getJsonTimer;

    QStringList downloadInfo;//1.size 2.url 3.fileName(不一定有)
    qint64 fileSize;

    bool judgElement(QString elementName, QString &element);
};

#endif // MYNETWORK_H
