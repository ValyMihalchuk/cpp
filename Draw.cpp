#pragma once
#include "stdafx.h"
#include "lab2.h"
using namespace std;

col Draw::GetTypeOfCollision(RECT &rcClient) {

	if (point.getX() + H + dir.getX()> rcClient.right)
		return right_col;
	else if (point.getX()+ dir.getX() < rcClient.left)
		return left_col;
	else if (point.getY() - H + dir.getY()< rcClient.top)
		return down_col;
	else if (point.getY() + dir.getY() > rcClient.bottom)
		return top_col;
	else
		return no_col;
}



void Draw::ToHandleCollision(RECT &rcClient, Vector &new_dir) {

	switch (GetTypeOfCollision(rcClient)) {

	case right_col:
		dir.setX(-dir.getX());
		break;

	case left_col:
		dir.setX(-dir.getY());
		break;

	case top_col:
		dir.setY(-dir.getY());
		break;

	case down_col:
		dir.setY(-dir.getY());
		break;

	case no_col:
		point += dir;
		break;
	}
}

void Draw::Init() {
	point.setX(H);
	point.setY(2*H);
	LEFT.setX(-1);
	RIGHT.setX(1);
	UP.setY(-1);
	DOWN.setY(1);
}

void Draw::DoDraw(HDC &hdc) {

	static list <Vector> prev;
	static HBRUSH hBrush, old_brush;
	static int current = 0;
	int R = 0, G = 0, B = 255;
	if (current == AmoutOfRec)
	{
		prev.pop_back();
		current--;
	}
	prev.push_front(point);
	current++;
	list <Vector> ::iterator it;
	for (it = prev.begin(); it != prev.end(); it++) {
		hBrush = CreateSolidBrush(RGB(R, G, B));
		SelectObject(hdc, hBrush);
		Rectangle(hdc, (*it).getX(), (*it).getY(), (*it).getX() + H, (*it).getY() - H);
		DeleteObject(hBrush);
		R += 20;
		G += 20;
	}

}
