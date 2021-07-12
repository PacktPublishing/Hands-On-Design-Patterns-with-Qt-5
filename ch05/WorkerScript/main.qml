import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15


Window {
    width: 400
    height: 120
    visible: true
    title: qsTr("WorkerScript Example")

    property int resultValue: 0

    Button {
        id: button
        x: 40
        y: 50
        width: 120
        height: 30
        text: qsTr("Button")
        state: "ready"

        onClicked: {
            myWorker.sendMessage("doCalc1")
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
            },
            State {
                name: "done"
                PropertyChanges {
                    target: button
                    text: "Done"
                }
                PropertyChanges {
                    target: resultBox
                    text: resultValue
                }
            }
        ]
    }

    Text {
        id: resultBox
        x: 200
        y: 50
        width: 160
        height: 30
        text: "---"
        font.pixelSize: 12
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    WorkerScript {
        id: myWorker
        source: "CalcWorker.mjs"

        onMessage: ( workerMessage ) => {
            if (workerMessage.newState !== undefined) {
                button.state = workerMessage.newState
            }
            if (workerMessage.newText !== undefined) {
                resultBox.text = workerMessage.newText
            }
            if (workerMessage.result !== undefined) {
                resultValue = workerMessage.result
            }
        }
    }
}
