import QtQuick 2.15
import QtQuick.Window 2.15


Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("QML (JS) Promise Chaining Example")

    Text {
        id: resultText
        text: "Can you get the correct result?"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 26
        minimumPointSize: 36
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.bottomMargin: 0
    }

    Rectangle {
        id: rectangle
        color: "#caafff"
        radius: 20
        anchors.fill: parent
        anchors {
            topMargin: mainWindow.height * 0.25
            bottomMargin: mainWindow.height * 0.25
            leftMargin: mainWindow.width * 0.25
            rightMargin: mainWindow.width * 0.25
        }
        Text {
            id: buttonText
            anchors.fill: parent
            text: qsTr("Press Me")
            visible:true;
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 36
            minimumPointSize: 36
        }
        MouseArea {
            anchors.fill: parent

            // (1) define our Promise
            function myPromise(val) {
                return new Promise((resolve, reject) => {
                                       if (val === 2) {
                                           resolve('The correct value was entered: ' + val)
                                       } else {
                                           reject('That is not the correct value: '+ val)
                                       }
                                   })
            }

            // (2) Method to execute if it is resolved
            function passed(message) {
                resultText.text = "Yeah! " + message;
            }

            // (3) Method to execute if it is rejected
            function failed(message) {
                resultText.text = "Boo! " + message;
            }

            onClicked: {
                myPromise(Math.round(Math.random() * 10) % 5).then(passed).catch(failed);
            }
        }
    }
}
