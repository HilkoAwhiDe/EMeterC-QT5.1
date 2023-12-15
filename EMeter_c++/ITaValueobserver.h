#ifndef INEDELOBSERVER_H
#define INEDELOBSERVER_H


class ITaValueObserver
{
public:
    virtual void receive(double canTaValue) = 0;
};

#endif // INEDELOBSERVER_H
