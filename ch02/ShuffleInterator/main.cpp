#include <QCoreApplication>

#include "ShuffleIterator.h"
#include <QVector>
#include <QDebug>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    QVector<int>    deck;
    for (int i = 1; i <= 52; ++i)   /// fill the deck with 1..52
    {
        deck << i;
    }

    ShuffleIterator<int>    iter(&deck);

    // get 4 different shuffles of the deck
    for (int i = 0; i < 4; ++i)
    {
        QVector<int> res;
        iter.Reshuffle();
        while (iter.hasNext())
        {
            res << iter.currentItem();
            iter.next();
        }
        qDebug() << res;
    }

    return 0;
}
