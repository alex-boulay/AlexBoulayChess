#include "ABPiece.h"
#include "ABChess.h"

unsigned char Names[7][7] = { "Empty", "Pawn", "Rook", "Knight", "Bishop", "Queen", "King" };
unsigned char Colors[2][6] = { "White","Black" };
unsigned char Values[7] = { 0,1,3,3,5,8 }; // theoretical piece values

unsigned char * ABPiece::getPieceName() {
	return Names[data & 7 -1];
}

ABcolor* ABPiece::getPieceColor() {
	if (data == 0) {
		return nullptr;
	}
	return Colors[data >> 3];
}

unsigned char ABPiece::getPieceValue() {
	return Values[data & 7 -1];
}

ABPiece::ABPiece(ABpiece piece, char x, char y,ABcolor c) {
	if (piece > 16) {
		throw ABPieceCreationException();
	}
	data = piece+(c<<3);
	place = x+(y<<4);
};
