#ifndef CONTROLER_H
#define CONTROLER_H

#include <QObject>
#include <QtWidgets/QDial>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <digitalclock.h>
#include "inedel.h"
#include "ITaValueObserver.h"

class ITaValueSubject;
class Calculator;

class Controler : public QObject, public ITaValueObserver
{
    Q_OBJECT
public:
    explicit Controler(QObject *parent = nullptr);
    Controler( QLCDNumber* TA, QLCDNumber* TAConter
              , QDial* sense, QLCDNumber* lcdSense ,INedel* nadel
    , QPushButton * countEin_Aus, QPushButton * countA_M
    , QPushButton * set_1, QPushButton * set_2
    , QPushButton * onOff, QPushButton * balNedel, QObject *parent = nullptr );
    virtual ~Controler();

    virtual void receive(double canTaValue) override;
    enum eSOURCE_TYPE {
        sFILE =1,
        sBLUETOOTHS = 2,
        sTCPIP = 3

    };


private Q_SLOTS:
    void onOff(bool onOff);
    void balance();
    void countOnOff();
    void countType();
    void countOnNedelBal();

private:
    void displayNedel(const double& TA, const double& canTaValue);
    void displayTA(const double& TA);

    void createSource(eSOURCE_TYPE type);

private:
    QLCDNumber*   m_TA;
    QLCDNumber*   m_TAConter;
    QDial*        m_sense;
    INedel*       m_nadel;
    QPushButton * m_countEin_Aus;
    QPushButton * m_countA_M;
    QPushButton * m_set_1;
    QPushButton * m_set_2;
    QPushButton * m_onOff;
    QPushButton * m_balNedel;
    ITaValueSubject * m_messSource;
    Calculator * calc;
    double ta = 0.0;
    double taCurrent = 0.0;
    double ticks = 0.0;
    double counterVal = 0.0;
    bool OnOff = false;
    bool bCountOnOff = false;
    bool countAuto = true;
    bool countTypeNedel = true;


};

#endif // CONTROLER_H
