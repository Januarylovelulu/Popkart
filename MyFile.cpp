#include "MyFile.h"
#include <QDebug>

MyFile::MyFile(QString fileName, QString path)
{
    this->fileName=fileName;
    this->path=path;
    this->directoryName=this->getDirectoryName(path);
    strListSelectAttr=strSelectAttr.split("\n");
}

void MyFile::setInitialEnvironment(int argc, char *argv[])
{
    QString path=MyFile::char_ToQString(argv[0]);
    path.replace("\\","/");
    this->argvElements.append(this->getPath(path));
    this->argvElements.append(this->getFileName(path));

    this->isInitial=true;

#ifdef Q_OS_WIN32
    if(argc>1)//如果是Windows文件关联方式打开的
    {
        path=MyFile::char_ToQString(argv[1]);
        path.replace("\\","/");
        this->setFileName(this->getFileName(path));
        this->setPath(this->getPath(path));
        this->argvElements.append(this->getPath(path));
        this->argvElements.append(this->getFileName(path));
    }
#endif

#ifdef Q_OS_MACOS
    this->sleep(1000);
    this->setFileName("1616.txt");
    this->setPath(this->getPath(path));
    if(this->isFileExist())//Macos下文件关联方式打开的
    {
        path=readTextFile();
        deleteFile();
        path.replace("\\","/");
        this->setFileName(this->getFileName(path));
        this->setPath(this->getPath(path));
        this->argvElements.append(this->getPath(path));
        this->argvElements.append(this->getFileName(path));
    }
#endif
}

MyFile::~MyFile()
{
    if(isProcessCmdExsist==true)
        delete processCmd;
}

void MyFile::setFileName(QString fileName)
{
    this->fileName=fileName;
}

void MyFile::setPath(QString path)
{
    this->path=path;
}

void MyFile::setDirectoryName(QString directoryName)
{
    this->directoryName=directoryName;
}

void MyFile::clearFileName()
{
    this->fileName.clear();
}

void MyFile::clearPath()
{
    this->path.clear();
}

void MyFile::clearDirectoryName()
{
    this->directoryName.clear();
}

QString MyFile::getFileName()
{
    return this->fileName;
}

QString MyFile::getPath()
{
    return this->path;
}

QString MyFile::getDirectoryName()
{
    return this->directoryName;
}

QStringList MyFile::getArgvElements()
{
    return this->argvElements;
}

QStringList MyFile::selectFile(MyFile::SelectAttr selectAttr)
{
    QFileDialog *fileDialog = new QFileDialog();
    fileDialog->setDirectory(".");
    QString strAttr;
    switch (selectAttr)
    {
    case selectExe:strAttr=this->strListSelectAttr.at(1);break;
    case selectApp:strAttr=this->strListSelectAttr.at(2);break;
    case selectHtml:strAttr=this->strListSelectAttr.at(3);break;
    case selectMusic:strAttr=this->strListSelectAttr.at(4);break;
    case selectPictrue:strAttr=this->strListSelectAttr.at(5);break;
    case selectText:strAttr=this->strListSelectAttr.at(6);break;
    default:strAttr=this->strListSelectAttr.at(0);
    }
    fileDialog->setWindowTitle(strAttr.split(";").at(1));
    fileDialog->setNameFilter(strAttr.split(";").at(1)+"("+strAttr.split(";").at(0)+")");
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    fileDialog->setViewMode(QFileDialog::Detail);
    QStringList fileNames;
    if(fileDialog->exec())
    {
        fileNames = fileDialog->selectedFiles();
    }
    QStringList fileNamePath;
    int index=0;//检测是否设置过文件名字路径
    for(auto tmp:fileNames)
    {
        if(index==0)
        {
            setFileName(getFileName(tmp));
            setPath(getPath(tmp));
            index++;
        }
        fileNamePath.append(tmp);
    }
    return fileNamePath;
}

QStringList MyFile::selectFile(QString suffix, QString titleName)
{
    QFileDialog *fileDialog = new QFileDialog();
    fileDialog->setDirectory(".");
    if(suffix.isEmpty())
    {
        fileDialog->setWindowTitle("选择文件");
        fileDialog->setNameFilter("选择所有文件(*)");
    }
    else
    {
        fileDialog->setWindowTitle("选择"+titleName);
        fileDialog->setNameFilter(titleName+"("+suffix+")");
    }
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    fileDialog->setViewMode(QFileDialog::Detail);
    QStringList fileNames;
    if(fileDialog->exec())
    {
        fileNames = fileDialog->selectedFiles();
    }
    QStringList fileNamePath;
    int index=0;//检测是否设置过文件名字路径
    for(auto tmp:fileNames)
    {
        if(index==0)
        {
            setFileName(getFileName(tmp));
            setPath(getPath(tmp));
            index++;
        }
        fileNamePath.append(tmp);
    }
    return fileNamePath;
}

QStringList MyFile::selectDirectory()
{
    QFileDialog *fileDialog = new QFileDialog();
    fileDialog->setWindowTitle("打开目录");
    fileDialog->setDirectory(".");
    fileDialog->setNameFilter("");
    fileDialog->setFileMode(QFileDialog::Directory);
    fileDialog->setViewMode(QFileDialog::Detail);
    QStringList fileNames;
    if(fileDialog->exec())
    {
        fileNames = fileDialog->selectedFiles();
    }
    QStringList fileNamePath;
    int index=0;//检测是否设置过文件名字路径
    for(auto tmp:fileNames)
    {
        if(index==0)
        {
            setFileName(getFileName(tmp));
            setPath(getPath(tmp));
            index++;
        }
        fileNamePath.append(tmp);
    }
    return fileNamePath;
}

QString MyFile::getFileName(QString path)
{
    QStringList strList=path.split("/");
    return strList.at(strList.length()-1);
}

QString MyFile::getPath(QString path)
{
    QStringList strList=path.split("/");
    path="";
    if(strList.length()<=1)
        return path;
    for(int x=0;x<strList.length()-1;x++)
    {
        path+=strList.at(x);
        if(x!=strList.length()-2)
        {
            path+="/";
        }
    }
    return path;
}

QString MyFile::getDirectoryName(QString path)
{
    QStringList strList=path.split("/");
    return strList.at(strList.length()-1);
}

QString MyFile::pathDesktop()
{
    QString path=QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    return path;
}

QString MyFile::pathDocument()
{
    QString path=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    return path;
}

void MyFile::sleep(int ms)
{
    QElapsedTimer t;
    t.start();
    while(t.elapsed()<ms)
        QCoreApplication::processEvents();
}

QString MyFile::char_ToQString(char *argv)
{
    return QString::fromLocal8Bit(argv);
}

void MyFile::clipboardCopy(const QString str)
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(str);
}

void MyFile::clipboardCopy(const QImage image)
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setImage(image);
}

void MyFile::clipboardCopy(const QPixmap pixmap)
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setPixmap(pixmap);
}

void MyFile::clipboardPaste()
{
    const QClipboard *clipboard = QApplication::clipboard();
    const QMimeData *mimeData = clipboard->mimeData();
    if (mimeData->hasImage()) {

    }
    else if (mimeData->hasHtml()) {

    }
    else if (mimeData->hasText()) {

    }
    else {

    }
}

bool MyFile::isFileExist(QString fileName, QString path)
{
    if(!judgElement("fileName",fileName))
        return false;
    judgElement("path",path);
    QFileInfo file(path+"/"+fileName);
    if(file.isFile())
        return true;
    else
        return false;
}

bool MyFile::isDirectoryExist(QString directoryName, QString path)
{
    if(!judgElement("directoryName",directoryName))
        return false;
    judgElement("path",path);
    QDir dir(path+"/"+directoryName);
    if(dir.exists())
        return true;
    return false;
}

bool MyFile::openDirectory(QString path)
{
    judgElement("path",path);
    if(QDesktopServices::openUrl(QUrl("file:"+path, QUrl::TolerantMode)))
        return true;
    else
        return false;
}

bool MyFile::openFile(QString fileName, QString path)
{
    if(!judgElement("fileName",fileName))
        return false;
    judgElement("path",path);
    if(QDesktopServices::openUrl(QUrl("file:"+path+"/"+fileName, QUrl::TolerantMode)))
        return true;
    else
        return false;

    //QProcess process(0);
    //process.startDetached(path+fileName,QStringList());
}

bool MyFile::openHtmlFile(QString websitePath)
{
    if(QDesktopServices::openUrl(QUrl(websitePath)))
        return true;
    else
        return false;
}

QString MyFile::readTextFile(QString fileName, QString path, bool isUTF_8)
{
    if(!judgElement("fileName",fileName))
        return "";
    judgElement("path",path);
    QFile file(path+"/"+fileName);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return "";
    }
    QTextStream in(&file);
    if(isUTF_8==true)
        in.setCodec("UTF-8");
    else
        in.setCodec("ANSI");
    QString str = in.readAll();
    file.close();
    return str;
}

QString MyFile::readTextFile(bool isUTF_8)
{
    QString fileName=getFileName();
    QString path=getPath();
    if(fileName.isEmpty())
        return "";
    judgElement("path",path);
    QFile file(path+"/"+fileName);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return "";
    }
    QTextStream in(&file);
    if(isUTF_8==true)
        in.setCodec("UTF-8");
    else
        in.setCodec("ANSI");
    QString str = in.readAll();
    file.close();
    return str;
}

QString MyFile::getCreatTime(QString fileName, QString path, QString timeFormat)
{
    if(!judgElement("fileName",fileName))
        return "";
    judgElement("path",path);
    QFileInfo file(path+"/"+fileName);
    return file.created().toString(timeFormat);
}

QString MyFile::getLastOverWriteTime(QString fileName, QString path, QString timeFormat)
{
    if(!judgElement("fileName",fileName))
        return "";
    judgElement("path",path);
    QFileInfo file(path+"/"+fileName);
    return file.lastModified().toString(timeFormat);
}

QString MyFile::getCurrentTime(QString timeFormat)
{
    QDateTime time;
    time = QDateTime::currentDateTime();
    return time.toString(timeFormat);
}

bool MyFile::rename(QString fileNameNew, QString path, QString fileNameOld)
{
    if(!judgElement("fileName",fileNameOld))
        return false;
    judgElement("path",path);
    if(QFile::rename(path+"/"+fileNameOld,path+"/"+fileNameNew))
        return true;
    else
        return false;
}

QStringList MyFile::fileInDirectory(QString path,bool isNeglectHide)
{
    judgElement("path",path);
    QDir dir(path);
    QStringList strList;
    if(!dir.exists())
        return strList;
    if(isNeglectHide==true)
        dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
    else
        dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden);
    QFileInfoList fileList = dir.entryInfoList();
    foreach (QFileInfo fi, fileList)
    {
        if (fi.isFile())
            strList.append(fi.fileName());
    }
    return strList;
}

QStringList MyFile::directoryInDirectory(QString path,bool isNeglectHide)
{
    judgElement("path",path);
    QDir dir(path);
    QStringList strList;
    if(!dir.exists())
        return strList;
    if(isNeglectHide==true)
        dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
    else
        dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden);
    QFileInfoList fileList = dir.entryInfoList();
    foreach (QFileInfo fi, fileList)
    {
        if (!fi.isFile())
            strList.append(fi.fileName());
    }
    return strList;
}

bool MyFile::writeTextFile(QString text, QString fileName, QString path, bool isUTF_8, QIODevice::OpenMode mode)
{
    if(!judgElement("fileName",fileName))
    {
        QString x="";
        int num=1;
        while(isFileExist(QString("LuLu%1.txt").arg(x),path))
        {
            x="_"+QString::number(num);
            num++;
        }
        qDebug()<<QString("fileName is empty!The default name is %1.").arg("LuLu"+x+".txt");
        fileName="LuLu"+x+".txt";
    }
    judgElement("path",path);
    QFile file(path+"/"+fileName);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text|mode))
    {
        return false;
    }
    QTextStream outPut(&file);
    if(isUTF_8==true)
        outPut.setCodec("UTF-8");
    else
        outPut.setCodec("ANSI");
    outPut<<text;
    file.close();
    return true;
}

bool MyFile::writeTextFile(QString text, bool isUTF_8, QIODevice::OpenMode mode)
{
    QString fileName=getFileName();
    QString path=getPath();
    if(!judgElement("fileName",fileName))
    {
        QString x="";
        int num=1;
        while(isFileExist(QString("LuLu%1.txt").arg(x),path))
        {
            x="_"+QString::number(num);
            num++;
        }
        qDebug()<<QString("fileName is empty!The default name is %1.").arg("LuLu"+x+".txt");
        fileName="LuLu"+x+".txt";
    }
    judgElement("path",path);
    QFile file(path+"/"+fileName);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text|mode))
    {
        return false;
    }
    QTextStream outPut(&file);
    if(isUTF_8==true)
        outPut.setCodec("UTF-8");
    else
        outPut.setCodec("ANSI");
    outPut<<text;
    file.close();
    return true;
}

bool MyFile::writeControlDataFile(QString text, QString fileName, QString path, bool isUTF_8)
{
    if(!judgElement("fileName",fileName))
    {
        QString x="";
        int num=1;
        while(isFileExist(QString("LuLu%1.log").arg(x),path))
        {
            x="_"+QString::number(num);
            num++;
        }
        qDebug()<<QString("fileName is empty!The default name is %1.").arg("LuLu"+x+".log");
        fileName="LuLu"+x+".log";
    }
    judgElement("path",path);
    QFile file(path+"/"+fileName);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))
    {
        return false;
    }
    QTextStream outPut(&file);
    if(isUTF_8==true)
        outPut.setCodec("UTF-8");
    else
        outPut.setCodec("ANSI");
    outPut<<this->getCurrentTime()+"\n";
    outPut<<text;
    file.close();
    return true;
}

void MyFile::createLinkFile(QString linkName, QString linkPath, QString fileName, QString path)
{
    if(!judgElement("fileName",fileName))
    {
        QString x="";
        int num=1;
        while(isFileExist(QString("LuLu%1.txt").arg(x),path))
        {
            x="_"+QString::number(num);
            num++;
        }
        qDebug()<<QString("fileName is empty!The default name is %1.").arg("LuLu"+x+".txt");
        fileName="LuLu"+x+".txt";
    }
    judgElement("path",path);
    if(linkPath.isEmpty())
    {
        linkPath=path;
    }
    QFile::link(path+"/"+fileName, linkPath+"/"+linkName+".lnk");
}

bool MyFile::createDirectory(QString directoryName, QString path)
{
    if(!judgElement("directoryName",directoryName))
    {
        QString x="";
        int num=1;
        while(isDirectoryExist(QString("LuLu%1").arg(x),path))
        {
            x="_"+QString::number(num);
            num++;
        }
        qDebug()<<QString("directoryName is empty!The default name is %1.").arg("LuLu"+x);
        directoryName="LuLu"+x;
    }
    judgElement("path",path);
    QDir dir(path);
    if(!dir.exists(directoryName))
    {
        dir.mkdir(directoryName);
        return true;
    }
    else
    {
        return false;
    }
}

bool MyFile::isThisExeAlreadyOPen()
{
#ifdef Q_OS_WIN32
    QProcess process;
    QStringList strList;
    process.start("tasklist.exe");
    QString result = startCmd("tasklist.exe");
    strList=result.split("\n");
    for(int x=0;x<strList.length();x++)
    {
        QString appName;
        if(this->isInitial)
            appName=this->getArgvElements().at(1);
        else
            appName=QApplication::applicationName()+".exe";

        int len=12;
        if(appName.length()>=len)
            appName.remove(len,appName.length()-len);

        if(strList.at(x).contains(appName,Qt::CaseInsensitive))
        {
            QStringList strList2=QString(strList.at(x)).split(" ", QString::SkipEmptyParts);
            if(strList2.length()==1)
            {
                continue;
            }
            if(strList2.at(0).contains(appName,Qt::CaseInsensitive)||appName.contains(strList2.at(0),Qt::CaseInsensitive))
            {
                if(strList2.at(1)!=QString::number((int)GetCurrentProcessId()))
                    return true;
            }
        }
    }
    return false;
#endif

#ifdef Q_OS_MACOS
    QStringList strList;
    int appTime=0;//计数有几个程序在运行
    QString result = startCmd("ps -A");
    strList=result.split("\n");
    for(int x=0;x<strList.length();x++)
    {
        if(QString(strList.at(x)).contains(QApplication::applicationName(),Qt::CaseSensitive))
        {
            QStringList strList2=QString(strList.at(x)).split(" ", QString::SkipEmptyParts);
            QStringList strList3=strList2.at(strList2.length()-1).split("/");
            QString appName;
            if(this->isInitial)
                appName=this->getArgvElements().at(1);
            else
                appName=QApplication::applicationName();
            if(strList3.at(strList3.length()-1).toUpper()==appName.toUpper())
            {
                appTime++;
            }
        }
    }
    if(appTime>=2)
    {
        return true;
    }
    return false;
#endif
}

int MyFile::isExeRunning(QString fileName)
{
    if(!judgElement("fileName",fileName))
    {
        return false;
    }

#ifdef Q_OS_WIN32
    QString result = startCmd("tasklist.exe");
    QStringList strList=result.split("\n");
    for(int x=0;x<strList.length();x++)
    {
        if(strList.at(x).contains(fileName,Qt::CaseInsensitive))
        {
            QStringList strList2=strList.at(x).split(" ",QString::SkipEmptyParts);
            if(strList2.at(0).toUpper()==fileName.toUpper())
            {
                return 1;
            }
        }
    }
    return 0;
#endif
#ifdef Q_OS_MACOS
    int PID=0;
    QString result = startCmd("ps -A");
    QStringList strList=result.split("\n");
    for(int x=0;x<strList.length();x++)
    {
        if(strList.at(x).contains(fileName,Qt::CaseSensitive))
        {
            QStringList strList2=strList.at(x).split(" ",QString::SkipEmptyParts);
            QStringList strList3=strList2.at(strList2.length()-1).split("/");
            if(strList3.at(strList3.length()-1).toUpper()==fileName.toUpper())
            {
                PID=strList2.at(0).toInt();
                break;
            }
        }
    }
    return PID;
#endif
}

bool MyFile::killExe(QString fileName)
{
    if(!judgElement("fileName",fileName))
    {
        return false;
    }
    QProcess process;
#ifdef Q_OS_WIN32
    if(isExeRunning(fileName))
    {
        QString c = "taskkill /im "+fileName+" /f";
        process.execute(c);
        return true;
    }
    else
        return false;
#endif
#ifdef Q_OS_MACOS
    int PID=isExeRunning(fileName);
    if(PID!=0)
    {
        process.execute("kill "+QString::number(PID));
        process.close();
        return true;
    }
    else
        return false;
#endif
}

bool MyFile::isOnline()
{
#ifdef Q_OS_MACOS
    QString result=startCmd("ping www.baidu.com",3000);
    QStringList strList=result.split("\n");
    int time=0;//检测有网则+1
    for(int x=0;x<strList.length();x++)
    {
        if(strList.at(x).contains("time="))
        {
            int timeDelay=strList.at(x).split("time=").at(1).split(".").at(0).toInt();//网络延迟
            if(timeDelay>0&&timeDelay<1000)
            {
                time++;
            }
        }
    }
    if(time>=(strList.length()-1)/2 && strList.length()>=2) return true;
    else return false;
#endif

#ifdef Q_OS_WIN32
    QString result=startCmd("ping www.baidu.com",3000);
    QStringList strList=result.split("\n",QString::SkipEmptyParts);
    int time=0,times=0;//检测有网则+1
    for(int x=0;x<strList.length();x++)
    {
        if(strList.at(x).contains("来自")||strList.at(x).contains("Reply"))
        {
            int timeDelay;
            if(strList.at(x).contains("来自"))
                timeDelay=strList.at(x).split("时间=").at(1).split("ms").at(0).toInt();//网络延迟
            else
                timeDelay=strList.at(x).split("time=").at(1).split("ms").at(0).toInt();//网络延迟
            if(timeDelay>0&&timeDelay<1000)
            {
                time++;
            }
            times++;
        }
    }
    if(time>=times/2 && strList.length()>=2) return true;
    else return false;
#endif
}

bool MyFile::deleteDirectory(QString path)
{
    judgElement("path",path);
    QDir dir(path);
    if(!dir.exists())
        return true;
    dir.setFilter(QDir::AllEntries | QDir::Hidden | QDir::NoDotAndDotDot);
    QFileInfoList fileList = dir.entryInfoList();
    foreach (QFileInfo fi, fileList)
    {
        if (fi.isFile())
            fi.dir().remove(fi.fileName());
        else
            deleteDirectory(path+"/"+fi.fileName());
    }
    return dir.rmpath(dir.absolutePath());
}

bool MyFile::deleteAllFileInDirectory(QString path)
{
    judgElement("path",path);
    QDir dir(path);
    if(!dir.exists())
        return this->createDirectory(getDirectoryName(path),getPath(path));
    dir.setFilter(QDir::AllEntries | QDir::Hidden | QDir::NoDotAndDotDot);
    QFileInfoList fileList = dir.entryInfoList();
    foreach (QFileInfo fi, fileList)
    {
        if (fi.isFile())
            fi.dir().remove(fi.fileName());
        else
        {
            deleteDirectory(path+"/"+fi.fileName());
        }
    }
    return this->createDirectory(getDirectoryName(path),getPath(path));
}

bool MyFile::deleteFile(QString fileName, QString path)
{
    if(!judgElement("fileName",fileName))
    {
        return false;
    }
    judgElement("path",path);
    QFile file(path+"/"+fileName);
    file.setPermissions(QFile::WriteOwner);
    if (file.exists())
    {
        file.remove();
        return true;
    }
    else
    {
        return false;
    }
}

bool MyFile::copyFile(QString pathTo, QString fileName, QString pathFrom)
{
    judgElement("fileName",fileName);
    judgElement("path",pathFrom);
    if(pathFrom==pathTo)
        return false;
    if(!isFileExist(fileName,pathFrom))//如果不存在源文件
    {
        return false;
    }
    if(isFileExist(fileName,pathTo))//如果存在名字相同的文件
    {
        deleteFile(fileName,pathTo);
    }
    if(!QFile::copy(pathFrom+"/"+fileName,pathTo+"/"+fileName))
    {
        return false;
    }
    return true;
}

QString MyFile::startCmd(QString cmd, int msecs, bool simpleMode)
{
    if(isProcessCmdExsist==true)
        delete processCmd;
    else
        isProcessCmdExsist=true;
    processCmd = new QProcess();

    processCmd->setProcessChannelMode(QProcess::MergedChannels);
    if(simpleMode)
    {
        processCmd->start(cmd);
        processCmd->waitForFinished(msecs);
        QTextStream in(processCmd);
        QString result = in.readAll();
        return result;
    }
    else
    {
        connect(processCmd,&QProcess::readyReadStandardOutput,this,&MyFile::on_getCmdMessage);
        processCmd->start(cmd);
        if(processCmd->waitForFinished(msecs))
        {
            emit sendCmdMessage("",1);
            delete processCmd;
            isProcessCmdExsist=false;
        }
        else
        {
            emit sendCmdMessage("",0);
            delete processCmd;
            isProcessCmdExsist=false;
        }
        return "";
    }

}

void MyFile::on_getCmdMessage()
{
    QByteArray qbt = processCmd->readAllStandardOutput();
    QString msg = QString::fromLocal8Bit(qbt);
    emit sendCmdMessage(msg,-1);
}

bool MyFile::judgElement(QString elementName, QString &element)
{
    if(elementName=="fileName")
    {
        if(element.isEmpty())
        {
            element=getFileName();
            if(element.isEmpty())
            {
                qDebug()<<"fileName is empty!";
                return false;
            }
        }
    }
    else if(elementName=="path")
    {
        if(element.isEmpty())
        {
            element=getPath();
            if(element.isEmpty())
            {
                element=QDir::currentPath();
                qDebug()<<"path is empty.It would find in current Directory.";
                return false;
            }
        }
    }
    else if(elementName=="directoryName")
    {
        if(element.isEmpty())
        {
            element=getDirectoryName();
            if(element.isEmpty())
            {
                qDebug()<<"directoryName is empty!";
                return false;
            }
        }
    }
    return true;
}
