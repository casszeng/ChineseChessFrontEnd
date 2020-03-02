import QtQuick 2.0
import "ChessPiecePaintManager.js" as ChessPiecePaintManager

Item{
    //Background Image
    Image
    {
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
            onPressed:
            {
                ChessPiecePaintManager.initialization();
                startbutton.source = "qrc:/startButton/Images/clickedStartbutton.png"
            }
            onReleased:
            {
                 startbutton.source = "qrc:/startButton/Images/start-button.png"
            }
        }
    }

    Item
    {
        id: game
        width: height * 0.95
        height: parent.height
        anchors.left: parent.left
        property int chosenRoll: -1
        property int chosenColumn: -1
        Board{
            anchors.fill: parent
        }

        function movePiece(fromRoll, fromColumn, toRoll, toColumn)
        {
            ChessPiecePaintManager.movePiece(fromRoll, fromColumn, toRoll, toColumn);
        }
    }
}
