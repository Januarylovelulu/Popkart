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

    if(settings->contains("ClientName")){
        QString name = settings->value("ClientName").toString();
        ui->lineEdit_name->setText(name);
    }

    ui->textEdit->setFocusPolicy(Qt::StrongFocus);
    ui->textEdit->setFocus();
    ui->textEdit->installEventFilter(this);//设置完后自动调用其eventFilter函数

    ui->textBrowser->setStyleSheet("font-size:16px;");

    connect(&timerWait,&QTimer::timeout,this,&ChatRoom::on_timeroutWait);
}

ChatRoom::~ChatRoom()
{
    delete settings;
    delete ui;
}

void ChatRoom::on_getMsg(QString msg)
{
    QStringList msgList = msg.split("&*&");
    if(msgList.at(0)=="number"){
        ui->label_totalPeople->setText("在线人数："+msgList.at(1));
        return;
    }

    ui->textBrowser->moveCursor(QTextCursor::End);

    if(msgList.at(0)=="all"){
        ui->textBrowser->setHtml(msgList.at(1));
        ui->label_totalPeople->setText("在线人数："+msgList.at(2));
    }
    else if(msgList.at(0)=="new" || msgList.at(0)=="system"){
        ui->textBrowser->insertHtml(msgList.at(1));
    }

    ui->textBrowser->moveCursor(QTextCursor::End);
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
