#include "stdafx.h"
#include "Game.h"



const bool Game::Step(const Table& labyrinth) {
	switch (dir) {
	case TOP:
		return labyrinth[point.first - 1][point.second].IsEmpty();
		break;
	case DOWN:
		return labyrinth[point.first + 1][point.second].IsEmpty();
		break;
	case LEFT:
		return labyrinth[point.first][point.second - 1].IsEmpty();
		break;
	case RIGHT:
		return labyrinth[point.first][point.second + 1].IsEmpty();
		break;
	}
}


dirs Game::Tunnel() {
	switch (dir) {
	case RIGHT:
		if (make_pair(point.first, point.second + 1) == make_pair(14.0f, 27.0f))
			return RIGHT;
		break;
	case LEFT:
		if (make_pair(point.first, point.second - 1) == make_pair(14.0f, 0.0f))
			return LEFT;
		break;
	default:
		return STAY;
	}

}


void Game::Move(const Table& labyrinth) {

	switch (Tunnel()) {
	case LEFT:
		point.second = 27.0f;
		return;
	case RIGHT:
		point.second = 0.0f;
		return;
	default:
		break;
	}


	switch (dir) {
	case TOP:
		if (Step(labyrinth))
			point.first -= 1;
		else
			dir = STAY;
		break;
	case DOWN:
		if (Step(labyrinth))
			point.first += 1;
		else
			dir = STAY;
		break;
	case LEFT:
		if (Step(labyrinth))
			point.second -= 1;
		else
			dir = STAY;
		break;
	case RIGHT:
		if (Step(labyrinth))
			point.second += 1;
		else
			dir = STAY;
		break;
	}
}