import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Extras 1.4

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("SpeedFacade")

    property QtObject blackboardFacade: theBlackboardFacade

    property double speed:    blackboardFacade.speed.data
    property double throttle: blackboardFacade.throttle.data
    property double distance: blackboardFacade.distance.data
    property double heading:  blackboardFacade.heading.data

    Label {
        id: odometer
        height: 48
        anchors.left: speedometer.left
        anchors.right: speedometer.right
        anchors.top: speedometer.bottom
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 36
        font.family: "Verdana"
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.topMargin: 0

        text: distance.toFixed(1)
    }

    CircularGauge {
        id: speedometer
        x: 197
        y: 64
        anchors.horizontalCenter: parent.horizontalCenter
        minimumValue: 0
        maximumValue: 200
        value: speed
    }

    Slider {
        id: throttleControl
        x: 574
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: throttleValue.top
        anchors.rightMargin: 20
        anchors.bottomMargin: 0
        anchors.topMargin: 20
        orientation: Qt.Vertical
        stepSize: 0.01
        from: -1
        value: 0

        onMoved: {
            blackboardFacade.update("throttle", throttleControl.value)
        }
    }

    Label {
        id: throttleValue
        x: 590
        y: 463
        height: 30
        text: throttle.toFixed(2)
        anchors.bottom: parent.bottom
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignBottom
        anchors.bottomMargin: 20
        anchors.horizontalCenter: throttleControl.horizontalCenter
        font.pointSize: 16
    }
}
