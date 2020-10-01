#pragma once
#include "stdafx.h"
#include "lab2.h"
using namespace std;

col Draw::GetTypeOfCollision(RECT rcClient) {

	if (point.x + H + dir.GetPoint().x > rcClient.right)
		return right_col;
	else if (point.x + dir.GetPoint().x < rcClient.left)
		return left_col;
	else if (point.y - H + dir.GetPoint().y < rcClient.top)
		return down_col;
	else if (point.y + dir.GetPoint().y > rcClient.bottom)
		return top_col;
	else
		return no_col;
}



void Draw::AppendToDir(POINT new_dir) {
	Vector temp;
	temp.setPoint(new_dir);
	dir += temp;
}

void Draw::ToHandleCollision(RECT rcClient, Vector &new_dir) {

	switch (GetTypeOfCollision(rcClient)) {

	case right_col:
		dir.setX(-dir.GetPoint().x);
		break;

	case left_col:
		dir.setX(-dir.GetPoint().x);
		break;

	case top_col:
		dir.setY(-dir.GetPoint().y);
		break;

	case down_col:
		dir.setY(-dir.GetPoint().y);
		break;

	case no_col:
		point.x += dir.GetPoint().x;
		point.y += dir.GetPoint().y;
		break;
	}
}

void Draw::Init() {
	point.x = H;
	point.y = 2*H;
}

void Draw::DoDraw(HDC hdc) {

	static list <POINT> prev;
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
	list <POINT> ::iterator it;
	for (it = prev.begin(); it != prev.end(); it++) {
		hBrush = CreateSolidBrush(RGB(R, G, B));
		SelectObject(hdc, hBrush);
		Rectangle(hdc, (*it).x, (*it).y, (*it).x + H, (*it).y - H);
		DeleteObject(hBrush);
		R += 20;
		G += 20;
	}

}
