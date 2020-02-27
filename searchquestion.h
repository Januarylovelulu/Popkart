#ifndef SEARCHQUESTION_H
#define SEARCHQUESTION_H

#include <QDialog>
#include <QMessageBox>
#include <QSettings>
#include "MyFile.h"

namespace Ui {
class SearchQuestion;
}

class SearchQuestion : public QDialog
{
    Q_OBJECT

public:
    explicit SearchQuestion(QWidget *parent = nullptr);
    ~SearchQuestion();

    QStringList searchQuestion(QString keyWords);

private slots:
    void on_pushButton_search_clicked();

private:
    Ui::SearchQuestion *ui;

    QSettings *settings;
    MyFile myFile;
};

#endif // SEARCHQUESTION_H
