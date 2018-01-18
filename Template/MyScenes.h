#pragma once
#include <Windows.h>

class MyScenes
{
public:
	static MyScenes* getInstance(HDC hdc,int sceneNumber);
	virtual void update() = 0;
	virtual void display() = 0;
};