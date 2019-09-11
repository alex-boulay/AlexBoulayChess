#pragma once
#include "ABPiece.h"
#include "ABChessBoard.h"

//general player
class ABPlayer {
protected:
	ABChessBoard *board;
	ABcolor color;//BLACK or WHITE
	ABPiece* Pieces[16] ; //all the pieces owned by the player
	char nmbr = 0;//nmbr of pieces
public:
	ABPlayer(ABcolor col,ABChessBoard* board);
	void putPieces();
	ABcolor getColor() { return color; }
	ABcolor ennemiColor();
};


//white player
class ABWPlayer:public ABPlayer {
public:
	ABWPlayer(ABChessBoard * board);
};

// black player
class ABBPlayer :public ABPlayer {
public:
	ABBPlayer(ABChessBoard* board);
};