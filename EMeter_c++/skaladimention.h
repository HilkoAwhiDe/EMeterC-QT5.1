#ifndef SKALADIMENTION_H
#define SKALADIMENTION_H
#include <QRectF>

class SkalaDimention
{
public:
    SkalaDimention();
    QRectF sk_rect() const;
    double winkelRatio();
private:
    QRectF m_rect;
};

#endif // SKALADIMENTION_H
