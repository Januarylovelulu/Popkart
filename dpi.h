#ifndef DPI_H
#define DPI_H

#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include "MyFile.h"

namespace Ui {
class DPI;
}

class DPI : public QDialog
{
    Q_OBJECT

public:
    explicit DPI(QWidget *parent = 0,QString path="");
    QString getDPI();
    void setDPI(int width,int height);
    ~DPI();

private slots:
    void on_sure_clicked();

    void on_back_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_lineEdit_width_textEdited(const QString &arg1);

    void on_lineEdit_height_textEdited(const QString &arg1);

private:
    Ui::DPI *ui;
    QString localHostPath;
    QString gameWidth;
    QString gameHeight;
    int screenWidth;
    int screenHeight;

    QSettings *settings;

    MyFile myFile;
};

#endif // DPI_H
