#pragma once
#include "ABPiece.h"

//coordinates of a point
typedef struct coord {
	int x, y;
	char color; //'b' blue 'g' green
}coord;

typedef struct CDrawList {
	struct coord draws[30];
	char size;
}CDrawList;


class ABChessBoard{
private:
	unsigned char board[8][8]; // 8 row by 8
	CDrawList dlist;

public:
	ABChessBoard();
	ABpiece getPiece(ABplace place);
	ABpiece getPiece(int x, int y); //get piece by coord
	void clearPosition(ABplace);
	void clearPosition(int x, int y);
	void putPiece(ABplace place, ABpiece piece);
	void putPiece(ABpiece piece, int x, int y);
	ABcolor caseColor(ABplace place) ;
};