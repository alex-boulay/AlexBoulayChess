#include "ABChessBoard.h"

ABpiece ABChessBoard::getPiece(ABplace p) {	//place is 0-3bits column 4-7bits row, a Row is 8 4bits columns
	return (board[p >> 4]) >> (( p&15)<<2); 
}

void ABChessBoard::clearPosition(ABplace p) {
	board[p >> 4] &= (0xFFFFFFFF - (15 << ((p & 15)<<2)));
}

void ABChessBoard::putPiece(ABplace place,ABpiece  piece){
	clearPosition(place);
	(board[place >> 4]) += (piece & 15) << ((place & 15)<< 2);
}


ABcolor caseColor(ABplace place) {
	return ((place & 7)+((place >> 3)&7)) ;
}
