#pragma once
#include "MyScenes.h"

#include<Windows.h>
#include<gl\GL.h>
#include<gl\GLU.h>
#include<iostream>

class MySquare : public MyScenes
{
public:
	HDC ghdc;
	GLfloat anglePyramid = 360.0f;

	MySquare(HDC hdc);
	~MySquare();

	// Inherited via MyScenes
	virtual void update() override;
	virtual void display() override;
};