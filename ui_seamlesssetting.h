/********************************************************************************
** Form generated from reading UI file 'seamlesssetting.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEAMLESSSETTING_H
#define UI_SEAMLESSSETTING_H

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

class Ui_SeamlessSetting
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *sure;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *back;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *SeamlessSetting)
    {
        if (SeamlessSetting->objectName().isEmpty())
            SeamlessSetting->setObjectName(QStringLiteral("SeamlessSetting"));
        SeamlessSetting->resize(350, 350);
        gridLayout_2 = new QGridLayout(SeamlessSetting);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        sure = new QPushButton(SeamlessSetting);
        sure->setObjectName(QStringLiteral("sure"));
        sure->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setStrikeOut(false);
        font.setStyleStrategy(QFont::PreferDefault);
        sure->setFont(font);

        gridLayout_2->addWidget(sure, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit = new QLineEdit(SeamlessSetting);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 40));
        lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        label = new QLabel(SeamlessSetting);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(SeamlessSetting);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        lineEdit_2 = new QLineEdit(SeamlessSetting);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(0, 40));
        lineEdit_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_2, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_3, 4, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 2);

        back = new QPushButton(SeamlessSetting);
        back->setObjectName(QStringLiteral("back"));
        back->setMinimumSize(QSize(0, 40));

        gridLayout_2->addWidget(back, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_4, 2, 0, 1, 2);


        retranslateUi(SeamlessSetting);

        QMetaObject::connectSlotsByName(SeamlessSetting);
    } // setupUi

    void retranslateUi(QDialog *SeamlessSetting)
    {
        SeamlessSetting->setWindowTitle(QApplication::translate("SeamlessSetting", "Dialog", Q_NULLPTR));
        sure->setText(QApplication::translate("SeamlessSetting", "\347\241\256\345\256\232\346\233\264\346\224\271", Q_NULLPTR));
        label->setText(QApplication::translate("SeamlessSetting", "\346\270\270\346\210\217\347\232\204 \345\211\215\350\277\233\351\224\256:", Q_NULLPTR));
        label_2->setText(QApplication::translate("SeamlessSetting", "\346\270\270\346\210\217\347\232\204 \345\226\267\346\260\224\351\224\256:", Q_NULLPTR));
        back->setText(QApplication::translate("SeamlessSetting", "\345\217\226\346\266\210\346\233\264\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SeamlessSetting: public Ui_SeamlessSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEAMLESSSETTING_H
