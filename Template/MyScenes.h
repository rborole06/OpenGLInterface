#pragma once
#include <Windows.h>
#include<gl\GL.h>
#include<gl\GLU.h>
#include<iostream>

class MyScenes
{
public:
	static MyScenes* getInstance(HDC hdc,int sceneNumber);
	virtual void update() = 0;
	virtual void display() = 0;
};