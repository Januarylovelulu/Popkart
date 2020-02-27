#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextBrowser>
#include <QMouseEvent>
#include <QEvent>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QAction>
#include <QTimer>
#include <QRadioButton>
#include <QMessageBox>
#include <QSettings>
#include <QPainter>
#include <QBitmap>
#include <QMouseEvent>
#include <Windows.h>
#include "shortcutchange.h"
#include "setting.h"
#include "seamlesssetting.h"
#include "dpi.h"
#include "ThreadCheckGameIsOpen.h"
#include "ThreadCheckHasNewVersion.h"
#include "searchquestion.h"
#include "changeversion.h"
#include "MyNetwork.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int argc,char *argv[],double version);
    ~MainWindow();
    bool getSeamlessOn();
    void seamlessTimerStart();
    void seamlessTimerStop();
    QTimer timer;
    void timerou();
    int getSeamlessKey();

    void changeVertion_fuction(){on_changeVersion();}//调用private slot中的on_changeVersion();

public slots:
    void on_getReturnHasNewVersion(bool have, QStringList htmlList);
    void on_DownloadFinish();

private slots:
    void on_changeVersion();
    void on_changeBackgroundPic();
    void on_searchQuestion();
    void on_miniShow();
    void on_quit();
    void on_startRefit();
    void on_startRepair();
    void on_resetPPConfig();
    void on_screenShotPath();
    void on_vedioPath();
    void on_shadowPath();
    void on_shadowDelete();
    void on_setting();
    void on_changeShortcut();
    void on_seamlessSetting();
    void on_gameDPI();
    void on_update();

    void on_changeCar_clicked();
    void on_startGame_clicked();
    void on_seamlessTurnOn_clicked();
    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);
    void on_showMainAction();
    void on_exitAppAction();
    void on_timeOutChangePic();
    void on_timeOutStartTimer();
    void on_timeOutCheckGameIsOpen(QString str);

    void on_carCode_textChanged(const QString &arg1);
    void on_comboBox_currentIndexChanged(const QString &arg1);
    void on_textBrowser_textChanged();

    void on_getTransparentFromSetting(const QString &str);

    void on_seamlessTimeout();
    void on_seamlessStart();

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);

private:
    void autoScrollTextBrowser(QTextBrowser *text);//textBrowser自动滚动到最底部
    void miniShow();
    void createActions();
    void createMenu();

    double version;
    double versionOnline;

    QString checkVersion();

    Ui::MainWindow *ui;
    QString thisWindowTitle;

    bool m_move=false;
    QPoint m_startPoint;
    QPoint m_windowPoint;

    QSettings *settings;
    QString localHostPath;
    bool ifHavePath;

    QMenu *mMenu;
    QAction *mShowMainAction;
    QAction *mExitAppAction;
    QSystemTrayIcon *mSysTrayIcon;

    QTimer changePicTimer;//每隔一段时间换广告图片
    QTimer startPicTimer;//每隔一段时间检测广告图片
    int changeThisFlag;//当前广告的标签
    int changePicNum;//广告个数
    int changePicShowNum;
    int choosePic[50];
    int versionAd;
    QRadioButton **changePicRadioBtn;
    void readAdPicture();
    void adFunction(int x);//给广告加入功能

    ThreadCheckGameIsOpen *threadCheckGameIsOpen;

    QxtGlobalShortcut* shortcutHide;
    QxtGlobalShortcut* shortcutShow;
    QxtGlobalShortcut* shortcutSeamless;
    QString shortcutKeypressHide;
    QString shortcutKeypressShow;
    QString shortcutKeypressSeamless;
    void shortcutBind();//绑定快捷键函数

    bool settingCheckBox[5];
    void settingChange();

    bool seamlessOn=false;
    QTimer seamlessTimer;
    int seamlessTime=10;

    int seamlessKey[2]={-1,-1};

    MyFile myFile;
};

#endif // MAINWINDOW_Hs


