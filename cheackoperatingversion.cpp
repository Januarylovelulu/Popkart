#include "cheackoperatingversion.h"
#include "ui_cheackoperatingversion.h"

#include <QDebug>

CheackOperatingVersion::CheackOperatingVersion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheackOperatingVersion)
{
    ui->setupUi(this);
    this->setWindowTitle("提示！");
    this->setStyleSheet("font-family:\"楷体\";"
                        "font-size:18px;"
                        "font-weight:200;");
    if(checkSystemVersion()=="Windows 10" || checkSystemVersion()=="Windows 8")
    {
        if(checkSystemVersion()=="Windows 10")
        {
            ui->label->setText("检测到在Windows 10 系统下运行,\n"
                               "须调整 KartRider.exe 的兼容性,\n"
                               "进化版本须安装朝鲜语语言包。\n"
                               "具体方法自行百度或查阅教程“运行前准备”\n"
                               "此页面只显示一次！");
        }
        else if(checkSystemVersion()=="Windows 8")
        {
            ui->label->setText("检测到在Windows 8 系统下运行,\n"
                               "须调整 KartRider.exe 的兼容性,\n"
                               "进化版本须安装朝鲜语语言包。\n"
                               "具体方法自行百度或查阅教程“运行前准备”\n"
                               "此页面只显示一次！");
        }
        ui->pushButton->setCheckable(false);
        ui->pushButton->setEnabled(false);
        ui->pushButton->setText("我知道了(8s)");
        connect(&timer,&QTimer::timeout,this,&CheackOperatingVersion::on_changeButtonText);
        timer.start(1000);
        this->exec();

    }
}

CheackOperatingVersion::~CheackOperatingVersion()
{
    delete ui;
}

QString CheackOperatingVersion::checkSystemVersion()
{
    QSysInfo sysInfo;
    QString str=sysInfo.kernelVersion();

    if(str.contains("10.0"))
        return "Windows 10";
    else if(str.contains("6.3")||str.contains("6.2"))
        return "Windows 8";
    else if(str.contains("6.1"))
        return "Windows 7";
    else if(str.contains("6.0"))
        return "Windows Vista";
    else
        return "Windows XP";
}

void CheackOperatingVersion::closeEvent(QCloseEvent *event)
{
    if(ui->pushButton->isCheckable()==false)
        event->ignore();
    else
        event->accept();
}

void CheackOperatingVersion::on_pushButton_clicked()
{
    this->~CheackOperatingVersion();
}

void CheackOperatingVersion::on_changeButtonText()
{
    static int x=7;
    if(x==0)
    {
        ui->pushButton->setText("我知道了");
        ui->pushButton->setCheckable(true);
        ui->pushButton->setEnabled(true);
    }
    else
    {
        ui->pushButton->setText(QString("我知道了(%1s)").arg(x));
        x--;
    }
}
