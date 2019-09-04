#pragma once
#include <wincodec.h>
#include <assert.h>
#include <d2d1.h>
#include "ABCDisplay.h"

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

	return hr;
}

int ABCDisplay::LoadFile(LPCWSTR name, ID2D1Bitmap* bmp) {
	int hr = S_OK;
	if (dfact == NULL) {
		hr = CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&dfact));
		assert(SUCCEEDED(hr));
	}

	hr = dfact->CreateDecoderFromFilename(name, NULL, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &reader);
	assert(SUCCEEDED(hr));

	hr = reader->GetFrame(0, &wicFrame);
	assert(SUCCEEDED(hr));
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