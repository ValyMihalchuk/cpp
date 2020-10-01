#pragma once
#include "stdafx.h"
#include "lab2.h"
using namespace std;

Vector& Vector::operator += (Vector& direct) {
	point.x += direct.point.x;
	point.y += direct.point.y;
	return *this;
}


void Vector::setX(float X) {
	point.x = X;
}

void Vector::setY(float Y) {
	point.y = Y;
}

void Vector::setPoint(POINT new_point)
{
	point = new_point;
}

POINT Vector::GetPoint() {
	return point;
}

