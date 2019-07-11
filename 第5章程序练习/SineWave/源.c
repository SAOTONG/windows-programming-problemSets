/*-----------------------------------------
SINEWAVE.C -- Sine Wave Using Polyline
(c) Charles Petzold, 1998
-----------------------------------------*/

#include <windows.h>
#include <math.h>

#define NUM    1000
#define TWOPI  (2 * 3.14159)

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("SineWave");
	HWND         hwnd;
	MSG          msg;
	WNDCLASS     wndclass;
	//
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	//注册窗口类
	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("Program requires Windows NT!"),
			szAppName, MB_ICONERROR);
		return 0;
	}

	//根据窗口类创建窗口
	hwnd = CreateWindow(szAppName, TEXT("Sine Wave Using Polyline"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	//展示窗户口
	ShowWindow(hwnd, iCmdShow);
	//该函数向窗口过程发送一个WM_PAINT消息来绘制客户区域
	UpdateWindow(hwnd);

	//从消息队列取消息
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int  cxClient, cyClient;
	HDC         hdc;
	int         i;
	PAINTSTRUCT ps;
	//供矩形使用的POINT数组
	//POINT       apt[5] = {100,100,200,100,200,200,100,200,100,100};
	//供正弦波使用的POINT数组
	POINT       apt[NUM];
	//供网格使用的RECT结构
	RECT        rect;
	//供网格使用的变量x
	int         x;
	//供网格使用的变量y
	int         y;
	switch (message)
	{
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		return 0;

	case WM_PAINT:
		hdc =	(hwnd, &ps);

		//网格
		GetClientRect(hwnd, &rect);
		for ( x = 0; x < rect.right; x+=100)
		{
			MoveToEx(hdc, x, 0, NULL);
			LineTo(hdc, x, rect.bottom);
		}
		for ( y = 0; y < rect.bottom; y+=100)
		{
			MoveToEx(hdc, 0, y, NULL);
			LineTo(hdc, rect.right, y);
		}

		//矩形
		/*MoveToEx(hdc, apt[0].x, apt[0].y, NULL);
		for (int i = 0; i < 5; i++)
		{
			LineTo(hdc, apt[i].x, apt[i].y);
		}*/

		//矩形
		/*Polyline(hdc, apt, 5);*/

		//矩形
		/*MoveToEx(hdc, apt[0].x, apt[0].y, NULL);
		PolylineTo(hdc, apt + 1, 4);*/

		//正弦波
		/*MoveToEx(hdc, 0, cyClient / 2, NULL);
		LineTo(hdc, cxClient, cyClient / 2);

		for (i = 0; i < NUM; i++)
		{
			apt[i].x = i * cxClient / NUM;
			apt[i].y = (int)(cyClient / 2 * (1 - sin(TWOPI * i / NUM)));
		}

		Polyline(hdc, apt, NUM);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
