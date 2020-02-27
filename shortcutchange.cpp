#include "shortcutchange.h"
#include "ui_shortcutchange.h"

#include <QDebug>

ShortcutChange::ShortcutChange(QWidget *parent, QString show, QString hide, QString seamless) :
    QDialog(parent),
    ui(new Ui::ShortcutChange)
{
    ui->setupUi(this);
    this->setWindowTitle("快捷键设置");
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

    ui->notice_hide->setStyleSheet("color:red");
    ui->notice_show->setStyleSheet("color:red");
    ui->notice_seamless->setStyleSheet("color:red");
    ui->notice_hide->hide();
    ui->notice_show->hide();
    ui->notice_seamless->hide();

    ui->hideInput->setMaxLength(1);
    ui->showInput->setMaxLength(1);
    ui->seamlessInput->setMaxLength(1);

    QRegExp regExp("^[A-Za-z0-9]+$");
    ui->hideInput->setValidator(new QRegExpValidator(regExp,this));
    ui->showInput->setValidator(new QRegExpValidator(regExp,this));
    ui->seamlessInput->setValidator(new QRegExpValidator(regExp,this));

    ui->sure->setEnabled(false);

    ifShortcutShowTrue=false;
    ifShortcutHideTrue=false;
    ifShortcutSeamlessTrue=false;

    connect(&show1,&QTimer::timeout,this,&ShortcutChange::on_timeoutShow);
    connect(&hide1,&QTimer::timeout,this,&ShortcutChange::on_timeoutHide);
    connect(&seamless1,&QTimer::timeout,this,&ShortcutChange::on_timeoutSeamless);

    ui->hideInput->setFocus();

    QString str = settings->value("settings").toString();
    if(!str.isEmpty())
    {
        QStringList strList=str.split(";");
        ui->hideInput->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(4)));
        ui->showInput->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(4)));
        ui->seamlessInput->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(4)));
        ui->sure->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->back->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        this->setWindowOpacity(QString(strList.at(6)).toDouble()/100.0);
    }
    ui->showInput->setText(show);
    ui->hideInput->setText(hide);
    ui->seamlessInput->setText(seamless);
}

ShortcutChange::~ShortcutChange()
{
    delete ui;
    delete settings;
}

void ShortcutChange::on_hideInput_textChanged(const QString &arg1)
{
    ui->sure->setEnabled(false);
    if(arg1.isEmpty())
    {
        ifShortcutHideTrue=false;
        return;
    }
    if(arg1.toUpper()==ui->showInput->text().toUpper())
    {
        ui->notice_hide->setText("快捷键已被占用");
        ui->notice_hide->show();
        hide1.start(5000);
        ui->hideInput->clear();
        ifShortcutHideTrue=false;
        return;
    }
    else if(arg1.toUpper()==ui->seamlessInput->text().toUpper())
    {
        ui->notice_hide->setText("快捷键已被占用ͬ");
        ui->notice_hide->show();
        hide1.start(5000);
        ui->hideInput->clear();
        ifShortcutHideTrue=false;
        return;
    }
    QxtGlobalShortcut *qxtGlobalShortcut;
    qxtGlobalShortcut=new QxtGlobalShortcut(QKeySequence(QString("Alt+%1").arg(arg1.toUpper())));
    if(qxtGlobalShortcut->isShortcutSuccessful())
    {
        ifShortcutHideTrue=true;
        ui->notice_hide->hide();
        if(ifShortcutShowTrue==true)
        {
            if(ifShortcutSeamlessTrue==true)
            {
                ui->sure->setEnabled(true);
                ui->notice_hide->hide();
                ui->sure->setFocus();
            }
            else
            {
                ui->seamlessInput->setFocus();
            }
        }
        else
        {
            ui->showInput->setFocus();
        }
    }
    else
    {
        ui->notice_hide->show();
        hide1.start(5000);
        ui->notice_hide->setText(QString("快捷键\"Alt+%1\"已被占用!").arg(arg1));
        ui->hideInput->clear();
        ifShortcutHideTrue=false;
    }
    delete qxtGlobalShortcut;
}

void ShortcutChange::on_showInput_textChanged(const QString &arg1)
{
    ui->sure->setEnabled(false);
    if(arg1.isEmpty())
    {
        ifShortcutShowTrue=false;
        return;
    }
    if(arg1.toUpper()==ui->hideInput->text().toUpper())
    {
        ui->notice_show->setText("快捷键已被占用");
        ui->notice_show->show();
        show1.start(5000);
        ui->showInput->clear();
        ifShortcutShowTrue=false;
        return;
    }
    else if(arg1.toUpper()==ui->seamlessInput->text().toUpper())
    {
        ui->notice_show->setText("快捷键已被占用");
        ui->notice_show->show();
        show1.start(5000);
        ui->showInput->clear();
        ifShortcutShowTrue=false;
        return;
    }
    QxtGlobalShortcut *qxtGlobalShortcut;
    qxtGlobalShortcut=new QxtGlobalShortcut(QKeySequence(QString("Alt+%1").arg(arg1.toUpper())));
    if(qxtGlobalShortcut->isShortcutSuccessful())
    {
        ifShortcutShowTrue=true;
        ui->notice_show->hide();
        if(ifShortcutHideTrue==true)
        {
            if(ifShortcutSeamlessTrue==true)
            {
                ui->sure->setEnabled(true);
                ui->notice_show->hide();
                ui->sure->setFocus();
            }
            else
            {
                ui->seamlessInput->setFocus();
            }
        }
        else
        {
            ui->hideInput->setFocus();
        }
    }
    else
    {
        ui->notice_show->show();
        show1.start(5000);
        ui->notice_show->setText(QString("快捷键\"Alt+%1\"已被占用!").arg(arg1));
        ui->showInput->clear();
        ifShortcutShowTrue=false;
    }
    delete qxtGlobalShortcut;
}

void ShortcutChange::on_seamlessInput_textChanged(const QString &arg1)
{
    ui->sure->setEnabled(false);
    if(arg1.isEmpty())
    {
        ifShortcutSeamlessTrue=false;
        return;
    }
    if(arg1.toUpper()==ui->showInput->text().toUpper())
    {
        ui->notice_seamless->setText("快捷键已被占用");
        ui->notice_seamless->show();
        seamless1.start(5000);
        ui->seamlessInput->clear();
        ifShortcutSeamlessTrue=false;
        return;
    }
    else if(arg1.toUpper()==ui->hideInput->text().toUpper())
    {
        ui->notice_seamless->setText("快捷键已被占用");
        ui->notice_seamless->show();
        seamless1.start(5000);
        ui->seamlessInput->clear();
        ifShortcutSeamlessTrue=false;
        return;
    }
    QxtGlobalShortcut *qxtGlobalShortcut;
    qxtGlobalShortcut=new QxtGlobalShortcut(QKeySequence(QString("Alt+%1").arg(arg1.toUpper())));
    if(qxtGlobalShortcut->isShortcutSuccessful())
    {
        ifShortcutSeamlessTrue=true;
        ui->notice_seamless->hide();
        if(ifShortcutShowTrue==true)
        {
            if(ifShortcutHideTrue==true)
            {
                ui->sure->setEnabled(true);
                ui->notice_seamless->hide();
                ui->sure->setFocus();
            }
            else
            {
                ui->hideInput->setFocus();
            }
        }
        else
        {
            ui->showInput->setFocus();
        }
    }
    else
    {
        ui->notice_seamless->show();
        seamless1.start(5000);
        ui->notice_seamless->setText(QString("快捷键\"Alt+%1\"已被占用!").arg(arg1));
        ui->seamlessInput->clear();
        ifShortcutSeamlessTrue=false;
    }
    delete qxtGlobalShortcut;
}

void ShortcutChange::on_shortcut(const bool &boolen)
{
    ifShortcutTrue=boolen;
}

void ShortcutChange::on_sure_clicked()
{
    settings->setValue("shortcut",ui->hideInput->text().toUpper()+";"+
                       ui->showInput->text().toUpper()+";"+
                       ui->seamlessInput->text().toUpper());
    this->close();
}

void ShortcutChange::on_timeoutShow()
{
    ui->notice_show->hide();
}

void ShortcutChange::on_timeoutHide()
{
    ui->notice_hide->hide();
}

void ShortcutChange::on_timeoutSeamless()
{
    ui->notice_seamless->hide();
}

void ShortcutChange::on_back_clicked()
{
    this->close();
}
