#pragma once
#include "Points.h"
class abstract_brush {
public:
	int size;
	int color;
	void mouse(Points& points, int button, int state, int x, int y);
	void motion(Points& points, int x, int y);
	void draw(Points& points);
	virtual void SetColor(int c) = 0;
	virtual void SetSize(int change) = 0;

};
