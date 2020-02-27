#ifndef MyFile_H
#define MyFile_H

#include <QString>
#include <QStringList>
#include <QProcess>
#include <QFileDialog>
#include <QDateTime>
#include <QDesktopServices>
#include <QElapsedTimer>
#include <QApplication>
#include <QClipboard>
#include <QMimeData>

#ifdef Q_OS_WIN32
#include "windows.h"
#endif

/*
 * 所有带nullptr的初值的函数的,在不赋值的情况下,都会默认用类的private中对应的变量
 * 当使用带nullptr的初值的函数,赋了初值,就不会使用类中对应的变量
 * 比如:当打开D:/123/1.txt文件时,当类中变量fileName=="1.txt",path=="D:/123".
 * 此时可直接用myFile.openFile();
 * 也可以用myFile.openFile("1.txt","D:/123");
 *
 * 当类中变量fileName,path都为空时,
 * 此时可以直接用myFile.openFile("1.txt","D:/123");
 * 也可以myFile.setFileName("1.txt");  myFile.setPath("D:/123");   myFile.openFile();
 *
 * 当使用setInitialEnvironmen(int argc,char *argv[]);的函数时,一般是把此程序设置为其他文件的默认打开程序
 * 此时调用此函数后,可以用if(this.getArgvElements().length()==4)来判断是不是被设置为默认程序而被动打开
 * 如果是被其他文件被动打开的,则私有变量fileName和path就自动被赋值为用户选择的文件.
 * setInitialEnvironmen(int argc,char *argv[]);的示例用法请在example.txt中查看
 *
 * 使用cmd功能，先绑定此类的sendCmdMessage信号，然后myFile.startCmd("ping localhost"); 就会从绑定的槽函数返回结果
 * 槽函数的声明模板 void getCmdMessage(QString msg,int isEnd);
*/

class MyFile :public QObject
{
    Q_OBJECT

public:
    enum SelectAttr{
        selectAll = 0,
        selectExe = 1,
        selectApp = 2,
        selectHtml = 3,
        selectMusic = 4,
        selectPictrue = 5,
        selectText = 6
    };
    Q_ENUM(SelectAttr)
    QStringList strListSelectAttr;
    const QString strSelectAttr="*;所有文件\n"
                                "*.exe;应用程序\n"
                                "*.app;应用程序\n"
                                "*.html *.css *.js;网页文件\n"
                                "*.mp3 *.flac *.wav *.aac *.ape;音乐\n"
                                "*.png *.jpg *.bmp *.ico,.heif,.jpge;图片\n"
                                "*.txt *.log *.lu;文本文件";

    explicit MyFile(QString fileName=nullptr, QString path=nullptr);//构造函数,为变量赋值,directoryName为path的最后的名字(最后一个"/"之后的)
    void setInitialEnvironment(int argc,char *argv[]);//处理程序初始化设计,用于判断是否用文件关联打开
    ~MyFile();
    void setFileName(QString fileName);
    void setPath(QString path);
    void setDirectoryName(QString directoryName);
    void clearFileName();
    void clearPath();
    void clearDirectoryName();
    QString getFileName();
    QString getPath();
    QString getDirectoryName();
    QStringList getArgvElements();//如果返回的QStringList长度等于4,则传参给了程序(即cmd调用程序后面跟参数,或者把程序设置为其他文件的默认打开程序)

    //下面的select函数除了选择文件夹,其他的返回值都是 路径+文件名 可以用getFileName()只获取文件名字,getPath()只获取路径
    QStringList selectFile(SelectAttr selectAttr=MyFile::selectAll);//打开文件选择界面,并返回文件的绝对路径,为fileName和path赋值（如果选择多个文件，赋值鼠标点击的第一个文件的路径）
                                                                //用预设的枚举值，快速选择
    QStringList selectFile(QString suffix,QString titleName);//重载函数
                                                         //参数suffix为文件的后缀名，titleName为选择界面标题
                                                         //示例：selectFile("*.png *.img" , "图片")
    QStringList selectDirectory();//打开文件夹选择界面,并返回文件夹的绝对路径,为directoryName和path赋值（如果选择多个文件夹，赋值鼠标点击的第一个文件夹的路径）

    QString getFileName(QString path);//获取path路径的最后的名字(最后一个"/"之后的)
    QString getPath(QString path);//在selectFile()保存路径之后,用此函数获取文件的路径(不包括文件名字)
    QString getDirectoryName(QString path);//获取path路径的最后的名字(最后一个"/"之后的)

    static QString pathDesktop();//返回桌面路径
    static QString pathDocument();//返回我的文档路径
    static void sleep(int ms);//睡眠时间，以毫秒为单位
    static QString char_ToQString(char *argv);//char*转QString
    static void clipboardCopy(const QString str);//复制到剪切板
    static void clipboardCopy(const QImage image);//复制到剪切板
    static void clipboardCopy(const QPixmap pixmap);//复制到剪切板
    void clipboardPaste();//获取剪切板

    bool isFileExist(QString fileName=nullptr, QString path=nullptr);//判断路径是否有该文件(默认当前路径)
    bool isDirectoryExist(QString directoryName=nullptr, QString path=nullptr);//判断路径是否有该文件夹(默认当前路径)

    bool openDirectory(QString path=nullptr);//打开路径的文件夹,默认为程序所在的文件夹
    bool openFile(QString fileName=nullptr, QString path=nullptr);//打开某个文件(比如exe,txt),默认为程序所在的文件夹
    bool openHtmlFile(QString websitePath);//访问网页

    QString readTextFile(QString fileName=nullptr, QString path=nullptr, bool isUTF_8=false);//读取文档里面的内容,返回所有内容(可搭配QStringList逐行保存),返回值为空(说明读入失败,或者文件本身为空)
    QString readTextFile(bool isUTF_8);//重载,此函数默认使用私有变量的fileName和path,fileName变量为空时,返回空字符串,path为空,默认当前路径
    QString getCreatTime(QString fileName=nullptr, QString path=nullptr, QString timeFormat="yyyy-MM-dd hh:mm:ss");//返回文件创建的时间,可用第三个参数调整时间格式
    QString getLastOverWriteTime(QString fileName=nullptr, QString path=nullptr, QString timeFormat="yyyy-MM-dd hh:mm:ss");//返回文件最后一次修改的时间
    static QString getCurrentTime(QString timeFormat="yyyy-MM-dd hh:mm:ss");//返回当前电脑时间
    bool rename(QString fileNameNew,QString path=nullptr,QString fileNameOld=nullptr);//给文件重命名,isNeglectHide是否忽略隐藏文件
    QStringList fileInDirectory(QString path=nullptr,bool isNeglectHide=false);//遍历文件夹里面的文件,isNeglectHide是否忽略隐藏文件
    QStringList directoryInDirectory(QString path=nullptr,bool isNeglectHide=false);//遍历文件夹里面的文件夹,isNeglectHide是否忽略隐藏文件

    bool writeTextFile(QString text, QString fileName=nullptr, QString path=nullptr, bool isUTF_8=false, QIODevice::OpenMode mode=QIODevice::Truncate);//把文件写出到电脑,第二个参数为默认覆盖上一次的数据，QIODevice::Append为不覆盖写入
    bool writeTextFile(QString text, bool isUTF_8, QIODevice::OpenMode mode=QIODevice::Truncate);//重载,此函数默认使用私有变量的fileName和path当做存储路径,fileName变量为空时系统取名,path为空时默认当前路径
    bool writeControlDataFile(QString text, QString fileName=nullptr, QString path=nullptr, bool isUTF_8=false);
    void createLinkFile(QString linkName, QString linkPath=nullptr, QString fileName=nullptr, QString path=nullptr);//创建程序的快捷方式到程序所在的文件夹
    bool createDirectory(QString directoryName=nullptr, QString path=nullptr);//创建文件夹

    bool isThisExeAlreadyOPen();//检测当前程序是否已经打开过,用于多开检测
    int isExeRunning(QString fileName=nullptr);//判断程序是否在运行，windows下：0为没有运行，其他为在运行；MacOS下：0为没有运行，其他为返回程序的PID
    bool killExe(QString fileName=nullptr);//关闭程序
    bool isOnline();//将花费2.5秒检测是否已经联网,会阻塞进程

    bool deleteDirectory(QString path=nullptr);//删除文件夹,默认为当前文件夹下的文件夹
    bool deleteAllFileInDirectory(QString path=nullptr);//删除文件夹里面的所有文件,默认为当前文件夹下的文件,如果没有此文件夹,就创建
    bool deleteFile(QString fileName=nullptr, QString path=nullptr);//删除文件
    bool copyFile(QString pathTo, QString fileName=nullptr, QString pathFrom=nullptr);//拷贝文件到pathTo

    QString startCmd(QString cmd , int msecs=-1 , bool simpleMode=true);//外界接口，获取cmd消息,msece为请求超时时间,它会阻塞进程直到时间超时或者完成搜索，-1为无限等待
                                                //simpleMode==true时不绑定槽,直接一次性由函数返回值返回cmd消息,simpleMode==false时，返回值为空，cmd消息由槽传输
                                             //使用前先绑定信号槽，信号为sendCmdMessage(QString,int)
                                             //sendCmdMessage传递的isEnd参数，1完成，0超时或者错误，-1正在继续

signals:
    void sendCmdMessage(QString str,int isEnd);//cmd信息的传出接口,isEnd=1完成，0超时或者错误，-1正在继续

private slots:
    void on_getCmdMessage();//获得终端的消息

private:
    QString fileName;
    QString directoryName;
    QString path;

    QStringList argvElements;//0为程序路径,1为程序名字,2为打开文件的路径,3为打开文件的名字
    bool isInitial=false;//如果是初始环境下打开的，那么argvElements应该至少有0,1

    bool judgElement(QString elementName, QString &element);

    QProcess *processCmd;//用于执行终端的命令
    bool isProcessCmdExsist=false;//防止processCmd被重复new
};

#endif//MyFile_H
