/********************************************************************************
** Form generated from reading UI file 'dpi.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPI_H
#define UI_DPI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DPI
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *sure;
    QPushButton *back;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_2;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QLineEdit *lineEdit_height;
    QLineEdit *lineEdit_width;
    QRadioButton *radioButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QDialog *DPI)
    {
        if (DPI->objectName().isEmpty())
            DPI->setObjectName(QStringLiteral("DPI"));
        DPI->setWindowModality(Qt::NonModal);
        DPI->resize(360, 360);
        gridLayout_2 = new QGridLayout(DPI);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        sure = new QPushButton(DPI);
        sure->setObjectName(QStringLiteral("sure"));
        sure->setMinimumSize(QSize(0, 40));

        gridLayout_2->addWidget(sure, 1, 0, 1, 1);

        back = new QPushButton(DPI);
        back->setObjectName(QStringLiteral("back"));
        back->setMinimumSize(QSize(0, 40));

        gridLayout_2->addWidget(back, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        radioButton_2 = new QRadioButton(DPI);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(radioButton_2, 5, 0, 1, 1);

        label = new QLabel(DPI);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 40));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 4);

        comboBox = new QComboBox(DPI);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(comboBox, 3, 1, 1, 3);

        label_2 = new QLabel(DPI);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 5, 2, 1, 1);

        lineEdit_height = new QLineEdit(DPI);
        lineEdit_height->setObjectName(QStringLiteral("lineEdit_height"));
        lineEdit_height->setMinimumSize(QSize(0, 40));
        lineEdit_height->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_height, 5, 3, 1, 1);

        lineEdit_width = new QLineEdit(DPI);
        lineEdit_width->setObjectName(QStringLiteral("lineEdit_width"));
        lineEdit_width->setMinimumSize(QSize(0, 40));
        lineEdit_width->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_width, 5, 1, 1, 1);

        radioButton = new QRadioButton(DPI);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setMinimumSize(QSize(0, 40));

        gridLayout->addWidget(radioButton, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_3, 4, 0, 1, 4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 4);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_4, 6, 0, 1, 4);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 2);

        verticalSpacer_5 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_5, 2, 0, 1, 2);

        sure->raise();
        label->raise();
        comboBox->raise();
        back->raise();
        radioButton->raise();
        radioButton_2->raise();
        lineEdit_width->raise();
        lineEdit_height->raise();
        label_2->raise();

        retranslateUi(DPI);

        QMetaObject::connectSlotsByName(DPI);
    } // setupUi

    void retranslateUi(QDialog *DPI)
    {
        DPI->setWindowTitle(QApplication::translate("DPI", "Dialog", Q_NULLPTR));
        sure->setText(QApplication::translate("DPI", "\347\241\256\345\256\232\344\277\256\346\224\271", Q_NULLPTR));
        back->setText(QApplication::translate("DPI", "\345\217\226\346\266\210", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("DPI", "\350\207\252\345\256\232\344\271\211\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
        label->setText(QApplication::translate("DPI", "  \345\275\223\345\211\215\346\270\270\346\210\217\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("DPI", "1024\303\227768", Q_NULLPTR)
         << QApplication::translate("DPI", "800\303\227600", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("DPI", "\303\227", Q_NULLPTR));
        radioButton->setText(QApplication::translate("DPI", "\351\200\211\346\213\251\345\210\206\350\276\250\347\216\207", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DPI: public Ui_DPI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPI_H
