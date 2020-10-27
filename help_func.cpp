#pragma once
#include "draw_menu.h"
#include "my_tree.h"


void start(string& structure) {
	m = text(structure).MakeTree();
	init(proccessMouse, renderScene, renderScene);
	glutMainLoop();
}

void DrawString(std::string& str) {
	for (auto s : str) {
		if (s == '(')
			return;
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s);
	}
}


void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLineWidth(2.0f);
	glColor3f(10, 20, 90);
	m->DrawCh(400, 600);
	glFinish();
	glutSwapBuffers();
}

void proccessMouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			m->ToClick(point((float)x - 350, -((float)y - 300)));
	}
}