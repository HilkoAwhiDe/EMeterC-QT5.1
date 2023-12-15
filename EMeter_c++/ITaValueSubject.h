#ifndef INEDELSUBJECT_H
#define INEDELSUBJECT_H
#include <QList>
#include "ITaValueObserver.h"

class ITaValueSubject
{
public:
    void addObserver(ITaValueObserver * obj);
    void removeObserver(ITaValueObserver * obj);
    void dispatch( double canValueTA);

    virtual void init() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
private:
    QList<ITaValueObserver *> m_list;

};

#endif // INEDELSUBJECT_H
