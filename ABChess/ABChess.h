#pragma once

#define ABEMPTY 0
#define ABPAWN 1
#define ABROOK 2
#define ABKNIGHT 3
#define ABBISHOP 4
#define ABQUEEN 5
#define ABKING 6
#define WHITE 0
#define BLACK 1

using ABplace = unsigned char;//place is 0-3bits column 4-7bits row
using ABpiece = unsigned char;//piece is a 0-3bit piece 0-2 is the type of piece 4 is the color
using ABcolor = unsigned char;// bit 0 BLACK or WHITE, if used as a pointer  point to a strign "BACK" or "WHITE"
using ABvalue = unsigned char;// Theoretical value of the piece