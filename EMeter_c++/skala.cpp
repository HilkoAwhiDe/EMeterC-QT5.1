#include "skala.h"
#include <QObject>
#include <QGraphicsItem>
#include "nedel.h"
#include "skaladimention.h"

class SKBackGround : public QGraphicsItem, public SkalaDimention
{
public:
    explicit SKBackGround(QGraphicsItem *parent = NULL);

protected:
    // Inherited from QGraphicsItem
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);


};


SKBackGround::SKBackGround(QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
}
QRectF SKBackGround::boundingRect() const
{
    return sk_rect();
}


void SKBackGround::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget * )
{
    //QPainter painter(this);
    QRectF frame( sk_rect());
    QPainter* p  = painter;
    if (p == NULL)
        return;
    const double pix_tick = winkelRatio(); // drehwinkel

    static const QPoint tick[4] = {
        QPoint(4, -355),
        QPoint(-4, -355),
        QPoint(0, -355),
        QPoint(0, -365)
    };
    static const QPoint ltick[4] = {
        QPoint(4, -355),
        QPoint(0, -355),
        QPoint(0, -355),
        QPoint(0, -365)
    };
    static const QPoint rtick[4] = {
        QPoint(-4, -355),
        QPoint(0, -355),
        QPoint(0, -355),
        QPoint(0, -365)
    };

    static const QPoint recLine[2] = {
        QPoint(0, -382),
        QPoint(0, -415)
    };

    if (painter == NULL)
        return;

    p->setRenderHint(QPainter::Antialiasing);
    p->save();

    p->fillRect(frame, Qt::transparent);


    double tx =frame.width()/2;
    double ty = frame.height();
    p->resetTransform();

    int side = qMin(frame.width(), frame.height());
    //p->scale(side / side, side / side);

    {
        p->setPen(Qt::SolidLine);

        // Oben
        QRectF rectangle2( 0, 0, frame.width(), frame.height()*1.4 );
        int startAngle2 = (34.1) * 16;
        int spanAngle2 = (114.2) * 16;

        rectangle2.moveTo(0,60);// oben
        p->drawArc(rectangle2, startAngle2, spanAngle2);

        // Unten
        QRectF rectangle( 0, 0, frame.width(), frame.height()*1.578 );
        int startAngle = (39.9) * 16;
        int spanAngle = (101.47) * 16;
        //p->fillRect(rectangle, Qt::green);

        rectangle.moveTo(0,96); // unten
        p->drawArc(rectangle, startAngle, spanAngle);


    }

    {
        p->setPen(Qt::SolidLine);
        p->translate(tx  , ty);

        p->rotate( 270);

        p->rotate( 38.5);


        for (int j = 0; j < 41; ++j) {
            {
                switch(j)
                {
                case 28:
                    p->drawText(QPoint(-27, -395), "FALL");
                    p->setPen(Qt::DotLine);
                    p->drawPolyline(recLine,2);
                    p->setPen(Qt::SolidLine);
                    break;
                case 15:
                    p->drawText(QPoint(-26, -395), "--- SET ---");
                    p->setPen(Qt::DotLine);
                    p->drawPolyline(recLine,2);
                    p->setPen(Qt::SolidLine);
                    break;
                case 16:
                case 14:
                    break;
                case 6:
                    p->drawText(QPoint(-17, -395), "RAISE");
                    p->setPen(Qt::NoPen);
                    //p->drawPolyline(recLine,2);
                    p->setPen(Qt::SolidLine);
                    break;
                default:
                    if ( j%2 == 0  )
                    {
                        p->drawPolyline(recLine,2);
                    }
                    break;
                }
            }
            //QString T = QString::number(j);
            switch(j)
            {
            case 0:
                p->drawPolyline(ltick, 4);
                break;
            case 40:
                p->drawPolyline(rtick, 4);
                break;
            default:
                p->drawPolyline(tick, 4);
                break;
            }
          //  p->drawText(QPoint(0, -380), T);
            p->rotate(  pix_tick );
        }
        p->translate(-tx  , -ty);

    }
    p->restore();

}


Skala::Skala(QWidget *parent)
    :QGraphicsView(parent)
    , m_nedel(new Nedel(NULL))
{
    //this->setBackgroundBrush(Qt::lightGray);
    mp_scene       = new QGraphicsScene(this->rect(), this );
    this->setScene(mp_scene);
    SKBackGround* bk = new SKBackGround(NULL);
    bk->setZValue(1);
    mp_scene->addItem(bk);
    m_nedel->setZValue(2);
    mp_scene->addItem(m_nedel);


}

INedel * Skala::nedel()
{
    return m_nedel;
}

