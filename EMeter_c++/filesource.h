#ifndef FILESOURCE_H
#define FILESOURCE_H

#include "ITaValueSubject.h"
#include <QObject>

class FileSource : public QObject, public ITaValueSubject
{
    Q_OBJECT
public:
    FileSource();
    virtual void init() override;
    virtual void start() override;
    virtual void stop() override;

public Q_SLOTS:
    void send();

private:
    QList<double> taList;
    QTimer *timer = NULL;
    int sendIndex = 0;



};

#endif // FILESOURCE_H
