import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.6

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Label {
        id: hello
        x: 32
        y: 184
        color: "orange"
        text: qsTr("Hello World!")
    }
}

/*##^##
Designer {
    D{i:1;anchors_x:84;anchors_y:227}
}
##^##*/
