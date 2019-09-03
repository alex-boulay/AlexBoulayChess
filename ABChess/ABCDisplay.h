#pragma once
#include <wincodec.h>
#include <assert.h>
#include <d2d1.h>

class ABCDisplay {
private:

	ID2D1Bitmap* board = NULL, * bpieces = NULL;
	IWICBitmapDecoder* reader = NULL;
	IWICImagingFactory* dfact = NULL;
	HRSRC imageResHandle = NULL;
	ID2D1HwndRenderTarget* rendertarget;

public:
	ABCDisplay();
	~ABCDisplay();
	void setRdt(ID2D1HwndRenderTarget* rd) { rendertarget = rd; };
	HRESULT decode();
	//int DrawPiece(ABpiece piece, ABplace place);
	//int splitpieces(ID2D1Bitmap* source, ID2D1Bitmap** dest, int nmbW, int nmbH); 
	void DrawBoard();
private:
	int LoadFile(LPCWSTR name, ID2D1Bitmap* bmp);// Lao a file in the bitmap
};