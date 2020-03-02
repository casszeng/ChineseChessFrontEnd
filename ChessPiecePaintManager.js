class Chess
{
    constructor(source, role, side, roll, column, alive)
    {
        this.source = source;
        this.role = role;
        this.side = side;
        this.roll = roll;
        this.column = column;
        this.alive = alive;
    }
}


let board = new Array(90);
let array = [
            new Chess("qrc:/chessPieces/Images/hongChe.png",    "Che",      0, 9, 0, true),
            new Chess("qrc:/chessPieces/Images/hongChe.png",    "Che",      0, 9, 8, true),
            new Chess("qrc:/chessPieces/Images/hongMa.png",     "Ma",       0, 9, 1, true),
            new Chess("qrc:/chessPieces/Images/hongMa.png",     "Ma",       0, 9, 7, true),
            new Chess("qrc:/chessPieces/Images/hongXiang.png",  "Xiang",    0, 9, 2, true),
            new Chess("qrc:/chessPieces/Images/hongXiang.png",  "Xiang",    0, 9, 6, true),
            new Chess("qrc:/chessPieces/Images/hongShi.png",    "Shi",      0, 9, 3, true),
            new Chess("qrc:/chessPieces/Images/hongShi.png",    "Shi",      0, 9, 5, true),
            new Chess("qrc:/chessPieces/Images/hongJiang.png",  "Jiang",    0, 9, 4, true),
            new Chess("qrc:/chessPieces/Images/hongPao.png",    "Pao",      0, 7, 1, true),
            new Chess("qrc:/chessPieces/Images/hongPao.png",    "Pao",      0, 7, 7, true),
            new Chess("qrc:/chessPieces/Images/hongBing.png",       "Bing",     0, 6, 0, true),
            new Chess("qrc:/chessPieces/Images/hongBing.png",       "Bing",     0, 6, 2, true),
            new Chess("qrc:/chessPieces/Images/hongBing.png",       "Bing",     0, 6, 4, true),
            new Chess("qrc:/chessPieces/Images/hongBing.png",       "Bing",     0, 6, 6, true),
            new Chess("qrc:/chessPieces/Images/hongBing.png",       "Bing",     0, 6, 8, true),

            new Chess("qrc:/chessPieces/Images/heiChe.png",     "Che",      1, 0, 0, true),
            new Chess("qrc:/chessPieces/Images/heiChe.png",     "Che",      1, 0, 8, true),
            new Chess("qrc:/chessPieces/Images/heiMa.png",      "Ma",       1, 0, 1, true),
            new Chess("qrc:/chessPieces/Images/heiMa.png",      "Ma",       1, 0, 7, true),
            new Chess("qrc:/chessPieces/Images/heiXiang.png",   "Xiang",    1, 0, 2, true),
            new Chess("qrc:/chessPieces/Images/heiXiang.png",   "Xiang",    1, 0, 6, true),
            new Chess("qrc:/chessPieces/Images/heiShi.png",     "Shi",      1, 0, 3, true),
            new Chess("qrc:/chessPieces/Images/heiShi.png",     "Shi",      1, 0, 5, true),
            new Chess("qrc:/chessPieces/Images/heiJiang.png",      "Jiang",    1, 0, 4, true),
            new Chess("qrc:/chessPieces/Images/heiPao.png",     "Pao",      1, 2, 1, true),
            new Chess("qrc:/chessPieces/Images/heiPao.png",     "Pao",      1, 2, 7, true),
            new Chess("qrc:/chessPieces/Images/heiBing.png",         "Bing",     1, 3, 0, true),
            new Chess("qrc:/chessPieces/Images/heiBing.png",         "Bing",     1, 3, 2, true),
            new Chess("qrc:/chessPieces/Images/heiBing.png",         "Bing",     1, 3, 4, true),
            new Chess("qrc:/chessPieces/Images/heiBing.png",         "Bing",     1, 3, 6, true),
            new Chess("qrc:/chessPieces/Images/heiBing.png",         "Bing",     1, 3, 8, true)
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

function deletePiece(roll, column)
{
    if(board[index(roll, column)] !== null)
    {
        board[index(roll, column)].destroy();
        board[index(roll, column)] = null;
        console.log("destory")
    }
}
