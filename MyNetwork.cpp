#include "MyNetwork.h"

#include <QDebug>

MyNetwork::MyNetwork(QString url)
{
    this->url=url;
}

MyNetwork::~MyNetwork()
{

}

void MyNetwork::on_updateDataReadProgress(qint64 now, qint64 all)
{
    nowData=now;
    allData=all;
    now+=downedData;
    all+=downedData;
    double ratio=(double)now*100/(double)all;
    if((int)((QString("%1").arg(all).toDouble())/pow(2,20))>=1)
    {
        emit returnDownloadStatute(QString("下载进度: %1MB / %2MB  %3%")
                                   .arg((int)(now*100.0/pow(2,20))/100.0)
                                   .arg((int)(all*100/pow(2,20))/100.0)
                                   .arg(QString::number(ratio,'f',2)));
        emit returnDownloadProgressBarValue((int)ratio);
    }
    else
    {
        emit returnDownloadStatute(QString("下载进度: %1KB / %2KB  %3%")
                                   .arg((int)(now*100.0/pow(2,10))/100.0)
                                   .arg((int)(all*100/pow(2,10))/100.0)
                                   .arg(QString::number(ratio,'f',2)));
        emit returnDownloadProgressBarValue((int)ratio);
    }

    int timeNow = timeDownloadSpeed.elapsed();
    if (timeNow > timerTime)
    {
        double timerTimeSize=(double)timeNow/1000.0;
        qint64 times=(allData-nowData)/((nowData-lastData)/timerTimeSize);
        QString time;
        if((int)(times/(60*60*24))>=1)
            time="剩余时间: >1天";
        else if((int)(times/(60*60))>=1)
            time=QString("剩余时间: %1时%2分%3秒").arg((int)(times/(60*60))).arg((int)(times%(60*60)/60)).arg((int)(times%60));
        else if((int)(times/(60))>=1)
            time=QString("剩余时间: %1分%2秒").arg((int)(times/(60))).arg((int)(times%60));
        else
            time=QString("剩余时间: %1秒").arg((int)(times));

        QString speed;
        if((int)((nowData-lastData)/pow(2,20)/timerTimeSize)>=1)
            speed=QString("下载速度: %1 MB/s").arg((double)((int)((nowData-lastData)*100/timerTimeSize/pow(10,6)))/100);
        else
            speed=QString("下载速度: %1 KB/s").arg((double)((int)((nowData-lastData)*100/timerTimeSize/pow(10,3)))/100);

        emit returnDownloadSpeedAndTime(speed+"    "+time);
        lastData=nowData;
        timeDownloadSpeed.restart();

        savedData=nowData+downedData;
        if(fileDownload->open(QIODevice::WriteOnly | QIODevice::Append))
        {
            fileDownload->write(replyDownload->readAll());
            myFile.writeTextFile(QString::number(savedData),downloadFileName+DOWNLOAD_FILE_SUFFIX+DOWNLOAD_FILE_Temporary_SUFFIX,downloadFilePath);
        }
        else {
            emit returnDownloadError("文件写入失败");
            stopDownload();
        }
        fileDownload->close();
    }

}

void MyNetwork::on_getFileSize(qint64 now, qint64 all)
{
    Q_UNUSED(now);
    QString fileName = replyDownload->rawHeader("Content-Disposition");
    int index = fileName.indexOf("filename=");
    fileName = fileName.mid(index + 9);
    if (fileName.isEmpty())
    {
        QUrl url1(url);
        QFileInfo fileInfo(url1.path());
        fileName += fileInfo.fileName();
    }
    QString type=replyDownload->rawHeader("Content-Type");
    if(all!=0 && !type.contains("text/html") &&
            !type.contains("text/octet") &&
            !type.contains("application/xml"))
    {
        this->downloadFileName=fileName;
        this->fileSize=all;
        this->downloadInfo.append(QString::number(fileSize));
        this->downloadInfo.append(url);
        this->downloadInfo.append(downloadFileName);
    }
//    for(int x=0;x<replyDownload->rawHeaderList().length();x++){
//        qDebug()<<replyDownload->rawHeaderList().at(x)<<" : "<<replyDownload->rawHeader(replyDownload->rawHeaderList().at(x));
//    }
    emit returnUrlInfo(downloadInfo);
    disconnect(replyDownload, &QNetworkReply::downloadProgress, this, &MyNetwork::on_getFileSize);
    replyDownload->deleteLater();
    replyDownload = nullptr;
    managerDownload->deleteLater();
    isDownloading=false;
}

void MyNetwork::on_getJson(QNetworkReply *reply)
{
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    //无错误返回
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();  //获取字节
        QString result(bytes);  //转化为字符串
        result.replace("\\/","/");
        emit returnJson(result);
        getJsonTimer.stop();
    }
    else
    {
        //处理错误
        emit returnJson("Error");
        getJsonTimer.stop();
    }
}

void MyNetwork::on_getJsonTimer()
{
    this->getJson(this->url,5000);
}

void MyNetwork::httpFinished()
{
    if(fileDownload->open(QIODevice::WriteOnly | QIODevice::Append))
    {
        fileDownload->write(replyDownload->readAll());
    }
    else {
        emit returnDownloadError("文件写入失败");
        stopDownload();
    }
    fileDownload->close();
    stopDownload();
    myFile.rename(downloadFileName,downloadFilePath,downloadFileName+DOWNLOAD_FILE_SUFFIX);
    myFile.deleteFile(downloadFileName+DOWNLOAD_FILE_SUFFIX+DOWNLOAD_FILE_Temporary_SUFFIX,downloadFilePath);
    emit returnDownloadStatute("下载完成！");
    emit returnDownloadFinish();
}

void MyNetwork::stopDownload()
{
    if(isDownloading==false)
        return;

    disconnect(replyDownload, &QNetworkReply::downloadProgress, this, &MyNetwork::on_updateDataReadProgress);
    disconnect(replyDownload, &QNetworkReply::finished, this, &MyNetwork::httpFinished);

    fileDownload->flush();
    fileDownload->close();
    replyDownload->deleteLater();
    replyDownload = nullptr;
    delete fileDownload;
    managerDownload->deleteLater();
    fileDownload = nullptr;
    isDownloading=false;

    downedData+=nowData;
    myFile.writeTextFile(QString::number(savedData),downloadFileName+DOWNLOAD_FILE_SUFFIX+DOWNLOAD_FILE_Temporary_SUFFIX,downloadFilePath);
}

QString MyNetwork::getHtmlContent(QString url)
{
    return getJson(url);
}

QString MyNetwork::getJson(QString url)
{
    if(!judgElement("url",url))
    {
        return "";
    }

    if(isGetJson==true){
        delete network_manager;
        delete network_request;
    }
    else
        isGetJson=true;

    network_manager = new QNetworkAccessManager();
    network_request = new QNetworkRequest();
    QNetworkReply *reply = network_manager->get(QNetworkRequest(QUrl(url)));

    if(isHasProxy==true)
        network_manager->setProxy(proxy);

    QByteArray responseData;
    QEventLoop eventLoop;
    connect(network_manager, &QNetworkAccessManager::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();       //block until finish
    responseData = reply->readAll();
    return QString(responseData);
}

void MyNetwork::getJson(QString url, int time)
{
    if(isGetJson==true){
        delete network_manager;
        delete network_request;
    }
    else
        isGetJson=true;

    network_manager = new QNetworkAccessManager();
    network_request = new QNetworkRequest();

    if(isHasProxy==true)
        network_manager->setProxy(proxy);

    connect(network_manager, &QNetworkAccessManager::finished, this, &MyNetwork::on_getJson);

    network_request->setUrl(QUrl(url));
    network_manager->get(*network_request);

    if(time>0){
        connect(&getJsonTimer,&QTimer::timeout,this,&MyNetwork::on_getJsonTimer);
        getJsonTimer.start(time);
    }
}

void MyNetwork::setProxy(QString IP, quint16 port, QNetworkProxy::ProxyType type)
{
    proxy.setType(type);
    proxy.setHostName(IP);
    proxy.setPort(port);
    isHasProxy=true;
}

void MyNetwork::setProxy(QString IP_Port, QNetworkProxy::ProxyType type)
{
    proxy.setType(type);
    QStringList strList=IP_Port.split(":");
    if(strList.length()!=2){
        isHasProxy=false;
        return ;
    }
    proxy.setHostName(strList.at(0));
    proxy.setPort(strList.at(1).toUInt());
    isHasProxy=true;
}

void MyNetwork::setUrl(QString url)
{
    this->url=url;
}

void MyNetwork::setFileName(QString fileName)
{
    this->downloadFileName=fileName;
}

void MyNetwork::setPath(QString path)
{
    this->downloadFilePath=path;
}

QString MyNetwork::getFileName()
{
    return this->downloadFileName;
}

QString MyNetwork::getUrl()
{
    return this->url;
}

QString MyNetwork::getPath()
{
    return this->downloadFilePath;
}

QStringList MyNetwork::getUrlFIleInfo()
{
    return this->downloadInfo;
}

qint64 MyNetwork::getFileSize()
{
    return this->allData;
}

void MyNetwork::startRequest(QUrl url)
{
    downedData=0;

    QNetworkRequest qheader;
    qheader.setUrl(url);
    if(myFile.isFileExist(downloadFileName+DOWNLOAD_FILE_SUFFIX,downloadFilePath))
    {
        if(myFile.isFileExist(downloadFileName+DOWNLOAD_FILE_SUFFIX+DOWNLOAD_FILE_Temporary_SUFFIX,downloadFilePath))
        {
            QString downedSize=myFile.readTextFile(downloadFileName+DOWNLOAD_FILE_SUFFIX+DOWNLOAD_FILE_Temporary_SUFFIX,downloadFilePath);
            qheader.setUrl(url);
            QString Range="bytes="+downedSize+"-";//告诉服务器从DownedSize起开始传输
            qheader.setRawHeader("Range",Range.toLatin1());
            downedData=downedSize.toLongLong();
        }
    }
    managerDownload = new QNetworkAccessManager(this);
    replyDownload = managerDownload->get(QNetworkRequest(qheader));
    connect(replyDownload, &QNetworkReply::downloadProgress, this, &MyNetwork::on_updateDataReadProgress);
    connect(replyDownload, &QNetworkReply::finished, this, &MyNetwork::httpFinished);

    lastData=0;
    nowData=0;

    timeDownloadSpeed.start();
}

QStringList MyNetwork::getIp()
{
    QString localHostName=QHostInfo::localHostName();
    QHostInfo info=QHostInfo::fromName(localHostName);
    QStringList strList;
    foreach (QHostAddress address, info.addresses())
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
        {
            strList.append(address.toString());
        }
    }
    this->ip=strList;
    return strList;
}

QString MyNetwork::getOutIp()
{
    QString req = "http://www.3322.org/dyndns/getip";
    QString res = getHtmlContent(req);
    res.remove("\n");
    res.remove("\r");
    res.remove(" ");
    return res;
}

void MyNetwork::getDownloadFileInfo(QString url)
{
    if(!judgElement("url",url))
    {
        return ;
    }
    if(isDownloading==true)
        return ;
    else
        isDownloading=true;

    QNetworkRequest qheader;
    qheader.setUrl(url);
    this->url=url;
    managerDownload = new QNetworkAccessManager(this);
    replyDownload = managerDownload->get(QNetworkRequest(qheader));
    connect(replyDownload, &QNetworkReply::downloadProgress, this, &MyNetwork::on_getFileSize);
}

bool MyNetwork::getIsDownloading()
{
    return isDownloading;
}

void MyNetwork::init()
{
    fileSize=0;
    lastData=0;
    nowData=0;
    allData=0;
    savedData=0;
    downedData=0;
    ip.clear();
    url.clear();
    downloadFileName.clear();
    downloadFilePath.clear();
    downloadInfo.clear();

    if(isGetJson){
        delete network_manager;
        delete network_request;
        isGetJson=false;
    }
    if(isDownloading){
        isDownloading=false;
    }
    if(isHasProxy){
        isHasProxy=false;
    }
}

void MyNetwork::download(QString fileName, QString path, QString url)
{
    if(!judgElement("url",url))
    {
        returnDownloadError("网址为空");
        return ;
    }
    if(!judgElement("downloadFileName",fileName))
        return ;
    if(!judgElement("downloadFilePath",path))
        return ;

    if(isDownloading==true)
        return;

    if(path.contains("\\"))
        path.replace("\\","/");

    if(url.contains("thunder://",Qt::CaseInsensitive))
    {
        url.remove("thunder://",Qt::CaseInsensitive);
        QByteArray byte = QByteArray::fromBase64(url.toLocal8Bit());
        url=QString(byte);
        url.remove(0,2);
        url.remove(url.length()-2,2);
    }

    if(!myFile.isFileExist(fileName,path))
    {
        downloadFileName=fileName;
    }
    else
    {
        if(myFile.isFileExist(fileName+DOWNLOAD_FILE_SUFFIX,path))
        {
            if(!myFile.isFileExist(fileName+DOWNLOAD_FILE_SUFFIX+DOWNLOAD_FILE_Temporary_SUFFIX,path))
            {
                myFile.deleteFile(fileName+DOWNLOAD_FILE_SUFFIX,path);
                myFile.sleep(1000);
            }
        }
        QStringList nameList=fileName.split(".");
        QString name;
        if(nameList.length()==1)
        {
            name=nameList.at(0);
        }
        else
        {
            for(int x=0;x<nameList.length()-1;x++)
                name+=nameList.at(x);
        }
        for(int x=0;;x++)
        {
            if(nameList.length()==1)
            {
                if(!myFile.isFileExist(name+QString("(%1)").arg(x+1),path))
                {
                    downloadFileName=name+QString("(%1)").arg(x+1);
                    break;
                }
            }
            else
            {
                if(!myFile.isFileExist(name+QString("(%1).").arg(x+1)+nameList.at(nameList.length()-1),path))
                {
                    downloadFileName=name+QString("(%1).").arg(x+1)+nameList.at(nameList.length()-1);
                    break;
                }
            }
        }
    }
    downloadFilePath=path;

    fileDownload = new QFile(path+"/"+downloadFileName+DOWNLOAD_FILE_SUFFIX);

    startRequest(url);
    isDownloading=true;
}

bool MyNetwork::judgElement(QString elementName, QString &element)
{
    if(elementName=="url" && element.isEmpty())
    {
        if(!this->url.isEmpty())
        {
            element=this->url;
            qDebug()<<"url is empty, use the class's attribute";
            return true;
        }
        else
        {
            qDebug()<<"url is empty，return false";
            return false;
        }
    }
    else if(elementName=="downloadFileName" && element.isEmpty())
    {
        if(!this->downloadFileName.isEmpty())
        {
            element=this->downloadFileName;
            qDebug()<<"fileName is empty, use the class's attribute";
            return true;
        }
        else
        {
            qDebug()<<"fileName and class's attribute are empty，return false";
            return false;
        }
    }
    else if(elementName=="downloadFilePath" && element.isEmpty())
    {
        if(!this->url.isEmpty())
        {
            element=this->downloadFilePath;
            qDebug()<<"path is empty, use the class's attribute";
            return true;
        }
        else
        {
            element=MyFile::pathDesktop();
            qDebug()<<"path and class's attribute are empty，use the desktop path";
            return true;
        }
    }
    else
    {
        return true;
    }
}
