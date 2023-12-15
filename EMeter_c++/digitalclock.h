#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QLCDNumber >
#include <QObject>

class DigitalClock : public QLCDNumber
{
    Q_OBJECT

public:
    DigitalClock(QWidget *parent = nullptr);

private slots:
    void showTime();
};

#endif // DIGITALCLOCK_H
