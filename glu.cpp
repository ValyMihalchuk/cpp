#pragma once
#include"glu.h"

using namespace std;

int windh, windw;


void Reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
	glMatrixMode(GL_MODELVIEW);
	windw = w;
	windh = h;
}


void init(mouse_func proccessMouse, render_func renderScene, render_func idl) {

	static bool isMenu = true;

	char Param[] = "param";
	char *argv[] = { Param, NULL };
	int argc = 1;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(700, 600);
	if (isMenu)
	{
		glutCreateWindow("Menu");
		isMenu = false;
	}
	glutDisplayFunc(renderScene);
	glutReshapeFunc(Reshape);
	glutIdleFunc(renderScene);
	glutMouseFunc(proccessMouse);
}






void NewWindow(int argc, char** argv, mouse_func proccessMouse, render_func renderScene) {
	glutInitWindowPosition(300, 300);
	glutInitWindowSize(300, 300);
	glutCreateWindow("Dialog");

	init(proccessMouse, renderScene, renderScene);
	
}
