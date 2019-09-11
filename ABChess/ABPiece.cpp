#include "ABPiece.h"

unsigned char Names[7][7] = {"Queen", "King","Rook","Knight","Bishop","Pawn","Empty" };
unsigned char Colors[2][6] = { "Black","White" };
unsigned char Values[7] = { 8,250,5,3,3,1,0 }; // theoretical piece values

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
	data = c+(piece<<1);
	place = y+(x<<4);
};
