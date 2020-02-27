#ifndef CHEACKOPERATINGVERSION_H
#define CHEACKOPERATINGVERSION_H

#include <QDialog>
#include <QSysinfo>
#include <QTimer>
#include <QCloseEvent>

namespace Ui {
class CheackOperatingVersion;
}

class CheackOperatingVersion : public QDialog
{
    Q_OBJECT

public:
    explicit CheackOperatingVersion(QWidget *parent = 0);
    ~CheackOperatingVersion();

    QString checkSystemVersion();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_changeButtonText();

private:
    Ui::CheackOperatingVersion *ui;

    QTimer timer;
};

#endif // CHEACKOPERATINGVERSION_H
