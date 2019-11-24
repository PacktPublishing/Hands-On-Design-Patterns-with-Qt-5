#ifndef SHUFFLEITERATOR_H
#define SHUFFLEITERATOR_H

#endif // SHUFFLEITERATOR_H

#include <QBitArray>
#include <QVector>

template <class T>
class ShuffleIterator
{
public:
    ShuffleIterator(QVector<T> *deck);

    void Reshuffle();

    void first()        {Reshuffle();}
    void next();
    bool hasNext() const;
    T currentItem() const;

private:
    QVector<T>      *m_deck;
    int             m_decksize;
    QVector<bool>   m_used;
    int             m_pos;
    int             m_count;
};


template<class T>
ShuffleIterator<T>::ShuffleIterator(QVector<T> *deck)
    : m_deck(deck)
{
    m_decksize = deck->count();
    Reshuffle();
}

template<class T>
void ShuffleIterator<T>::Reshuffle()
{
    m_used.fill(false, m_decksize);
    m_count = 0;
    next();
}

template<class T>
void ShuffleIterator<T>::next()
{
    ++m_count;      // used one more item
    do {
        m_pos = qrand() % m_decksize;
    } while (m_used[m_pos] == true);
}

template<class T>
bool ShuffleIterator<T>::hasNext() const
{
    return (m_count < m_decksize);
}

template<class T>
T ShuffleIterator<T>::currentItem() const
{
    return m_deck->at(m_pos);
}
