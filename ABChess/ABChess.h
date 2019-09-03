#pragma once
#include <iostream>
#include "ABCDisplay.h"
using namespace std;

class ABChess: public ABCDisplay {
public:
	ABChess();
	~ABChess();

	// Register the window class and call methods for instantiating drawing resources
	HRESULT Initialize();

	// Process and dispatch messages
	void RunMessageLoop();

private:

	// Initialize device-independent resources.
	HRESULT CreateDeviceIndependentResources();

	// Initialize device-dependent resources.
	HRESULT CreateDeviceResources();

	// Release device-dependent resource.
	void DiscardDeviceResources();

	// Draw content.
	HRESULT OnRender();

	// Resize the render target.
	void OnResize(
		UINT width,
		UINT height
	);

	// The windows procedure.
	static LRESULT CALLBACK WndProc(
		HWND hWnd,
		UINT message,
		WPARAM wParam,
		LPARAM lParam
	);

public:
	HWND m_hwnd;
	ID2D1Factory* m_pDirect2dFactory;
	ID2D1HwndRenderTarget* m_pRenderTarget;
	ID2D1SolidColorBrush* m_pLightSlateGrayBrush;
	ID2D1SolidColorBrush* m_pCornflowerBlueBrush;
};

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