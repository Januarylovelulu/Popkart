#ifndef THREAD_H
#define THREAD_H

#ifdef _MSC_VER
#pragma execution_character_set("utf-8")

#include <QObject>
#include <QThread>
#include <QKeyEvent>
#include <QCoreApplication>

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread();
    void setRun(bool run=false);

protected:
    void run();

signals:

public slots:

private:
    bool isRun;
};

#endif // THREAD_H
#endif
