#pragma once
#include "draw_menu.h"
#include "my_tree.h"

bool menu_mytree::ASearch(string& s) {
	for (std::string::iterator it = this->data.begin(); it != this->data.end(); ++it) {
		if (*it == '[') {
			for (std::string::iterator jt = it; jt != this->data.end(); ++jt) {
				if (*jt == ']') {
					s = string(it + 1, jt);
					this->data.replace(it, jt + 1, "");
					return true;
				}
			}
		}
	}
	return false;
}


void menu_mytree::DrawName(menu_mytree* ptr) {
	point p = ((menu_mytree*)(ptr))->button[0] + ((menu_mytree*)(ptr))->button[1];
	p = p / 2;
	p.SetPositionOfName();
	string name = ptr->GetData();
	DrawString(name);
}

void menu_mytree::ButtonInit(float w, float h) {
	float step = h / child.size() / 2;
	for (int i = 0; i < child.size(); i++) {
		((menu_mytree*)(this->child[i]))->button[0] = point(-w / 8, step * i - h / 4);
		((menu_mytree*)(this->child[i]))->button[1] = point(w / 8, step * (i + 1) - h / 4);
	}
}


void menu_mytree::ToDialog() {
	string a;
	while (ASearch(a)) {
		menu_mytree* pp = new menu_mytree(a);
		(*this).AddCh(pp);
	}
	NewWindow(0, NULL, proccessMouse, renderScene);

}

void menu_mytree::DrawCh(float w, float h) {
	ButtonInit(w, h);
	for (auto i = GetFirstCh(); i != NULL; i = next_child()) {
		DrawName((menu_mytree*)(i));
	}
}

void menu_mytree::ToClick(point p) {
	for (auto i = GetFirstCh(); i != NULL; i = next_child()) {
		if (p.IsBetween(((menu_mytree*)(i))->button[0], ((menu_mytree*)(i))->button[1])) {
			*this = *((menu_mytree*)(i));
			(this->*action)();
			return;
		}
	}
}
