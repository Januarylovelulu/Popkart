#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include <QSettings>
#include "MyFile.h"

namespace Ui {
class Setting;
}

class Setting : public QDialog
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();

signals:
    void transparent(const QString&);


private slots:
    void on_back_clicked();

    void on_sure_clicked();

    void on_transparent_output_valueChanged(int position);
    void on_transparent_input_valueChanged(int position);
    void on_transparent_btn_valueChanged(int position);
    void on_transparent_window_valueChanged(int position);

private:
    Ui::Setting *ui;

    QSettings *settings;
    MyFile myFile;
};

#endif // SETTING_H
