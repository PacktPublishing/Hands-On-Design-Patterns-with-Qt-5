#ifndef SINGLETON_H
#define SINGLETON_H


class Singleton
{
public:
    Singleton *Instance();
    Singleton(const Singleton& right) = delete;

private:
    Singleton() = default;

    static Singleton *m_instance;
};

#endif // SINGLETON_H
