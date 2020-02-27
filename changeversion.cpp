#include "changeversion.h"
#include "ui_changeversion.h"

#include <QDebug>

ChangeVersion::ChangeVersion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeVersion)
{
    ui->setupUi(this);

    this->setWindowTitle("切换版本");
    this->setMaximumSize(this->width(),this->height());
    this->setMinimumSize(this->width(),this->height());

    settings = new QSettings(QSettings::NativeFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    QString pathPic=settings->value("picPath").toString();
    QImage imgBackgroud(pathPic);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),
                     QBrush(imgBackgroud.scaled(this->width(),this->height())));
    this->setPalette(palette);

    this->setStyleSheet("font-family:\"楷体\";"
                        "font-size:18px;"
                        "font-weight:100;");

    ui->lineEdit_1->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
    ui->lineEdit_3->setEnabled(false);
    ui->lineEdit_4->setEnabled(false);
    ui->lineEdit_5->setEnabled(false);
    ui->lineEdit_6->setEnabled(false);
    ui->pushButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    ui->pushButton_10->setEnabled(true);
    ui->pushButton_11->setEnabled(true);
    ui->pushButton_12->setEnabled(true);

    QString str = settings->value("settings").toString();
    if(!str.isEmpty())
    {
        QStringList strList=str.split(";");
        ui->lineEdit_1->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(4)));
        ui->lineEdit_2->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(4)));
        ui->lineEdit_3->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(4)));
        ui->lineEdit_4->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(4)));
        ui->lineEdit_5->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(4)));
        ui->lineEdit_6->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(4)));
        ui->pushButton_1->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->pushButton_2->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->pushButton_3->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->pushButton_4->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->pushButton_5->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->pushButton_6->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->pushButton_7->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->pushButton_8->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->pushButton_9->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->pushButton_10->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->pushButton_11->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->pushButton_12->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->pushButton_close->setStyleSheet(QString("background:rgb(255,100,100,%1);").arg(strList.at(5)));
        ui->pushButton_selectPath->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        this->setWindowOpacity(QString(strList.at(6)).toDouble()/100.0);
    }

    //读取popCarPath
    if(settings->contains("popCarPath"))
    {
        QString path=settings->value("popCarPath").toString();
        int version=checkPath(path);
        switch (version) {
        case 1:ui->lineEdit_1->setText(path);settings->setValue("Path2.0",path);break;
        case 2:ui->lineEdit_2->setText(path);settings->setValue("Path2.1",path);break;
        case 3:ui->lineEdit_3->setText(path);settings->setValue("Path3.0",path);break;
        case 4:ui->lineEdit_4->setText(path);settings->setValue("PathPSM",path);break;
        case 5:ui->lineEdit_5->setText(path);settings->setValue("PathYouHua",path);break;
        case 6:ui->lineEdit_6->setText(path);settings->setValue("PathJinHua",path);break;
        default:;
        }
    }

    //读取各个版本的路径注册表
    for(int x=0;x<6;x++)
        isHaveGame[x]=false;
    isHaveGame[6]=true;

    if(settings->contains("path2.0"))
    {
        QString path=settings->value("path2.0").toString();
        if(checkPath(path)==1)
        {
            ui->lineEdit_1->setText(path);
            ui->pushButton_1->setEnabled(true);
            ui->pushButton_7->setEnabled(false);
            isHaveGame[checkPath(path)-1]=true;
        }
        else
            settings->remove("path2.0");
    }
    if(settings->contains("path2.1"))
    {
        QString path=settings->value("path2.1").toString();
        if(checkPath(path)==2)
        {
            ui->lineEdit_2->setText(path);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_8->setEnabled(false);
            isHaveGame[checkPath(path)-1]=true;
        }
        else
            settings->remove("path2.1");
    }
    if(settings->contains("path3.0"))
    {
        QString path=settings->value("path3.0").toString();
        if(checkPath(path)==3)
        {
            ui->lineEdit_3->setText(path);
            ui->pushButton_3->setEnabled(true);
            ui->pushButton_9->setEnabled(false);
            isHaveGame[checkPath(path)-1]=true;
        }
        else
            settings->remove("path3.0");
    }
    if(settings->contains("pathPSM"))
    {
        QString path=settings->value("pathPSM").toString();
        if(checkPath(path)==4)
        {
            ui->lineEdit_4->setText(path);
            ui->pushButton_4->setEnabled(true);
            ui->pushButton_10->setEnabled(false);
            isHaveGame[checkPath(path)-1]=true;
        }
        else
            settings->remove("pathPSM");
    }
    if(settings->contains("pathYouHua"))
    {
        QString path=settings->value("pathYouHua").toString();
        if(checkPath(path)==5)
        {
            ui->lineEdit_5->setText(path);
            ui->pushButton_5->setEnabled(true);
            ui->pushButton_11->setEnabled(false);
            isHaveGame[checkPath(path)-1]=true;
        }
        else
            settings->remove("pathYouHua");
    }
    if(settings->contains("pathJinHua"))
    {
        QString path=settings->value("pathJinHua").toString();
        if(checkPath(path)==6)
        {
            ui->lineEdit_6->setText(path);
            ui->pushButton_6->setEnabled(true);
            ui->pushButton_12->setEnabled(false);
            isHaveGame[checkPath(path)-1]=true;
        }
        else
            settings->remove("pathJinHua");
    }
    for(int x=0;x<6;x++)
    {
        if(isHaveGame[x]==true)
            break;
        if(x==5)
        {
            isHaveGame[6]=false;
        }
    }
}

ChangeVersion::~ChangeVersion()
{
    delete ui;
    delete settings;
}

void ChangeVersion::paintEvent(QPaintEvent *event)
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

void ChangeVersion::mousePressEvent(QMouseEvent *event)
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

void ChangeVersion::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        //移动中的鼠标位置相对于初始位置的相对位置.
        QPoint relativePos = event->globalPos() - m_startPoint;
        //然后移动窗体即可.
        this->move(m_windowPoint + relativePos );
    }
}

void ChangeVersion::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        //改变移动状态.
        m_move = false;
    }
}

void ChangeVersion::on_pushButton_selectPath_clicked()
{
    QStringList str=myFile.selectDirectory();
    if(str.isEmpty())
        return;

    QString path=str.at(0);
    int version=checkPath(path);
    switch (version) {
    case 1:ui->lineEdit_1->setText(path);ui->pushButton_1->setEnabled(true);ui->pushButton_7->setEnabled(false);settings->setValue("Path2.0",path);break;
    case 2:ui->lineEdit_2->setText(path);ui->pushButton_2->setEnabled(true);ui->pushButton_8->setEnabled(false);settings->setValue("Path2.1",path);break;
    case 3:ui->lineEdit_3->setText(path);ui->pushButton_3->setEnabled(true);ui->pushButton_9->setEnabled(false);settings->setValue("Path3.0",path);break;
    case 4:ui->lineEdit_4->setText(path);ui->pushButton_4->setEnabled(true);ui->pushButton_10->setEnabled(false);settings->setValue("PathPSM",path);break;
    case 5:ui->lineEdit_5->setText(path);ui->pushButton_5->setEnabled(true);ui->pushButton_11->setEnabled(false);settings->setValue("PathYouHua",path);break;
    case 6:ui->lineEdit_6->setText(path);ui->pushButton_6->setEnabled(true);ui->pushButton_12->setEnabled(false);settings->setValue("PathJinHua",path);break;
    default:;
    }
    if(myFile.isFileExist("Qt5Widgets.dll",path))
    {
        QMessageBox box(this);
        box.addButton("确定",QMessageBox::YesRole);
        box.addButton("取消",QMessageBox::NoRole);
        box.setText("检测到旧版启动器，是否删除相关文件？");
        box.setInformativeText("删除文件不会影响游戏的正常运行");
        if(box.exec()==0)
        {
            myFile.deleteDirectory(path+"/ad");
            myFile.deleteDirectory(path+"/dat2.0");
            myFile.deleteDirectory(path+"/dat3.0");
            myFile.deleteDirectory(path+"/iconengines");
            myFile.deleteDirectory(path+"/imageformats");
            myFile.deleteDirectory(path+"/Log");
            myFile.deleteDirectory(path+"/platforms");
            myFile.deleteDirectory(path+"/styles");
            myFile.deleteDirectory(path+"/translations");
            myFile.deleteFile("first",path);
            myFile.deleteFile("D3Dcompiler_47.dll",path);
            myFile.deleteFile("libEGL.dll",path);
            myFile.deleteFile("libGLESV2.dll",path);
            myFile.deleteFile("opengl32sw.dll",path);
            myFile.deleteFile("Qt5Core.dll",path);
            myFile.deleteFile("Qt5Gui.dll",path);
            myFile.deleteFile("Qt5Svg.dll",path);
            myFile.deleteFile("Qt5Widgets.dll",path);
            myFile.deleteFile("多开检测.exe",path);
            myFile.deleteFile("使用说明.docx",path);
            if(path!=QApplication::applicationDirPath())
                myFile.deleteFile("游戏启动器.exe",path);
        }
    }
}

int ChangeVersion::checkPath(QString path)
{
    if(myFile.isFileExist("KartRider.exe",path))
    {
        return checkVersion(path);
    }
    else
    {
        return 0;
    }
}

int ChangeVersion::checkVersion(QString str)
{
    if(str.isEmpty())
    {
        return 0;
    }

    if(myFile.isFileExist("【跑友公社】优化版·超高速改装文件.exe",str)||myFile.isFileExist("优化版标志.txt",str))
    {
        return 5;
    }
    else if(myFile.isFileExist("mav.dat",str)||myFile.isFileExist("进化版标志.txt",str))
    {
        return 6;
    }
    else if(myFile.isFileExist("Uninstall.exe",str)||myFile.isFileExist("PSM版标志.txt",str))
    {
        return 4;
    }
    else if(myFile.isFileExist("KartRiderCN.ini",str)||myFile.isFileExist("2.1版标志.txt",str))
    {
        return 2;
    }
    else if(myFile.isFileExist("NanumGothicBold.ttf",str)||myFile.isFileExist("2.0版标志.txt",str))
    {
        return 1;
    }
    else
    {
        return 3;
    }
}

void ChangeVersion::on_pushButton_1_clicked()
{
    QString path=ui->lineEdit_1->text();
    if(checkPath(path)==1)
    {
        settings->setValue("popCarPath",path);
    }
    this->close();
}

void ChangeVersion::on_pushButton_2_clicked()
{
    QString path=ui->lineEdit_2->text();
    if(checkPath(path)==2)
    {
        settings->setValue("popCarPath",path);
    }
    this->close();
}

void ChangeVersion::on_pushButton_3_clicked()
{
    QString path=ui->lineEdit_3->text();
    if(checkPath(path)==3)
    {
        settings->setValue("popCarPath",path);
    }
    this->close();
}

void ChangeVersion::on_pushButton_4_clicked()
{
    QString path=ui->lineEdit_4->text();
    if(checkPath(path)==4)
    {
        settings->setValue("popCarPath",path);
    }
    this->close();
}

void ChangeVersion::on_pushButton_5_clicked()
{
    QString path=ui->lineEdit_5->text();
    if(checkPath(path)==5)
    {
        settings->setValue("popCarPath",path);
    }
    this->close();
}

void ChangeVersion::on_pushButton_6_clicked()
{
    QString path=ui->lineEdit_6->text();
    if(checkPath(path)==6)
    {
        settings->setValue("popCarPath",path);
    }
    this->close();
}

void ChangeVersion::on_pushButton_7_clicked()
{
    download(1);
}

void ChangeVersion::on_pushButton_8_clicked()
{
    download(2);
}

void ChangeVersion::on_pushButton_9_clicked()
{
    download(3);
}

void ChangeVersion::on_pushButton_10_clicked()
{
    download(4);
}

void ChangeVersion::on_pushButton_11_clicked()
{
    download(5);
}

void ChangeVersion::on_pushButton_12_clicked()
{
    download(6);
}

void ChangeVersion::setPushButton(bool on)
{
    if(on == true)
    {
        if(ui->lineEdit_1->text().isEmpty())
            ui->pushButton_7->setEnabled(on);
        if(ui->lineEdit_2->text().isEmpty())
            ui->pushButton_8->setEnabled(on);
        if(ui->lineEdit_3->text().isEmpty())
            ui->pushButton_9->setEnabled(on);
        if(ui->lineEdit_4->text().isEmpty())
            ui->pushButton_10->setEnabled(on);
        if(ui->lineEdit_5->text().isEmpty())
            ui->pushButton_11->setEnabled(on);
        if(ui->lineEdit_6->text().isEmpty())
            ui->pushButton_12->setEnabled(on);
    }
    else
    {
        ui->pushButton_7->setEnabled(on);
        ui->pushButton_8->setEnabled(on);
        ui->pushButton_9->setEnabled(on);
        ui->pushButton_10->setEnabled(on);
        ui->pushButton_11->setEnabled(on);
        ui->pushButton_12->setEnabled(on);
    }
}

void ChangeVersion::download(int cmd)
{
    setPushButton(false);
    myFile.sleep(50);
    QString html=myNetwork.getHtmlContent("https://januarylovelulu.github.io/index/index.html");
    setPushButton(true);
    if(html.isEmpty())
    {
        QMessageBox box(this);
        box.addButton("确定",QMessageBox::YesRole);
        box.setText("未获取到服务器请求\n"
                    "请确定已经连入互联网");
        box.exec();
        return;
    }
    html.replace("\t","");
    html.replace("\r","");
    QStringList htmlList=html.split("\n");

    htmlList=htmlList.at(cmd).split("：：");

    if(htmlList.length()>=5)
    {
        QMessageBox box(this);
        box.addButton("服务器下载",QMessageBox::YesRole);
        box.addButton("百度云(推荐)",QMessageBox::YesRole);
        box.addButton("取消",QMessageBox::NoRole);
        box.setWindowTitle("选择下载方式");
        box.setText("当前的版本可从服务器上下载\n"
                    "如果百度云限速，可以尝试服务器下载\n"
                    "从服务器下载的速度平均为700KB/s\n"
                    "服务器是作者花钱买的，速度慢请见谅");
        int res=box.exec();
        if(res==0)
        {
            QStringList afterNameList=htmlList.at(4).split(".");
            QString afterName=afterNameList.at(afterNameList.length()-1);
            Download *download_=new Download(htmlList.at(0)+"."+afterName,MyFile::pathDesktop(),htmlList.at(4));
            download_->exec();
            delete download_;
        }
        else if(res==1)
        {
            myFile.clipboardCopy(htmlList.at(3));
            QMessageBox box(this);
            box.addButton("确定",QMessageBox::YesRole);
            box.setText("提取码已经复制到\"剪切板\"\n"
                        "点击确定跳转到百度云盘");
            box.exec();
            myFile.openHtmlFile(htmlList.at(1));
        }
        else
        {

        }
    }
    else
    {
        myFile.clipboardCopy(htmlList.at(3));
        QMessageBox box(this);
        box.addButton("确定",QMessageBox::YesRole);
        box.addButton("取消",QMessageBox::NoRole);
        box.setText("提取码已经复制到\"剪切板\"\n"
                    "点击确定跳转到百度云盘");
        int res=box.exec();
        if(res==0)
            myFile.openHtmlFile(htmlList.at(1));
    }
}

void ChangeVersion::on_pushButton_close_clicked()
{
    this->close();
}
