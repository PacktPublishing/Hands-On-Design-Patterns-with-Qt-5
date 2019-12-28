#ifndef MILEAGEDISPLAY_H
#define MILEAGEDISPLAY_H

#include "KnowledgeSource.h"
#include <QWidget>

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

    enum Modes {Overall, PerSec};
    Q_ENUM(Modes)

private slots:
    void nextMode();

protected:
    // void postUpdate(Topic a_topic) final;

private:
    Ui::FuelUsageDisp *ui;

    Modes   m_mode;
};

#endif // MILEAGEDISPLAY_H
