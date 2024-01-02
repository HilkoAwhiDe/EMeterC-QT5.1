#include <QtNetwork>

#include "tcpsource.h"


TcpSource::TcpSource(const QString& host, int port )
    : m_hostName(host)
    , m_nPort(port)
{
}

void TcpSource::init()
{
    m_pclientSocket = new QTcpSocket(this);
    connect(m_pclientSocket, &QTcpSocket::readyRead,
            this, &TcpSource::send);


}
void TcpSource::start()
{
    m_pclientSocket->connectToHost(m_hostName, 80);
    if ( m_pclientSocket->waitForConnected() )
    {
        m_pclientSocket->write("Start");
    }


}
void TcpSource::stop()
{
    m_pclientSocket->close();


}

void TcpSource::send()
{
    double dVal = 0.0;
    if(m_pclientSocket->state() == QAbstractSocket::ConnectedState)
    {
        if (m_pclientSocket->waitForReadyRead() && m_pclientSocket->bytesAvailable() >= 4)
        {
            QByteArray ar = m_pclientSocket->readAll().constData();
            const char * pIn = ar.constData();

            //qDebug() << strlen(szLine);
            if (strlen(szLine) > 3)
            {
                qDebug() << pIn;
                dVal = atof(pIn);
                dispatch( dVal );
            }
        }
    }
}
