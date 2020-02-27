#include "dpi.h"
#include "ui_dpi.h"

#include <QDebug>

DPI::DPI(QWidget *parent, QString path) :
    QDialog(parent),
    ui(new Ui::DPI)
{
    ui->setupUi(this);

    this->setWindowTitle("分辨率设置");
    this->setMaximumSize(this->width(),this->height());
    this->setMinimumSize(this->width(),this->height());

    settings = new QSettings(QSettings::NativeFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    QString pathPic=settings->value("picPath").toString();
    QImage imgBackgroud(pathPic);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),
                     QBrush(imgBackgroud.scaled(this->width(),this->height())));
    this->setPalette(palette);

    QString str=settings->value("settings").toString();
    if(!str.isEmpty())
    {
        QStringList strList=str.split(";");
        ui->lineEdit_width->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(4)));
        ui->lineEdit_height->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(4)));
        ui->sure->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->back->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        this->setWindowOpacity(QString(strList.at(6)).toDouble()/100.0);
    }
//    ui->label_2->setStyleSheet("background:rbg(255,255,255,0);");

    localHostPath=path;

    ui->radioButton->setChecked(true);

    QString read=myFile.readTextFile("PPConfig.ini",path);
    QStringList strList=read.split("\n");
    for(int x=0;x<strList.length();x++)
    {
        if(QString(strList.at(x)).contains("width=",Qt::CaseInsensitive))
        {
            QStringList str=QString(strList.at(x)).split("=");
            gameWidth=str.at(1);
        }
        else if(QString(strList.at(x)).contains("height=",Qt::CaseInsensitive))
        {
            QStringList str=QString(strList.at(x)).split("=");
            gameHeight+=str.at(1);
        }
    }

    QRect screen = QApplication::desktop()->screenGeometry();
    screenWidth=screen.width();
    screenHeight=screen.height();
    if(screenWidth<1400)
    {
        if(settings->contains("DPI"))
        {
            QString read=settings->value("DPI").toString();
            if(read!=QString(gameWidth+"×"+gameHeight))
            {
                gameWidth="800";
                gameHeight="600";
                setDPI(800,600);
            }
        }
        else
        {
            settings->setValue("DPI","800×600");
            gameWidth="800";
            gameHeight="600";
            setDPI(800,600);
        }
    }

    ui->label->setText("当前游戏分辨率: "+gameWidth+"×"+gameHeight);
    ui->label->setStyleSheet("font-size:21px;");

    ui->comboBox->setEnabled(true);
    ui->lineEdit_width->setEnabled(false);
    ui->lineEdit_height->setEnabled(false);

    QRegExp regExp("^[0-9]+$");
    ui->lineEdit_width->setValidator(new QRegExpValidator(regExp,this));
    ui->lineEdit_height->setValidator(new QRegExpValidator(regExp,this));
    ui->lineEdit_width->setMaxLength(4);
    ui->lineEdit_height->setMaxLength(4);
    ui->lineEdit_width->setText(gameWidth);
    ui->lineEdit_height->setText(gameHeight);
}

QString DPI::getDPI()
{
    return gameWidth+"×"+gameHeight;
}

void DPI::setDPI(int width, int height)
{
    QString read=myFile.readTextFile("PPConfig.ini",localHostPath);
    QStringList strList=read.split("\n");
    read="";
    for(int x=0;x<strList.length();x++)
    {
        if(QString(strList.at(x)).contains("width=",Qt::CaseInsensitive))
        {
            read+="Width="+QString::number(width)+"\n";
            continue;
        }
        if(QString(strList.at(x)).contains("height=",Qt::CaseInsensitive))
        {
            read+="Height="+QString::number(height)+"\n";
            continue;
        }
        if(x==strList.length()-1)
            read+=strList.at(x);
        else
            read+=strList.at(x)+"\n";
    }
    myFile.writeTextFile(read,"PPConfig.ini",localHostPath);
}

DPI::~DPI()
{
    delete ui;
    delete settings;
}

void DPI::on_sure_clicked()
{
    if(ui->radioButton->isChecked())
    {
        QString combobox=ui->comboBox->currentText();
        QStringList comboboxList=combobox.split("×");
        gameWidth=QString(comboboxList.at(0));
        gameHeight=QString(comboboxList.at(1));
    }
    else
    {
        gameWidth=ui->lineEdit_width->text();
        gameHeight=ui->lineEdit_height->text();
    }
    setDPI(gameWidth.toInt(),gameHeight.toInt());

    if(screenWidth<1400)
        settings->setValue("DPI",gameWidth+"×"+gameHeight);

    this->close();
}

void DPI::on_back_clicked()
{
    this->close();
}

void DPI::on_radioButton_clicked()
{
    ui->comboBox->setEnabled(true);
    ui->lineEdit_width->setEnabled(false);
    ui->lineEdit_height->setEnabled(false);
}

void DPI::on_radioButton_2_clicked()
{
    ui->lineEdit_width->setEnabled(true);
    ui->lineEdit_height->setEnabled(true);
    ui->comboBox->setEnabled(false);
}

void DPI::on_lineEdit_width_textEdited(const QString &arg1)
{
    ui->lineEdit_height->setText(QString::number(arg1.toInt()/4*3));
    if(arg1.isEmpty())
        ui->lineEdit_height->clear();
}

void DPI::on_lineEdit_height_textEdited(const QString &arg1)
{
    ui->lineEdit_width->setText(QString::number(arg1.toInt()/3*4));
    if(arg1.isEmpty())
        ui->lineEdit_width->clear();
}
