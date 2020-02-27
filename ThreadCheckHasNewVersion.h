#ifndef THREADCHECKHASNEWVERSION_H
#define THREADCHECKHASNEWVERSION_H

#include <QThread>
#include "MyFile.h"
#include "MyNetwork.h"
#include <QSettings>

class ThreadCheckHasNewVersion : public QThread
{
    Q_OBJECT

public:
    ThreadCheckHasNewVersion(QObject *parent,double version);
    ~ThreadCheckHasNewVersion();
    void stop();
    bool getStopped();
    void startReady();

protected:
    void run();

private:
    volatile bool stopped;

    MyFile myFile;
    MyNetwork myNetwork;

    double version;

signals:
    void returnResult(bool msg,QStringList msg2);
};

#endif // THREADCHECKHASNEWVERSION_H
