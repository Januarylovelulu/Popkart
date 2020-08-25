#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include "cheackoperatingversion.h"

QString getQssContent()
{
    QFile styleSheet(":/log/styleSheet.css");
    if (!styleSheet.open(QIODevice::ReadOnly))
    {
        qWarning("Can't open the style sheet file.");
        return "";
    }
    return styleSheet.readAll();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(getQssContent());

    double version=3.76;

    QPixmap pixmap("./picture/loading.png");
    QPixmap scaledPixmap = pixmap.scaled(500,500,Qt::KeepAspectRatio);
    QSplashScreen splash(scaledPixmap);
    splash.setFont(QFont("楷体",20,60));
    splash.show();
    a.processEvents();

    splash.showMessage("正在启动程序...", Qt::AlignBottom|Qt::AlignLeft, Qt::red);

    QCoreApplication::setOrganizationName(QString("FuQinQuWeiWan"));
    QCoreApplication::setApplicationName(QString("游戏启动器"));

    QSettings settings(QSettings::NativeFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    MyFile myFile;
    myFile.setInitialEnvironment(argc,argv);

    if(settings.contains("deleteName"))
    {
        QString fileName=settings.value("deleteName").toString();
        QString filePath=settings.value("deletePath").toString();
        myFile.deleteFile(fileName,filePath);
        settings.remove("deleteName");
        settings.remove("deletePath");
        QStringList fileList=myFile.fileInDirectory(MyFile::pathDesktop());
        for(int x=0;x<fileList.length();x++)
        {
            if(fileList.at(x).contains("游戏启动器"))
            {
                myFile.deleteFile(fileList.at(x),MyFile::pathDesktop());
            }
        }
        //0为程序路径,1为程序名字,2为打开文件的路径,3为打开文件的名字
        if(myFile.getArgvElements().at(0)!=myFile.pathDesktop())
        {
            myFile.createLinkFile(myFile.getArgvElements().at(1)
                                  ,MyFile::pathDesktop()
                                  ,myFile.getArgvElements().at(1)
                                  ,myFile.getArgvElements().at(0));
        }
    }
    else
    {

        if(!settings.contains("isFirst"))
        {
            settings.setValue("Application Version",version);
            settings.setValue("picPath","");
            settings.setValue("popCarPath","");
            settings.setValue("isFirst",0);
        }
        else
        {
            double version1 = settings.value("Application Version").toDouble();
            settings.setValue("Application Version",version);

            QString str=settings.value("settings").toString();
            QStringList strList=str.split(";");
            if(strList.length()<=7||strList.length()>=10)
                settings.remove("settings");
            else if(strList.length()==8)
            {
                settings.setValue("settings",str+";1");
                strList.append("1");
            }

            if(version1>version)
            {
                QMessageBox box;
                box.addButton("确定",QMessageBox::YesRole);
                box.setText("检测到曾经下载过更高版本的启动器\n"
                            "也没啥，只是提醒你一下");
                box.exec();
            }
        }
    }

    settings.setValue("isFirst",settings.value("isFirst").toInt()+1);

    if(settings.value("isFirst").toInt()==10 || settings.value("isFirst").toInt()%50==0)
    {
        QMessageBox box(QMessageBox::NoIcon,"Thanks","");
        box.addButton("确定",QMessageBox::YesRole);
        box.setText("这是您第"+QString::number(settings.value("isFirst").toInt())+
                    "次打开启动器\n"
                    "谢谢您的使用和支持！");
        box.setIconPixmap(QPixmap("./picture/thanks.png"));
        box.exec();
    }

    if(!settings.contains("ifNotWin7"))
    {
        splash.showMessage("正在获取系统信息...", Qt::AlignBottom|Qt::AlignLeft, Qt::red);
        settings.setValue("ifNotWin7",1);
        CheackOperatingVersion *checkOperatingVersion=new CheackOperatingVersion();
    }

    splash.showMessage("正在加载程序...", Qt::AlignBottom|Qt::AlignLeft, Qt::red);

    QSharedMemory singleton(a.applicationName());
    if(!singleton.create(1))  {    //已经存在的
        QMessageBox box;
        box.setWindowTitle("已经打开");
        box.setText("已经有此软件运行!");
        box.addButton("好的",QMessageBox::RejectRole);
        box.exec();

        exit(0);
    }

    MainWindow w(argc,argv,version);
    w.show();
    splash.finish(&w);

    if(settings.contains("Path2.0")
            ||settings.contains("Path2.1")
            ||settings.contains("Path3.0")
            ||settings.contains("PathPSM")
            ||settings.contains("PathYouHua")
            ||settings.contains("PathJinHua")
            ||settings.contains("PathX"))
    {
        //如果有任何一个路径，do nothing
    }
    else
    {
        w.changeVertion_fuction();
    }

    return a.exec();
}
