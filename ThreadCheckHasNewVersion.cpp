#include "ThreadCheckHasNewVersion.h"

#include <QDebug>

ThreadCheckHasNewVersion::ThreadCheckHasNewVersion(QObject* parent, double version):QThread(parent)
{
    stopped=true;
    this->version=version;
}

ThreadCheckHasNewVersion::~ThreadCheckHasNewVersion()
{

}

void ThreadCheckHasNewVersion::stop()
{
    this->stopped=true;
}

bool ThreadCheckHasNewVersion::getStopped()
{
    return this->stopped;
}

void ThreadCheckHasNewVersion::startReady()
{
    this->stopped=false;
}

void ThreadCheckHasNewVersion::run()
{
    startReady();
    if(myFile.isOnline())
    {
        QString html=myNetwork.getHtmlContent("https://lulu.gold/index");
        if(!html.isEmpty())
        {
            html.replace("\t","");
            html.replace("\r","");
            QStringList htmlList=html.split("\n");
            htmlList=htmlList.at(0).split("：：");
            double versionOnline=htmlList.at(1).toDouble();
            if(versionOnline>version)
            {
                emit returnResult(true,htmlList);
            }
            else
            {
                emit returnResult(false,htmlList);
            }
        }
    }
    else
    {
        emit returnResult(false,QStringList("outline"));
    }
}
