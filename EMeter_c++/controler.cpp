#include "controler.h"
#include "calculator.h"
#include "ITaValueSubject.h"
#include "filesource.h"
#include "tcpsource.h"

 Controler::Controler(QObject *parent) : QObject(parent)
{

}

Controler::Controler( QLCDNumber* TA, QLCDNumber* TAConter
          , QDial* sense, QLCDNumber* lcdSense ,INedel* nadel
, QPushButton * countEin_Aus, QPushButton * countA_M
, QPushButton * set_1, QPushButton * set_2
, QPushButton * onOff, QPushButton * balNedel, QObject *parent )
    : m_TA(TA), m_TAConter(TAConter), m_sense(sense), m_nadel(nadel), m_countEin_Aus(countEin_Aus), m_countA_M(countA_M)
    , m_set_1(set_1),  m_set_2(set_2), m_onOff(onOff), m_balNedel(balNedel), QObject(parent)
{
    createSource( sTCPIP);
    m_messSource->addObserver(this);
    m_messSource->init();
    calc = new Calculator();
    ta = 0.0;
    ticks = 0.0;
    m_nadel->setTickAbsulut(-2);
    m_TA->setEnabled(false);
    connect(sense, SIGNAL(valueChanged(int)), lcdSense, SLOT(display(int)));

    connect(m_onOff, &QPushButton::clicked, this, &Controler::onOff);

    connect(m_countEin_Aus, &QPushButton::clicked, this, &Controler::countOnOff);
    connect(m_countA_M, &QPushButton::clicked, this, &Controler::countType);
    connect(m_balNedel, &QPushButton::clicked, this, &Controler::countOnNedelBal);


    connect(m_set_1, &QPushButton::clicked, this, &Controler::balance);
    connect(m_set_2, &QPushButton::clicked, this, &Controler::balance);

}
Controler::~Controler()
{
    m_messSource->stop();
    m_messSource->removeObserver(this);
}


void Controler::receive(double canTaValue)
{
    if (ta == 0.0)
    {
        ta = canTaValue;
        displayTA(ta);
        displayNedel(ta, ta);
    } else
    {
        displayNedel(ta, canTaValue);
    }
    taCurrent = canTaValue;

}

void Controler::displayNedel(const double& TA, const double& canTaValue)
{
    if (OnOff && bCountOnOff){
        if (countTypeNedel)
        {
            if (canTaValue < taCurrent)
            {
                double c = counterVal;
                c = c + (taCurrent - canTaValue);
                QString strValue = QString::number(c, 'f', 1);
                m_TAConter->display(strValue);
                counterVal = c;
            }

        }
    }

    double delta = TA - canTaValue;
    m_nadel->setTickAbsulut(15 + calc->deltaTaToTicks(m_sense->value() ,delta) );
}


void Controler::displayTA(const double& TA)
{
    QString strValue = QString::number(TA, 'f', 2);
    m_TA->display(strValue);
}

void Controler::onOff(bool )
{
    if (!OnOff)
    {
        m_onOff->setText(tr("Off"));
        OnOff = true;
        m_nadel->setTickAbsulut(0);
        m_messSource->start();
    } else
    {
        m_onOff->setText(tr("On"));
        OnOff = false;
        m_messSource->stop();
        displayTA(0.0);
        m_TAConter->display(0.0);
        counterVal = 0.0;
        ta = 0.0;
        m_nadel->setTickAbsulut(-2);
        bCountOnOff = false;
        m_countEin_Aus->setText(tr("Off"));
    }
    m_TA->setEnabled(OnOff);
}

void Controler::balance()
{
    if (OnOff ){
        if (bCountOnOff){
            if (!countTypeNedel)
            {
                if (taCurrent < ta)
                {
                    double c = m_TAConter->value();
                    c = c + ta -  taCurrent;
                    m_TAConter->display(c);
                }

            }
        }

        ta = taCurrent;
        displayTA(ta);
    }
}

void Controler::countOnOff()
{
    if (OnOff){
        if (!bCountOnOff)
        {
            m_countEin_Aus->setText(tr("On"));
            bCountOnOff = true;
        } else
        {
            m_countEin_Aus->setText(tr("Off"));
            bCountOnOff = false;
        }
    }
 }

void Controler::countType()
{
    if (!countAuto)
    {
        m_countA_M->setText(tr("Auto"));
        countAuto = true;
    } else
    {
        m_countA_M->setText(tr("Manuel"));
        countAuto = false;
    }

}
void Controler::countOnNedelBal()
{
    if (!countTypeNedel)
    {
        m_balNedel->setText(tr("Nedel"));
        countTypeNedel = true;
    } else
    {
        m_balNedel->setText(tr("Balance"));
        countTypeNedel = false;
    }

}

void Controler::createSource(eSOURCE_TYPE type)
{
    switch (type) {
    case sFILE:
        m_messSource = new FileSource();

        break;
    case sBLUETOOTHS:

        break;
    case sTCPIP:
        m_messSource = new TcpSource("dose1",80);

        break;
    default:
        break;
    }

}
