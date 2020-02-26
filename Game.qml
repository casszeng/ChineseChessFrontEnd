import QtQuick 2.0

Item {
    id: gameP
    property int mod: 0
    property int seleted: -1
    property int side
    Board
    {
        id: gameBoard
        anchors.fill: parent

        MouseArea
        {
            anchors.fill: parent
            enabled: seleted !== -1 && pieces.itemAt(seleted).selected
            onClicked:
            {
                var bx = mouse.x - (mouse.x - gameBoard.x) % pieces.itemAt(seleted).width;
                var by = mouse.y - (mouse.y - gameBoard.y) % pieces.itemAt(seleted).height;
                backAnim.target = pieces.itemAt(seleted);
                pieces.itemAt(seleted).beginDrag = Qt.point(bx, by);
                backAnim.from = Qt.point(pieces.itemAt(seleted).x, pieces.itemAt(seleted).y);
                backAnim.to = Qt.point(pieces.itemAt(seleted).beginDrag.x, pieces.itemAt(seleted).beginDrag.y);
                backAnim.start();
                pieces.itemAt(seleted).selected = false;
                seleted = -1;
                ++gameP.side;
                gameP.side %= 2;
            }
        }
    }

    ParallelAnimation{
        id: backAnim
        property point from
        property point to
        property QtObject target
        NumberAnimation{
            id: backAnimX
            target: backAnim.target
            from: backAnim.from.x
            to: backAnim.to.x
            property: "x";
            duration: 50
        }

        NumberAnimation{
            id: backAnimY
            target: backAnim.target
            from: backAnim.from.y
            to: backAnim.to.y
            property: "y";
            duration: 50
        }
    }

    //Put Chess Pieces on the board
    Repeater
    {
        id: pieces
        model: mod

        ChessPiece
        {
            id: piece
            width: gameBoard.width / 9
            height: gameBoard.height / 10
            source: gamePlay.src(index)
            role: gamePlay.role(index)
            side: gamePlay.side(index)
            roll: gamePlay.roll(index)
            column: gamePlay.column(index)
            x: column * width + gameBoard.x
            y: roll * height + gameBoard.y
            property bool selected: false
            Drag.active: mouseArea.drag.active
            z: mouseArea.drag.active || mouseArea.pressed ? 2: 1
            property point beginDrag

            MouseArea{
                id: mouseArea
                anchors.fill: piece
                drag.target: piece
                enabled: gameP.seleted === -1 && gameP.side === parent.side
                onPressed:
                {
                    parent.beginDrag = Qt.point(parent.x, parent.y); //record the start location of current piece
                }
                onReleased: {
                    if(parent.x === parent.beginDrag.x && parent.y === parent.beginDrag.y)
                    {
                        parent.selected = true
                        gameP.seleted = index;
                    }
                    else
                    {
                        if(parent.x > gameBoard.x && parent.y > gameBoard.y     //place the piece to the nearest location
                                && parent.x < gameBoard.x + gameBoard.width
                                && parent.y < gameBoard.y + gameBoard.height)
                        {
                            var bx = parent.x - (parent.x - gameBoard.x) % parent.width;
                            var by = parent.y - (parent.y - gameBoard.y) % parent.height;
                            parent.beginDrag = Qt.point(bx, by);
                        }
                        backAnim.target = parent
                        backAnim.from = Qt.point(parent.x, parent.y);

                        backAnim.to = Qt.point(parent.beginDrag.x, parent.beginDrag.y);
                        backAnim.start()
                        ++gameP.side;
                        gameP.side %= 2;
                    }
                }
            }

        }
    }

}
