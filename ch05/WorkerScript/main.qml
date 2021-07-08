import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Item {
        id: anItem

        property int resultValue: 0

        Button {
            id: button
            x: 177
            y: 179
            text: qsTr("Button")

            onClicked: {
                myWorker.sendMessage("doCalc1")
            }
        }

        states: [
            State {
                name: "ready"
                PropertyChanges {
                    target: button
                    text: "Ready"
                }
            },
            State {
                name: "running"
                PropertyChanges {
                    target: button
                    text: "Running"
                }
                PropertyChanges {
                    target: resultBox
                    text: "---"
                }
            },
            State {
                name: "done"
                PropertyChanges {
                    target: button
                    text: "Done"
                }
                PropertyChanges {
                    target: resultBox
                    text: anItem.resultValue
                }
            }
        ]

    }

    Text {
        id: resultBox
        x: 324
        y: 193
        text: "---"
        font.pixelSize: 12
    }


    WorkerScript {
        id: myWorker
        source: "CalcWorker.mjs"

        onMessage: ( workerMessage ) => {
                       if (workerMessage.newState !== undefined) {
                           anItem.state = workerMessage.newState
                       }
                       if (workerMessage.newText !== undefined) {
                           resultBox.text = workerMessage.newText
                       }
                       if (workerMessage.result !== undefined) {
                           anItem.resultValue = workerMessage.result
                       }
                   }
    }


}
