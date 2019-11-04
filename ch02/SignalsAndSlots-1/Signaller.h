#ifndef SIGNALLER_H
#define SIGNALLER_H

#include <QObject>

class Signaller : public QObject
{
    Q_OBJECT
public:
    explicit Signaller(QObject *parent = nullptr);

    void SendSimpleSignal();    ///< (1) Send a simple signal

signals:                        //   (2) Start the signals section
    void SimpleSignal();        ///< (3) A simple Signal with no data

public slots:                   //   (4) Start the public slot section
    void CatchSimpleSignal();   ///< (5) A Slot to handle SimpleSignal
};

#endif // SIGNALLER_H
