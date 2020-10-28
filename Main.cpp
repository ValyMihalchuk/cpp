

#include "stdafx.h"
#include "Main.h"

#define MAX_LOADSTRING 100
#include "Level.h"
#include "Graphics.h"


#define TIME_OF_RelaxR 1001
#define SEARCH_Pacman_TIMER 1002


Level level;


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
char szClassName[] = "CG_WAPI_Template";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASS wc;

	ifstream inFile;
	inFile.open("labyrinth.txt", std::ifstream::in);

	level.InitLevel(inFile);


	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = (LPCWSTR)szClassName;


	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, (LPCWSTR)"Не могу зарегистрировать класс окна!", (LPCWSTR)"Ошибка", MB_OK);
		return 0;
	}

	// Создаем основное окно приложения
	hWnd = CreateWindow(
		(LPCWSTR)szClassName, // Имя класса 
		L"Шаблон WinAPI приложения", // Текст заголовка
		WS_OVERLAPPEDWINDOW, // Стиль окна 
		50, 50, // Позиция левого верхнего угла 
		1000, 1000, // Ширина и высота окна 
		(HWND)NULL, // Указатель на родительское окно NULL 
		(HMENU)NULL, // Используется меню класса окна 
		(HINSTANCE)hInstance, // Указатель на текущее приложение
		NULL); // Передается в качестве lParam в событие WM_CREATE

	SetTimer(hWnd, TIME_OF_RelaxR, 1000 * 7, NULL);     // no timer callback 
	SetTimer(hWnd, SEARCH_Pacman_TIMER, 1000 * 27, NULL);

	if (!hWnd)
	{
		MessageBox(NULL, (LPCWSTR)"Не удается создать главное окно!", (LPCWSTR)"Ошибка", MB_OK);
		return 0;
	}

	// Показываем наше окно
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// Выполняем цикл обработки сообщений до закрытия приложения
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return (lpMsg.wParam);
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	RECT Rect;
	HDC hdc, hCmpDC;
	HBITMAP hBmp;

	SetTimer(hWnd, 1, 100, NULL);
	switch (messg)
	{
	case WM_TIMER:
		InvalidateRect(hWnd, NULL, FALSE);
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_LEFT:
			level.ChangePacmandir(LEFT);
			break;
		case VK_RIGHT:
			level.ChangePacmandir(RIGHT);
			break;
		case VK_UP:
			level.ChangePacmandir(TOP);
			break;
		case VK_DOWN:
			level.ChangePacmandir(DOWN);
			break;
		}
		InvalidateRect(hWnd, NULL, FALSE);
	case WM_PAINT:
		GetClientRect(hWnd, &Rect);
		hdc = BeginPaint(hWnd, &ps);

	
		hCmpDC = CreateCompatibleDC(hdc);
		hBmp = CreateCompatibleBitmap(hdc, Rect.right - Rect.left,
			Rect.bottom - Rect.top);
		SelectObject(hCmpDC, hBmp);


		LOGBRUSH br;
		br.lbStyle = BS_SOLID;
		br.lbColor = 0xEECCCC;
		HBRUSH brush;
		brush = CreateBrushIndirect(&br);
		FillRect(hCmpDC, &Rect, brush);
		DeleteObject(brush);


		level.Play();

		Display(hCmpDC, level);


		SetStretchBltMode(hdc, COLORONCOLOR);
		BitBlt(hdc, 0, 0, Rect.right - Rect.left, Rect.bottom - Rect.top,
			hCmpDC, 0, 0, SRCCOPY);


		DeleteDC(hCmpDC);
		DeleteObject(hBmp);
		hCmpDC = NULL;

		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return (DefWindowProc(hWnd, messg, wParam, lParam));
	}
	return (0);
}
