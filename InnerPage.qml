import QtQuick 2.0
import QtQuick 2.9
import QtQuick.Controls 1.1

Item {
    id: rootId
    height: 600
    width: 800
    signal openMenu(int x,int y)
    Text {
        anchors.centerIn: parent
        text: "Hello World!"
        font.pointSize: 30
        color: "red"
    }
    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            if (mouse.button === Qt.RightButton)
            {
                var pos = mapToGlobal(mouse.x, mouse.y)
                rootId.openMenu(pos.x , pos.y)
            }
        }
    }
}

