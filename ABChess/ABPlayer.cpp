#include "ABPlayer.h"

ABPlayer::ABPlayer(ABcolor col,ABChessBoard* b) {
	color = col;
	board = b;
};

ABcolor ABPlayer::ennemiColor() {
	return 1 - getColor();
}
void ABPlayer::putPieces() {
	char row0, row1;
	row0 = 0;
	row1 = 1;
	if (color == BLACK) {
		row0 = 7;
		row1 = 6;
	}
	Pieces[0] = new ABRook(0, row0, color);
	board->putPiece(Pieces[0]->getData(), 0, row0);
	Pieces[1] = new ABKnight(1, row0, color);
	board->putPiece(Pieces[1]->getData(), 1, row0);
	Pieces[2] = new ABBishop(2, row0, color);
	board->putPiece(Pieces[2]->getData(), 2, row0);
	Pieces[3] = new ABQueen(3, row0, color);
	board->putPiece(Pieces[3]->getData(), 3, row0);
	Pieces[4] = new ABKing(4, row0, color);
	board->putPiece(Pieces[4]->getData(), 4, row0);
	Pieces[5] = new ABBishop(5, row0, color);
	board->putPiece(Pieces[5]->getData(), 5, row0);
	Pieces[6] = new ABKnight(6, row0, color);
	board->putPiece(Pieces[6]->getData(), 6, row0);
	Pieces[7] = new ABRook(7, row0, color);
	board->putPiece(Pieces[7]->getData(), 7, row0);
	for (int i = 0; i < 8; i++) {
		Pieces[7+i] = new ABPawn(i,row1, color);
		board->putPiece(Pieces[7+i]->getData(), i, row1);
	}
	nmbr = 16;
}

ABWPlayer::ABWPlayer(ABChessBoard *board) : ABPlayer(WHITE,board) {
};

ABBPlayer::ABBPlayer(ABChessBoard * board) : ABPlayer(BLACK,board) {
};