#include<Windows.h>
#include<Math.h>
#include<gl\glew.h>
#include<gl\GL.h>
#include<gl\GLU.h>
#include<iostream>

#ifndef _ISCENE_H
#define _ISCENE_H

/*REFERENCE FOR HEASER GUARDS
https://en.wikipedia.org/wiki/Include_guard
*/

enum SCENE_NUMBER
{
	MAIN,
	PRATIK,
	PRAVEEN,
	RAHUL,
	SURAJ
};

class IOpenGL
{
public:
	static IOpenGL* GetInstance(SCENE_NUMBER scene);
	virtual BOOL SceneHandler(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) = 0;
	virtual void Initialize()= 0;
	virtual void Update() = 0;
	virtual void Resize(int width, int height) = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void SceneTransition() = 0;
	virtual void UnInitialize() = 0;
};

#endif