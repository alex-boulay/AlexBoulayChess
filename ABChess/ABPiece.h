#include <string>
#include <iostream>
#include <exception>
#pragma once


#define ABQUEEN 0
#define ABKING 1
#define ABROOK 2
#define ABKNIGHT 3
#define ABBISHOP 4
#define ABPAWN 5
#define ABEMPTY 6
#define BLACK 0
#define WHITE 1

using ABplace = unsigned char;//place is 0-3bits column 4-7bits row
using ABpiece = unsigned char;//piece is a bit 0 colot bit 1-3 value
using ABcolor = unsigned char;// bit 0 BLACK or WHITE, if used as a pointer  point to a strign "BACK" or "WHITE"
using ABvalue = unsigned char;// Theoretical value of the piece
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
	ABpiece data;// bit 0 color bit 1-3 value
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