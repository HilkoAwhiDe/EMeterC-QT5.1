#include "filesource.h"
#include <QTimer>

FileSource::FileSource()
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &FileSource::send);
}

void FileSource::init()
{
    double t2 = 0.5;
    double ta2 = 2.0;
    int punkte = 44;

    taList.clear();
    taList.append(ta2); // set Posion
    // Fall
    for (int i = 1; i  < punkte; ++i)
    {
        taList.append(ta2 - t2/10*i);
    }

    for (int i = punkte - 1; i  > -1; --i)
    {
        taList.append(ta2 - t2/10*i);
    }

    // Rise
    for (int i = 1; i  < punkte; ++i)
    {
        taList.append(ta2 + t2/10*i);
    }

    for (int i = punkte - 1; i  > -1; --i)
    {
        taList.append(ta2 + t2/10*i);
    }


    //    ohmList.append(4629.629629);// 2 Ticks by sense 1 delta 370,370
                                // periode ein tick entspricht 185.185 Ohm 40 Ticks == 1,6 TA 1T == 0,04 TA
    //ohmList.append(5000.0); // set Posion

    //ohmList.append(5000.0 + 370.370); // set Posion

    //ohmList.append(4746.19289);// 5 Ticks by sense 40 delta 253,807
                                // periode ein tick entspricht 50.761 Ohm
}
void FileSource::start()
{
    sendIndex = 0;
    timer->start(20);


}
void FileSource::stop()
{
    timer->stop();


}

void FileSource::send()
{
    dispatch( taList.at(sendIndex));
    sendIndex = (sendIndex + 1)%taList.count();

}
