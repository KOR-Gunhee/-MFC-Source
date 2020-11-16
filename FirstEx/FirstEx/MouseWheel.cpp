#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevinstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS WndClass;
	HWND hwnd;
	MSG msg;

	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = TEXT("MOuseClass");
	if (!RegisterClass(&WndClass))
		return 1;

	hwnd = CreateWindow(
		TEXT("MouseClass"),
		TEXT("MouseSDK"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	ShowWindow(hwnd, nCmdShow);

	while (GetMessage(&msg, NULL, 0, 0 ) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	TCHAR str1[200] = TEXT("마우스 휠을 움직여 보세요");

	switch (message)
	{
	case WM_CREATE:
		return 0;

	case WM_MOUSEWHEEL:
		MessageBox(hwnd, TEXT("마우스 휠을 움직이셨습니다."), TEXT("마우스 휠 조작!"), MB_OK);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}