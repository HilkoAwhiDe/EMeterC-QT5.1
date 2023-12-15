#ifndef SKALA_H
#define SKALA_H
#include <QGraphicsView>
#include "inedel.h"

class Nedel;

class Skala  : public QGraphicsView
{
public:
    Skala(QWidget *parent = nullptr);

    INedel * nedel();

private:
    QGraphicsScene * mp_scene;
    Nedel * m_nedel;

};

#endif // SKALA_H
