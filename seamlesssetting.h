#ifndef SEAMLESSSETTING_H
#define SEAMLESSSETTING_H

#include <QDialog>
#include <QSettings>
#include "MyFile.h"

namespace Ui {
class SeamlessSetting;
}

class SeamlessSetting : public QDialog
{
    Q_OBJECT

public:
    explicit SeamlessSetting(QWidget *parent = 0);
    ~SeamlessSetting();
    void setKey(int key);
    void sure(bool b);
    QString translateKey(int key);//虚拟转qt::key
    int seamlessKey[2]={-1,-1};
    bool isSureBtnEnable();

private slots:
    void on_sure_clicked();

    void on_back_clicked();

private:
    Ui::SeamlessSetting *ui;

    QSettings *settings;

    MyFile myFile;
};

#endif // SEAMLESSSETTING_H

