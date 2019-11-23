import QtQuick 2.0

Item {
    id: element
    visible: true
    BorderImage {
        id: borderImage
        x: 143
        y: 104
        width: 389
        height: 293
        clip: false
        verticalTileMode: BorderImage.Stretch
        horizontalTileMode: BorderImage.Stretch
        border.bottom: 10
        border.top: 10
        border.right: 10
        border.left: 10
        source: "43183511045_46fa6859b8_c.jpg"
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1;anchors_height:238;anchors_width:324;anchors_x:143;anchors_y:104}
}
##^##*/
