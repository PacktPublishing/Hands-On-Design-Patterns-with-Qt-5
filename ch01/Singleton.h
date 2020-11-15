#ifndef SINGLETON_H
#define SINGLETON_H

class Data {
    // nothing to see here
};

class Singleton {
public:
    static Singleton *Instance();
    Singleton(const Singleton &right) = delete;
    Singleton & operator=(const Singleton &right) = delete;

    Data data();
    void setData(Data &data);

private:
    Singleton();

    static Singleton *m_instance;
    Data              m_data;
};

#endif // SINGLETON_H
