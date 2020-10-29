#pragma once

#include "Painting.h"


void mouse(int button, int state, int x, int y) {
	paint->Mouse(button, state, x, y);
}
void motion(int x, int y)
{
	paint->Motion(x, y);
}

void display()
{
	paint->Display();
}

void menu(int i) {
	paint->SwitchMenu(i);
}
void Painting::SwitchMenu(int item)
{
	switch (item)
	{
	case 1:
		SetBrush();
		break;
	case 2:
		SetEraser();
		break;
	case 3:
		MakeBig();
		break;
	case 4:
		MakeSmall();
		break;
	case 5:
		MakeRed();
		break;
	case 6:
		MakeOrange();
		break;
	}

	glutPostRedisplay();

	return;
}
void Painting::MakeMenu()
{
	glutCreateMenu(menu);
	glutAddMenuEntry("Brush",1);
	glutAddMenuEntry("Eraser", 2);
	glutAddMenuEntry("Big",3);
	glutAddMenuEntry("Small", 4);
	glutAddMenuEntry("Red", 5);
	glutAddMenuEntry("Blue", 6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void Painting::init() {
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("GLUT");
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutDisplayFunc(display);
	MakeMenu();
	glutMainLoop();
}

