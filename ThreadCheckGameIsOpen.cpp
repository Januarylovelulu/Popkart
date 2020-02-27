#include "ThreadCheckGameIsOpen.h"

#include <QDebug>

ThreadCheckGameIsOpen::ThreadCheckGameIsOpen(QObject* parent):QThread(parent)
{
    stopped=true;
}

ThreadCheckGameIsOpen::~ThreadCheckGameIsOpen()
{

}

void ThreadCheckGameIsOpen::stop()
{
    this->stopped=true;
}

bool ThreadCheckGameIsOpen::getStopped()
{
    return this->stopped;
}

void ThreadCheckGameIsOpen::startReady()
{
    this->stopped=false;
    isGameOn=false;
}

void ThreadCheckGameIsOpen::run()
{
    startReady();
    while(!this->stopped)
    {
        if(!myFile.isExeRunning("kartRider.exe"))
        {
            if(myFile.isExeRunning("PPServer.exe"))
            {
                myFile.killExe("PPServer.exe");
            }
            if(isGameOn==true)//游戏打开了，才会发送“开始游戏”
            {
                emit returnResult("开始游戏");
                isGameOn=false;
            }
            this->msleep(500);
            if(myFile.isExeRunning(("AdBalloonExt.exe")))
            {
                myFile.killExe("AdBalloonExt.exe");
            }
        }
        else
        {
            if(isGameOn==false)
            {
                emit returnResult("关闭游戏");
                isGameOn=true;
            }
        }
        this->msleep(300);
    }
}
