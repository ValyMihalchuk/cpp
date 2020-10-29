#pragma once
#pragma once

#include "abstract_brush.h"
#include <gl/glut.h>


void abstract_brush::mouse(Points & points, int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
		points.Clear();
	points.Push(x, y);
	glutPostRedisplay();
}

void abstract_brush::motion(Points & points, int x, int y)
{
	points.Push(x, y);
	glutPostRedisplay();
}

void abstract_brush::draw(Points & points)
{
	//glClearColor(0, 0, 0, 1);
	//glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double w = glutGet(GLUT_WINDOW_WIDTH);
	double h = glutGet(GLUT_WINDOW_HEIGHT);
	glOrtho(0, w, h, 0, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBegin(GL_LINE_STRIP);
	glLineWidth(size);
	//glVertex3f(0, 5, 0);
	glColor3ub(color, 0, 50);
	for (size_t i = 0; i < points.GetSize(); i += 2)
	{
	
		glVertex3f(points.GetPoint(i), points.GetPoint(i+1), 0.0);
		//glRectf(points.GetPoint(i), points.GetPoint(i + 1), points.GetPoint(i) + 1, points.GetPoint(i) + 1);
		//glVertex2i(points.GetPoint(i), points.GetPoint(i+1));
	}
	glEnd();

	glutSwapBuffers();
}

