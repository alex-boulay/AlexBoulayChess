#include "ABPlayer.h"

ABPlayer::ABPlayer(ABcolor col,ABChessBoard* board) {
	color = col;
	board = board;
	putPieces();
};

ABcolor ABPlayer::ennemiColor() {
	return 1 - getColor();
}
void ABPlayer::putPieces() {
	char row0, row1;
	row0 = 0;
	row1 = 1;
	if (color == BLACK) {
		row0 = 8;
		row1 = 7;
	}
	Pieces[0] = new ABRook(0, row0, color);
	Pieces[1] = new ABKnight(1, row0, color);
	Pieces[2] = new ABBishop(2, row0, color);
	Pieces[3] = new ABKing(3, row0, color);
	Pieces[4] = new ABQueen(4, row0, color);
	Pieces[5] = new ABBishop(5, row0, color);
	Pieces[6] = new ABKnight(6, row0, color);
	Pieces[7] = new ABRook(7, row0, color);
	for (int i = 0; i < 8; i++) {
		Pieces[7+i] = new ABPawn(i,row1, color);
	}
	nmbr = 16;
}

ABWPlayer::ABWPlayer(ABChessBoard *board) : ABPlayer(WHITE,board) {
};

ABBPlayer::ABBPlayer(ABChessBoard * board) : ABPlayer(BLACK,board) {
};