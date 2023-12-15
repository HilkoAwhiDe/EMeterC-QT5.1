#ifndef TcpSource_H
#define TcpSource_H

#include "ITaValueSubject.h"
#include <QObject>

class QTcpSocket;

class TcpSource : public QObject, public ITaValueSubject
{
    Q_OBJECT
public:
    TcpSource(const QString& host, int port = 80);
    virtual void init() override;
    virtual void start() override;
    virtual void stop() override;

public Q_SLOTS:
    void send();

private:
    QString m_hostName;
	int    m_nPort;
    QTcpSocket * m_pclientSocket;


};

#endif // TcpSource_H
