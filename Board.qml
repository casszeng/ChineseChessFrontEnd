import QtQuick 2.0

Item {
    Image
    {
        source: "qrc:/board/Images/chessBoard.png"
        anchors.fill: parent
    }
    MouseArea
    {
        property int chosenRoll: getChosenRoll()
        property int chosenColumn: getChosenColumn()
        property int roll
        property int column
        anchors.fill: parent
        onClicked:
        {
            roll = getRoll(mouse.y)
            column = getColumn(mouse.x)
            console.log(roll)
            console.log(column)
            if(chosenRoll !== -1 && chosenColumn !== -1 && (chosenRoll !== roll || chosenColumn !== column))
            {
                movePiece(chosenRoll, chosenColumn, roll, column);
                setChosenRoll(-1);
                setChosenColumn(-1);
            }
        }
    }

    function setChosenRoll(r)
    {
        parent.chosenRoll = r;
    }

    function setChosenColumn(c)
    {
        parent.chosenColumn = c;
    }

    function getChosenRoll()
    {
        return parent.chosenRoll;
    }
    function getChosenColumn()
    {
        return parent.chosenColumn;
    }
    function movePiece(fromRoll, fromColumn, toRoll, toColumn)
    {
        parent.movePiece(fromRoll, fromColumn, toRoll, toColumn);
    }

    function getRoll(y)
    {
        var max = 9;
        var min = 0;
        var rol =  y / (height / 10)

        if(rol > max)
        {
            rol = max
        }
        if(rol < min)
        {
            rol = min
        }

        return rol;
    }
    function getColumn(x)
    {
        var max = 8;
        var min = 0;
        var col =  x / (width / 9)

        if(col > max)
        {
            col = max
        }
        if(col < min)
        {
            col = min
        }

        return col;

    }
}
