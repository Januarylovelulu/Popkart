#ifndef CHANGEBACKGROUNDPICTRUE_H
#define CHANGEBACKGROUNDPICTRUE_H

#ifdef _MSC_VER
#pragma execution_character_set("utf-8")

#include <QDialog>
#include <QPixmap>
#include "MyFile.h"

namespace Ui {
class ChangeBackgroundPictrue;
}

class ChangeBackgroundPictrue : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeBackgroundPictrue(QWidget *parent = 0,QSize size=QSize(0,0));
    ~ChangeBackgroundPictrue();

private slots:
    void on_sure_clicked();

    void on_back_clicked();

private:
    Ui::ChangeBackgroundPictrue *ui;
};

#endif // CHANGEBACKGROUNDPICTRUE_H

#endif