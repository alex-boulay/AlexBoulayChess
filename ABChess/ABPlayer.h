#pragma once
#include "ABChess.h"
#include "ABPiece.h"

//general player
class ABPlayer {
protected:
	ABcolor color;//BLACK or WHITE
	ABPiece* Pieces[16] ; //all the pieces owned by the player
	char nmbr = 0;//nmbr of pieces
public:
	ABPlayer(ABcolor col);
	void putPieces();
	ABcolor getColor() { return color; }
	ABcolor ennemiColor();
};


//white player
class ABWPlayer:ABPlayer {
public:
	ABWPlayer();
};

// black player
class ABBPlayer : ABPlayer {
public:
	ABBPlayer();
};