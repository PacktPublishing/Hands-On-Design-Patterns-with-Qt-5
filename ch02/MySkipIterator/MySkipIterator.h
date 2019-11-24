#ifndef MYSKIPITERATOR_H
#define MYSKIPITERATOR_H

#include <QList>

template <class T>
class MySkipIterator : QList<T>::iterator
{
public:
    MySkipIterator(QList<T> *a_list, int skip);
    void first();
    void next();
    bool hasNext();
    T currentElement();

    int skipValue() const;
    void setSkipValue(int skipValue);

private:
    int         m_pos;          ///< Where we are in the container
    int         m_skipValue;    ///< how many to skip
    QList<T>    *m_list;        ///< the container
};

template<class T>
MySkipIterator<T>::MySkipIterator(QList<T> *a_list, int skip)
    : m_pos(0), m_skipValue(skip), m_list(a_list)
{
    // nothing to do here
}

template<class T>
void MySkipIterator<T>::first()
{
    m_pos = 0;
}

template<class T>
void MySkipIterator<T>::next()
{
    auto lsize = m_list->count();
    if (lsize > 0)
    {
        m_pos += m_skipValue;
        if (m_pos > lsize)
        {
            m_pos = lsize;
        }
    }
}

template<class T>
bool MySkipIterator<T>::hasNext()
{
    auto lsize = m_list->count();
    return (m_pos < (lsize - 1));
}

template<class T>
T MySkipIterator<T>::currentElement()
{
    T result;
    auto lsize = m_list->count();
    if (m_pos < lsize)
    {
        result = m_list->at(m_pos);
    }
    return result;
}

template<class T>
int MySkipIterator<T>::skipValue() const
{
    return m_skipValue;
}

template <class T>
void MySkipIterator<T>::setSkipValue(int skipValue)
{
    m_skipValue = skipValue;
}

#endif // MYSKIPITERATOR_H
