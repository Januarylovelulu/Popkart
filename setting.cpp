#include "setting.h"
#include "ui_setting.h"

#include <QDebug>

Setting::Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    this->setWindowTitle("设置修改");
    this->setMaximumSize(this->width(),this->height());
    this->setMinimumSize(this->width(),this->height());


    this->move(parent->x()-this->width(),parent->y()*1.1);
    if(this->x()<0)
        this->move(parent->x()+parent->width()-15,parent->y()*1.1);

    settings = new QSettings(QSettings::NativeFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    QString pathPic=settings->value("picPath").toString();
    QImage imgBackgroud(pathPic);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),
                     QBrush(imgBackgroud.scaled(this->width(),this->height())));
    this->setPalette(palette);

    ui->transparent_btn->setMaximum(255);
    ui->transparent_input->setMaximum(255);
    ui->transparent_output->setMaximum(255);
    ui->transparent_window->setMinimum(40);
    ui->transparent_window->setMaximum(100);

    QString str=settings->value("settings").toString();
    if(!str.isEmpty())
    {
        QStringList strList=str.split(";");
        if(strList.at(0)=="1")
            ui->checkBox->setChecked(true);
        else
            ui->checkBox->setChecked(false);

        if(strList.at(1)=="1")
            ui->checkBox_2->setChecked(true);
        else
            ui->checkBox_2->setChecked(false);
        if(strList.at(2)=="1")
            ui->checkBox_3->setChecked(true);
        else
            ui->checkBox_3->setChecked(false);
        if(strList.at(7)=="1")
            ui->checkBox_4->setChecked(true);
        else
            ui->checkBox_4->setChecked(false);
        if(strList.at(8)=="1")
            ui->checkBox_5->setChecked(true);
        else
            ui->checkBox_5->setChecked(false);

        ui->transparent_output->setValue(QString(strList.at(3)).toInt());
        ui->transparent_input->setValue(QString(strList.at(4)).toInt());
        ui->transparent_btn->setValue(QString(strList.at(5)).toInt());
        ui->transparent_window->setValue(QString(strList.at(6)).toInt());

        ui->label_output->setText(QString("输出框透明度：%1").arg(strList.at(3)));
        ui->label_input->setText(QString("输入框透明度：%1").arg(strList.at(4)));
        ui->label_btn->setText(QString("按钮的透明度：%1").arg(strList.at(5)));
        ui->label_window->setText(QString("程序的透明度：%1").arg(QString(strList.at(6))));

        ui->sure->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->back->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        this->setWindowOpacity(QString(strList.at(6)).toDouble()/100.0);

        parent->setWindowOpacity(QString(strList.at(6)).toDouble()/100.0);
    }
}

Setting::~Setting()
{
    delete ui;
    delete settings;
}

void Setting::on_back_clicked()
{
    this->close();
}

void Setting::on_sure_clicked()
{
    QString str;
    if(ui->checkBox->isChecked()==true)
        str+="1;";
    else
        str+="0;";

    if(ui->checkBox_2->isChecked()==true)
        str+="1;";
    else
        str+="0;";
    if(ui->checkBox_3->isChecked()==true)
        str+="1;";
    else
        str+="0;";

    str+=QString::number(ui->transparent_output->value())+";";
    str+=QString::number(ui->transparent_input->value())+";";
    str+=QString::number(ui->transparent_btn->value())+";";
    str+=QString::number(ui->transparent_window->value())+";";

    if(ui->checkBox_4->isChecked()==true)
        str+="1;";
    else
        str+="0;";
    if(ui->checkBox_5->isChecked()==true)
        str+="1";
    else
        str+="0";

    settings->setValue("settings",str);
    this->close();
}

void Setting::on_transparent_output_valueChanged(int position)
{
    ui->label_output->setText(QString("输出框透明度：%1").arg(position));
    emit transparent(QString("输出:%1").arg(position));
}

void Setting::on_transparent_input_valueChanged(int position)
{
    ui->label_input->setText(QString("输入框透明度：%1").arg(position));
    emit transparent(QString("输入:%1").arg(position));
}

void Setting::on_transparent_btn_valueChanged(int position)
{
    ui->label_btn->setText(QString("按钮的透明度：%1").arg(position));
    emit transparent(QString("按钮:%1").arg(position));

    ui->sure->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(position));
    ui->back->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(position));
}

void Setting::on_transparent_window_valueChanged(int position)
{
    ui->label_window->setText(QString("程序的透明度：%1").arg(position));
    this->setWindowOpacity((double)(position)/100.0);
    emit transparent(QString("窗体:%1").arg(position));
}
