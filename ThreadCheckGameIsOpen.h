#ifndef THREADCHECKGAMEISOPEN_H
#define THREADCHECKGAMEISOPEN_H

#include <QThread>
#include "MyFile.h"

class ThreadCheckGameIsOpen : public QThread
{
    Q_OBJECT

public:
    ThreadCheckGameIsOpen(QObject *parent);
    ~ThreadCheckGameIsOpen();
    void stop();
    bool getStopped();
    void startReady();

protected:
    void run();

private:
    volatile bool stopped;

    MyFile myFile;
    bool isGameOn;

signals:
    void returnResult(QString msg);
};

#endif // THREADCHECKGAMEISOPEN_H
