#include "thread.h"
#include <QDebug>
#include <windows.h>

Thread::Thread()
{

}

void Thread::setRun(bool run)
{
    isRun=run;
}

void Thread::run()
{
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_X, Qt::NoModifier, QString());
    isRun=true;
    while(isRun)
    {
        //keybd_event(0x58, 0x45, KEYEVENTF_EXTENDEDKEY, 0);//按键按下
        sleep(1);
        QCoreApplication::sendEvent(this, &keyPress);
        //keybd_event(0x58, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);//按键松开
    }
}
