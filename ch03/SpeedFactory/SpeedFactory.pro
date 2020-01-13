QT       += core gui widgets scxml
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Blackboard.cpp \
    DashWidget.cpp \
    FuelUsageCalc.cpp \
    FuelUsageDisp.cpp \
    HeadingIndicator.cpp \
    HeadlightSwitch.cpp \
    HighBeamIndicator.cpp \
    KnowledgeSource.cpp \
    KnowledgeSourceFactory.cpp \
    Odometer.cpp \
    Speedometer.cpp \
    Throttle.cpp \
    Vehicle.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    Blackboard.h \
    DashWidget.h \
    DashWidgetFactory.h \
    FuelUsageCalc.h \
    FuelUsageDisp.h \
    HeadingIndicator.h \
    HeadingIndicatorFactory.h \
    HeadlightSwitch.h \
    HighBeamIndicator.h \
    KnowledgeSource.h \
    KnowledgeSourceFactory.h \
    MainWindow.h \
    Odometer.h \
    Speedometer.h \
    Throttle.h \
    Topic.h \
    Vehicle.h

FORMS += \
    FuelUsageDisp.ui \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

STATECHARTS += \
    CruiseControlStateMachine.scxml \
    FuelDisplayStateMachine.scxml \
    HeadlightStateMachine.scxml
