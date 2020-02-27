/********************************************************************************
** Form generated from reading UI file 'searchquestion.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHQUESTION_H
#define UI_SEARCHQUESTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_SearchQuestion
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_search;
    QPushButton *pushButton_search;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *SearchQuestion)
    {
        if (SearchQuestion->objectName().isEmpty())
            SearchQuestion->setObjectName(QStringLiteral("SearchQuestion"));
        SearchQuestion->resize(520, 520);
        gridLayout = new QGridLayout(SearchQuestion);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_search = new QLineEdit(SearchQuestion);
        lineEdit_search->setObjectName(QStringLiteral("lineEdit_search"));
        lineEdit_search->setMinimumSize(QSize(0, 50));
        lineEdit_search->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_search, 0, 0, 1, 1);

        pushButton_search = new QPushButton(SearchQuestion);
        pushButton_search->setObjectName(QStringLiteral("pushButton_search"));
        pushButton_search->setMinimumSize(QSize(120, 50));

        gridLayout->addWidget(pushButton_search, 0, 1, 1, 1);

        textBrowser = new QTextBrowser(SearchQuestion);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 1, 0, 1, 2);


        retranslateUi(SearchQuestion);

        QMetaObject::connectSlotsByName(SearchQuestion);
    } // setupUi

    void retranslateUi(QDialog *SearchQuestion)
    {
        SearchQuestion->setWindowTitle(QApplication::translate("SearchQuestion", "Dialog", Q_NULLPTR));
        lineEdit_search->setText(QString());
        pushButton_search->setText(QApplication::translate("SearchQuestion", "\346\220\234\347\264\242\351\227\256\351\242\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SearchQuestion: public Ui_SearchQuestion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHQUESTION_H
