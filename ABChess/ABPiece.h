#include <string>
#include <iostream>
#include <exception>
#include "ABChess.h"
#pragma once

using namespace std;

struct ABPieceCreationException : public std::exception
{
	const char* what() const throw ()
	{
		return "Piece Creation Execetion : char value is too hight";
	}
};


class ABPiece {
private:
	ABplace place;
	ABpiece data;// bit 0-2 type of piece 3 color
public:
	unsigned char* getPieceName();
	ABcolor* getPieceColor();
	ABvalue getPieceValue();
	ABPiece(ABpiece piece, char x, char y,ABcolor color);
	ABpiece getData() { return data; }
};

class ABBishop:public ABPiece
{
public:
	ABBishop(char x, char y,ABcolor c) :ABPiece(ABBISHOP, x, y,c) {};
};
class ABPawn :public ABPiece
{
public:
	ABPawn(char x,char y,ABcolor c) :ABPiece(ABPAWN, x,y,c) {};
};
class ABRook :public ABPiece
{
public:
	ABRook(char x, char y,ABcolor c) :ABPiece(ABROOK, x,y,c) {};
};
class ABKing:public ABPiece
{
public:
	ABKing(char x, char y, ABcolor c) :ABPiece(ABKING, x,y,c) {};
};
class ABQueen :public ABPiece
{
public:
	ABQueen(char x, char y, ABcolor c) :ABPiece(ABQUEEN, x,y,c) {};
};
class ABKnight :public ABPiece
{
public:
	ABKnight(char x, char y, ABcolor c) :ABPiece(ABKNIGHT, x,y,c) {};
};