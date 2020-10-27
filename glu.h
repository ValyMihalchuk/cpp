#pragma once
#include <string>
#include <gl/glut.h>

typedef void(*key_func)(int, int, int);
typedef void(*mouse_func)(int, int, int, int);
typedef void(*render_func)();

void DrawString(std::string& str);
void init(mouse_func proccessMouse, render_func renderScene, render_func idl);
void NewWindow(int argc, char** argv, mouse_func proccessMouse, render_func renderScene);

class point {
private:
    float x;
    float y;
public:
    point() { x = y = 0; }
    point(float xx, float yy) { x = xx; y = yy; }

    point operator + (point& rv) {
        point res(x + rv.x, y + rv.y);
        return point(x + rv.x, y + rv.y);
    }

    point& operator / (int rv) {
        point res(x / rv, y / rv);
        return res;
    }

	bool IsBetween(point& a, point& b) {
		if (x > a.x && x < b.x && y > a.y && y < b.y)
			return true;
		return false;
	}

	void SetPositionOfName() {
		glRasterPos2f(x, y);
	}

};

