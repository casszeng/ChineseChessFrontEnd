class Chess
{
    constructor(source, roll, column)
    {
        this.source = source;
        this.roll = roll;
        this.column = column;
    }
}

let board = new Array(90);
let array = [
            new Chess("qrc:/chessPieces/Images/hongChe.png",    9, 0),
            new Chess("qrc:/chessPieces/Images/hongChe.png",    9, 8),
            new Chess("qrc:/chessPieces/Images/hongMa.png",     9, 1),
            new Chess("qrc:/chessPieces/Images/hongMa.png",     9, 7),
            new Chess("qrc:/chessPieces/Images/hongXiang.png",  9, 2),
            new Chess("qrc:/chessPieces/Images/hongXiang.png",  9, 6),
            new Chess("qrc:/chessPieces/Images/hongShi.png",    9, 3),
            new Chess("qrc:/chessPieces/Images/hongShi.png",    9, 5),
            new Chess("qrc:/chessPieces/Images/hongJiang.png",  9, 4),
            new Chess("qrc:/chessPieces/Images/hongPao.png",    7, 1),
            new Chess("qrc:/chessPieces/Images/hongPao.png",    7, 7),
            new Chess("qrc:/chessPieces/Images/hongBing.png",   6, 0),
            new Chess("qrc:/chessPieces/Images/hongBing.png",   6, 2),
            new Chess("qrc:/chessPieces/Images/hongBing.png",   6, 4),
            new Chess("qrc:/chessPieces/Images/hongBing.png",   6, 6),
            new Chess("qrc:/chessPieces/Images/hongBing.png",   6, 8),

            new Chess("qrc:/chessPieces/Images/heiChe.png",     0, 0),
            new Chess("qrc:/chessPieces/Images/heiChe.png",     0, 8),
            new Chess("qrc:/chessPieces/Images/heiMa.png",      0, 1),
            new Chess("qrc:/chessPieces/Images/heiMa.png",      0, 7),
            new Chess("qrc:/chessPieces/Images/heiXiang.png",   0, 2),
            new Chess("qrc:/chessPieces/Images/heiXiang.png",   0, 6),
            new Chess("qrc:/chessPieces/Images/heiShi.png",     0, 3),
            new Chess("qrc:/chessPieces/Images/heiShi.png",     0, 5),
            new Chess("qrc:/chessPieces/Images/heiJiang.png",   0, 4),
            new Chess("qrc:/chessPieces/Images/heiPao.png",     2, 1),
            new Chess("qrc:/chessPieces/Images/heiPao.png",     2, 7),
            new Chess("qrc:/chessPieces/Images/heiBing.png",    3, 0),
            new Chess("qrc:/chessPieces/Images/heiBing.png",    3, 2),
            new Chess("qrc:/chessPieces/Images/heiBing.png",    3, 4),
            new Chess("qrc:/chessPieces/Images/heiBing.png",    3, 6),
            new Chess("qrc:/chessPieces/Images/heiBing.png",    3, 8)
        ];

var component = null;

function initialization()
{
    for(var r = 0; r < 10; ++r)
    {
        for(var c = 0; c < 9; ++c)
        {
            if(board[index(r, c)] !== undefined && board[index(r, c)] !== null)
            {
                board[index(r, c)].destroy();
            }

            board[index(r, c)] = null;

        }
    }

    for(var i = 0; i < 32; ++i)
    {
        generatePieces(array[i]);
    }
}

function index(roll, column)
{
    return 9 * roll + column;
}

function generatePieces(piece)
{
    if (component === null)
    {
        component = Qt.createComponent("ChessPiece.qml");
    }
    if (component.status === Component.Ready)
    {
        var dynamicObject = component.createObject(game);
        if (dynamicObject === null)
        {
            console.log("error creating block");
            console.log(component.errorString());
            return false;
        }
        dynamicObject.source            = piece.source;
        dynamicObject.roll              = piece.roll;
        dynamicObject.column            = piece.column;
        board[index(piece.roll, piece.column)] = dynamicObject;
    }
    else
    {
        console.log("error loading block component");
        console.log(component.errorString());
        return false;
    }
    return true;
}

function movePiece(fromRoll, fromColumn, toRoll, toColumn)
{

    deletePiece(toRoll, toColumn);
    if(board[index(fromRoll, fromColumn)] !== null)
    {
        board[index(toRoll, toColumn)] = board[index(fromRoll, fromColumn)];
        board[index(fromRoll, fromColumn)] = null;
        board[index(toRoll, toColumn)].roll = toRoll;
        board[index(toRoll, toColumn)].column = toColumn;
    }

}

function movePiecebyIndex(from, to)
{

    deletePiecebyIndex(to);
    if(board[from] !== null)
    {
        board[to] = board[from];
        board[from] = null;
        board[to].roll = to / 9;
        board[to].column = to % 9;
    }

}

function deletePiecebyIndex(i)
{
    if(board[i] !== null)
    {
        board[i].destroy();
        board[i] = null;
        console.log("destory")
    }
}

function deletePiece(roll, column)
{
    if(board[index(roll, column)] !== null)
    {
        board[index(roll, column)].destroy();
        board[index(roll, column)] = null;
        console.log("destory")
    }
}

function highlightChosen(roll, column)
{
    for(var i = 0; i < 90; ++i)
    {
        if(board[i] !== null)
        {
            board[i].glowRadius = 0;
            if(i === index(roll, column))
            {
                board[i].glowRadius = 4;
            }
        }
    }
}
