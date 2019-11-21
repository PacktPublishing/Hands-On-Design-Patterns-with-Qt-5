import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.6

Window {                            // (1) define the window
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Label {                         // (2) define the Label in window
        id: hello
        x: 32
        y: 184
        color: "#0800ff"            // (3) blue by rgb code
        text: qsTr("Hello World!")  // (3) translatable text
    }
}

/*##^##
Designer {
    D{i:1;anchors_x:84;anchors_y:227}
}
##^##*/
