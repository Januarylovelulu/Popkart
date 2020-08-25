#include "chatroom.h"
#include "ui_chatroom.h"

ChatRoom::ChatRoom(QWidget *parent, QTcpSocket *client) :
    QDialog(parent),
    ui(new Ui::ChatRoom)
{
    ui->setupUi(this);

    //设置窗口标题
    this->setWindowTitle("聊天室");
    this->client=client;

    settings = new QSettings(QSettings::NativeFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    QString pathPic=settings->value("picPath").toString();
    QImage imgBackgroud(pathPic);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),
                     QBrush(imgBackgroud.scaled(this->width(),this->height())));
    this->setPalette(palette);

    QString str = settings->value("settings").toString();
    if(!str.isEmpty())
    {
        QStringList strList=str.split(";");
        ui->textBrowser->setStyleSheet(QString("background:rgb(255,255,255,%1);font-size:16px;").arg(strList.at(3)));
        ui->label_totalPeople->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(3)));
        ui->textEdit->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(4)));
        ui->lineEdit_name->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(4)));
        ui->pushButton_send->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        ui->pushButton_close->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
    }

    if(settings->contains("ClientName")){
        QString name = settings->value("ClientName").toString();
        ui->lineEdit_name->setText(name);
    }

    ui->textEdit->setFocusPolicy(Qt::StrongFocus);
    ui->textEdit->setFocus();
    ui->textEdit->installEventFilter(this);//设置完后自动调用其eventFilter函数

    ui->textBrowser->setOpenLinks(false);
    connect(ui->textBrowser,SIGNAL(anchorClicked(const QUrl&)),this, SLOT(on_openUrl(const QUrl&)));

    connect(&timerWait,&QTimer::timeout,this,&ChatRoom::on_timeroutWait);
}

ChatRoom::~ChatRoom()
{
    delete settings;
    delete ui;
}

void ChatRoom::on_getMsg(QByteArray msg)
{
    static QByteArray msgStaticByteArray;
    msgStaticByteArray += msg;
    QTextCodec *codec = QTextCodec::codecForName("GB18030");
    QString msgStatic = codec->toUnicode(msgStaticByteArray);
    if(msgStatic.endsWith("&**&")) {
        // 分割多条命令
        QStringList msgStrList = msgStatic.split("&**&");
        // 执行每条命令
        for(QString msgStr : msgStrList) {
            QStringList msgList = msgStr.split("&*&");
            if(msgList.at(0)=="number"){
                ui->label_totalPeople->setText("在线人数："+msgList.at(1));
            }


            if(msgList.at(0)=="all"){
                ui->textBrowser->setHtml(msgList.at(1));
                ui->label_totalPeople->setText("在线人数："+msgList.at(2));
                ui->textBrowser->moveCursor(QTextCursor::End);
            }
            else if(msgList.at(0)=="new" || msgList.at(0)=="system"){
                ui->textBrowser->moveCursor(QTextCursor::End);
                ui->textBrowser->insertHtml(msgList.at(1));
                ui->textBrowser->moveCursor(QTextCursor::End);
            }

        }
        msgStaticByteArray.clear();
    }
}

void ChatRoom::on_pushButton_send_clicked()
{
    if(ui->lineEdit_name->text().isEmpty()){
        QMessageBox box(this);
        box.setText("请在右边输入昵称");
        box.setWindowTitle("提示");
        box.addButton("确定",QMessageBox::YesRole);
        box.exec();
        ui->lineEdit_name->setFocus();
        return;
    }
    else if(ui->lineEdit_name->text().contains(" ")){
        QMessageBox box(this);
        box.setText("昵称不允许包含空格！\n请重新输入");
        box.setWindowTitle("提示");
        box.addButton("确定",QMessageBox::YesRole);
        box.exec();
        ui->lineEdit_name->clear();
        ui->lineEdit_name->setFocus();
        return;
    }

    if(ui->textEdit->toPlainText().isEmpty())
        return;

    QString msg;
    if(ui->textEdit->toPlainText().split("^&^").length()==2 && ui->textEdit->toPlainText().split("^&^").at(0)=="command"){
        msg = ui->textEdit->toPlainText().split("^&^").at(1);
    }
    else{
        msg = "new&*&";
        msg += ui->textEdit->toPlainText()+"&*&";
        msg += "<b style='color:blue'>";
        msg += ui->lineEdit_name->text();
        msg += "</b>";
    }
    settings->setValue("ClientName",ui->lineEdit_name->text());

    write(msg,this->client);
    ui->pushButton_send->setEnabled(false);
    timerWait.start(2000);
    ui->textEdit->clear();
}

void ChatRoom::on_pushButton_close_clicked()
{
    this->close();
}

void ChatRoom::on_timeroutWait()
{
    ui->pushButton_send->setEnabled(true);
}

void ChatRoom::on_openUrl(const QUrl &url)
{
    QDesktopServices::openUrl(url);
}

bool ChatRoom::eventFilter(QObject *target, QEvent *event)
{
    if(target == ui->textEdit)
    {
        if(event->type() == QEvent::KeyPress)//回车键
        {
             QKeyEvent *e = static_cast<QKeyEvent *>(event);
             if(e->key() == Qt::Key_Return || e->key() == Qt::Key_Enter)
             {
                 if(e->modifiers() == Qt::ControlModifier){
                     ui->textEdit->insertPlainText("\n");
                 }
                 else if(ui->textEdit->hasFocus() || ui->pushButton_send->hasFocus()){
                     on_pushButton_send_clicked();
                 }
                 return true;
             }
        }
    }
    return QWidget::eventFilter(target,event);
}

void ChatRoom::write(QString msg, QTcpSocket *socket)
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    socket->write(codec->fromUnicode(msg));
}
