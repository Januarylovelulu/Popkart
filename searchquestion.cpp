#include "searchquestion.h"
#include "ui_searchquestion.h"

#include <QDebug>

SearchQuestion::SearchQuestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchQuestion)
{
    ui->setupUi(this);
    this->setWindowTitle("搜索解决办法");
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
    QString text = myFile.readTextFile("问题库.html","./问题库",true);
//    text.remove("./图片/");
    if(text.indexOf("./图片/") < 20) {
        text.remove(text.indexOf("./图片/"),5);
    }
    text.remove("white-space: pre-wrap;");
    QString len = "background-color:#ffffff;";
    while(text.indexOf("background-color:#",Qt::CaseInsensitive) != -1){
        text.remove(text.indexOf("background-color:#",Qt::CaseInsensitive),len.length());
    }

    text.replace("./图片/","./问题库/图片/");

    int span = text.indexOf("<span ");

    text.replace("</span>","</span>/n");
//    text.replace("<span","/n<span");

    head = text.left(span);
    end = "</p></body></html>";

    text.remove(0,span);
    text.remove("</p></body></html>");

    QStringList pList = text.split("/n",QString::SkipEmptyParts);
    for(int x = 0;x < pList.length()-1;x++){
        QString str = pList[x];
        if(str.contains(">Q") && str.contains(keyWords)) {
            QString resultTmp = str;
            x++;
            while(x < pList.length() && !pList[x].contains(">Q")){
                resultTmp += pList[x] + "<br>";
                x++;
            }
            resultList << resultTmp;
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
    ui->textBrowser->insertHtml(head);
    for(QString str : resultList) {
        ui->textBrowser->insertHtml(str + "<br>");
    }
    ui->textBrowser->insertHtml(end);
}
