import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4

Window {
    visible: true
    width: height * 1.2
    height: 800
    title: qsTr("象棋")

    Game
    {
        anchors.fill: parent
    }
}
