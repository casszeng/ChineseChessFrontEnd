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
                gamePlay.init();
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
        property int side: 0

        Board{
            anchors.fill: parent
        }

        function highlightChosen(chosenRoll, chosenColumn)
        {
            ChessPiecePaintManager.highlightChosen(chosenRoll, chosenColumn);
        }

        function movePiece(fromRoll, fromColumn, toRoll, toColumn)
        {
            if(gamePlay.checkMove(game.side, fromRoll, fromColumn, toRoll, toColumn))
            {
                ChessPiecePaintManager.movePiece(fromRoll, fromColumn, toRoll, toColumn);
                if(gamePlay.checkWin(0))
                {
                    gamePlay.init();
                    ChessPiecePaintManager.initialization();
                }
                else
                {
                    ChessPiecePaintManager.movePiecebyIndex(computer.moveFrom(gamePlay), computer.moveTo(gamePlay));
                    if(gamePlay.checkWin(1))
                    {
                        gamePlay.init();
                        ChessPiecePaintManager.initialization();
                    }
                }
                return true;

            }
            else
            {
                return false;
            }
        }
    }
}
