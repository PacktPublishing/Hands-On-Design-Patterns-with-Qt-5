import QtQuick 2.15
import QtQuick.Window 2.15


Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("QML (JS) Promise Chaining Example")

    property int score : 25;

    Text {
        id: scoreText
        x: 6
        y: 21
        width: 84
        height: 35
        color: (score < 0 ) ? "red" : ((score < 5) ? "orange" : "green")
        text: score
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        font.italic: true
        font.bold: true
    }

    Text {
        id: scoreLabel
        x: 20
        y: 46
        text: qsTr("Score")
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 16
    }

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
                console.log("Passed : " + message);
                resultText.text = "Yeah! " + message;
            }

            // (3) Method to execute if it is rejected
            function failed(message) {
                console.log("Failed : " + message);
                resultText.text = "Boo! " + message;
            }

            // ** Score handling methods **
            // (4) Reward passing by adding to score
            function rewardPassed() {
                score += 10;
                console.log("rewardPassed : " + score);
            }

            // (5) Deduct 1 from score for trying
            function deductTry() {
                score -= 1;
                console.log("deductTry : " + score);
            }

            // (6) Deduct 2 for getting the wrong value
            function deductFail() {
                score -= 2;
                console.log("deductFail : " + score);
            }

            // (7) What to do when the button is clicked
            onClicked: {
                console.log("--- Guessing ---")
                // (8) The cost of playing
                deductTry();

                // (9) Try 'myPromise' and then act appropriately
                myPromise(Math.round(Math.random() * 10) % 5)
                        .then(passed).then(rewardPassed)
                        .catch(function(message) {failed(message); deductFail()})
                        ;
            }
        }
    }
}
