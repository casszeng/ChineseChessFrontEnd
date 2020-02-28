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
                if(pieces.itemAt(seleted).beginDrag.x !== bx || pieces.itemAt(seleted).beginDrag.y !== by)
                {
                    var fc = gameBoard.getRoll(pieces.itemAt(seleted).beginDrag.x);
                    var fr = gameBoard.getColumn(pieces.itemAt(seleted).beginDrag.y);
                    var c = gameBoard.getRoll(bx);
                    var r = gameBoard.getColumn(by);

                    if(gamePlay.checkMove(fr, r, fc, c))
                    {
                        pieces.itemAt(seleted).beginDrag = Qt.point(bx, by);
                        ++gameP.side;
                        gameP.side %= 2;
                    }
                }

                backAnim.from = Qt.point(pieces.itemAt(seleted).x, pieces.itemAt(seleted).y);
                backAnim.to = Qt.point(pieces.itemAt(seleted).beginDrag.x, pieces.itemAt(seleted).beginDrag.y);
                backAnim.start();
                pieces.itemAt(seleted).selected = false;
                seleted = -1;
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
    function getRoll(x)
    {
        return gameBoard.width / (x - chessBoard.x);
    }

    function getColumn(y)
    {
        return gameBoard.width / (y - chessBoard.y);
    }
    //Put Chess Pieces on the board
    Repeater
    {
        id: pieces
        model: mod

        ChessPiece
        {
            id: piece

            width:  gameBoard.width / 9
            height: gameBoard.height / 10

            //create chess pieces with data from c++
            source: gamePlay.src(index)
            role:   gamePlay.role(index)
            side:   gamePlay.side(index)
            roll:   gamePlay.roll(index)
            column: gamePlay.column(index)
            x:      column * width + gameBoard.x
            y:      roll * height + gameBoard.y
            z:      mouseArea.drag.active || mouseArea.pressed ? 3: 1
            Drag.active: mouseArea.drag.active
            property bool   selected: false
            property point  beginDrag

            MouseArea{
                id: mouseArea
                anchors.fill: piece
                drag.target: piece
                enabled: gameP.seleted === -1 && gameP.side === parent.side && gamePlay.alive(index)
                onPressed:
                {
                    parent.beginDrag = Qt.point(parent.x, parent.y); //record the start location of current piece
                }
                onReleased: {
                    //place the piece to the nearest location
                    if(
                            parent.x > gameBoard.x
                         && parent.y > gameBoard.y
                         && parent.x < gameBoard.x + gameBoard.width
                         && parent.y < gameBoard.y + gameBoard.height
                      )
                    {
                        var bx = parent.x - (parent.x - gameBoard.x) % parent.width;
                        var by = parent.y - (parent.y - gameBoard.y) % parent.height;
                        if(bx === parent.beginDrag.x && by === parent.beginDrag.y)  //if press then released immediatly that piece will be selected
                        {
                            parent.selected = true
                            gameP.seleted = index;
                        }
                        else
                        {
                            var fc = gameBoard.getRoll(parent.beginDrag.x);
                            var fr = gameBoard.getColumn(parent.beginDrag.y);
                            var c = gameBoard.getRoll(bx);
                            var r = gameBoard.getColumn(by);

                            if(gamePlay.checkMove(fr, r, fc, c))
                            {
                                parent.beginDrag = Qt.point(bx, by);
                                ++gameP.side;
                                gameP.side %= 2;
                            }

                        }
                    }

                    backAnim.target = piece
                    backAnim.from = Qt.point(piece.x, piece.y);

                    backAnim.to = Qt.point(piece.beginDrag.x, piece.beginDrag.y);
                    backAnim.start()
                }
            }

        }
    }

}
