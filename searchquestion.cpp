#include "searchquestion.h"
#include "ui_searchquestion.h"

#include <QDebug>

SearchQuestion::SearchQuestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchQuestion)
{
    ui->setupUi(this);
    this->setWindowTitle("搜索解决办法");
    this->setMaximumSize(this->width(),800);
    this->setMinimumSize(this->width(),this->height());

    settings = new QSettings(QSettings::NativeFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());

    QString pathPic=settings->value("picPath").toString();
    QImage imgBackgroud(pathPic);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),
                     QBrush(imgBackgroud.scaled(this->width(),this->height())));
    this->setPalette(palette);

    this->setStyleSheet("font-family:\"楷体\";"
                        "font-size:18px;"
                        "font-weight:100;");

    QString str = settings->value("settings").toString();
    if(!str.isEmpty())
    {
        QStringList strList=str.split(";");
        ui->textBrowser->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(3)));
        ui->lineEdit_search->setStyleSheet(QString("background:rgb(255,255,255,%1);").arg(strList.at(4)));
        ui->pushButton_search->setStyleSheet(QString("background:rgb(25,255,255,%1);").arg(strList.at(5)));
        this->setWindowOpacity(QString(strList.at(6)).toDouble()/100.0);
    }
}

SearchQuestion::~SearchQuestion()
{
    delete ui;
    delete settings;
}

QStringList SearchQuestion::searchQuestion(QString keyWords)
{
    QStringList resultList;
    QStringList readList=myFile.readTextFile("问题库.txt","./问题库").split("\n",QString::SkipEmptyParts);
    for(int x=0;x<readList.length()-1;x++)
    {
        if(readList.at(x).contains("Q：") && readList.at(x+1).contains("A："))
        {
            if(readList.at(x).contains(keyWords,Qt::CaseInsensitive))
            {
                int ax=x+1;
                QString str;
                str+=readList.at(x)+"\n";
                while(!readList.at(ax).contains("Q："))
                {
                    str+=readList.at(ax)+"\n";
                    ax++;
                    if(ax>=readList.length())
                        break;
                }
                str+="\n";
                resultList.append(str);
            }
        }
    }
    return resultList;
}

void SearchQuestion::on_pushButton_search_clicked()
{
    QString question=ui->lineEdit_search->text();
    if(question.isEmpty())
        return ;

    question.remove("需要");
    question.remove("为什么");
    question.remove("为什");
    question.remove("才能够");
    question.remove("才能");
    question.remove("能够");
    question.remove("吗");
    question.remove("么");
    question.remove("嘛");
    question.remove("啊");
    question.remove("呀");
    question.remove("呢");
    QStringList questionList;
    if(question.length()==1)
    {
        questionList.append(question);
    }
    else
    {
        for(int x=0;x<question.length()-1;x++)
        {
            QString str=QString(question.at(x))+QString(question.at(x+1));
            if(!questionList.contains(str))
                questionList.append(str);
        }
    }

    QStringList resultList;
    for(int x=0;x<questionList.length();x++)
    {
        QStringList str=searchQuestion(questionList.at(x));
        for(int x=0;x<str.length();x++)
        {
            if(!resultList.contains(str.at(x)))
            {
                resultList.append(str.at(x));
            }
        }
    }
    ui->textBrowser->clear();
    if(resultList.isEmpty())
    {
        ui->textBrowser->setText("\n问题库中没有该问题\n请前往跑跑单机吧查阅《游戏时遇到问题？点我！》以进行查找！");
        QMessageBox box(this);
        box.addButton("确定",QMessageBox::YesRole);
        box.addButton("取消",QMessageBox::NoRole);
        box.setText("问题库中没有该问题，很抱歉没有帮助到你 \n是否需要跳转到贴吧，查阅更详细的资料？");
        if(box.exec()==0)
        {
            QString read=myFile.readTextFile("贴吧路径.txt","./问题库");
            myFile.openHtmlFile(read);
        }
        return;
    }
    for(int x=0;x<resultList.length();x++)
    {
        QStringList strList=resultList.at(x).split("\n",QString::SkipEmptyParts);
        ui->textBrowser->setTextColor(QColor("blue"));
        ui->textBrowser->insertPlainText("\n"+strList.at(0)+"\n");
        ui->textBrowser->setTextColor(QColor("black"));
        for(int y=1;y<strList.length();y++)
        {
            ui->textBrowser->insertPlainText(strList.at(y)+"\n");
        }
    }
}
