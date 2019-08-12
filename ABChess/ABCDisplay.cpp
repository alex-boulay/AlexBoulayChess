#pragma once
#include <wincodec.h>
#include <assert.h>
#include <d2d1.h>

class ABCDisplay {
private:

	ID2D1Bitmap* board=NULL,* pieces = NULL;
	IWICBitmapDecoder* reader = NULL;
	IWICImagingFactory* dfact = NULL;
	HRSRC imageResHandle = NULL;
	ID2D1HwndRenderTarget* rendertarget;

public:
	ABCDisplay(ID2D1HwndRenderTarget* rdt) {
		rendertarget = rdt;
	}

	HRESULT decode() {
		int hr = S_OK;

		hr=LoadFile(L"Chessboard.png", board);
		assert(SUCCEEDED(hr));
		hr=LoadFile(L"ChessPiecesArray.png",pieces);
		assert(SUCCEEDED(hr));
		rendertarget->DrawBitmap(
			board, //bitmap
			D2D1::RectF(0.f, 0.f, board->GetSize.width, board->GetSize.height),
			1.0f,//Opacity
			D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
			D2D1::RectF(0.0f, 0.0f, board->GetSize().width, board->GetSize().height)
		);

		return hr;
	}

private:
	int LoadFile(LPCWSTR name, ID2D1Bitmap* bmp) {
		int hr = S_OK;
		if (dfact == NULL) {
			hr = CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&dfact));
			assert(SUCCEEDED(hr));
		}
		else {
			assert(FALSE);
		}
		if (reader == NULL) {
			hr = dfact->CreateDecoderFromFilename(name, NULL, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &reader);
			assert(SUCCEEDED(hr));
		}
		else {
			assert(FALSE);
		}

		IWICBitmapFrameDecode* wicFrame = NULL;
		hr = reader->GetFrame(0, &wicFrame);
		assert(SUCCEEDED(hr));
		IWICFormatConverter* wicConverter = NULL;
		hr = dfact->CreateFormatConverter(&wicConverter);
		assert(SUCCEEDED(hr));
		hr = wicConverter->Initialize(wicFrame,
			GUID_WICPixelFormat32bppPBGRA, //pixel format
			WICBitmapDitherTypeNone,
			NULL, //no palette needed
			0.0,//transparency
			WICBitmapPaletteTypeCustom);
		assert(SUCCEEDED(hr));
		hr = rendertarget->CreateBitmapFromWicBitmap(wicConverter, NULL, &bmp);
		assert(SUCCEEDED(hr));
		return hr;
	}
};