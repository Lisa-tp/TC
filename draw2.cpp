// draw.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "draw2.h"
#include <vector>
#include <cstdio>
#include <windowsx.h>

#define MAX_LOADSTRING 100
#define TMR_1 1
#define TMR_2 2
#define TMR_3 3
#define TMR_4 4

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

INT value;
int timer = 0;
int i = 0;
int j = 0;
int k = 0;
int e = 0;
int t = 0;
int tx = 0; // x trojkat
int ty = 0; // y trojkat

// buttons
HWND hwndButton;

// sent data
int col = 0;
std::vector<Point> data;
RECT drawArea1 = { 0, 0, 800, 350 };
RECT drawArea2 = { 10, 25, 630, 340};

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	Buttons(HWND, UINT, WPARAM, LPARAM);


void MyOnPaint(HDC hdc)
{
	Rectangle(hdc, 10, 10, 630, 25); //wierzch dzwiga
	Rectangle(hdc, 160, 24, 172, 170); //dzwig
	Rectangle(hdc, 153, 169, 180, 175); //dzwig

	HBRUSH hBrush = CreateSolidBrush(RGB(60, 60, 60)); // kolor linii na gorze
	HBRUSH hOldBrush = SelectBrush(hdc, hBrush);
	
	Rectangle(hdc, 10, 350, 180, 340); //platforma

	SelectBrush(hdc, hOldBrush);
	DeleteObject(hBrush);


	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(51, 102, 255));// kolor obwod figur
	HPEN hOldPen = SelectPen(hdc, hPen);

	 hBrush = CreateSolidBrush(RGB(77, 195, 255)); // kolor srodek figur
	 hOldBrush = SelectBrush(hdc, hBrush);

	POINT vertices[] = { {540, 280}, {500, 340}, {580, 340} };
	Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));
	Rectangle(hdc, 370, 340, 310, 280);
	Ellipse(hdc, 470, 340, 410, 280);

	SelectBrush(hdc, hOldBrush);
	DeleteObject(hBrush);

	SelectPen(hdc, hOldPen);
	DeleteObject(hPen);
}

void dzwig(HDC hdc)
{
	//	InvalidateRect(hWnd, &drawArea2, TRUE);
	if ((i + 172) <= 620 && (i + 160) >= 20 && (j + 170) <= 275 && (j + 170) >= 70)
	{
		Rectangle(hdc, 160 + i, 24, 172 + i, 170 + j); //dzwig
		Rectangle(hdc, 153+i, 169 + j, 180+i, 175 + j); //dzwig
	}

	else if ((j + 170) < 70)
	{
		Rectangle(hdc, 160 + i, 24, 172 + i, 70); //dzwig
		Rectangle(hdc, 153 + i, 69, 180 + i, 75); //dzwig
	}
	else if ((j + 170) > 275)
	{
		Rectangle(hdc, 160 + i, 24, 172 + i, 275); //dzwig
		Rectangle(hdc, 153 + i, 274, 180 + i, 280); //dzwig
	}
	else if ((i + 160) < 20)
	{
		Rectangle(hdc, 19, 24, 31, 170 + j); //dzwig
		Rectangle(hdc, 12, 169 + j, 39, 175 + j); //dzwig
	}
	else if ((i + 172) > 620)
	{
		Rectangle(hdc, 609, 24, 621, 170 + j); //dzwig
		Rectangle(hdc, 602, 169 + j, 629, 175 + j); //dzwig
	}
		
}

void jaki_zaczepiony()
{
	/*if (i > 157 && i < 190)
	{
		k = 1;
		MessageBox(NULL, L"k", L"Uwaga", MB_OK);
	}
	else if (i > 257 && i < 290)
	{
		e = 1;
		MessageBox(NULL, L"e", L"Uwaga", MB_OK);
	}*/
	if (i > 360 && i < 387 && (j + 170) >= 275)
	{
		t = 1;
		MessageBox(NULL, L"Zaczepiono trojkat", L"Uwaga", MB_OK);
	}
}

void czy_mozna_odczepic(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps)
{
	if (i < -13 && i>-156 && (j + 170) >= 275)
	{
		t = 0;
		MessageBox(NULL, L"Odczepiono trojkat", L"Uwaga", MB_OK);
		/*InvalidateRect(hWnd, &drawArea2, TRUE); //repaint drawArea
		hdc = BeginPaint(hWnd, &ps);
		
		EndPaint(hWnd, &ps);*/
	}
}

void figury(HDC hdc)
{	
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(51, 102, 255));// kolor obwod figur
	HPEN hOldPen = SelectPen(hdc, hPen);

	HBRUSH hBrush = CreateSolidBrush(RGB(77, 195, 255)); // kolor srodek figur
	HBRUSH hOldBrush = SelectBrush(hdc, hBrush);

	POINT vertices[] = { {(540+tx), (280+ty)}, {(500+tx), (340+ty)}, {(580+tx), (340+ty)} };
	Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));

	POINT verticess[] = { {(540 ), (280) }, {(500), (340)}, {(580), (340)} };
	Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));

	Rectangle(hdc, 370, 340, 310, 280);
	Ellipse(hdc, 470, 340, 410, 280);

	SelectBrush(hdc, hOldBrush);
	DeleteObject(hBrush);
}

void paint(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps, RECT *drawArea)
{
	//if (drawArea == NULL)
	//{
		//InvalidateRect(hWnd, NULL, TRUE); // repaint all
	//	MyOnPaint(hdc);
	//}
	//else
	InvalidateRect(hWnd, drawArea, TRUE); //repaint drawArea
	hdc = BeginPaint(hWnd, &ps);
	MyOnPaint(hdc);
	EndPaint(hWnd, &ps);
}

void repaintWindow(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps, RECT *drawArea)
{
	if (drawArea == NULL)
	{
		InvalidateRect(hWnd, NULL, TRUE); // repaint all
		hdc = BeginPaint(hWnd, &ps);
		//dzwig(hdc, j);
		EndPaint(hWnd, &ps);
	}

	else
		InvalidateRect(hWnd, drawArea, TRUE); //repaint drawArea
	hdc = BeginPaint(hWnd, &ps);
	dzwig(hdc);
	figury(hdc);
	EndPaint(hWnd, &ps);
}


void inputData()
{	
	data.push_back(Point(0, 0));
	for (int i = 1; i < 100; i++){
		data.push_back(Point(2*i+1, 200 * rand()/RAND_MAX));
	}
}


int OnCreate(HWND window)
{
	inputData();
	return 0;
}


// main function (exe hInstance)
int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	value = 0;


	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);



	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAW));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	GdiplusShutdown(gdiplusToken);

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAW));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_DRAW);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;


	hInst = hInstance; // Store instance handle (of exe) in our global variable

	// main window
	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	// create button and store the handle                                                       
	
	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Start"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		667, 10,                                  // the left and top co-ordinates
		85, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON0,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("1"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		300, 350,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON1,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("2"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		400, 350,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON2,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("3"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		500, 350,                                  // the left and top co-ordinates
		80, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON3,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Grab"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		667, 200,                                  // the left and top co-ordinates
		85, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON4,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Release"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		667, 260,                                  // the left and top co-ordinates
		85, 50,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON5,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits you dont really need

	// create button and store the handle                                                                                                         

	hwndButton = CreateWindow(TEXT("button"), TEXT("<-"), // przycisk wlaczajacy timer
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		645, 120, 40, 30, hWnd, (HMENU)ID_RBUTTON1, GetModuleHandle(NULL), NULL);

	hwndButton = CreateWindow(TEXT("button"), TEXT("->"), // przycisk wylaczajacy timer
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		735, 120, 40, 30, hWnd, (HMENU)ID_RBUTTON2, GetModuleHandle(NULL), NULL);

	hwndButton = CreateWindow(TEXT("button"), TEXT("^"), // przycisk wylaczajacy timer
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		690, 80, 40, 30, hWnd, (HMENU)ID_RBUTTON3, GetModuleHandle(NULL), NULL);

	hwndButton = CreateWindow(TEXT("button"), TEXT("v"), // przycisk wylaczajacy timer
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		690, 160, 40, 30, hWnd, (HMENU)ID_RBUTTON4, GetModuleHandle(NULL), NULL);

	hwndButton = CreateWindow(TEXT("button"), TEXT("P"), // przycisk wylaczajacy timer
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		690, 120, 40, 30, hWnd, (HMENU)ID_RBUTTON5, GetModuleHandle(NULL), NULL);

	OnCreate(hWnd);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window (low priority)
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;


	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		// MENU & BUTTON messages
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_BUTTON0:
			i = 0;
			j = 0;
			k = 0;
			e = 0;
			t = 0;
			tx = 0; // x trojkat
			ty = 0; // y trojkat
			paint(hWnd, hdc, ps, &drawArea1);
			break;
		case ID_BUTTON1 :
			//repaintWindow(hWnd, hdc, ps, &drawArea1);
			break;
		case ID_BUTTON2 :
			//repaintWindow(hWnd, hdc, ps, NULL);
			break;
		case ID_BUTTON3:

			//repaintWindow(hWnd, hdc, ps, NULL);
			break;
		case ID_BUTTON4:
			jaki_zaczepiony();
			repaintWindow(hWnd, hdc, ps, &drawArea2);
			break;
		case ID_BUTTON5:
			czy_mozna_odczepic(hWnd, hdc, ps);
			repaintWindow(hWnd, hdc, ps, &drawArea2);
			break;
		case ID_RBUTTON1: // timer on
			SetTimer(hWnd, TMR_1, 25, 0);
			break;
		case ID_RBUTTON2: //timer off
			SetTimer(hWnd, TMR_2, 25, 0);
			break;
		case ID_RBUTTON3: //timer off
			SetTimer(hWnd, TMR_3, 25, 0);
			break;
		case ID_RBUTTON4: //timer off
			SetTimer(hWnd, TMR_4, 25, 0);
			break;
		case ID_RBUTTON5: //timer off
			KillTimer(hWnd, TMR_1);
			KillTimer(hWnd, TMR_2);
			KillTimer(hWnd, TMR_3);
			KillTimer(hWnd, TMR_4);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here (not depend on timer, buttons)
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case TMR_1:
			if ((i + 160) >= 20)
			{
				i--;
				//i = i - 4;
				if (t == 1)
					tx--;
			
				repaintWindow(hWnd, hdc, ps, &drawArea2);
				
			}	
			break;
		case TMR_2:
			if ((i + 172) <= 620)
			{
				i++;
				//i = i + 4;
				if (t == 1)
					tx++;
				
				repaintWindow(hWnd, hdc, ps, &drawArea2);
			}
			break;
		case TMR_3:
			if ((j + 170) >= 70)
			{
				j--;
				if (t == 1)
					ty--;
				
				//j = j - 4;
				repaintWindow(hWnd, hdc, ps, &drawArea2);
			}
			break;
		case TMR_4:
			if ((j + 170) <= 275)
			{
				j++;
				if (t == 1)
					ty++;
				
				//j = j + 4;
				repaintWindow(hWnd, hdc, ps, &drawArea2);
			}
			break;
		}

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
