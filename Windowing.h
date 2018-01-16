#include<Windows.h>
#include<Math.h>
#include<gl\glew.h>
#include<gl\GL.h>
#include<gl\GLU.h>
#include<iostream>
#include "IOpenGL.h"

#pragma comment(lib,"glu32.lib")
#pragma comment(lib, "opengl32.lib")

enum STYLE
{
	HIDE,
	NORMAL,
	MINIMIZED,
	MAXIMIZED,
	NOACTIVATE,
	SHOW,
	MINIMIZE,
	MINNOACTIVE,
	SHOWNA,
	RESTORE,
};

class Windowing
{
public:
	Windowing(HINSTANCE hInstance, TCHAR *title);
	~Windowing();

	BOOL Register();
	BOOL Show(int width, int height, int style);
	BOOL IntializeGL();

	int StartMessageLoop();

	void ReSize(int width, int height);
	void ToggleFullScreen();

private:
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
	LRESULT CALLBACK OGLWindowingProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

	HINSTANCE hInstance;
	HWND hwnd;
	TCHAR *szAppName;
	WNDCLASSEX wndclass;
	LONG dwStyle;
	WINDOWPLACEMENT  wpPrev;
	MONITORINFO monitorInfo;
	HDC hdc;
	HGLRC hglrc;

	int width;
	int height;

	bool gbFullScreen;
	bool gbEscapeKeyIsPressed;
	bool gbActiveWindow;
	bool bDone;
	IOpenGL * scene;
};
