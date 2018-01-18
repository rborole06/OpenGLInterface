#include "MySquare.h"


MySquare::MySquare(HDC hdc)
{
	ghdc = hdc;
	//MessageBox(NULL, TEXT("eee"), TEXT("ddda"), MB_OK);
}


MySquare::~MySquare()
{
}

void MySquare::update()
{
	// code
	anglePyramid = anglePyramid - 0.05f;
	if (anglePyramid <= 360.0f)
		anglePyramid = anglePyramid + 360.0f;
}

void MySquare::display()
{
	void drawSquare();

	//code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(anglePyramid, 0.0f, 0.0f, 1.0f);

	drawSquare();
	//MessageBox(NULL, TEXT("eee"), TEXT("ddda"), MB_OK);

	SwapBuffers(ghdc);
}

void drawSquare()
{
	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 0.0f);

	glVertex2f(1.0f, 1.0f);

	glVertex2f(-1.0f, 1.0f);

	glVertex2f(-1.0f, -1.0f);

	glVertex2f(1.0f, -1.0f);

	glEnd();
}
