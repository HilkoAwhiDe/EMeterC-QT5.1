#include <QtGui>

#include <QTime>
#include <QPen>
#include "QRect"
#include "QPainter"
#include <QString>
#include "nedel.h"

#define SKALA 360.0

Nedel::Nedel(QGraphicsItem *parent)
    : QGraphicsItem(parent)
    , m_NedelPos (0.0)
{

}

QRectF Nedel::boundingRect() const
{
    return sk_rect();
}

void Nedel::setTickAbsulut(double tick)
{
    m_NedelPos = tick;
    if (m_widget != NULL)
        m_widget->update();
}


void Nedel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget * widget)
//void Nedel::paintEvent(QPaintEvent *pe)
{
    //Q_UNUSED(widget);
    Q_UNUSED(option);
    m_widget = widget;
    //QPainter painter(this);
    QRectF frame( sk_rect());
  QPainter* p  = painter;
  if (p == NULL)
      return;
  static const QPoint nedlGrafic[3] = {
      QPoint(2, -338),
      QPoint(-2, -338),
      QPoint(0, -395)
  };
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
  if (painter == NULL)
      return;

  QColor nedelColor(Qt::black);
  p->setRenderHint(QPainter::Antialiasing);
  p->save();

  const double winkel_tick = winkelRatio(); // drehwinkel

    p->fillRect(frame, Qt::transparent);

    double tx =frame.width()/2;
    double ty = frame.height();
     p->resetTransform();

   //p->translate(tx  , ty);

  int side = qMin(frame.width(), frame.height());
  //p->scale(side / side, side / side);



  {


    p->translate(tx  , ty);
    //  p->rotate(270.0 + 75); set
    //  p->rotate(270.0 + 30); anschlag links
      //  p->rotate(270.0 + 38.5); Rise ende
        //p->rotate(270.0 + 270.0 + 38.5 + 101.5); //Fall ende
    p->rotate( 270.0 + 38.5 + (m_NedelPos * winkel_tick));

      p->setPen(Qt::NoPen);
      p->setBrush(nedelColor);


    //  p->rotate(270.0 + 75); set
    //  p->rotate(270.0 + 30); anschlag links
      //  p->rotate(270.0 + 38.5); Rise ende
        //p->rotate(wk); //Fall ende
      p->drawConvexPolygon(nedlGrafic, 3);
      //QString T = QString::number(m_NedelPos);
      p->setPen(Qt::SolidLine);
      //p->drawText(QPoint(-1, -320), T);
      p->translate(-tx  , -ty);
  }

    p->restore();

}
