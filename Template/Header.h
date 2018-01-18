#pragma once

#ifndef GRANDPARENT_H
#define GRANDPARENT_H

#include<Windows.h>
#include<gl\GL.h>
#include<gl\GLU.h>
#include<iostream>

#include "MySquare.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#define PI 3.1415926535898

#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")


	//Prototype Of WndProc() declared Globally
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	//Global variable declarations
	HWND ghwnd = NULL;
	HDC ghdc = NULL;
	HGLRC ghrc = NULL;

	DWORD dwStyle;
	WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };

	bool gbActiveWindow = false;
	bool gbEscapeKeyIsPressed = false;
	bool gbFullscreen = false;
	bool gbIsAPressed = false;

	GLfloat anglePyramid = 0.0f;

	MyScenes *myScenes;

#endif