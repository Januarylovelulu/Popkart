#ifndef CHANGEVERSION_H
#define CHANGEVERSION_H

#include <QDialog>
#include <QSettings>
#include <QMessageBox>
#include <QPainter>
#include <QBitmap>
#include <QMouseEvent>
#include "MyFile.h"
#include "MyNetwork.h"
#include "download.h"

namespace Ui {
class ChangeVersion;
}

class ChangeVersion : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeVersion(QWidget *parent = nullptr);
    bool isHaveGame[7];//是否有游戏,0-5为版本是否ture，6为0-5是否有ture
    ~ChangeVersion();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_pushButton_selectPath_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::ChangeVersion *ui;

    void setPushButton(bool on);

    int checkPath(QString path);
    int checkVersion(QString str);

    void download(int cmd);

    bool m_move=false;
    QPoint m_startPoint;
    QPoint m_windowPoint;

    QSettings *settings;

    MyFile myFile;
    MyNetwork myNetwork;
};

#endif // CHANGEVERSION_H
