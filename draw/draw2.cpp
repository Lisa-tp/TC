// TP-projekt-4-Jelizaveta-Kurilcik-183022-Maciej-Jankowski-180120-ACiR3

#include "stdafx.h"
#include "draw2.h"
#include <vector>
#include <cstdio>
#include <windowsx.h>
#include <cstdlib>
#include <iostream>
#include <wingdi.h>

#define MAX_LOADSTRING 100
#define TMR_1 1
#define TMR_2 2
#define TMR_3 3
#define TMR_4 4

HINSTANCE hInst;
TCHAR szTitle[MAX_LOADSTRING];
TCHAR szWindowClass[MAX_LOADSTRING];

INT value;
bool startujemy = false;
int timer = 0;
int i = 0;
int j = 0;
int k = 0;
int e = 0;
int t = 0;
int tx = 0; // x trojkat
int ty = 0; // y trojkat
int P1 = 1;
int P2 = 2;
int P3 = 3;
int l_trojkatow;
int ktory_trojkat;
int wieza = 0;
int m = 0;

//sta³e bêd¹ce koordynatami rysowanych figur;

const int drawAreaA1 = 0;
const int drawAreaA2 = 0;
const int drawAreaA3 = 800;
const int drawAreaA4 = 350;
const int drawAreaB1 = 10;
const int drawAreaB2 = 25;
const int drawAreaB3 = 630;
const int drawAreaB4 = 340;
const int dzwigA1 = 10;
const int dzwigA2 = 10;
const int dzwigA3 = 630;
const int dzwigA4 = 25;
const int dzwigB1 = 160;
const int dzwigB2 = 24;
const int dzwigB3 = 172;
const int dzwigB4 = 170;
const int dzwigC1 = 153;
const int dzwigC2 = 169;
const int dzwigC3 = 180;
const int dzwigC4 = 175;
const int platforma1 = 10;
const int platforma2 = 350;
const int platforma3 = 180;
const int platforma4 = 340;
const int trojkat_start_1x = 540;
const int trojkat_start_1y = 280;
const int trojkat_start_2x = 510;
const int trojkat_start_2y = 340;
const int trojkat_start_3x = 570;
const int trojkat_start_3y = 340;
const int trojkat_wysokosc = trojkat_start_2y - trojkat_start_1y;
const int kwadrat_start1 = 370;
const int kwadrat_start2 = 340;
const int kwadrat_start3 = 310;
const int kwadrat_start4 = 280;
const int kolo1 = 470;
const int kolo2 = 340;
const int kolo3 = 410;
const int kolo4 = 280;
int tx1;
int ty1;
int tx2;
int ty2;
int tx3;
int ty3;
int Ttx[50];
int Tty[50];
int granica_p = -13;
int granica_l = -156;
int wieza_y = 0;



HWND hwndButton;


int col = 0;
std::vector<Point> data;
RECT drawArea1 = { drawAreaA1, drawAreaA2, drawAreaA3, drawAreaA4 };
RECT drawArea2 = { drawAreaB1, drawAreaB2, drawAreaB3, drawAreaB4 };

ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	Buttons(HWND, UINT, WPARAM, LPARAM);
int czy_trojkat(int j);
void jaki_zaczepiony();
void czy_mozna_odczepic(HWND hWnd, HDC& hdc, PAINTSTRUCT& ps);


void jaki_zaczepiony()
{
	if (czy_trojkat(i) == 1)
	{
		if (i > 260 && i < 287 && (j + 170) >= 275)
		{
			t = ktory_trojkat;
			l_trojkatow++;
			tx = -100;
			ty = 0;
			MessageBox(NULL, L"Zaczepiono trojkat", L"Ale jazda", MB_OK);
		}
		if (i > 160 && i < 187 && (j + 170) >= 275)
		{
			t = ktory_trojkat;
			l_trojkatow++;
			tx = -200;
			ty = 0;
			MessageBox(NULL, L"Zaczepiono trojkat", L"Ale jazda", MB_OK);
		}
		if (i > 360 && i < 387 && (j + 170) >= 275)
		{
			t = ktory_trojkat;
			l_trojkatow++;
			tx = 0;
			ty = 0;
			MessageBox(NULL, L"Zaczepiono trojkat", L"Ale jazda", MB_OK);
		}
	}
}

void czy_mozna_odczepic(HWND hWnd, HDC& hdc, PAINTSTRUCT& ps)
{
	if (m < 3)
	{
		if (i <= granica_p+20 && i>= granica_l-20 && (j + 170) >= (275 - wieza_y))
		{
			t = 0;
			if (Tty[ktory_trojkat - 1] == 0 - wieza_y)
			{
				MessageBox(NULL, L"Odczepiono trojkat", L"I co teraz?", MB_OK);
			}
			else
			{
				MessageBox(NULL, L"Korekta wysokosci... Odczepiono trojkat.", L"I co teraz?", MB_OK);
				Tty[ktory_trojkat - 1] = 0 - wieza_y;
				j = j - wieza_y;

			}

			ktory_trojkat++;
			granica_p = i+40;
			granica_l = i-40;
			wieza_y = wieza_y + 60;
			tx = 0;
			ty = 0;
			m++;
			if (m > 1)
				MessageBox(NULL, L"Wieza zwiekszyla sie, max wysokosc: 3", L"I co teraz?", MB_OK);
		}
	}
	else
		MessageBox(NULL, L"Nie mozna zbudowac wiekszej wiezy", L"Smuteczek...", MB_OK);
}



void MyOnPaint(HDC hdc)
{
	Rectangle(hdc, dzwigA1, dzwigA2, dzwigA3, dzwigA4);
	Rectangle(hdc, dzwigB1, dzwigB2, dzwigB3, dzwigB4);
	Rectangle(hdc, dzwigC1, dzwigC2, dzwigC3, dzwigC4);

	HBRUSH hBrush = CreateSolidBrush(RGB(200, 60, 60));
	HBRUSH hOldBrush = SelectBrush(hdc, hBrush);

	Rectangle(hdc, platforma1, platforma2, platforma3, platforma4);

	SelectBrush(hdc, hOldBrush);
	DeleteObject(hBrush);


	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(51, 102, 255));
	HPEN hOldPen = SelectPen(hdc, hPen);

	 hBrush = CreateSolidBrush(RGB(77, 195, 255));
	 hOldBrush = SelectBrush(hdc, hBrush);


		 for (int i1 = 0; i1 < l_trojkatow+1; i1++)
		 {
			 POINT vertices1[] = { {(trojkat_start_1x + Ttx[i1]), (trojkat_start_1y + Tty[i1])}, {(trojkat_start_2x + Ttx[i1]), (trojkat_start_2y + Tty[i1])}, {(trojkat_start_3x + Ttx[i1]), (trojkat_start_3y + Tty[i1])} };
			 Polygon(hdc, vertices1, sizeof(vertices1) / sizeof(vertices1[0]));
		 }
	 Rectangle(hdc, kwadrat_start1, kwadrat_start2, kwadrat_start3, kwadrat_start4);
	 Ellipse(hdc, kolo1, kolo2, kolo3, kolo4);

	SelectBrush(hdc, hOldBrush);
	DeleteObject(hBrush);

	SelectPen(hdc, hOldPen);
	DeleteObject(hPen);
}

void dzwig(HDC hdc)
{
	if ((i + dzwigB3) <= 620 && (i + dzwigB1) >= 20 && (j + dzwigB4) <= 275 && (j + dzwigB4) >= 70)
	{
		Rectangle(hdc, 160 + i, 24, 172 + i, 170 + j);
		Rectangle(hdc, 153+i, 169 + j, 180+i, 175 + j);
	}

	else if ((j + dzwigB4) < 70)
	{
		Rectangle(hdc, 160 + i, 24, 172 + i, 70);
		Rectangle(hdc, 153 + i, 69, 180 + i, 75);
	}
	else if ((j + dzwigB4) > 275)
	{
		Rectangle(hdc, 160 + i, 24, 172 + i, 275);
		Rectangle(hdc, 153 + i, 274, 180 + i, 280);
	}
	else if ((i + dzwigB1) < 20)
	{
		Rectangle(hdc, 19, 24, 31, 170 + j);
		Rectangle(hdc, 12, 169 + j, 39, 175 + j);
	}
	else if ((i + dzwigB3) > 620)
	{
		Rectangle(hdc, 609, 24, 621, 170 + j);
		Rectangle(hdc, 602, 169 + j, 629, 175 + j);
	}

}

void figury(HDC hdc)
{
	{
		Ttx[ktory_trojkat-1] = tx;
		Tty[ktory_trojkat-1] = ty;
	}

	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(51, 102, 255));
	HPEN hOldPen = SelectPen(hdc, hPen);

	HBRUSH hBrush = CreateSolidBrush(RGB(77, 195, 255));
	HBRUSH hOldBrush = SelectBrush(hdc, hBrush);


	switch (P1 % 3)
	{
	case 1:
		Rectangle(hdc, kwadrat_start1, kwadrat_start2, kwadrat_start3, kwadrat_start4);

		break;
	case 2:
		Ellipse(hdc, kolo1-100, kolo2, kolo3-100, kolo4);
		break;
	case 0:
		POINT vertices3[] = { {(kwadrat_start1), (kwadrat_start2)}, {(kwadrat_start3), (kwadrat_start2)}, {((kwadrat_start1 + kwadrat_start3) / 2), (kwadrat_start4)} };
		Polygon(hdc, vertices3, sizeof(vertices3) / sizeof(vertices3[0]));
		break;
	}

	switch (P2 % 3)
	{
	case 1:
		Rectangle(hdc, kwadrat_start1+100, kwadrat_start2, kwadrat_start3+100, kwadrat_start4);

		break;
	case 2:
		Ellipse(hdc, kolo1, kolo2, kolo3, kolo4);
		break;
	case 0:
		POINT vertices2[] = { {(kolo1), (kolo2)}, {(kolo3), (kolo2)}, {((kolo1 + kolo3) / 2 ), (kolo4)} };
		Polygon(hdc, vertices2, sizeof(vertices2) / sizeof(vertices2[0]));
		break;
	}

	switch (P3 % 3)
	{
	case 1:
		Rectangle(hdc, kwadrat_start1+200, kwadrat_start2, kwadrat_start3+200, kwadrat_start4);

		break;
	case 2:
		Ellipse(hdc, kolo1+100, kolo2, kolo3+100, kolo4);
		break;
	case 0:
		POINT vertices1[] = { {(trojkat_start_1x), (trojkat_start_1y)}, {(trojkat_start_2x), (trojkat_start_2y)}, {(trojkat_start_3x), (trojkat_start_3y)} };
		Polygon(hdc, vertices1, sizeof(vertices1) / sizeof(vertices1[0]));
		break;
	}



	for (int i1 = 0; i1 < l_trojkatow-1  ; i1++)
	{
		POINT vertices1[] = { {(trojkat_start_1x + Ttx[i1]), (trojkat_start_1y + Tty[i1])}, {(trojkat_start_2x + Ttx[i1]), (trojkat_start_2y + Tty[i1])}, {(trojkat_start_3x + Ttx[i1]), (trojkat_start_3y + Tty[i1])} };
		Polygon(hdc, vertices1, sizeof(vertices1) / sizeof(vertices1[0]));
	}



	SelectBrush(hdc, hOldBrush);
	DeleteObject(hBrush);


}

void paint(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps, RECT *drawArea)
{
	InvalidateRect(hWnd, drawArea, TRUE);
	hdc = BeginPaint(hWnd, &ps);
	MyOnPaint(hdc);
	EndPaint(hWnd, &ps);
}

void repaintWindow(HWND hWnd, HDC &hdc, PAINTSTRUCT &ps, RECT *drawArea)
{
	if (startujemy == true)
	{
		hdc = GetDC(hWnd);
		if (drawArea == NULL)
		{
			InvalidateRect(hWnd, NULL, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
		}

		else

			InvalidateRect(hWnd, drawArea, TRUE);
		hdc = BeginPaint(hWnd, &ps);
		dzwig(hdc);
		figury(hdc);
		EndPaint(hWnd, &ps);
		SwapBuffers(hdc);
		ReleaseDC(hWnd, hdc);
	}


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

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	MSG msg;
	HACCEL hAccelTable;



	l_trojkatow = 1;
	ktory_trojkat = 1;
	value = 0;



	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);


	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);




	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAW));


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



int czy_trojkat(int i)
{

	if (i > 160 && i < 187)
	{
		if (P1 % 3 == 0)
			return 1;
		else
			return 0;
	}

	if (i > 260 && i< 287)
	{
		if (P2 % 3 == 0)
			return 1;
		else
			return 0;
	}

	if (i > 360 && i < 387)
	{
		if (P3 % 3 == 0)
			return 1;
		else
			return 0;
	}

}

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


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;


	hInst = hInstance;

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);


	hwndButton = CreateWindow(TEXT("button"),
		TEXT("Start"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		667, 10,
		85, 50,
		hWnd,
		(HMENU)ID_BUTTON0,
		hInstance,
		NULL);

	hwndButton = CreateWindow(TEXT("button"),
		TEXT("1"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		300, 350,
		80, 50,
		hWnd,
		(HMENU)ID_BUTTON1,
		hInstance,
		NULL);

	hwndButton = CreateWindow(TEXT("button"),
		TEXT("2"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		400, 350,
		80, 50,
		hWnd,
		(HMENU)ID_BUTTON2,
		hInstance,
		NULL);

	hwndButton = CreateWindow(TEXT("button"),
		TEXT("3"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		500, 350,
		80, 50,
		hWnd,
		(HMENU)ID_BUTTON3,
		hInstance,
		NULL);

	hwndButton = CreateWindow(TEXT("button"),
		TEXT("Grab"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		667, 200,
		85, 50,
		hWnd,
		(HMENU)ID_BUTTON4,
		hInstance,
		NULL);

	hwndButton = CreateWindow(TEXT("button"),
		TEXT("Release"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		667, 260,
		85, 50,
		hWnd,
		(HMENU)ID_BUTTON5,
		hInstance,
		NULL);

	hwndButton = CreateWindow(TEXT("button"), TEXT("<-"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		645, 120, 40, 30, hWnd, (HMENU)ID_RBUTTON1, GetModuleHandle(NULL), NULL);

	hwndButton = CreateWindow(TEXT("button"), TEXT("->"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		735, 120, 40, 30, hWnd, (HMENU)ID_RBUTTON2, GetModuleHandle(NULL), NULL);

	hwndButton = CreateWindow(TEXT("button"), TEXT("^"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		690, 80, 40, 30, hWnd, (HMENU)ID_RBUTTON3, GetModuleHandle(NULL), NULL);

	hwndButton = CreateWindow(TEXT("button"), TEXT("v"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		690, 160, 40, 30, hWnd, (HMENU)ID_RBUTTON4, GetModuleHandle(NULL), NULL);

	hwndButton = CreateWindow(TEXT("button"), TEXT("P"),
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

		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_BUTTON0: //start
			startujemy = true;
			P1 = 1;
			P2 = 2;
			P3 = 3;
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
			KillTimer(hWnd, TMR_1);
			KillTimer(hWnd, TMR_2);
			KillTimer(hWnd, TMR_3);
			KillTimer(hWnd, TMR_4);
			P1++;
			break;
		case ID_BUTTON2 :
			KillTimer(hWnd, TMR_1);
			KillTimer(hWnd, TMR_2);
			KillTimer(hWnd, TMR_3);
			KillTimer(hWnd, TMR_4);
			P2++;
			break;
		case ID_BUTTON3:
			KillTimer(hWnd, TMR_1);
			KillTimer(hWnd, TMR_2);
			KillTimer(hWnd, TMR_3);
			KillTimer(hWnd, TMR_4);
			P3++;
			break;
		case ID_BUTTON4:
			KillTimer(hWnd, TMR_1);
			KillTimer(hWnd, TMR_2);
			KillTimer(hWnd, TMR_3);
			KillTimer(hWnd, TMR_4);
			jaki_zaczepiony();
			repaintWindow(hWnd, hdc, ps, &drawArea2);
			break;
		case ID_BUTTON5:
			KillTimer(hWnd, TMR_1);
			KillTimer(hWnd, TMR_2);
			KillTimer(hWnd, TMR_3);
			KillTimer(hWnd, TMR_4);
			czy_mozna_odczepic(hWnd, hdc, ps);
			repaintWindow(hWnd, hdc, ps, &drawArea2);
			break;
		case ID_RBUTTON1:
			SetTimer(hWnd, TMR_1, 100, 0);
			KillTimer(hWnd, TMR_2);
			KillTimer(hWnd, TMR_3);
			KillTimer(hWnd, TMR_4);
			break;
		case ID_RBUTTON2:
			SetTimer(hWnd, TMR_2, 100, 0);
			KillTimer(hWnd, TMR_1);
			KillTimer(hWnd, TMR_3);
			KillTimer(hWnd, TMR_4);
			break;
		case ID_RBUTTON3:
			SetTimer(hWnd, TMR_3, 100, 0);
			KillTimer(hWnd, TMR_1);
			KillTimer(hWnd, TMR_2);
			KillTimer(hWnd, TMR_4);
			break;
		case ID_RBUTTON4:
			SetTimer(hWnd, TMR_4, 100, 0);
			KillTimer(hWnd, TMR_1);
			KillTimer(hWnd, TMR_2);
			KillTimer(hWnd, TMR_3);

			break;
		case ID_RBUTTON5:
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
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case TMR_1: //lewo
			if ((i + 160 ) >= 20 )
			{
				//i--;
				i = i - 4;
				if (t > 0)
					tx = tx - 4;

				repaintWindow(hWnd, hdc, ps, &drawArea2);
			}
			break;
		case TMR_2:
			if ((i + 172) <= 620) // prawo
			{
				//i++;
				i = i + 4;
				if (t > 0 )
					tx = tx + 4;

				repaintWindow(hWnd, hdc, ps, &drawArea2);
			}
			break;
		case TMR_3:
			if ((j + 170) >= 70 ) //gora
			{
				if ((j + 170) == (275 - wieza_y))
				{
					KillTimer(hWnd, TMR_3);
				}
				//j--;
				j = j - 4;
				if (t > 0)
					ty = ty - 4;


				repaintWindow(hWnd, hdc, ps, &drawArea2);
			}
			break;
		case TMR_4: //dol
			if ((j + 170) <= 275)
			{

				//j++;
				j = j + 4;
				if (t > 0)
					ty = ty + 4;


				repaintWindow(hWnd, hdc, ps, &drawArea2);
			}
			break;
		}

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

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
