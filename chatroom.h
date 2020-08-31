#ifndef CHATROOM_H
#define CHATROOM_H

#include <QDialog>
#include <QTcpSocket>
#include <QTextCodec>
#include <QMessageBox>
#include <QTimer>
#include <QSettings>
#include <QKeyEvent>
#include <QByteArray>
#include "MyNetwork.h"

namespace Ui {
class ChatRoom;
}

class ChatRoom : public QDialog
{
    Q_OBJECT

public:
    explicit ChatRoom(QWidget *parent = 0,QTcpSocket *client = nullptr);
    ~ChatRoom();

public slots:
    void on_getMsg(QByteArray msg);

private slots:
    void on_pushButton_send_clicked();

    void on_pushButton_close_clicked();

    void on_timeroutWait();

    void on_openUrl(const QUrl&url);

protected:
    bool eventFilter(QObject *target, QEvent *event);//事件过滤器

private:
    Ui::ChatRoom *ui;

    QTcpSocket *client;
    MyNetwork myNetwork;

    QSettings *settings;

    QTimer timerWait; // 发送信息设置时间间隔

public:
    // socket的写
    static void write(QString msg,QTcpSocket *socket);
};

#endif // CHATROOM_H
