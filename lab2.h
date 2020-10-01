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
	POINT point;
public:

	Vector& operator += (Vector& direct);
	void setX(float X);
	void setY(float Y);
	void setPoint(POINT new_point);
	POINT GetPoint();
};


class Draw {
private:
	Vector dir;
	POINT point;
	col GetTypeOfCollision(RECT rcClient);
public:
	POINT LEFT = { -1,  0 };
	POINT RIGHT = { 1,  0 };
	POINT UP = { 0,  -1 };
	POINT DOWN = { 0,  1 };

	void AppendToDir(POINT new_dir);
	void ToHandleCollision(RECT rcClient, Vector &new_dir);
	void Init();
	void DoDraw(HDC hdc);

};