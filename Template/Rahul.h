#pragma once
#include "MyScenes.h"

class Rahul : public MyScenes
{
public:
	HDC ghdc;
	GLfloat angleSphere = 0.0f;
	GLfloat angleRedLight = 0.0f;
	GLfloat angleGreenLight = 0.0f;
	GLfloat angleBlueLight = 0.0f;
	GLUquadric *quadric = NULL;

	// light 0 components (red light)
	GLfloat light_0_ambient[4] = { 0.0f,0.0f,0.0f,0.0f };
	GLfloat light_0_diffuse[4] = { 1.0f,0.0f,0.0f,0.0f };
	GLfloat light_0_specular[4] = { 1.0f,0.0f,0.0f,0.0f };
	GLfloat light_0_position[4] = { 0.0f,0.0f,0.0f,0.0f };

	// light 1 components (green light)
	GLfloat light_1_ambient[4] = { 0.0f,0.0f,0.0f,0.0f };
	GLfloat light_1_diffuse[4] = { 0.0f,1.0f,0.0f,0.0f };
	GLfloat light_1_specular[4] = { 0.0f,1.0f,0.0f,0.0f };
	GLfloat light_1_position[4] = { 0.0f,0.0f,0.0f,0.0f };

	// light 2 components (blue light)
	GLfloat light_2_ambient[4] = { 0.0f,0.0f,0.0f,0.0f };
	GLfloat light_2_diffuse[4] = { 0.0f,0.0f,1.0f,0.0f };
	GLfloat light_2_specular[4] = { 0.0f,0.0f,1.0f,0.0f };
	GLfloat light_2_position[4] = { 0.0f,0.0f,0.0f,0.0f };

	// material array
	GLfloat material_ambient[4] = { 0.0f,0.0f,0.0f,0.0f };
	GLfloat material_diffuse[4] = { 1.0f,1.0f,1.0f,1.0f };
	GLfloat material_specular[4] = { 1.0f,1.0f,1.0f,1.0f };
	GLfloat material_shininess[4] = { 50.0f,50.0f,50.0f,0.0f };

	Rahul(HDC hdc);
	~Rahul();

	// Inherited via MyScenes
	virtual void update() override;
	virtual void display() override;
};
