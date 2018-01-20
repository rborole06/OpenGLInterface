#include "Rahul.h"

Rahul::Rahul(HDC hdc)
{
	ghdc = hdc;

	glEnable(GL_LIGHTING);

	// set light source parameters for light 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_0_specular);

	// Enable the lighting for light 0
	glEnable(GL_LIGHT0);

	// set light source parameters for light 1
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_1_specular);

	// Enable the lighting for light 1
	glEnable(GL_LIGHT1);

	// set light source parameters for light 2
	glLightfv(GL_LIGHT2, GL_AMBIENT, light_2_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_2_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light_2_specular);

	// Enable the lighting for light 2
	glEnable(GL_LIGHT2);

	// material array
	glMaterialfv(GL_FRONT, GL_SHININESS, material_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, material_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);

	quadric = gluNewQuadric();
}

Rahul::~Rahul()
{
	angleSphere = 0.0f;
	angleRedLight = 0.0f;
	angleGreenLight = 0.0f;
	angleBlueLight = 0.0f;

	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHTING);

	if (quadric)
	{
		gluDeleteQuadric(quadric);
		quadric = NULL;
	}
}

void Rahul::update()
{
	angleRedLight = angleRedLight + 0.1f;
	if (angleRedLight >= 360)
	{
		angleRedLight = 0.0f;
	}
	angleGreenLight = angleGreenLight + 0.1f;
	if (angleGreenLight >= 360)
	{
		angleGreenLight = 0.0f;
	}
	angleBlueLight = angleBlueLight + 0.1f;
	if (angleBlueLight >= 360)
	{
		angleBlueLight = 0.0f;
	}
}

void Rahul::display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();

	// set camera position
	gluLookAt(0, 0, 0.1, 0, 0, 0, 0, 1, 0);

	// rotate red light around x axis
	glPushMatrix();
	glRotatef(angleRedLight, 1, 0, 0);
	light_0_position[1] = angleRedLight;
	glLightfv(GL_LIGHT0, GL_POSITION, light_0_position);
	glPopMatrix();

	// rotate green light around y axis
	glPushMatrix();
	glRotatef(angleGreenLight, 0, 1, 0);
	light_1_position[0] = angleGreenLight;
	glLightfv(GL_LIGHT1, GL_POSITION, light_1_position);
	glPopMatrix();

	// rotate blue light around z axis
	glPushMatrix();
	glRotatef(angleBlueLight, 0, 0, 1);
	light_2_position[0] = angleBlueLight;
	glLightfv(GL_LIGHT2, GL_POSITION, light_2_position);
	glPopMatrix();

	// draw sphere
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -3.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	gluSphere(quadric, 0.75, 30, 30);
	glPopMatrix();

	glPopMatrix();

	SwapBuffers(ghdc);
}