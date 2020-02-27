#ifndef SHORTCUTCHANGE_H
#define SHORTCUTCHANGE_H

#include <QDialog>
#include <QTimer>
#include <QRegExpValidator>
#include <QSettings>
#include "MyFile.h"
#include "qxtglobalshortcut.h"

namespace Ui {
class ShortcutChange;
}

class ShortcutChange : public QDialog
{
    Q_OBJECT

public:
    explicit ShortcutChange(QWidget *parent = 0, QString show="", QString hide1="",QString seamless="");
    ~ShortcutChange();

private slots:
    void on_hideInput_textChanged(const QString &arg1);

    void on_showInput_textChanged(const QString &arg1);

    void on_seamlessInput_textChanged(const QString &arg1);

    void on_shortcut(const bool& boolen);

    void on_back_clicked();
    void on_sure_clicked();

    void on_timeoutShow();
    void on_timeoutHide();
    void on_timeoutSeamless();

private:
    Ui::ShortcutChange *ui;

    bool ifShortcutTrue;
    bool ifShortcutShowTrue;
    bool ifShortcutHideTrue;
    bool ifShortcutSeamlessTrue;

    QTimer show1;
    QTimer hide1;
    QTimer seamless1;

    QSettings *settings;

    MyFile myFile;
};

#endif // SHORTCUTCHANGE_H
