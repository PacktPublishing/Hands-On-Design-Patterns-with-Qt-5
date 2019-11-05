#ifndef SIGNALLER_H
#define SIGNALLER_H

#include <QObject>
#include <QDateTime>

class Signaler : public QObject
{
    Q_OBJECT
public:
    explicit Signaler(QObject *parent = nullptr);

    void SendSimpleSignal();    ///< (1) Send the SimpleSignal
    void SendIntSignal();       ///< (2) Send the IntSignal

signals:                        //   (3) Start the signals section
    void SimpleSignal();        ///< (4) A simple signal with no data
    void IntSignal(int v);      ///< (5) A signal that contains an int

public slots:                   //   (6) Start the public slot section
    void CatchSimpleSignal();   ///< (7) A Slot to handle SimpleSignal
    void CatchIntSignal(int v); ///< (8) A Slot to handle SendIntSignal

    void DoSendSignals();       ///< (9) Used to send signals
};

#endif // SIGNALLER_H
