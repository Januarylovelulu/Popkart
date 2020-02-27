/********************************************************************************
** Form generated from reading UI file 'cheackoperatingversion.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHEACKOPERATINGVERSION_H
#define UI_CHEACKOPERATINGVERSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CheackOperatingVersion
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *CheackOperatingVersion)
    {
        if (CheackOperatingVersion->objectName().isEmpty())
            CheackOperatingVersion->setObjectName(QStringLiteral("CheackOperatingVersion"));
        CheackOperatingVersion->resize(400, 300);
        gridLayout_2 = new QGridLayout(CheackOperatingVersion);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(CheackOperatingVersion);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        pushButton = new QPushButton(CheackOperatingVersion);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(pushButton, 1, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(CheackOperatingVersion);

        QMetaObject::connectSlotsByName(CheackOperatingVersion);
    } // setupUi

    void retranslateUi(QDialog *CheackOperatingVersion)
    {
        CheackOperatingVersion->setWindowTitle(QApplication::translate("CheackOperatingVersion", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("CheackOperatingVersion", "Win10", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CheackOperatingVersion", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CheackOperatingVersion: public Ui_CheackOperatingVersion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHEACKOPERATINGVERSION_H
