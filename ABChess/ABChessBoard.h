#pragma once
#include "ABChess.h"

class ABChessBoard{
private:
	unsigned char board[8][8]; // 8 row by 8

public:
	ABChessBoard();
	ABpiece getPiece(ABplace place);
	ABpiece getPiece(int x, int y); //get piece by coord
	void clearPosition(ABplace);
	void putPiece(ABplace place, ABpiece piece);
	ABcolor caseColor(ABplace place) {};
};