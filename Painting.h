#pragma once
#include "abstract_brush.h"
#include "brush.h"
#include "eraser.h"
#include "Points.h"
#include <GL/glut.h>

#define N 100
using namespace std;

class Painting {
private:
	brush* brush_mode = new brush;
	eraser* eraser_mode = new eraser;
	abstract_brush* current_mode = brush_mode;
	Points* points = new Points;
public:
	void init();
	void Mouse(int button, int state, int x, int y) { current_mode->mouse(*points, button, state, x, y); }
	void Motion(int x, int y) { current_mode->motion(*points, x, y); }
	void Display() {  current_mode->draw(*points); }
	void SetBrush() { current_mode = brush_mode; }
	void SetEraser() { current_mode = eraser_mode; }
	void MakeBig() { current_mode->SetSize(20); }
	void MakeSmall() { current_mode->SetSize(5); }
	void MakeOrange() { current_mode->SetColor(40); }
	void MakeRed() { current_mode->SetColor(255); }
	void SwitchMenu(int item);
	void MakeMenu();


	void save(string& filename) {
		std::ofstream out;
		out.open(filename);

		for (int i = 0; i < points->GetSize(); i++) {
			out << points->GetPoint(i);
		}
		out.close();
	}

	void load(string& filename) {
		ifstream in;
		in.open(filename);
		char tmp;
		for (int i = 0; i < N; i++) {
			in >> tmp;
			points->Push(tmp, 0);
		}
		in.close();
	}

};
extern Painting* paint;


