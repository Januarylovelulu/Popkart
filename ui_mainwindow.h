/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *openPath;
    QAction *changeBackgroundPic;
    QAction *startRefit;
    QAction *startRepair;
    QAction *screenShotPath;
    QAction *vedioPath;
    QAction *shadowPath;
    QAction *shadowDelete;
    QAction *setting;
    QAction *changeShortcut;
    QAction *seamlessSetting;
    QAction *gameDPI;
    QAction *searchQuestion;
    QAction *changeVersion;
    QAction *minishow;
    QAction *quit;
    QAction *resetPPConfig;
    QAction *update;
    QWidget *centralWidget;
    QTextBrowser *textBrowser;
    QPushButton *changeCar;
    QLineEdit *carCode;
    QPushButton *startGame;
    QComboBox *comboBox;
    QLabel *adPicture;
    QPushButton *seamlessTurnOn;
    QLineEdit *carChangeShow;
    QLabel *label_icon;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(605, 635);
        openPath = new QAction(MainWindow);
        openPath->setObjectName(QStringLiteral("openPath"));
        openPath->setCheckable(false);
        openPath->setChecked(false);
        QIcon icon;
        icon.addFile(QStringLiteral("../build-Popkart-Desktop_Qt_5_9_1_MSVC2015_64bit-Release/Log/normal.png"), QSize(), QIcon::Normal, QIcon::Off);
        openPath->setIcon(icon);
        changeBackgroundPic = new QAction(MainWindow);
        changeBackgroundPic->setObjectName(QStringLiteral("changeBackgroundPic"));
        changeBackgroundPic->setCheckable(false);
        changeBackgroundPic->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral("../build-Popkart-Desktop_Qt_5_9_1_MSVC2015_64bit-Release/Log/press.png"), QSize(), QIcon::Normal, QIcon::Off);
        changeBackgroundPic->setIcon(icon1);
        startRefit = new QAction(MainWindow);
        startRefit->setObjectName(QStringLiteral("startRefit"));
        startRefit->setIcon(icon);
        startRepair = new QAction(MainWindow);
        startRepair->setObjectName(QStringLiteral("startRepair"));
        startRepair->setIcon(icon1);
        screenShotPath = new QAction(MainWindow);
        screenShotPath->setObjectName(QStringLiteral("screenShotPath"));
        vedioPath = new QAction(MainWindow);
        vedioPath->setObjectName(QStringLiteral("vedioPath"));
        shadowPath = new QAction(MainWindow);
        shadowPath->setObjectName(QStringLiteral("shadowPath"));
        shadowDelete = new QAction(MainWindow);
        shadowDelete->setObjectName(QStringLiteral("shadowDelete"));
        setting = new QAction(MainWindow);
        setting->setObjectName(QStringLiteral("setting"));
        changeShortcut = new QAction(MainWindow);
        changeShortcut->setObjectName(QStringLiteral("changeShortcut"));
        seamlessSetting = new QAction(MainWindow);
        seamlessSetting->setObjectName(QStringLiteral("seamlessSetting"));
        gameDPI = new QAction(MainWindow);
        gameDPI->setObjectName(QStringLiteral("gameDPI"));
        searchQuestion = new QAction(MainWindow);
        searchQuestion->setObjectName(QStringLiteral("searchQuestion"));
        changeVersion = new QAction(MainWindow);
        changeVersion->setObjectName(QStringLiteral("changeVersion"));
        minishow = new QAction(MainWindow);
        minishow->setObjectName(QStringLiteral("minishow"));
        quit = new QAction(MainWindow);
        quit->setObjectName(QStringLiteral("quit"));
        resetPPConfig = new QAction(MainWindow);
        resetPPConfig->setObjectName(QStringLiteral("resetPPConfig"));
        update = new QAction(MainWindow);
        update->setObjectName(QStringLiteral("update"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 291, 561));
        textBrowser->setOpenExternalLinks(false);
        changeCar = new QPushButton(centralWidget);
        changeCar->setObjectName(QStringLiteral("changeCar"));
        changeCar->setEnabled(false);
        changeCar->setGeometry(QRect(460, 140, 131, 61));
        carCode = new QLineEdit(centralWidget);
        carCode->setObjectName(QStringLiteral("carCode"));
        carCode->setEnabled(false);
        carCode->setGeometry(QRect(320, 10, 271, 55));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(carCode->sizePolicy().hasHeightForWidth());
        carCode->setSizePolicy(sizePolicy);
        carCode->setAlignment(Qt::AlignCenter);
        startGame = new QPushButton(centralWidget);
        startGame->setObjectName(QStringLiteral("startGame"));
        startGame->setEnabled(false);
        startGame->setGeometry(QRect(460, 510, 131, 61));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEnabled(false);
        comboBox->setGeometry(QRect(320, 140, 131, 61));
        comboBox->setMaxCount(2147483640);
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);
        adPicture = new QLabel(centralWidget);
        adPicture->setObjectName(QStringLiteral("adPicture"));
        adPicture->setGeometry(QRect(320, 222, 270, 270));
        adPicture->setAlignment(Qt::AlignCenter);
        seamlessTurnOn = new QPushButton(centralWidget);
        seamlessTurnOn->setObjectName(QStringLiteral("seamlessTurnOn"));
        seamlessTurnOn->setEnabled(false);
        seamlessTurnOn->setGeometry(QRect(320, 510, 131, 61));
        carChangeShow = new QLineEdit(centralWidget);
        carChangeShow->setObjectName(QStringLiteral("carChangeShow"));
        carChangeShow->setGeometry(QRect(320, 83, 271, 40));
        carChangeShow->setAlignment(Qt::AlignCenter);
        carChangeShow->setReadOnly(true);
        label_icon = new QLabel(centralWidget);
        label_icon->setObjectName(QStringLiteral("label_icon"));
        label_icon->setGeometry(QRect(255, 10, 46, 46));
        label_icon->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        adPicture->raise();
        textBrowser->raise();
        changeCar->raise();
        carCode->raise();
        startGame->raise();
        comboBox->raise();
        seamlessTurnOn->raise();
        carChangeShow->raise();
        label_icon->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 605, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_2->setEnabled(false);
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_3->setEnabled(true);
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_4->setEnabled(true);
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addSeparator();
        menu->addAction(changeVersion);
        menu->addSeparator();
        menu->addAction(changeBackgroundPic);
        menu->addSeparator();
        menu->addAction(searchQuestion);
        menu->addSeparator();
        menu->addAction(minishow);
        menu->addSeparator();
        menu->addAction(quit);
        menu_2->addSeparator();
        menu_2->addAction(startRefit);
        menu_2->addSeparator();
        menu_2->addAction(startRepair);
        menu_2->addSeparator();
        menu_2->addAction(resetPPConfig);
        menu_2->addSeparator();
        menu_3->addSeparator();
        menu_3->addAction(screenShotPath);
        menu_3->addSeparator();
        menu_3->addAction(vedioPath);
        menu_3->addSeparator();
        menu_3->addAction(shadowPath);
        menu_3->addSeparator();
        menu_3->addAction(shadowDelete);
        menu_3->addSeparator();
        menu_4->addSeparator();
        menu_4->addAction(setting);
        menu_4->addSeparator();
        menu_4->addAction(changeShortcut);
        menu_4->addSeparator();
        menu_4->addAction(seamlessSetting);
        menu_4->addSeparator();
        menu_4->addAction(gameDPI);
        menu_4->addSeparator();
        menu_4->addAction(update);
        menu_4->addSeparator();

        retranslateUi(MainWindow);

        comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        openPath->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\350\277\220\350\241\214\346\226\207\344\273\266", Q_NULLPTR));
        changeBackgroundPic->setText(QApplication::translate("MainWindow", "\346\233\264\346\215\242\350\203\214\346\231\257\345\233\276\347\211\207", Q_NULLPTR));
        startRefit->setText(QApplication::translate("MainWindow", "\346\224\271\350\243\205\345\231\250", Q_NULLPTR));
        startRepair->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256\346\224\271\350\243\205", Q_NULLPTR));
        screenShotPath->setText(QApplication::translate("MainWindow", "\346\210\252\345\233\276\346\226\207\344\273\266\345\244\271", Q_NULLPTR));
        vedioPath->setText(QApplication::translate("MainWindow", "\350\247\206\351\242\221\346\226\207\344\273\266\345\244\271", Q_NULLPTR));
        shadowPath->setText(QApplication::translate("MainWindow", "\345\275\261\345\255\220\346\226\207\344\273\266\345\244\271", Q_NULLPTR));
        shadowDelete->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\275\261\345\255\220", Q_NULLPTR));
        setting->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\351\200\211\351\241\271", Q_NULLPTR));
        changeShortcut->setText(QApplication::translate("MainWindow", "\345\277\253\346\215\267\351\224\256\346\233\264\346\224\271", Q_NULLPTR));
        seamlessSetting->setText(QApplication::translate("MainWindow", "\346\227\240\347\274\235\350\256\276\347\275\256", Q_NULLPTR));
        gameDPI->setText(QApplication::translate("MainWindow", "\346\270\270\346\210\217\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
        searchQuestion->setText(QApplication::translate("MainWindow", "\351\227\256\351\242\230\346\220\234\347\264\242(\345\270\256\345\212\251)", Q_NULLPTR));
        changeVersion->setText(QApplication::translate("MainWindow", "\345\210\207\346\215\242\346\270\270\346\210\217\347\211\210\346\234\254", Q_NULLPTR));
        minishow->setText(QApplication::translate("MainWindow", "\346\234\200\345\260\217\345\214\226\345\210\260\346\211\230\347\233\230", Q_NULLPTR));
        quit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\345\220\257\345\212\250\345\231\250", Q_NULLPTR));
        resetPPConfig->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256PPConfig", Q_NULLPTR));
        update->setText(QApplication::translate("MainWindow", "\346\243\200\346\237\245\346\233\264\346\226\260", Q_NULLPTR));
        changeCar->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\350\275\246\350\276\206\344\273\243\347\240\201", Q_NULLPTR));
        carCode->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\346\225\260\345\255\227\345\210\207\346\215\242,\345\220\215\345\255\227\346\237\245\344\273\243\347\240\201", Q_NULLPTR));
        startGame->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\270\270\346\210\217", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\233\264\346\224\271\350\275\246\350\276\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\233\264\346\224\271\350\247\222\350\211\262", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\233\264\346\224\271\351\243\236\345\256\240", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\233\264\346\224\271\345\226\267\346\274\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\233\264\346\224\271\350\275\246\347\211\214", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\233\264\346\224\271\345\256\240\347\211\251", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\233\264\346\224\271\346\234\215\351\245\260", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\233\264\346\224\271\347\234\274\351\225\234", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\233\264\346\224\271\346\260\224\347\220\203", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\233\264\346\224\271\346\211\213\346\235\226", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\233\264\346\224\271\345\244\264\351\245\260", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\233\264\346\224\271\347\202\253\345\205\211", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\233\264\346\224\271\345\215\260\350\256\260", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\233\264\346\224\271\345\220\215\345\226\267", Q_NULLPTR)
        );
        adPicture->setText(QApplication::translate("MainWindow", "\346\270\270\346\210\217\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
        seamlessTurnOn->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\227\240\347\274\235", Q_NULLPTR));
        carChangeShow->setText(QString());
        label_icon->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\350\217\234\345\215\225", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\346\224\271\350\243\205(\351\207\215\347\275\256)", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\346\210\252\345\233\276/\350\247\206\351\242\221", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256\351\200\211\351\241\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
