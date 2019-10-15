#include "Singleton.h"

Singleton *Singleton::m_instance = nullptr;

Singleton *Singleton::Instance()
{
    if (!m_instance) {
        m_instance = new Singleton();
    }
    return m_instance;
}
