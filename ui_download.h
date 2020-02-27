/********************************************************************************
** Form generated from reading UI file 'download.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOAD_H
#define UI_DOWNLOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Download
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QPushButton *pushButton_1;
    QLineEdit *lineEdit;
    QLabel *label_1;
    QProgressBar *progressBar;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *Download)
    {
        if (Download->objectName().isEmpty())
            Download->setObjectName(QStringLiteral("Download"));
        Download->resize(460, 460);
        gridLayout_2 = new QGridLayout(Download);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_3 = new QPushButton(Download);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 40));

        gridLayout_2->addWidget(pushButton_3, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(Download);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 40));

        gridLayout_2->addWidget(pushButton_2, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(Download);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 8, 0, 1, 2);

        pushButton_1 = new QPushButton(Download);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(pushButton_1, 1, 1, 1, 1);

        lineEdit = new QLineEdit(Download);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        label_1 = new QLabel(Download);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_1, 3, 0, 1, 2);

        progressBar = new QProgressBar(Download);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 6, 0, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_3, 7, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_5, 9, 0, 1, 2);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_6, 5, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 2);

        verticalSpacer_4 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_4, 2, 0, 1, 2);


        retranslateUi(Download);

        QMetaObject::connectSlotsByName(Download);
    } // setupUi

    void retranslateUi(QDialog *Download)
    {
        Download->setWindowTitle(QApplication::translate("Download", "Dialog", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Download", "\345\205\263\351\227\255", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Download", "\344\270\213\350\275\275", Q_NULLPTR));
        label_2->setText(QString());
        pushButton_1->setText(QApplication::translate("Download", "\351\200\211\346\213\251\344\277\235\345\255\230\345\234\260\345\235\200", Q_NULLPTR));
        label_1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Download: public Ui_Download {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOAD_H
