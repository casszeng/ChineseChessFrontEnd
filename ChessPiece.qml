import QtQuick 2.0

Item {
    width: parent.width / 9
    height: parent.height / 10
    property string source
    property int    roll
    property int    column

    x: column * (parent.width / 9)
    y: roll * (parent.height / 10)
    z: mouseArea.drag.active ? 3 : 1
    Image {
        id:             chessImage
        source:         parent.source
        anchors.fill:   parent
    }

    MouseArea
    {
        id: mouseArea
        anchors.fill: parent
        property int toRoll
        property int toColumn
        property int fromRoll: getChosenRoll()
        property int fromColumn: getChosenColumn()
        drag.target: parent
        onReleased:
        {
            toRoll = getRoll(parent.y + parent.height / 2);
            toColumn = getColumn(parent.x  + parent.width / 2);
            if(roll === toRoll && toColumn === column)
            {
                if(fromRoll !== -1 && fromColumn !== -1 && fromRoll !== roll && fromColumn !== column)
                {
                    movePiece(fromRoll, fromColumn, roll, column);
                    setChosenRoll(-1);
                    setChosenColumn(-1);
                }
                else
                {
                    setChosenRoll(toRoll);
                    setChosenColumn(toColumn);
                }
            }
            else
            {
                movePiece(roll, column, toRoll, toColumn);
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
        var rol =  y / (parent.height / 10)

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
        var col =  x / (parent.width / 9)

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
