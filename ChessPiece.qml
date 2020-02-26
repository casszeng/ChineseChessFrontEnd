import QtQuick 2.0

Item {
    id: chessPiece
    property string source: ""
    property int role: 0
    property int side: 0
    property int roll: 0
    property int column: 0
    Image {
        id: chessImage
        source: chessPiece.source
        anchors.fill: parent
    }

}
