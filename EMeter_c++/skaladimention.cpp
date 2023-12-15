#include "skaladimention.h"

SkalaDimention::SkalaDimention()
    : m_rect(QPointF( 0, 0), QPointF(760,475))
{


}
QRectF SkalaDimention::sk_rect() const
{
    return m_rect;
}

double SkalaDimention::winkelRatio()
{
    return 101.5 / 40.0;

}
