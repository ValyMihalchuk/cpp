#pragma once
#include "SetUpAndLibs.h"
#include "Element.h"

using Table = vector<vector<Element>>;

enum dirs {
	TOP,
	DOWN,
	LEFT,
	RIGHT,
	STAY
};

class Game {
private:
	xy point;
	dirs dir;
	const bool Step(const Table& labyrinth);
	dirs Tunnel();
public:
	Game(const xy& Point, const dirs& Dir) { point.first = Point.first; point.second = Point.second; dir = Dir; }
	void Move(const Table& labyrinth);
	xy GetPoint() const{return point;}
	dirs GetDir() const{return dir;}
	void ChangePoint(const xy& xy) {point = xy;}
	void ChangeDir(const dirs& Dir) {dir = Dir;}
};