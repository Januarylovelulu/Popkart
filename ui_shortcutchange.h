/********************************************************************************
** Form generated from reading UI file 'shortcutchange.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHORTCUTCHANGE_H
#define UI_SHORTCUTCHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ShortcutChange
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *sure;
    QPushButton *back;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *showInput;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *seamlessInput;
    QLabel *notice_hide;
    QLabel *notice_seamless;
    QLabel *notice_show;
    QLineEdit *hideInput;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *ShortcutChange)
    {
        if (ShortcutChange->objectName().isEmpty())
            ShortcutChange->setObjectName(QStringLiteral("ShortcutChange"));
        ShortcutChange->resize(390, 390);
        gridLayout_2 = new QGridLayout(ShortcutChange);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        sure = new QPushButton(ShortcutChange);
        sure->setObjectName(QStringLiteral("sure"));
        sure->setMinimumSize(QSize(0, 40));

        gridLayout_2->addWidget(sure, 1, 0, 1, 1);

        back = new QPushButton(ShortcutChange);
        back->setObjectName(QStringLiteral("back"));
        back->setMinimumSize(QSize(0, 40));

        gridLayout_2->addWidget(back, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_4, 6, 0, 1, 2);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_6, 10, 0, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_3, 4, 0, 1, 2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_5, 8, 0, 1, 2);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_7, 0, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 2);

        showInput = new QLineEdit(ShortcutChange);
        showInput->setObjectName(QStringLiteral("showInput"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(showInput->sizePolicy().hasHeightForWidth());
        showInput->setSizePolicy(sizePolicy);
        showInput->setMinimumSize(QSize(0, 40));
        showInput->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(showInput, 5, 1, 1, 1);

        label = new QLabel(ShortcutChange);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(ShortcutChange);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 9, 0, 1, 1);

        seamlessInput = new QLineEdit(ShortcutChange);
        seamlessInput->setObjectName(QStringLiteral("seamlessInput"));
        sizePolicy.setHeightForWidth(seamlessInput->sizePolicy().hasHeightForWidth());
        seamlessInput->setSizePolicy(sizePolicy);
        seamlessInput->setMinimumSize(QSize(0, 40));
        seamlessInput->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(seamlessInput, 9, 1, 1, 1);

        notice_hide = new QLabel(ShortcutChange);
        notice_hide->setObjectName(QStringLiteral("notice_hide"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(notice_hide->sizePolicy().hasHeightForWidth());
        notice_hide->setSizePolicy(sizePolicy2);
        notice_hide->setMinimumSize(QSize(0, 40));
        notice_hide->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(notice_hide, 3, 0, 1, 2);

        notice_seamless = new QLabel(ShortcutChange);
        notice_seamless->setObjectName(QStringLiteral("notice_seamless"));
        sizePolicy2.setHeightForWidth(notice_seamless->sizePolicy().hasHeightForWidth());
        notice_seamless->setSizePolicy(sizePolicy2);
        notice_seamless->setMinimumSize(QSize(0, 40));
        notice_seamless->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(notice_seamless, 11, 0, 1, 2);

        notice_show = new QLabel(ShortcutChange);
        notice_show->setObjectName(QStringLiteral("notice_show"));
        sizePolicy2.setHeightForWidth(notice_show->sizePolicy().hasHeightForWidth());
        notice_show->setSizePolicy(sizePolicy2);
        notice_show->setMinimumSize(QSize(0, 40));
        notice_show->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(notice_show, 7, 0, 1, 2);

        hideInput = new QLineEdit(ShortcutChange);
        hideInput->setObjectName(QStringLiteral("hideInput"));
        sizePolicy.setHeightForWidth(hideInput->sizePolicy().hasHeightForWidth());
        hideInput->setSizePolicy(sizePolicy);
        hideInput->setMinimumSize(QSize(0, 40));
        hideInput->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(hideInput, 1, 1, 1, 1);

        label_2 = new QLabel(ShortcutChange);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 5, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_8, 12, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 2);


        retranslateUi(ShortcutChange);

        QMetaObject::connectSlotsByName(ShortcutChange);
    } // setupUi

    void retranslateUi(QDialog *ShortcutChange)
    {
        ShortcutChange->setWindowTitle(QApplication::translate("ShortcutChange", "Dialog", Q_NULLPTR));
        sure->setText(QApplication::translate("ShortcutChange", "\347\241\256\345\256\232", Q_NULLPTR));
        back->setText(QApplication::translate("ShortcutChange", "\350\277\224\345\233\236", Q_NULLPTR));
        showInput->setText(QString());
        label->setText(QApplication::translate("ShortcutChange", "\346\234\200\345\260\217\345\214\226\345\277\253\346\215\267\351\224\256 Alt+", Q_NULLPTR));
        label_3->setText(QApplication::translate("ShortcutChange", "\346\227\240\347\274\235\347\232\204\345\277\253\346\215\267\351\224\256 Alt+", Q_NULLPTR));
        seamlessInput->setText(QString());
        notice_hide->setText(QApplication::translate("ShortcutChange", "\346\234\200\345\260\217\345\214\226", Q_NULLPTR));
        notice_seamless->setText(QApplication::translate("ShortcutChange", "\346\234\200\345\260\217\345\214\226", Q_NULLPTR));
        notice_show->setText(QApplication::translate("ShortcutChange", "\346\234\200\345\260\217\345\214\226", Q_NULLPTR));
        hideInput->setText(QString());
        label_2->setText(QApplication::translate("ShortcutChange", "\344\270\273\347\225\214\351\235\242\345\277\253\346\215\267\351\224\256 Alt+", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ShortcutChange: public Ui_ShortcutChange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHORTCUTCHANGE_H
