#include "download.h"
#include "ui_download.h"

Download::Download(QString fileName, QString path, QString url, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Download)
{
    ui->setupUi(this);

    settings = new QSettings(QSettings::NativeFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    QString pathPic=settings->value("picPath").toString();
    QImage imgBackgroud(pathPic);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),
                     QBrush(imgBackgroud.scaled(this->width(),this->height())));
    this->setPalette(palette);

    this->setStyleSheet("font-family:\"楷体\";"
                        "font-size:17px;"
                        "font-weight:100;");

    QString str = settings->value("settings").toString();
    if(!str.isEmpty())
    {
        QStringList strList=str.split(";");
        ui->lineEdit->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(4)));
        ui->pushButton_1->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->pushButton_2->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->pushButton_3->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        this->setWindowOpacity(QString(strList.at(6)).toDouble()/100.0);
        ui->progressBar->setStyleSheet("border:2px solid grey;border-radius:5px;text-align:center;");
    }

    if(path.isEmpty())
    {
        ui->lineEdit->setText(MyFile::pathDesktop());
        this->path=MyFile::pathDesktop();
    }
    else
    {
        ui->lineEdit->setText(path);
        this->path=path;
    }
    this->url=url;
    this->fileName=fileName;

    setWindowTitle("下载文件： "+fileName);
}

Download::~Download()
{
    delete ui;
    delete settings;
}

void Download::closeEvent(QCloseEvent *event)
{
    if(isDownloading==true)
    {
        QMessageBox box(this);
        box.addButton("确定",QMessageBox::YesRole);
        box.addButton("取消",QMessageBox::NoRole);
        box.setWindowTitle("确定退出？");
        box.setText("一旦退出，下载立即取消\n"
                    "退出后，下载数据会保留\n"
                    "下次下载时，会接着下载");
        int res=box.exec();
        if(res==0)
        {
            event->accept();
            myNetwork.stopDownload();
            return;
        }
        else
        {
            event->ignore();
            return;
        }
    }
    myNetwork.stopDownload();
    event->accept();
}

void Download::on_pushButton_1_clicked()
{
    QStringList path=myFile.selectDirectory();
    if(!path.isEmpty())
    {
        ui->lineEdit->setText(path.at(0));
        this->path=path.at(0);
    }
}

void Download::on_pushButton_2_clicked()
{
    if(ui->pushButton_2->text()=="下载")
    {
        connect(&myNetwork,&MyNetwork::returnDownloadProgressBarValue,ui->progressBar,&QProgressBar::setValue);
        connect(&myNetwork,&MyNetwork::returnDownloadStatute,ui->label_1,&QLabel::setText);
        connect(&myNetwork,&MyNetwork::returnDownloadSpeedAndTime,ui->label_2,&QLabel::setText);
        connect(&myNetwork,&MyNetwork::returnDownloadFinish,this,&Download::on_DownloadFinish);
        myNetwork.download(fileName,path,url);
        ui->lineEdit->setEnabled(false);
        ui->pushButton_1->setEnabled(false);
        ui->pushButton_2->setText("暂停");
        isDownloading=true;
    }
    else
    {
        ui->pushButton_2->setText("下载");
        myNetwork.stopDownload();
        disconnect(&myNetwork,&MyNetwork::returnDownloadProgressBarValue,ui->progressBar,&QProgressBar::setValue);
        disconnect(&myNetwork,&MyNetwork::returnDownloadStatute,ui->label_1,&QLabel::setText);
        disconnect(&myNetwork,&MyNetwork::returnDownloadSpeedAndTime,ui->label_2,&QLabel::setText);
        disconnect(&myNetwork,&MyNetwork::returnDownloadFinish,this,&Download::on_DownloadFinish);
        isDownloading=false;
    }
}

void Download::on_pushButton_3_clicked()
{
    this->close();
}

void Download::on_DownloadFinish()
{
    ui->lineEdit->setEnabled(true);
    ui->pushButton_1->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    isDownloading=false;
    emit returnDownloadFinish();
}
