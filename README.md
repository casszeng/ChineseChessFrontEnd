# ChineseChessFrontEnd
<h1>Day1 Structure building</h1>
<h3>Feature List</h3>
<li>Click on a chess piece and click another place to make a move</li>
<li>Drag and drop to make a move</li>
<li>Player vs Player on a single UI</li>
<li>Start a new game or Restart game by clicking new game</li>
<p>
Using a picture to show the board, calculate the size of a block to put chess picture into the UI by their location. Disable other side clicking and draging. Handle click and drag event to send chess stucture and from and to locations to rules to check placement. Any other placements will not be avalible for player to put. Will switch side on each placement. Will make a game status check after each placement and will end the game when there is a win or draw. 
</p>
<h1>Day2 implementing user interface</h1>
<li>Draw board</li>
<li>Put in chess pieces</li>
<li>Handle moving of chess pieces</li>
<h3>move by clicking chess piece then click other places:   </h3>
<li>first click on chess piece to select the chess piece</li>
<li>then click on anyother places on the board to move</li>
<h3>move by drag and drop: </h3>
<li>press and hold on chess piece</li>
<li>drag to another place on the board</li>
<li>release to put down piece</li>
<li>piece will auto adjust location by using this equation: currentx - (currentx - boardx) % chesspiecewidth</li>
<h3>Switching side and disable oppenet side</h3>
<p>in game put a property called side and initialize it to 0 when starting a new game. increase it then mod 2 to get side, 0 for red, 1 for black. disables mouse area of opponent side</p>
<h1>Day3 implementing rules</h1>
<h3>move logic</h3>
<p>use move checking in C++ to check move, if it return 0, then it's not movable, 1 for moving to a empty space, 2 for eating oppenent piece, after successful move change roll and column of the moving piece, swap side,after successful eating, decrease model of repeater by 1 and remove eaten chesspiece from vector</p>