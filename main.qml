import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4

Window {
    visible: true
    width: height * 1.2
    height: 800
    title: qsTr("Hello World")

    //Background Image
    Image {
        id: background
        source: "qrc:/background/Images/background.png"
        anchors.fill: parent
    }

    //Start button for starting or restart the game
    Image
    {
        id: startbutton
        width: parent.width * 0.15
        height: width

        anchors.right: parent.right

        source: "qrc:/startButton/Images/start-button.png"


        MouseArea
        {
            anchors.fill: parent
            onPressed: {
                gamePlay.initNewGame();
                game.mod = 32
                startbutton.source = "qrc:/startButton/Images/clickedStartbutton.png"
            }
            onReleased:
            {
                 startbutton.source = "qrc:/startButton/Images/start-button.png"
                game.side = 0;
            }
        }
    }

    Game
    {
        id: game
        width: height * 0.95
        height: parent.height
        anchors.left: parent.left
    }
}
