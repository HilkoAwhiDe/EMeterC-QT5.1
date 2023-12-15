#include "ITaValueSubject.h"


void ITaValueSubject::addObserver(ITaValueObserver * obj)
{
    if (obj != NULL && -1 == m_list.indexOf(obj) )
    {
            m_list.append(obj);
    }
}
void ITaValueSubject::removeObserver(ITaValueObserver * obj)
{
    int i = m_list.indexOf(obj);
    if (-1 != i )
    {
            m_list.removeAt(i);
    }

}

void ITaValueSubject::dispatch( double canValueTA)
{
//    for (QList<INedelObserver *>::Iterator iter = m_list.first(); iter <> m_list.last(); ++iter )
     for (int i = 0;  i <  m_list.count(); ++i )
    {
        m_list.at(i)->receive(canValueTA);
    }
}
