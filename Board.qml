import QtQuick 2.0

Item {
    Image {
        id: chessBoard
        source: "qrc:/board/Images/chessBoard.png"

        anchors.fill: parent
    }

    function getRoll(x)
    {
        return (x - chessBoard.x) / (chessBoard.width / 9);
    }

    function getColumn(y)
    {
        return (y - chessBoard.y) / (chessBoard.width / 10);
    }
}
