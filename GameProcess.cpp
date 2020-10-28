#include "stdafx.h"
#include "Pacman.h"

bounties Pacman::EatScores(const Table& labyrinth) {
	switch (labyrinth[GetPoint().first][GetPoint().second].GetBounty()) {
	case DEFAULT:
		return DEFAULT;
		break;

	case ENERGY:
		return ENERGY;
		break;

	case NONE:
		break;
	}
}

void Pacman::RecreatePacman() {
	ChangePoint(make_pair(29.0, 12.0));
	ChangeDir(STAY);
}

bounties Pacman::Action(const Table& labyrinth) {
	Move(labyrinth);
	return EatScores(labyrinth);
}