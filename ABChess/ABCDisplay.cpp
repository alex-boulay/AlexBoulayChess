#pragma once
#include <wincodec.h>
#include <assert.h>
#include <d2d1.h>
#include "ABCDisplay.h"
#include <iostream>
#include <string> 
#include <sstream>

using namespace std;

template<class Interface>
inline void SafeRelease(
	Interface** ppInterfaceToRelease
)
{
	if (*ppInterfaceToRelease != NULL)
	{
		(*ppInterfaceToRelease)->Release();

		(*ppInterfaceToRelease) = NULL;
	}
}

ABCDisplay::ABCDisplay() {
}

HRESULT ABCDisplay::decode() {
	int hr = S_OK;

	hr = LoadFile(L"ChessBoard.png", board);
	assert(SUCCEEDED(hr));
	hr = rendertarget->CreateBitmapFromWicBitmap(wicConverter, NULL, &board);
	assert(SUCCEEDED(hr));
	hr = LoadFile(L"ChessPiecesArray.png", bpieces);
	assert(SUCCEEDED(hr));
	hr = rendertarget->CreateBitmapFromWicBitmap(wicConverter, NULL, &bpieces);
	assert(SUCCEEDED(hr));
	stringstream buff;
	buff << "taille board : " << board->GetPixelSize().width << " x " << board->GetPixelSize().height << endl;
	buff << "taille bpieces : " << bpieces->GetPixelSize().width << " x " << bpieces->GetPixelSize().height << endl;
	string s = buff.str();
	wstring stemp = wstring(s.begin(), s.end());
	LPCWSTR sw = stemp.c_str();
	OutputDebugString(sw);
	return hr;
}

int ABCDisplay::LoadFile(LPCWSTR name, ID2D1Bitmap* bmp) {
	int hr = S_OK;
	if (dfact == NULL) {
		hr = CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&dfact));
		assert(SUCCEEDED(hr));
	}
	if (reader != NULL) {
		reader->Release();
	}
	hr = dfact->CreateDecoderFromFilename(name, NULL, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &reader);
	assert(SUCCEEDED(hr));
	if (wicFrame != NULL) {
		wicFrame->Release();
	}
	hr = reader->GetFrame(0, &wicFrame);
	assert(SUCCEEDED(hr));
	if (wicConverter != NULL) {
		wicFrame->Release();
	}
	hr = dfact->CreateFormatConverter(&wicConverter);
	assert(SUCCEEDED(hr));
	hr = wicConverter->Initialize(wicFrame,
		GUID_WICPixelFormat32bppPBGRA, //pixel format
		WICBitmapDitherTypeNone,
		NULL, //no palette needed
		0.0,//transparency
		WICBitmapPaletteTypeCustom);
	assert(SUCCEEDED(hr));
	return hr;
}

/**
int ABCDisplay::splitpieces(ID2D1Bitmap* source, ID2D1Bitmap** dest, int nmbW,int nmbH) {
	HRESULT hr = S_OK;
	int imgWidth = source->GetPixelSize().width / nmbW;
	int imgHeight = source->GetPixelSize().height / nmbH;
	for (int i = 0; i < nmbH; i++) {
		for (int j = 0; j < nmbW; j++) {


		}
	}
	return hr;
}


int ABCDisplay ::DrawPiece(ABpiece piece, ABplace place) {
	FLOAT imgHeight = bpieces->GetSize().height;
	FLOAT imgWidth = bpieces->GetSize().width;

	return 0;
}**/


void ABCDisplay::DrawPiece(ABpiece pi,ABplace pl) { // Draw a piece unless it's an empty case on the board
	DrawPiece(pi, pl >> 4, pl & 15);
}

void ABCDisplay::DrawPiece(ABpiece pi, int x, int y) { // Draw a piece unless it's an empty case on the board
	if (((pi >> 2) & 15) == 7) return;
	float placeWE = 53.0f + (73.f * x);
	float placeHE = (70.f * y);
	rendertarget->DrawBitmap(
		bpieces,
		D2D1::RectF(placeWE, placeHE, placeWE + 75.f, placeHE + 75.f),
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(((pi >> 1) & 15) * 60.f, (pi & 1) * 60.f, ((pi >> 1) & 15) * 60.f + 60.f, (pi & 1) * 60.f + 60.f)
	);
}

void ABCDisplay::DrawBoard() {
	rendertarget->DrawBitmap(
		board,
		D2D1::RectF(0.0f,0.0f,rendertarget->GetSize().width,rendertarget->GetSize().height),
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
}

ABCDisplay::~ABCDisplay() {
	SafeRelease(&board);
	SafeRelease(&bpieces);
	SafeRelease(&reader);
	SafeRelease(&dfact);
}