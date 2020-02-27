/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Setting
{
public:
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QSlider *transparent_btn;
    QPushButton *sure;
    QPushButton *back;
    QSlider *transparent_input;
    QSlider *transparent_output;
    QLabel *label_output;
    QLabel *label_input;
    QLabel *label_btn;
    QCheckBox *checkBox_3;
    QSlider *transparent_window;
    QLabel *label_window;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;

    void setupUi(QDialog *Setting)
    {
        if (Setting->objectName().isEmpty())
            Setting->setObjectName(QStringLiteral("Setting"));
        Setting->resize(481, 546);
        checkBox = new QCheckBox(Setting);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(40, 20, 291, 41));
        checkBox_2 = new QCheckBox(Setting);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(40, 70, 291, 41));
        transparent_btn = new QSlider(Setting);
        transparent_btn->setObjectName(QStringLiteral("transparent_btn"));
        transparent_btn->setGeometry(QRect(40, 380, 191, 16));
        transparent_btn->setOrientation(Qt::Horizontal);
        sure = new QPushButton(Setting);
        sure->setObjectName(QStringLiteral("sure"));
        sure->setGeometry(QRect(70, 480, 151, 41));
        back = new QPushButton(Setting);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(270, 480, 151, 41));
        transparent_input = new QSlider(Setting);
        transparent_input->setObjectName(QStringLiteral("transparent_input"));
        transparent_input->setGeometry(QRect(40, 330, 191, 16));
        transparent_input->setOrientation(Qt::Horizontal);
        transparent_output = new QSlider(Setting);
        transparent_output->setObjectName(QStringLiteral("transparent_output"));
        transparent_output->setGeometry(QRect(40, 280, 191, 16));
        transparent_output->setOrientation(Qt::Horizontal);
        label_output = new QLabel(Setting);
        label_output->setObjectName(QStringLiteral("label_output"));
        label_output->setGeometry(QRect(250, 270, 201, 41));
        label_input = new QLabel(Setting);
        label_input->setObjectName(QStringLiteral("label_input"));
        label_input->setGeometry(QRect(250, 320, 201, 41));
        label_btn = new QLabel(Setting);
        label_btn->setObjectName(QStringLiteral("label_btn"));
        label_btn->setGeometry(QRect(250, 370, 201, 41));
        checkBox_3 = new QCheckBox(Setting);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(40, 120, 291, 41));
        transparent_window = new QSlider(Setting);
        transparent_window->setObjectName(QStringLiteral("transparent_window"));
        transparent_window->setGeometry(QRect(40, 430, 191, 16));
        transparent_window->setOrientation(Qt::Horizontal);
        label_window = new QLabel(Setting);
        label_window->setObjectName(QStringLiteral("label_window"));
        label_window->setGeometry(QRect(250, 420, 201, 41));
        checkBox_4 = new QCheckBox(Setting);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(40, 170, 291, 41));
        checkBox_5 = new QCheckBox(Setting);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setGeometry(QRect(40, 220, 291, 41));

        retranslateUi(Setting);

        QMetaObject::connectSlotsByName(Setting);
    } // setupUi

    void retranslateUi(QDialog *Setting)
    {
        Setting->setWindowTitle(QApplication::translate("Setting", "Dialog", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Setting", "\345\274\200\345\247\213\346\270\270\346\210\217\345\220\216\350\207\252\345\212\250\346\234\200\345\260\217\345\214\226", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("Setting", "\345\277\253\346\215\267\351\224\256\346\211\223\345\274\200", Q_NULLPTR));
        sure->setText(QApplication::translate("Setting", "\347\241\256\345\256\232", Q_NULLPTR));
        back->setText(QApplication::translate("Setting", "\345\217\226\346\266\210", Q_NULLPTR));
        label_output->setText(QApplication::translate("Setting", "\350\276\223\345\207\272\346\241\206\351\200\217\346\230\216\345\272\246:", Q_NULLPTR));
        label_input->setText(QApplication::translate("Setting", "\350\276\223\345\205\245\346\241\206\351\200\217\346\230\216\345\272\246:", Q_NULLPTR));
        label_btn->setText(QApplication::translate("Setting", "\346\214\211\351\222\256\347\232\204\351\200\217\346\230\216\345\272\246:", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("Setting", "\345\274\200\345\247\213\346\270\270\346\210\217\345\211\215\350\257\242\351\227\256\346\270\270\346\210\217\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
        label_window->setText(QApplication::translate("Setting", "\347\250\213\345\272\217\347\232\204\351\200\217\346\230\216\345\272\246:", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("Setting", "\345\274\200\345\247\213\346\270\270\346\210\217\345\220\216\345\220\257\345\212\250\345\231\250\350\207\252\345\212\250\351\235\240\345\217\263", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("Setting", "\350\207\252\345\212\250\346\243\200\346\237\245\346\233\264\346\226\260\347\211\210\346\234\254", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Setting: public Ui_Setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
