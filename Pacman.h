#pragma once

#include "resource.h"
#include "SetUpAndLibs.h"
#include "Game.h"
#include "Element.h"


class Pacman : public Game {
private:
	bounties EatScores(const Table& labyrinth);
public:
	Pacman() : Game(make_pair(29.0, 12.0), STAY) {}
	void RecreatePacman();
	bounties Action(const Table& labyrinth);
};