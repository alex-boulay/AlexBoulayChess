#pragma once
#include "ABChess.h"

class ABChessBoard{
private:
	unsigned int board[8];

public:
	ABpiece getPiece(ABplace place);
	void clearPosition(ABplace);
	void putPiece(ABplace place, ABpiece piece);
	ABcolor caseColor(ABplace place) {};
};