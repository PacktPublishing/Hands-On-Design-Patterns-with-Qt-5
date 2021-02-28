// Event Loop Example

#include <QThread>
#include <QVector>
#include <QDebug>

void Task1();
void Task2();

int main(int argc, char *argv[])
{
    // The Event Loop never ends
    while (true) {
        Task1();
        Task2();

        // ... Add more task calls here

        // wait 1 second before looping again
        QThread::sleep(1);
    }
    return 0;
}

// Task 1
void Task1() {
    static int stepNumber = 0;

    switch(stepNumber) {
    case 0:
        qDebug() << "Task 1: Step 0";
        break;

    case 1:
        qDebug() << "Task 1: Step 1";
        break;

    case 2:
        qDebug() << "Task 1: Step 2";
        break;

    // ... add more steps in here

    default:
        // do nothing;
        break;
    }

    stepNumber = (stepNumber + 1) % 2;    // correct to number of active steps
}


// Steps for task 2
void T2_S0() { qDebug() << "Task 2: Step 0" ; }
void T2_S1() { qDebug() << "Task 2: Step 1" ; }
void T2_S2() { qDebug() << "Task 2: Step 2" ; }
void T2_S3() { qDebug() << "Task 2: Step 3" ; }

// Task 2
void Task2() {
    const QVector<std::function<void()> > taskTable {
        T2_S0,
        T2_S1,
        T2_S2,
        T2_S3,
        [] () { qDebug() << "Task 2: Step 4, A Lambda Function!";}
    };

    static int stepNumber = 0;
    taskTable[stepNumber]();

    stepNumber = (stepNumber + 1) % taskTable.count();
}
