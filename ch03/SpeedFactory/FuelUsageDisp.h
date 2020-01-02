#ifndef MILEAGEDISPLAY_H
#define MILEAGEDISPLAY_H

#include "KnowledgeSource.h"
#include <QWidget>

class QScxmlStateMachine;

QT_BEGIN_NAMESPACE
namespace Ui { class FuelUsageDisp; }
QT_END_NAMESPACE

class FuelUsageDisp : public QWidget, public KnowledgeSource
{
    Q_OBJECT

public:
    FuelUsageDisp(QWidget *parent);
    ~FuelUsageDisp() = default;

    void setBlackboard(Blackboard *a_blackboard) final;
    void act(Topic a_topic) final;


    QScxmlStateMachine *modeSM() const;
    void setModeSM(QScxmlStateMachine *modeSM);

public slots:
    void updateMode();
private slots:
    void nextMode();

protected:
    // void postUpdate(Topic a_topic) final;

private:
    Ui::FuelUsageDisp   *ui;

    QScxmlStateMachine  *m_modeSM;  ///< (1) mode state machine

    double  m_perSec;
    double  m_perDist;
    double  m_total;
    double  m_perFuel;
};

#endif // MILEAGEDISPLAY_H
