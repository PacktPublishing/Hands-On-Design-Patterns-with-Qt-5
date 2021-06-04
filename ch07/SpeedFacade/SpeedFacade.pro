QT += quick
QT += scxml
QT += positioning
#== QT += core gui widgets


CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        BlackboardFacade.cpp \
        FuelUsageCalc.cpp \
        KnowledgeSource.cpp \
        PositionSource.cpp \
        Topic.cpp \
        Vehicle.cpp \
        WeatherFetcher.cpp \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    DataDictionary.txt \
    SpeedFacade.conf \
    SpeedFacade.dia \
    SpeedFacade.pro.user \
    main.qml

STATECHARTS += \
    CruiseControlStateMachine.scxml \
    WeatherFetchigStateMachine.scxml

HEADERS += \
    BlackboardFacade.h \
    FuelUsageCalc.h \
    KnowledgeSource.h \
    KnowledgeSourceFactory.h \
    PositionSource.h \
    PropertyClassTemplates.h \
    Topic.h \
    Vehicle.h \
    WeatherFetcher.h
