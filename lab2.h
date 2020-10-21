#pragma once

#include "resource.h"
#include <math.h>
#include <stdio.h>
#include <list>

using namespace std;

#define H 20
#define AmoutOfRec 10

enum col {
	top_col,
	down_col,
	right_col,
	left_col,
	no_col
};



class Vector {
private:
	float x = 0;
	float y = 0;
public:

	Vector& operator += (Vector& vec) {
		x += vec.x;
		y += vec.y;
		return *this;
	}
	void setX(float X) { x = X; };
	void setY(float Y) { y = Y; };
	void setPoint(Vector &new_point) { x = new_point.x; y = new_point.y; };
	float getX() { return x; };
	float getY() { return y; };

};




class Draw {
private:
	Vector dir;
	Vector point;
	col GetTypeOfCollision(RECT &rcClient);
public:
	Vector LEFT;
	Vector RIGHT;
	Vector UP;
	Vector DOWN;

	void AppendToDir(Vector &new_dir) { dir += new_dir; };
	void ToHandleCollision(RECT &rcClient, Vector &new_dir);
	void Init();
	void DoDraw(HDC &hdc);

};