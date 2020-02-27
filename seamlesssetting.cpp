#include "seamlesssetting.h"
#include "ui_seamlesssetting.h"

#include <QDebug>
#include <Windows.h>

SeamlessSetting::SeamlessSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SeamlessSetting)
{
    ui->setupUi(this);

    this->setWindowTitle("无缝设置");
    this->setMaximumSize(this->width(),this->height());
    this->setMinimumSize(this->width(),this->height());

    ui->sure->setEnabled(false);

    settings = new QSettings(QSettings::NativeFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    QString pathPic=settings->value("picPath").toString();
    QImage imgBackgroud(pathPic);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),
                     QBrush(imgBackgroud.scaled(this->width(),this->height())));
    this->setPalette(palette);

    ui->lineEdit->setStyleSheet("background:rbg(255,255,255,40);");
    ui->lineEdit_2->setStyleSheet("background:rbg(255,255,255,40);");

    QString str=settings->value("settings").toString();
    if(!str.isEmpty())
    {
        QStringList strList=str.split(";");
        ui->lineEdit->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(4)));
        ui->lineEdit_2->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(4)));
        ui->sure->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->back->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        this->setWindowOpacity(QString(strList.at(6)).toDouble()/100.0);
    }

    if(settings->contains("seamlessSetting"))
    {
        QString read=settings->value("seamlessSetting").toString();
        QStringList strList=read.split(";");
        seamlessKey[0]=QString(strList.at(0)).toInt();
        seamlessKey[1]=QString(strList.at(1)).toInt();
        ui->sure->setEnabled(true);
    }
    else
    {
        seamlessKey[0]=-1;
        seamlessKey[1]=-1;
    }

    if(seamlessKey[1]!=-1)
    {
        ui->lineEdit_2->setText(translateKey(seamlessKey[1]));
    }
    else
    {
        ui->lineEdit->setFocus();
    }
    if(seamlessKey[0]!=-1)
    {
        ui->lineEdit->setText(translateKey(seamlessKey[0]));
    }
    else
    {
        ui->lineEdit->setFocus();
    }
}

SeamlessSetting::~SeamlessSetting()
{
    delete ui;
    delete settings;
}
void SeamlessSetting::setKey(int key)
{
    if(ui->lineEdit->hasFocus())
    {
        ui->lineEdit->setEnabled(false);
        ui->lineEdit->setText(translateKey(key));
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_2->clearFocus();
        seamlessKey[0]=key;
//        ui->lineEdit_2->setFocus();
    }
    else if(ui->lineEdit_2->hasFocus())
    {
        ui->lineEdit_2->setEnabled(false);
        ui->lineEdit_2->setText(translateKey(key));
        ui->lineEdit_2->setEnabled(true);
        seamlessKey[1]=key;
//        ui->lineEdit_2->clearFocus();
    }
}

void SeamlessSetting::sure(bool b)
{
    ui->sure->setEnabled(b);
}

QString SeamlessSetting::translateKey(int key)
{
    if(key>=48&&key<=57)
        return QString::number(key-48);
    if(key>=96&&key<=105)
        return "Num:"+QString::number(key-96);
    if(key>=65&&key<=90)
    {
        QString list="abcdefghijklmnopqrstuvwxyz";
        return list.at(key-65);
    }
    switch(key)
    {
    case 8:return "BackSpace";
    case 9:return "TAB";
//    case 13:return "Enter(Right)";
    case 20:return "Caps Lock";
    case 32:return "Space";
    case 37:return "←";
    case 38:return "↑";
    case 39:return "→";
    case 40:return "↓";
    case 160:return "Shift(Left)";
    case 161:return "Shift(Right)";
    case 162:return "Ctrl(Left)";
    case 163:return "Ctrl(Right)";
    case 164:return "Alt(Left)";
    case 165:return "Alt(Right)";
    default:return "";
    }
}

bool SeamlessSetting::isSureBtnEnable()
{
    if(seamlessKey[0]!=-1&&seamlessKey[1]!=-1)
    {
        if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty())
            return false;
        else
            return true;
    }
    return false;
}

void SeamlessSetting::on_sure_clicked()
{
    settings->setValue("seamlessSetting",QString::number(seamlessKey[0])+";"+QString::number(seamlessKey[1]));
    this->close();
}

void SeamlessSetting::on_back_clicked()
{
    this->close();
}
