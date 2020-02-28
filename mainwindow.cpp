#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

HHOOK keyHook=NULL;
void unHook();
void setHook();
LRESULT CALLBACK keyProc(int nCode,WPARAM wParam,LPARAM lParam );
MainWindow *thisClass;
SeamlessSetting *seam;
int seamlessLock=0;

MainWindow::MainWindow(int argc, char *argv[], double version) :
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    myFile.setInitialEnvironment(argc,argv);

    settings = new QSettings(QSettings::NativeFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    this->version=version;

    ui->textBrowser->insertPlainText("启动器版本:"+QString::number(version)+"\n"
                                     "作者：");
    ui->textBrowser->setTextColor("red");
    ui->textBrowser->insertPlainText("抚琴曲委婉\n");
    ui->textBrowser->setTextColor("black");
//    ui->textBrowser->insertPlainText("作者个人的空间：\n");
//    ui->textBrowser->setTextColor("blue");
//    ui->textBrowser->insertPlainText("www.ruiruiandlulu.online\n");
//    ui->textBrowser->setTextColor("black");
    ui->textBrowser->insertPlainText("\n打开启动器的记录："
                                     +QString::number(settings->value("isFirst").toInt())
                                     +"次\n");
    ui->label_icon->setStyleSheet("background:transparent");
    ui->label_icon->setScaledContents(true);
    ui->label_icon->hide();

    thisWindowTitle="游戏启动器 V"+QString::number(version);

    if(myFile.isThisExeAlreadyOPen())
    {
        QMessageBox box;
        box.setWindowTitle("已经打开");
        box.setText("已经有此软件运行!");
        box.addButton("好的",QMessageBox::RejectRole);
        box.exec();
        exit(0);
    }

    ifHavePath=false;

    //背景图片的检测
    QString pathPic=settings->value("picPath").toString();
    if(pathPic.isEmpty())
    {
        pathPic="./picture/background.png";
        settings->setValue("picPath",pathPic);
    }
    else
    {
        if(!myFile.isFileExist(myFile.getFileName(pathPic),myFile.getPath(pathPic)))
        {
            pathPic="./picture/background.png";
            settings->setValue("picPath","./picture/background.png");
        }
    }
    QImage imgBackgroud(pathPic);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(imgBackgroud.scaled(this->width(),this->height())));
    this->setPalette(palette);

    //检测跑跑卡丁车单机版路径
    localHostPath=settings->value("popCarPath").toString();
    if(myFile.isFileExist("KartRider.exe"))
    {
        localHostPath=QDir::currentPath();
        settings->setValue("popCarPath",localHostPath);

        QString version=checkVersion();
        if(version=="2.0")
            settings->setValue("Path2.0",localHostPath);
        else if(version=="2.1")
            settings->setValue("Path2.1",localHostPath);
        else if(version=="3.0")
            settings->setValue("Path3.0",localHostPath);
        else if(version=="PSM")
            settings->setValue("PathPSM",localHostPath);
        else if(version=="优化")
            settings->setValue("PathYouHua",localHostPath);
        else if(version=="进化")
            settings->setValue("PathJinHua",localHostPath);

        ui->textBrowser->insertPlainText("\n找到配置文件夹\n游戏版本:"+checkVersion()+"\n");
        ui->label_icon->setPixmap("./picture/"+checkVersion()+".ico");
//        ui->label_icon->show();
        ifHavePath=true;
    }
    else if(!localHostPath.isEmpty())
    {
        if(myFile.isFileExist("KartRider.exe",localHostPath))
        {
            ui->textBrowser->insertPlainText("\n找到配置文件夹\n游戏版本:"+checkVersion()+"\n");
            ui->label_icon->setPixmap("./picture/"+checkVersion()+".ico");
//            ui->label_icon->show();
            ifHavePath=true;
        }
        else
        {
            ui->textBrowser->insertPlainText("\n没有正确配置文件夹路径,请手动选择\n");
            settings->setValue("popCarPath","");
        }
    }
    else
    {
        ui->textBrowser->insertPlainText("\n没有正确配置文件夹路径,请手动选择\n");
    }

    //无路径时，按钮灰色
    if(ifHavePath==true)
    {
        ui->menu_2->setEnabled(true);
        ui->carCode->setEnabled(true);
        ui->comboBox->setEnabled(true);
        ui->changeCar->setEnabled(true);
        ui->startGame->setEnabled(true);
        ui->seamlessTurnOn->setEnabled(true);

        ui->carCode->installEventFilter(this);
    }

    ui->carChangeShow->hide();
    ui->comboBox->move(ui->comboBox->x(),100);
    ui->changeCar->move(ui->changeCar->x(),100);
    ui->adPicture->move(ui->adPicture->x(),200);

    //美化
    this->setStyleSheet("font-family:\"楷体\";"
                        "font-size:21px;"
                        "font-weight:100;");
    ui->changeCar->setStyleSheet("font-size:18px;");

    for(int x=0;x<ui->comboBox->count();x++)
    {
        ui->comboBox->setItemData(x, QColor(255,255,255,100) , Qt::ForegroundRole);
    }
    ui->carCode->setStyleSheet("font-size:18px;");

    ui->adPicture->setAttribute(Qt::WA_TranslucentBackground);

    this->setMinimumSize(this->width(),this->height());
    this->setMaximumSize(this->width(),this->height());

    //设置
    settingChange();

    //menu菜单栏
    connect(ui->changeVersion,&QAction::triggered,this,&MainWindow::on_changeVersion);
    connect(ui->changeBackgroundPic,&QAction::triggered,this,&MainWindow::on_changeBackgroundPic);
    connect(ui->searchQuestion,&QAction::triggered,this,&MainWindow::on_searchQuestion);
    connect(ui->minishow,&QAction::triggered,this,&MainWindow::on_miniShow);
    connect(ui->quit,&QAction::triggered,this,&MainWindow::on_quit);

    connect(ui->startRefit,&QAction::triggered,this,&MainWindow::on_startRefit);
    connect(ui->startRepair,&QAction::triggered,this,&MainWindow::on_startRepair);
    connect(ui->resetPPConfig,&QAction::triggered,this,&MainWindow::on_resetPPConfig);

    connect(ui->screenShotPath,&QAction::triggered,this,&MainWindow::on_screenShotPath);
    connect(ui->vedioPath,&QAction::triggered,this,&MainWindow::on_vedioPath);
    connect(ui->shadowPath,&QAction::triggered,this,&MainWindow::on_shadowPath);
    connect(ui->shadowDelete,&QAction::triggered,this,&MainWindow::on_shadowDelete);

    connect(ui->setting,&QAction::triggered,this,&MainWindow::on_setting);
    connect(ui->changeShortcut,&QAction::triggered,this,&MainWindow::on_changeShortcut);
    connect(ui->seamlessSetting,&QAction::triggered,this,&MainWindow::on_seamlessSetting);
    connect(ui->gameDPI,&QAction::triggered,this,&MainWindow::on_gameDPI);
    connect(ui->update,&QAction::triggered,this,&MainWindow::on_update);


    //广告轮播
    connect(&changePicTimer,&QTimer::timeout,this,&MainWindow::on_timeOutChangePic);
    connect(&startPicTimer,&QTimer::timeout,this,&MainWindow::on_timeOutStartTimer);
    readAdPicture();

    //无缝设置
    if(settings->contains("seamlessSetting"))
    {
        QString read=settings->value("seamlessSetting").toString();
        QStringList strList=read.split(";");
        seamlessKey[0]=QString(strList.at(0)).toInt();
        seamlessKey[1]=QString(strList.at(1)).toInt();
    }
    else
    {
        seamlessKey[0]=-1;
        seamlessKey[1]=-1;
    }

    //最小化到托盘
    mSysTrayIcon = new QSystemTrayIcon(this);
    QIcon icon = QIcon("./picture/game.ico");
    mSysTrayIcon->setIcon(icon);
    mSysTrayIcon->setToolTip(QObject::trUtf8("跑跑卡丁车启动器"));
    connect(mSysTrayIcon,&QSystemTrayIcon::activated,this,&MainWindow::on_activatedSysTrayIcon);
    createActions();
    createMenu();
    mSysTrayIcon->show();

    threadCheckGameIsOpen = new ThreadCheckGameIsOpen(this);
    connect(threadCheckGameIsOpen,&ThreadCheckGameIsOpen::returnResult,this,&MainWindow::on_timeOutCheckGameIsOpen);
    threadCheckGameIsOpen->start();

    //检查是否为最新版
    QString strS=settings->value("settings").toString();
    QStringList strListS=strS.split(";");
    if(strListS.at(8)=="1")
    {
        ThreadCheckHasNewVersion *threadCheckHasNewVersion=new ThreadCheckHasNewVersion(this,version);
        connect(threadCheckHasNewVersion,&ThreadCheckHasNewVersion::returnResult,this,&MainWindow::on_getReturnHasNewVersion);
        threadCheckHasNewVersion->startReady();
        threadCheckHasNewVersion->start();
        ui->textBrowser->insertPlainText("\n正在检查是否有新版本\n");
    }
}

MainWindow::~MainWindow()
{
    threadCheckGameIsOpen->stop();
    threadCheckGameIsOpen->wait();
    if(!shortcutKeypressShow.isEmpty())
        delete shortcutShow;
    if(!shortcutKeypressHide.isEmpty())
        delete shortcutHide;
    if(!shortcutKeypressSeamless.isEmpty())
        delete shortcutSeamless;
    delete threadCheckGameIsOpen;
    delete settings;
    delete ui;
}

bool MainWindow::getSeamlessOn()
{
    return this->seamlessOn;
}

void MainWindow::seamlessTimerStart()
{
    this->seamlessTimer.start(seamlessTime);
}

void MainWindow::seamlessTimerStop()
{
    this->seamlessTimer.stop();
}

void MainWindow::on_changeVersion()
{
    if(myFile.isExeRunning("KartRider.exe"))
    {
        QMessageBox box(this);
        box.addButton("确定", QMessageBox::AcceptRole);
        box.addButton("取消", QMessageBox::RejectRole);
        box.setWindowTitle(thisWindowTitle);
        box.setText(QString("进入切换版本界面会关闭游戏\n"
                            "是否打开切换版本界面并关闭游戏?"));
        int boxReturn=box.exec();
        if(boxReturn == 0)
        {
            if(myFile.isExeRunning("KartRider.exe"))
            {
                myFile.killExe("KartRider.exe");
            }
            if(myFile.isExeRunning("PPServer.exe"))
            {
                myFile.killExe("PPServer.exe");
            }
            myFile.sleep(500);
            if(myFile.isExeRunning(("AdBalloonExt.exe")))
            {
                myFile.killExe("AdBalloonExt.exe");
            }
        }
        else if(boxReturn==1)
        {
            return;
        }
    }
    QString path=settings->value("popCarPath").toString();
    ChangeVersion *changeVersion = new ChangeVersion(this);
    if(changeVersion->isHaveGame[6]==false)
    {
        QMessageBox box(this);
        box.addButton("确定",QMessageBox::YesRole);
        box.setText("未检测到任何游戏\n"
                    "请选择游戏路径，或者下载游戏");
        box.exec();
    }
    changeVersion->exec();
    delete changeVersion;
    QString pathAfter=settings->value("popCarPath").toString();
    if(path!=pathAfter || (path.isEmpty() && !pathAfter.isEmpty()))
    {
        ui->textBrowser->setText("\n版本切换 成功\n当前游戏版本："+checkVersion()+"\n");
        localHostPath=pathAfter;
        if(ifHavePath==false)
        {
            ifHavePath=true;
            ui->menu_2->setEnabled(true);
            ui->carCode->setEnabled(true);
            ui->comboBox->setEnabled(true);
            ui->changeCar->setEnabled(true);
            ui->startGame->setEnabled(true);
            ui->seamlessTurnOn->setEnabled(true);

            ui->carCode->installEventFilter(this);
        }
        readAdPicture();
        ui->label_icon->setPixmap("./picture/"+checkVersion()+".ico");
//        ui->label_icon->show();
    }
    else
    {
        if(checkVersion().isEmpty())
        {
            ui->label_icon->hide();
            ui->textBrowser->setText("\n版本切换 失败\n原因可能如下：\n"
                                     "①未添加游戏路径\n"
                                     "②添加游戏路径后没有切换游戏版本\n\n"
                                     "当前游戏版本：未选择\n");
        }
        else
            ui->textBrowser->setText("\n版本切换 失败\n原因可能如下：\n"
                                     "①版本选择重复\n"
                                     "②版本切换页面关闭\n\n"
                                     "当前游戏版本："+checkVersion()+"\n");
    }
}

void MainWindow::on_changeBackgroundPic()
{
    QStringList pathList=myFile.selectFile(MyFile::selectPictrue);
    QString path;
    if(pathList.isEmpty())
        return;
    else
    {
        path=pathList.at(0);
        QImage imgBackgroud(path);
        QPalette palette;
        palette.setBrush(this->backgroundRole(),
                         QBrush(imgBackgroud.scaled(this->width(),this->height())));
        this->setPalette(palette);

        settings->setValue("picPath",path);
        ui->textBrowser->insertPlainText("\n背景图片更换成功!\n");
    }
}

void MainWindow::on_searchQuestion()
{
    SearchQuestion *searchQuestion = new SearchQuestion(this);
    searchQuestion->exec();
    delete searchQuestion;
}

void MainWindow::on_miniShow()
{
    miniShow();
}

void MainWindow::on_quit()
{
    close();
}

void MainWindow::on_startRefit()
{
    if(ifHavePath==false)
        return ;

    ui->textBrowser->insertPlainText("\n改装器启动中");


    if(myFile.isFileExist("修改器.lnk",localHostPath))
    {
        myFile.deleteFile("修改器.lnk",localHostPath);
    }
    myFile.createLinkFile("修改器",localHostPath,"修改器.exe",localHostPath);

    if(myFile.openFile("修改器.lnk",localHostPath))
    {
        ui->textBrowser->insertPlainText("\n改装器已经打开\n");
        myFile.deleteFile("修改器.lnk",localHostPath);
    }
    else
    {
        ui->textBrowser->insertPlainText("\n改装器打开失败,请手动打开\n");
    }
}

void MainWindow::on_startRepair()
{
    QMessageBox box(this);
    box.addButton("确认重置", QMessageBox::AcceptRole);
    box.addButton("取消重置", QMessageBox::RejectRole);
    box.setWindowTitle(thisWindowTitle);
    box.setText("你要重置改装吗？\n"
                "此操作会覆盖所有改装文件");
    int qMess=box.exec();

    QString version=checkVersion();

    QString path;
    if(version=="2.0"||version=="2.1")
    {
        path="./dat2.0";
    }
    else
    {
        path="./dat3.0";
    }
    if(qMess==0)
    {
        ui->textBrowser->insertPlainText("\n版本："+version+"\n");
        for(int x=0;x<3;x++)
        {
            if(!myFile.isFileExist(QString("Kart%1.dat").arg(x),path))
            {
                ui->textBrowser->insertPlainText(QString("Kart%1.dat文件丢失!\n").arg(x));
                ui->textBrowser->insertPlainText("\n重置改装操作失败!\n");
                return;
            }
        }
        for(int x=0;x<3;x++)
        {
//            QString read=myFile.readTextFile(QString("Kart%1.dat").arg(x),path);
            if(myFile.copyFile(localHostPath,QString("Kart%1.dat").arg(x),path))
            {
                ui->textBrowser->insertPlainText(QString("Kart%1.dat文件替换成功!\n").arg(x));
            }
            else
            {
                ui->textBrowser->insertPlainText(QString("Kart%1.dat文件替换失败!\n").arg(x));
                ui->textBrowser->insertPlainText("\n重置改装操作失败!\n");
                return;
            }
        }
        ui->textBrowser->insertPlainText("\n重置改装操作成功!\n");
    }
}

void MainWindow::on_resetPPConfig()
{
    QMessageBox box(this);
    box.setText("是否重置该游戏版本的PPConfig？");
    box.setInformativeText("推荐换车时，游戏闪退使用");
    box.addButton("确定",QMessageBox::YesRole);
    box.addButton("取消",QMessageBox::NoRole);
    int a=box.exec();
    if(a==0)
    {
        QString read=myFile.readTextFile("PPConfig.ini",":/log");
        if(myFile.isFileExist("PPConfig.ini",this->localHostPath) && !read.isEmpty())
            myFile.deleteFile("PPConfig.ini",this->localHostPath);
        if(myFile.writeTextFile(read,"PPConfig.ini",localHostPath))
        {
            ui->textBrowser->insertPlainText("\n重置PPConfig成功！\n");
            return;
        }
        ui->textBrowser->insertPlainText("\n重置PPConfig失败！\n");
    }
}

void MainWindow::on_screenShotPath()
{
    if(myFile.openDirectory(MyFile::pathDocument()+"/跑跑卡丁车/图片"))
    {
        ui->textBrowser->insertPlainText("\n截图文件夹打开成功!\n");
    }
    else
    {
        if(!myFile.isDirectoryExist("跑跑卡丁车",MyFile::pathDocument())){
            myFile.createDirectory("跑跑卡丁车",MyFile::pathDocument());
        }
        if(myFile.createDirectory("图片",MyFile::pathDocument()+"/跑跑卡丁车")){
            ui->textBrowser->insertPlainText("\n截图文件夹不存在，已经建立!\n");
        }
        else{
            ui->textBrowser->insertPlainText("\n截图文件夹不存在，并出现未知错误，创建失败!\n");
        }
    }
}

void MainWindow::on_vedioPath()
{
    if(myFile.openDirectory(MyFile::pathDocument()+"/跑跑卡丁车/VIDEO"))
    {
        ui->textBrowser->insertPlainText("\n视频文件夹打开成功!\n");
    }
    else
    {
        if(!myFile.isDirectoryExist("跑跑卡丁车",MyFile::pathDocument())){
            myFile.createDirectory("跑跑卡丁车",MyFile::pathDocument());
        }
        if(myFile.createDirectory("VIDEO",MyFile::pathDocument()+"/跑跑卡丁车")){
            ui->textBrowser->insertPlainText("\n视频文件夹不存在，已经建立!\n");
        }
        else{
            ui->textBrowser->insertPlainText("\n视频文件夹不存在，并出现未知错误，创建失败!\n");
        }
    }
}

void MainWindow::on_shadowPath()
{
    if(myFile.openDirectory(MyFile::pathDocument()+"/跑跑卡丁车/玩家资料"))
    {
        ui->textBrowser->insertPlainText("\n影子文件夹打开成功!\n");
    }
    else
    {
        if(!myFile.isDirectoryExist("跑跑卡丁车",MyFile::pathDocument())){
            myFile.createDirectory("跑跑卡丁车",MyFile::pathDocument());
        }
        if(myFile.createDirectory("玩家资料",MyFile::pathDocument()+"/跑跑卡丁车")){
            ui->textBrowser->insertPlainText("\n影子文件夹不存在，已经建立!\n");
        }
        else{
            ui->textBrowser->insertPlainText("\n影子文件夹不存在，并出现未知错误，创建失败!\n");
        }
    }
}

void MainWindow::on_shadowDelete()
{
    if(myFile.isDirectoryExist("玩家资料",MyFile::pathDocument()+"/跑跑卡丁车"))
    {
        myFile.deleteAllFileInDirectory(MyFile::pathDocument()+"/跑跑卡丁车/玩家资料");
        ui->textBrowser->insertPlainText("\n影子文件已经删除!\n");
    }
    else
    {
        ui->textBrowser->insertPlainText("\n影子文件夹不存在，已经建立!\n");
        myFile.createDirectory("玩家资料",MyFile::pathDocument()+"/跑跑卡丁车");
    }
}

void MainWindow::on_setting()
{
    Setting *setting;
    setting=new Setting(this);
    connect(setting,&Setting::transparent,this,&MainWindow::on_getTransparentFromSetting);
    setting->exec();
    delete setting;
    settingChange();
}

void MainWindow::on_changeShortcut()
{
    if(!shortcutKeypressHide.isEmpty())
    {
        delete shortcutHide;
    }
    if(!shortcutKeypressShow.isEmpty())
    {
        delete shortcutShow;
    }
    if(!shortcutKeypressSeamless.isEmpty())
    {
        delete shortcutSeamless;
    }
    ShortcutChange *shortcutChange;
    shortcutChange=new ShortcutChange(this,shortcutKeypressShow,shortcutKeypressHide,shortcutKeypressSeamless);

    shortcutKeypressShow="";
    shortcutKeypressHide="";
    shortcutKeypressSeamless="";

    shortcutChange->exec();
    delete shortcutChange;
    shortcutBind();
}

void MainWindow::on_seamlessSetting()
{
    setHook();
    seamlessLock=1;
    seam=new SeamlessSetting(this);
    seam->exec();
    delete seam;
    seamlessLock=0;
    if(seamlessOn==false)
    {
        unHook();
    }
    if(settings->contains("seamlessSetting"))
    {
        QString read=settings->value("seamlessSetting").toString();
        QStringList strList=read.split(";");
        seamlessKey[0]=QString(strList.at(0)).toInt();
        seamlessKey[1]=QString(strList.at(1)).toInt();
    }
    else
    {
        ui->textBrowser->insertPlainText("\n无缝键位没有设置!\n");
    }
}

void MainWindow::on_gameDPI()
{
    DPI *dpi=new DPI(this,localHostPath);
    dpi->exec();
    delete dpi;
}

void MainWindow::on_update()
{
    ThreadCheckHasNewVersion *threadCheckHasNewVersion=new ThreadCheckHasNewVersion(this,version);
    connect(threadCheckHasNewVersion,&ThreadCheckHasNewVersion::returnResult,this,&MainWindow::on_getReturnHasNewVersion);
    threadCheckHasNewVersion->startReady();
    threadCheckHasNewVersion->start();
    ui->textBrowser->insertPlainText("\n正在检查是否有新版本\n");
}

void MainWindow::autoScrollTextBrowser(QTextBrowser *text)
{
    text->moveCursor(QTextCursor::End);
}

void MainWindow::miniShow()
{
    this->hide();
    QString str="\"Alt+"+shortcutKeypressShow+"\"可快速打开软件\n";
    std::string s1=str.toStdString();
    mSysTrayIcon->showMessage(QObject::trUtf8("最小化到托盘"),
                                      QObject::trUtf8(s1.c_str()),
                                      QSystemTrayIcon::Information,
                                      100);
}

void MainWindow::createActions()
{
    mShowMainAction = new QAction(QObject::trUtf8("显示主界面"),this);
    connect(mShowMainAction,&QAction::triggered,this,&MainWindow::on_showMainAction);
    mExitAppAction = new QAction(QObject::trUtf8("退出"),this);
    connect(mExitAppAction,&QAction::triggered,this,&MainWindow::on_exitAppAction);
}

void MainWindow::createMenu()
{
    mMenu = new QMenu(this);
    mMenu->addAction(mShowMainAction);
    mMenu->addSeparator();
    mMenu->addAction(mExitAppAction);
    mSysTrayIcon->setContextMenu(mMenu);
}

QString MainWindow::checkVersion()
{
    QString str=settings->value("popCarPath").toString();
    if(str.isEmpty())
    {
        return "";
    }

    if(myFile.isFileExist("【跑友公社】优化版·超高速改装文件.exe",str)||myFile.isFileExist("优化版标志.txt",str))
    {
        return "优化";
    }
    else if(myFile.isFileExist("mav.dat",str)||myFile.isFileExist("进化版标志.txt",str))
    {
        return "进化";
    }
    else if(myFile.isFileExist("Uninstall.exe",str)||myFile.isFileExist("PSM版标志.txt",str))
    {
        return "PSM";
    }
    else if(myFile.isFileExist("KartRiderCN.ini",str)||myFile.isFileExist("2.1版标志.txt",str))
    {
        return "2.1";
    }
    else if(myFile.isFileExist("NanumGothicBold.ttf",str)||myFile.isFileExist("2.0版标志.txt",str))
    {
        return "2.0";
    }
    else
    {
        return "3.0";
    }
}

void MainWindow::readAdPicture()
{
    if(startPicTimer.isActive())
    {
        startPicTimer.stop();
        for(int x=0;x<changePicShowNum;x++)
        {
            delete changePicRadioBtn[x];
        }
        delete changePicRadioBtn;
    }
    for(int x=0;x<50;x++)
        choosePic[x]=-1;

    changePicNum=0;
    for(int x=0;;x++)
    {
        if(myFile.isFileExist(QString("%1.png").arg(x),"./ad"))
        {
            changePicNum++;
        }
        else
        {
            break;
        }
    }
    changeThisFlag=0;

    QString version=checkVersion();
    if(version=="2.0")
        versionAd=1;
    else if(version=="2.1")
        versionAd=2;
    else if(version=="3.0")
        versionAd=3;
    else if(version=="PSM")
        versionAd=4;
    else if(version=="优化")
        versionAd=5;
    else if(version=="进化")
        versionAd=6;
    else
        versionAd=0;

    QString str=myFile.readTextFile("操作文件.ini","./ad");
    QStringList strList=str.split("\n");
    QStringList strListVersion;
    for(int x=0;x<strList.length();x++)
    {
        strListVersion.append(strList.at(x).split("***").at(0));
    }

    changePicShowNum=0;
    for(int x=0;x<strListVersion.length();x++)
    {
        if(strListVersion.at(x).contains(QString::number(versionAd))||strListVersion.at(x).contains("0"))
        {
            choosePic[changePicShowNum]=x;
            changePicShowNum++;
        }
    }

    changePicRadioBtn=new QRadioButton *[changePicShowNum];
    for(int x=0;x<changePicShowNum;x++)
    {
        changePicRadioBtn[x]=new QRadioButton(ui->adPicture);
        changePicRadioBtn[x]->setText("");
        changePicRadioBtn[x]->resize(16,16);
        changePicRadioBtn[x]->move(ui->adPicture->width()-(changePicShowNum-x)*1.5*changePicRadioBtn[x]->width()
                                   ,ui->adPicture->height()-20);
        changePicRadioBtn[x]->installEventFilter(this);
        changePicRadioBtn[x]->setMouseTracking(true);
        changePicRadioBtn[x]->setStyleSheet("background:rgb(255,255,255,0);");
        changePicRadioBtn[x]->show();
    }
    ui->adPicture->installEventFilter(this);
    ui->adPicture->setPixmap(QPixmap("./ad/"+QString::number(choosePic[0])+".png"));
    ui->adPicture->setScaledContents(true);
    ui->adPicture->setMouseTracking(true);
    ui->adPicture->setCursor (Qt::PointingHandCursor);
    changePicRadioBtn[changeThisFlag]->setChecked(true);

    startPicTimer.start(500);
}

void MainWindow::adFunction(int x)
{
    QString read=myFile.readTextFile("操作文件.ini","./ad");
    QStringList strListLine=read.split("\n");
    if(strListLine.length()<=x)
    {
        ui->textBrowser->insertPlainText("\n没有对应的操作!\n");
        return;
    }
    QStringList strThis=QString(strListLine.at(choosePic[x])).split("***");
    QString cmd=strThis.at(1);
    QString path=strThis.at(2);
    if(cmd=="打开网页")
    {
        myFile.openHtmlFile(path);
    }
    else if(cmd=="打开文件")
    {
        if(path.contains("localHostPathReplace"))
        {
            path.remove("localHostPathReplace");
            myFile.openFile(myFile.getFileName(path),localHostPath+myFile.getPath(path));
        }
        else
            myFile.openFile(myFile.getFileName(path),myFile.getPath(path));
    }
    else if(cmd=="打开文件夹")
    {
        if(path.contains("localHostPathReplace"))
        {
            path.remove("localHostPathReplace");
            myFile.openDirectory(localHostPath+path);
        }
        else
            myFile.openDirectory(path);
    }
    else if(cmd=="输出到输出框")
    {
        if(path.contains("clear the textBrowser"))
        {
            path.remove("clear the textBrowser");
            ui->textBrowser->clear();
        }
        QString str=path.replace("^^","\n");
        ui->textBrowser->insertPlainText(str+"\n");
    }
    else if(cmd=="打开帮助窗口")
    {
        on_searchQuestion();
    }
    else if(cmd=="重置PPConfig" || cmd=="重置ppconfig")
    {
        on_resetPPConfig();
    }
}

void MainWindow::shortcutBind()
{
    if(settingCheckBox[1]==false)
    {
        ui->textBrowser->insertPlainText("\ntest\n");
        return ;
    }
    QString read=settings->value("shortcut").toString();
    if(!read.isEmpty())
    {
        QStringList strList=read.split(";");

        shortcutHide = new QxtGlobalShortcut(QKeySequence(QString("Alt+%1").arg(strList.at(0))));
        if(shortcutHide->isShortcutSuccessful())
        {
            connect(shortcutHide,&QxtGlobalShortcut::activated,this,&MainWindow::miniShow);
            shortcutKeypressHide=strList.at(0);
        }
        else
        {
            shortcutKeypressHide="";
            ui->textBrowser->insertPlainText("\n最小化到托盘快捷键绑定失败!请手动绑定\n");
            delete shortcutHide;
        }

        shortcutShow = new QxtGlobalShortcut(QKeySequence(QString("Alt+%1").arg(strList.at(1))));
        if(shortcutShow->isShortcutSuccessful())
        {
            connect(shortcutShow,&QxtGlobalShortcut::activated,this,&MainWindow::on_showMainAction);
            shortcutKeypressShow=strList.at(1);
        }
        else
        {
            shortcutKeypressShow="";
            ui->textBrowser->insertPlainText("\n打开主页面快捷键绑定失败!请手动绑定\n");
            delete shortcutShow;
        }

        shortcutSeamless=new QxtGlobalShortcut(QKeySequence(QString("Alt+%1").arg(strList.at(2))));
        if(shortcutSeamless->isShortcutSuccessful())
        {
            connect(shortcutSeamless,&QxtGlobalShortcut::activated,this,&MainWindow::on_seamlessStart);
            connect(&seamlessTimer,&QTimer::timeout,this,&MainWindow::on_seamlessTimeout);
            shortcutKeypressSeamless=strList.at(2);
        }
        else
        {
            shortcutKeypressSeamless="";
            ui->textBrowser->insertPlainText("\n无缝快捷键绑定失败!请手动绑定\n");
            delete shortcutSeamless;
        }
    }
    else
    {
        ui->textBrowser->insertPlainText("\n没有进行快捷键绑定的设置.请点击\"");
        ui->textBrowser->setTextColor(QColor("blue"));
        ui->textBrowser->insertPlainText(QString("菜单->快捷键更改"));
        ui->textBrowser->setTextColor(QColor("black"));
        ui->textBrowser->insertPlainText("\"设置快捷键\n");
    }
}

void MainWindow::settingChange()
{
    if(!settings->contains("settings"))
    {
        settings->setValue("settings","0;1;1;166;216;166;96;1;1");
    }
    QString str=settings->value("settings").toString();
    if(!str.isEmpty())
    {
        if(!shortcutKeypressHide.isEmpty())
        {
            delete shortcutHide;
            shortcutKeypressHide="";
        }
        if(!shortcutKeypressShow.isEmpty())
        {
            delete shortcutShow;
            shortcutKeypressShow="";
        }
        if(!shortcutKeypressSeamless.isEmpty())
        {
            delete shortcutSeamless;
            shortcutKeypressSeamless="";
        }

        QStringList strList=str.split(";");
        if(strList.at(0)=="1")
            settingCheckBox[0]=true;
        else
            settingCheckBox[0]=false;

        if(strList.at(1)=="1")
        {
            settingCheckBox[1]=true;
            ui->changeShortcut->setEnabled(true);
            shortcutBind();
        }
        else
        {
            settingCheckBox[1]=false;
            ui->changeShortcut->setEnabled(false);
            ui->textBrowser->insertPlainText("\ntest\n");
        }

        if(strList.at(2)=="1")
            settingCheckBox[2]=true;
        else
            settingCheckBox[2]=false;

        if(strList.at(7)=="1")
            settingCheckBox[3]=true;
        else
            settingCheckBox[3]=false;

        if(strList.at(8)=="1")
            settingCheckBox[4]=true;
        else
            settingCheckBox[4]=false;

        ui->textBrowser->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(3)));
        ui->carCode->setStyleSheet(QString("background:rgb(255,255,255,%1);"
                                           "font-size:18px;").arg(strList.at(4)));
        ui->changeCar->setStyleSheet(QString("background:rgb(25,255,255,%1);"
                                             "font-size:18px;").arg(strList.at(5)));
        ui->startGame->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->seamlessTurnOn->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));

        this->setWindowOpacity(QString(strList.at(6)).toDouble()/100.0);
    }
}

void MainWindow::on_changeCar_clicked()
{
    if(ui->carCode->text().isEmpty())
    {
        return ;
    }

    QString version=checkVersion();
    if(version=="PSM")
        version="3.0";

    if(ui->changeCar->text().contains("更改"))
    {
        QString code;
        if(ui->comboBox->currentText()=="更改车辆")
        {
            code="car";
        }
        else if(ui->comboBox->currentText()=="更改角色")
        {
            code="role";
        }
        else if(ui->comboBox->currentText()=="更改飞宠")
        {
            code="flypet";
        }
        else if(ui->comboBox->currentText()=="更改喷漆")
        {
            code="paint";
        }
        else if(ui->comboBox->currentText()=="更改车牌")
        {
            code="plate";
        }
        else if(ui->comboBox->currentText()=="更改头饰")
        {
            code="headdress";
        }
        else if(ui->comboBox->currentText()=="更改眼镜")
        {
            code="glass";
        }
        else if(ui->comboBox->currentText()=="更改手杖")
        {
            code="cane";
        }
        else if(ui->comboBox->currentText()=="更改气球")
        {
            code="ballon";
        }
        else if(ui->comboBox->currentText()=="更改服饰")
        {
            code="dress";
        }
        else if(ui->comboBox->currentText()=="更改炫光")
        {
            code="glare";
        }
        else if(ui->comboBox->currentText()=="更改印记")
        {
            code="driftTrace";
        }
        else if(ui->comboBox->currentText()=="更改宠物")
        {
            code="pet";
        }
        else if(ui->comboBox->currentText()=="更改名喷")
        {
            code="namePaint";
        }

        QString str=myFile.readTextFile("PPConfig.ini",localHostPath);
        QStringList strList=str.split("\n");
        int time=0;
        for(int x=0;x<strList.length();x++)
        {
            if(QString(strList.at(x)).contains(code,Qt::CaseInsensitive))
            {
                time=x;
                break;
            }
        }
        strList[time]=code+"="+ui->carCode->text();
        str="";
        for(int x=0;x<strList.length();x++)
        {
            if(x==strList.length()-1)
                str+=strList[x];
            else
                str+=strList[x]+"\n";
        }
        QString strIni=str;


        //修改信息

        str=myFile.readTextFile(ui->comboBox->currentText()+".txt",QString(":/%1").arg(version));
        str.replace(" ","");
        if(str=="")
        {
            ui->textBrowser->insertPlainText("\n\""+ui->comboBox->currentText()
                                             +".txt\"无法读取\n");
            return;
        }

        strList=str.split("\n");
        for(int x=0;x<strList.length();x++)
        {
            if(QString(strList.at(x)).contains(ui->carCode->text()+"：",Qt::CaseInsensitive))
            {
                str=strList.at(x);
                QStringList strListOnlyOnece=str.split("：");
                if(strListOnlyOnece.at(0)==ui->carCode->text())
                {
                    strList=str.split("：");
                    break;
                }
            }
            if(x==strList.length()-1)
            {
                ui->textBrowser->insertPlainText("\n错误：代码本内不包含此物品!\n");
                return ;
            }
        }

        if(QString(strList.at(1)).contains("crash",Qt::CaseInsensitive))//crash代码判断
        {
            QMessageBox box(this);
            box.setText("此代码会引起游戏崩溃");
            box.setInformativeText("禁止进行此操作！");
            box.addButton("返回",QMessageBox::YesRole);
            box.exec();
            return;
        }

        ui->textBrowser->insertPlainText("\n更改信息成功\n");
        ui->textBrowser->insertPlainText("更改为："+strList.at(1)+"\n");

        myFile.writeTextFile(strIni,"PPConfig.ini",localHostPath);

        ui->carCode->clear();
    }
    else
    {

        QString str=myFile.readTextFile(ui->comboBox->currentText()+".txt",QString(":/%1").arg(version));
        str.replace(" ","");
        QStringList strList=str.split("\n");
        ui->textBrowser->clear();
        ui->textBrowser->insertPlainText("以下为搜索的结果：\n");
        int times=0;
        for(int x=0;x<strList.length();x++)
        {
            if(ui->carCode->text()=="help")
            {
                if(QString(strList.at(x)).contains("：",Qt::CaseInsensitive))
                {
                    ui->textBrowser->insertPlainText(strList.at(x)+"\n");
                    times++;
                }
            }
            else
            {
                if(QString(strList.at(x)).contains(ui->carCode->text(),Qt::CaseInsensitive))
                {
                    ui->textBrowser->insertPlainText(strList.at(x)+"\n");
                    times++;
                }
            }
        }
        if(times==0)
        {
            ui->textBrowser->setText("搜索无结果!\n");
        }
        ui->carCode->clear();
    }
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj==ui->carCode)
    {
        if(event->type() == QMouseEvent::MouseButtonRelease)
        {
            if(ui->carCode->text()=="输入数字切换,名字查代码"||
                    ui->carCode->text().contains("输入\"help\"查看所有"))
            {
                ui->carCode->clear();
                return true;
            }
            return false;
        }
        else if(event->type() == QEvent::FocusOut)
        {
            if(ui->carCode->text().isEmpty())
            {
                ui->carCode->setText("输入\"help\"查看所有"+
                                     ui->comboBox->currentText().replace("更改",""));
                ui->changeCar->setFocus();
                return true;
            }
            return false;
        }
    }
    else if(obj==ui->adPicture)
    {
        if(event->type() == QMouseEvent::MouseMove)
        {
            changePicTimer.stop();
            return true;
        }
        else if(event->type() == QMouseEvent::MouseButtonRelease)
        {
            changePicTimer.stop();
            adFunction(changeThisFlag);
            return true;
        }
        return false;
    }
    else
    {
        for(int x=0;x<changePicShowNum;x++)
        {
            if(obj==changePicRadioBtn[x])
            {
                if(event->type() == QMouseEvent::MouseMove)
                {
                    changePicTimer.stop();
                    changePicRadioBtn[x]->setChecked(true);
                    ui->adPicture->setPixmap(QPixmap(QString("./ad/%1.png").arg(choosePic[x])));
                    changeThisFlag=x;
                    return true;
                }
                return false;
            }
        }
    }
    return QObject::eventFilter(obj, event);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter painter(&bmp);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::black);
    painter.drawRoundedRect(bmp.rect(),16,16);
    setMask(bmp);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_move = true;
        //记录鼠标的世界坐标.
        m_startPoint = event->globalPos();
        //记录窗体的世界坐标.
        m_windowPoint = this->frameGeometry().topLeft();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        //移动中的鼠标位置相对于初始位置的相对位置.
        QPoint relativePos = event->globalPos() - m_startPoint;
        //然后移动窗体即可.
        this->move(m_windowPoint + relativePos );
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        //改变移动状态.
        m_move = false;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //  快捷键，使回车就能换车
    if(event->key() == Qt::Key_Return){
        if(!ui->carCode->text().isEmpty() && !ui->carCode->text().contains("输入数字"))
            on_changeCar_clicked();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(myFile.isExeRunning("kartRider.exe"))
    {
        QMessageBox box(this);
        box.addButton("最小化", QMessageBox::AcceptRole);
        box.addButton("取消", QMessageBox::RejectRole);
        box.addButton("退出程序", QMessageBox::AcceptRole);
        box.setWindowTitle(thisWindowTitle);
        box.setText("当前游戏正在运行,是否关闭游戏？\n");
        int boxReturn=box.exec();
        if(boxReturn == 0)
        {
            event->ignore();
            miniShow();
            return;
        }
        else if(boxReturn==1)
        {
            event->ignore();
            return;
        }
        else
        {
            myFile.killExe("kartRider.exe");
        }
    }
    if(myFile.isExeRunning("PPServer.exe"))
    {
        myFile.killExe("PPServer.exe");
    }
    myFile.sleep(500);
    if(myFile.isExeRunning(("AdBalloonExt.exe")))
    {
        myFile.killExe("AdBalloonExt.exe");
    }
    delete mSysTrayIcon;
    delete mMenu;
    delete mShowMainAction;
    delete mExitAppAction;
    threadCheckGameIsOpen->stop();
    threadCheckGameIsOpen->terminate();
    threadCheckGameIsOpen->wait();
    event->accept();
    unHook();
    exit(0);
}

void MainWindow::on_carCode_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);

    ui->carChangeShow->hide();
    ui->comboBox->move(ui->comboBox->x(),100);
    ui->changeCar->move(ui->changeCar->x(),100);
    ui->adPicture->move(ui->adPicture->x(),200);

    QString version=checkVersion();
    if(version=="PSM")
        version="3.0";

    QString code=ui->comboBox->currentText();
    code.replace("更改","");

    QString str=ui->carCode->text();
    if(str.length()>=6||str.isEmpty())
    {
        ui->changeCar->setText("查找"+code+"代码");
        return;
    }
    QByteArray ba = str.toLatin1();
    const char *s = ba.data();


    while(*s && *s>='0' && *s<='9') s++;

    if (*s)
    {
        ui->changeCar->setText("查找"+code+"代码");
    }
    else
    {
        ui->changeCar->setText("更改"+code);
        if(!myFile.isFileExist(ui->comboBox->currentText()+".txt",QString(":/%1").arg(version)))
        {
            ui->carChangeShow->setText("\""+ui->comboBox->currentText()
                                             +".txt\"无法读取");
        }
        else
        {
            str=myFile.readTextFile(ui->comboBox->currentText()+".txt",QString(":/%1").arg(version));
            str.replace(" ","");
            QStringList strList=str.split("\n");

            for(int x=0;x<strList.length();x++)
            {
                if(QString(strList.at(x)).contains(ui->carCode->text()+"：",Qt::CaseInsensitive))
                {
                    str=strList.at(x);
                    QStringList strListOnlyOnece=str.split("：");
                    if(strListOnlyOnece.at(0)==ui->carCode->text())
                    {
                        strList=str.split("：");
                        ui->carChangeShow->setText(strList.at(1));
                        break;
                    }
                }
                if(x==strList.length()-1)
                {
                    ui->carChangeShow->setText("没有这个!");
                }
            }
        }

        ui->carChangeShow->show();
        ui->comboBox->move(ui->comboBox->x(),140);
        ui->changeCar->move(ui->changeCar->x(),140);
        ui->adPicture->move(ui->adPicture->x(),222);

    }
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    on_carCode_textChanged("");
    QString str=ui->carCode->text();
    if(str.contains("输入\"help"))
    {
        QStringList strList=str.split("所有");
        QString s1=strList.at(0)+"所有";
        strList=ui->comboBox->currentText().split("更改");
        ui->carCode->setText(s1+strList.at(1));
    }
}

void MainWindow::on_textBrowser_textChanged()
{
    autoScrollTextBrowser(ui->textBrowser);
}

void MainWindow::on_getTransparentFromSetting(const QString &str)
{
    QStringList strList=str.split(":");
    if(strList.at(0)=="输出")
    {
        ui->textBrowser->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(1)));
    }
    else if(strList.at(0)=="输入")
    {
        ui->carCode->setStyleSheet(QString("background:rgb(255,255,255,%1);"
                                           "font-size:18px;").arg(strList.at(1)));
    }
    else if(strList.at(0)=="按钮")
    {
        ui->changeCar->setStyleSheet(QString("background:rgb(25,255,255,%1);"
                                             "font-size:18px;").arg(strList.at(1)));
        ui->startGame->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(1)));
        ui->seamlessTurnOn->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(1)));
    }
    else if(strList.at(0)=="窗体")
    {
        this->setWindowOpacity(QString(strList.at(1)).toDouble()/100.0);
    }
}

void MainWindow::on_getReturnHasNewVersion(bool have,QStringList htmlList)
{
    if(have==true)
    {
        ui->textBrowser->insertPlainText("检测到有新版本\n");
        QMessageBox box(this);
        box.addButton("确定下载(推荐)",QMessageBox::YesRole);
        box.addButton("取消下载",QMessageBox::NoRole);
        box.setText("<p style='font-size:14px'>"
                    "检测到新版本启动器<br><br>"
                    "最新版本代号：V"+htmlList.at(1)+"<br>"
                    "当前版本代号：V"+QString::number(this->version)+"<br><br>"
                    +QString(htmlList.at(3)).replace("^^","<br>")+
                    "</p>");
        box.setIconPixmap(QPixmap("./picture/thanks.png"));
        int result=box.exec();
        if(result == 0)
        {
            if(myFile.isFileExist("游戏启动器V"+htmlList.at(1)+".exe",myFile.getArgvElements().at(0)))
            {
                myFile.deleteFile("游戏启动器V"+htmlList.at(1)+".exe",myFile.getArgvElements().at(0));
                myFile.sleep(1000);
            }
            Download *download=new Download("游戏启动器V"+htmlList.at(1)+".exe",
                                            myFile.getArgvElements().at(0),
                                            htmlList.at(2));
            connect(download,&Download::returnDownloadFinish,this,&MainWindow::on_DownloadFinish);
            download->on_pushButton_2_clicked();
            this->versionOnline=htmlList.at(1).toDouble();
            download->exec();
            delete download;
        }
    }
    else
    {
        if(htmlList.at(0)=="outline")
            ui->textBrowser->insertPlainText("未接入互联网！\n");
        else
            ui->textBrowser->insertPlainText("当前已是最新版本！\n");
    }
}

void MainWindow::on_DownloadFinish()
{
    //0为程序路径,1为程序名字,2为打开文件的路径,3为打开文件的名字
    if(myFile.openFile("游戏启动器V"+QString::number(versionOnline)+".exe", myFile.getArgvElements().at(0)))
    {
        settings->setValue("deleteName",myFile.getArgvElements().at(1));
        settings->setValue("deletePath",myFile.getArgvElements().at(0));
        exit(0);
    }
}

void MainWindow::on_startGame_clicked()
{
    if(ifHavePath==false)
        return ;

    if(settingCheckBox[2]==1 && ui->startGame->text()=="开始游戏")
    {
        DPI *dpi=new DPI(this,localHostPath);
        QMessageBox box(this);
        box.addButton("开始游戏", QMessageBox::AcceptRole);
        box.addButton("取消", QMessageBox::RejectRole);
        box.addButton("设置分辨率", QMessageBox::AcceptRole);
        box.setWindowTitle(thisWindowTitle);
        box.setText(QString("当前游戏分辨率为: %1\n"
                            "是否更改游戏分辨率?\n"
                            "PS:可在设置中取消此提示").arg(dpi->getDPI()));
        int boxReturn=box.exec();
        if(boxReturn == 0)
        {
            delete dpi;
        }
        else if(boxReturn==1)
        {
            delete dpi;
            return;
        }
        else
        {
            dpi->exec();
            delete dpi;
        }
    }

    if(ui->startGame->text()=="开始游戏")
    {
        ui->textBrowser->insertPlainText("\n游戏启动中");

        if(myFile.isExeRunning("AdBalloonExt.exe"))
        {
            myFile.killExe("AdBalloonExt.exe");
        }
        if(myFile.isFileExist("PPServer.lnk",localHostPath))
        {
            myFile.deleteFile("PPServer.lnk",localHostPath);
        }
        myFile.createLinkFile("PPServer",localHostPath,"PPServer.exe",localHostPath);

        if(!myFile.isExeRunning("KartRider.exe"))
        {
            if(myFile.openFile("KartRider.exe",localHostPath))
            {
                ui->textBrowser->insertPlainText("\n游戏已经启动\n");
                if(settingCheckBox[0])
                    miniShow();
            }
            else
            {
                ui->textBrowser->insertPlainText("\n游戏启动失败,请手动打开游戏\n");
            }
        }
        myFile.sleep(200);
        if(!myFile.isExeRunning("PPServer.exe"))
        {
            if(myFile.openFile("PPServer.lnk",localHostPath))
                myFile.deleteFile("PPServer.lnk",localHostPath);
        }
    }
    else
    {
        if(myFile.isExeRunning("KartRider.exe"))
        {
            myFile.killExe("KartRider.exe");
        }
        if(myFile.isExeRunning("PPServer.exe"))
        {
            myFile.killExe("PPServer.exe");
        }
        myFile.sleep(500);
        if(myFile.isExeRunning(("AdBalloonExt.exe")))
        {
            myFile.killExe("AdBalloonExt.exe");
        }
        ui->textBrowser->insertPlainText("\n游戏已关闭\n");
    }
}

void MainWindow::on_seamlessTurnOn_clicked()
{
    on_seamlessStart();
}

void MainWindow::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::Trigger:
        break;
    case QSystemTrayIcon::DoubleClick:
    {
        on_showMainAction();
        break;
    }
    default:
        break;
    }
}

void MainWindow::on_showMainAction()
{
    this->activateWindow();
    this->showNormal();
}

void MainWindow::on_exitAppAction()
{
    if(!myFile.isExeRunning("kartRider.exe"))
    {
        if(myFile.isExeRunning("PPServer.exe"))
        {
            myFile.killExe("PPServer.exe");
        }
    }

    this->~MainWindow();
    exit(0);
}

void MainWindow::on_timeOutChangePic()
{
    if(changeThisFlag<changePicShowNum-1)
    {
        changeThisFlag++;
    }
    else
    {
        changeThisFlag=0;
    }
    ui->adPicture->setPixmap(QPixmap(QString("./ad/%1.png").arg(choosePic[changeThisFlag])));
    changePicRadioBtn[changeThisFlag]->setChecked(true);
}

void MainWindow::on_timeOutStartTimer()
{
    QPoint pt=cursor().pos();
    int opsition=this->geometry().y()-this->y()+ui->menuBar->height();

    pt=QPoint(pt.x()-this->x(),pt.y()-this->y()-opsition);

    if(pt.x()>ui->adPicture->x() && pt.x()<ui->adPicture->x()+ui->adPicture->width())
    {
        if(pt.y()>ui->adPicture->y() && pt.y()<ui->adPicture->y()+ui->adPicture->height())
        {
            return;
        }
    }
    if(!changePicTimer.isActive())
    {
        changePicTimer.start(3000);
    }
}

void MainWindow::on_timeOutCheckGameIsOpen(QString str)
{
    ui->startGame->setText(str);
    if(str=="开始游戏")
    {
        if(seamlessOn==true)
            on_seamlessStart();//未检测到游戏，会自动关闭无缝

        if(settingCheckBox[3]==1)
        {
            QRect screen = QApplication::desktop()->screenGeometry();
            int screenWidth=screen.width();
//            this->move(width/2-this->width()/2,this->y());
            int widgetWidth=this->width();
            for(int x=this->x();x>=screenWidth/2-widgetWidth/2;x-=20){
                myFile.sleep(5);
                this->move(x,this->y());
            }
        }
    }
    else{
        if(settingCheckBox[3]==1)
        {
            QRect screen = QApplication::desktop()->screenGeometry();
            int screenWidth=screen.width();
            int widgetWidth=this->width();
            for(int x=this->x();x<=screenWidth-widgetWidth-80;x+=20){
                myFile.sleep(5);
                this->move(x,this->y());
            }
        }
    }
}


void MainWindow::on_seamlessTimeout()
{
    keybd_event(seamlessKey[1],MapVirtualKey(seamlessKey[1], 0),0,0);
    Sleep(10);
    keybd_event(seamlessKey[1],MapVirtualKey(seamlessKey[1], 0),KEYEVENTF_KEYUP,0);
}

void MainWindow::on_seamlessStart()
{
    if(!settings->contains("seamlessSetting"))
    {
        QMessageBox box(this);
        box.addButton("取消", QMessageBox::RejectRole);
        box.setWindowTitle(thisWindowTitle);
        box.setText("无缝设置不存在！请设置后再试\n");
        box.exec();
        on_seamlessSetting();
        return ;
    }
    if(myFile.isExeRunning("NexonPlug.exe")||myFile.isExeRunning("NexonPlay.exe"))
    {
        QMessageBox box(this);
        box.addButton("我确认开启无缝", QMessageBox::YesRole);
        box.addButton("取消操作(推荐)", QMessageBox::RejectRole);
        box.setWindowTitle("警告！");
        box.setText("警告！！！！！！！！！\n"
                    "检测到有韩服的游戏正在运行\n"
                    "韩服跑跑，使用无缝可能封号\n\n"
                    "你确定要打开无缝？");
        int res=box.exec();
        if(res!=0)
        {
            return ;
        }
    }
    if(!myFile.isExeRunning("KartRider.exe") && ui->seamlessTurnOn->text()=="打开无缝")
    {
        QMessageBox box(this);
        box.addButton("开启无缝", QMessageBox::YesRole);
        box.addButton("取消操作", QMessageBox::RejectRole);
        box.setWindowTitle(thisWindowTitle);
        box.setText("游戏尚未启动\n\n"
                    "你确定要打开无缝？");
        int res=box.exec();
        if(res!=0)
        {
            return ;
        }
    }

    if(seamlessOn==false)
    {
        seamlessTime=10;
        //seamlessTimer.start(seamlessTime);

        thisClass=this;

        connect(&timer,&QTimer::timeout,this,&MainWindow::timerou);
        timer.start(300);

        seamlessOn=true;
        mSysTrayIcon->showMessage(QObject::trUtf8("跑跑卡丁车"),
                                          QObject::trUtf8("无缝已打开\n"),
                                          QSystemTrayIcon::Information,
                                          100);
        ui->seamlessTurnOn->setText("关闭无缝");
    }
    else
    {
        seamlessTimer.stop();
        seamlessOn=false;
        timer.stop();
        unHook();
        mSysTrayIcon->showMessage(QObject::trUtf8("跑跑卡丁车"),
                                          QObject::trUtf8("无缝已关闭\n"),
                                          QSystemTrayIcon::Information,
                                          100);
        ui->seamlessTurnOn->setText("打开无缝");
    }
}

void MainWindow::timerou()
{
    unHook();
    setHook();
}

int MainWindow::getSeamlessKey()
{
    return this->seamlessKey[0];
}

void unHook()
{
    UnhookWindowsHookEx(keyHook);
}

void setHook()
{
    keyHook =SetWindowsHookEx( WH_KEYBOARD_LL,keyProc,GetModuleHandle(NULL),0);
}

LRESULT CALLBACK keyProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    //��WH_KEYBOARD_LLģʽ��lParam ��ָ��KBDLLHOOKSTRUCT���͵�ַ
    KBDLLHOOKSTRUCT *pkbhs = (KBDLLHOOKSTRUCT *) lParam;
    if(nCode == HC_ACTION)
    {
        if(seamlessLock==0)
        {
            if(thisClass->getSeamlessOn())
            {
                if(pkbhs->vkCode==thisClass->getSeamlessKey())
                {
                    if(wParam==WM_KEYDOWN)
                    {
                        thisClass->seamlessTimerStart();
                    }
                    else
                    {
                        thisClass->seamlessTimerStop();
                    }
                }
            }
            return 0;//����1��ʾ��ȡ��Ϣ���ٴ���,����0��ʾ��������,��Ϣ��������
        }
        if(seamlessLock==1)
        {
            seam->setKey(pkbhs->vkCode);
            seam->sure(seam->isSureBtnEnable());
            return 0;
        }
        return 0;
    }
    else
        return CallNextHookEx(keyHook, nCode, wParam, lParam);
}
