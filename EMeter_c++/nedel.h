#ifndef NEDEL_H
#define NEDEL_H

#include <QObject>
#include <QWidget>
#include <QObject>
#include <QGraphicsItem>
#include "inedel.h"
#include "skaladimention.h"


class Nedel : public QObject, public QGraphicsItem, public INedel, SkalaDimention
{
    Q_OBJECT
public:
    explicit Nedel(QGraphicsItem *parent = NULL);
    virtual void setTickAbsulut(double tick) override;
protected:
    // Inherited from QGraphicsItem
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);


signals:

private:
    double m_NedelPos = 0.0;
    QWidget * m_widget = NULL;
};

#endif // NEDEL_H
