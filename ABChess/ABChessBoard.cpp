#include "ABChessBoard.h"

ABpiece ABChessBoard::getPiece(ABplace p) {	//place is 0-3bits column 4-7bits row, a Row is 8 4bits columns
	return board[p >> 4][ p&15]; 
}

ABpiece ABChessBoard::getPiece(int x, int y) {
	return board[x][y];
}

void ABChessBoard::clearPosition(ABplace p) {
	board[p >> 4][p&15]=7;
}

void ABChessBoard::putPiece(ABplace place,ABpiece  piece){
	clearPosition(place);
	board[place >> 4][place&15]=piece;
}


ABcolor caseColor(ABplace place) {
	return ((place & 7)+((place >> 3)&7)) ;
}


ABChessBoard::ABChessBoard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = 7;
		}
	}
}