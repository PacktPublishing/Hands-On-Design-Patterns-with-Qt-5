#ifndef SIGNALLER_H
#define SIGNALLER_H

#include "Person.h"

#include <QObject>
#include <QDateTime>

class Signaler : public QObject
{
    Q_OBJECT

public:
    explicit Signaler(QObject *parent = nullptr);

    void SendSimpleSignal();    ///< (1) Send the SimpleSignal
    void SendIntSignal();       ///< (2) Send the IntSignal
    void SendPerson();          ///< (3) Send a PersonSignal

signals:                        //   (4) Start the signals section
    void SimpleSignal();        ///< (5) A simple signal with no data
    void IntSignal(int v);      ///< (6) A signal that contains an int
    void PersonSignal(Person p);///< (7) A signal that sends a person

public slots:                   //   (8) Start the public slot section
    void CatchSimpleSignal();   ///< (9) A Slot to handle SimpleSignal
    void CatchIntSignal(int v); ///< (10) A Slot to handle SendIntSignal
    void CatchPerson(Person p); ///< (11) A Slot to handle PersonSignal

    void DoSendSignals();       ///< (12) Used to send signals
};

#endif // SIGNALLER_H
