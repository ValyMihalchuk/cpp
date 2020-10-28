#include "stdafx.h"
#include "Level.h"

STATE_OF_GAME currGamestate = BEGIN;

Level::Level() {
	doubleEvilScores = 1;
	levelStage = 1;
	PacmanLifes = 4;
	countOfEatenDEFAULTPoints = 0;
	countOfEatenENERGYs = 0;
	countOfEatenFruits = 0;
	scores = 0;
}

void Level::RemoveEvils() {
	EvilsThatAlive.clear();
	EvilsThatDead.clear();
}

void Level::PlaceInEvils() {
	for (int i = 0; i < AMOUNT_OF_EVILS; i++) {
		EvilsThatAlive.emplace_back();
	}
}

void Level::BeginLevel() {
	RemoveEvils();
	curLabyrinth.clear();
	doubleEvilScores = 1;
	countOfEatenDEFAULTPoints = 0;
	countOfEatenENERGYs = 0;
	levelStage++;
	currGamestate = BEGIN;

	curLabyrinth = backUpLabyrinth;
	PlaceInEvils();
	pacman.RecreatePacman();
}


void Level::BeginGame() {
	RemoveEvils();
	curLabyrinth.clear();
	doubleEvilScores = 1;
	countOfEatenDEFAULTPoints = 0;
	countOfEatenENERGYs = 0;
	countOfEatenFruits = 0;
	levelStage = 1;
	currGamestate = BEGIN;

	PacmanLifes = AMOUNT_OF_LIFES;
	scores = 0;

	curLabyrinth = backUpLabyrinth;
	PlaceInEvils();
	pacman.RecreatePacman();
}

void Level::EvilsActions() {
	vector<int> rememberEvilsThatDead;
	for (vector<Evil>::iterator it = EvilsThatAlive.begin(); it < EvilsThatAlive.end(); it++) {
		switch (it->Move(curLabyrinth, pacman)) {
		case EAT:
			if (--PacmanLifes == 0) {
				BeginGame();
				return;
			}
			else {
				SetPacmanDeath();
				return;
			}
			break;
		case EATTEN:
			it->SetEvilDeath();
			EvilsThatDead.push_back(*it);
			rememberEvilsThatDead.push_back(it - EvilsThatAlive.begin());
			scores += 200 * doubleEvilScores;
			doubleEvilScores += 2;
			break;
		}
	}


	for (auto i : rememberEvilsThatDead) {
		EvilsThatAlive.erase(EvilsThatAlive.begin() + i);
	}

}

void Level::PacmanAction() {
	switch (pacman.Action(curLabyrinth)) {
	case DEFAULT:
		curLabyrinth[pacman.GetPoint().first][pacman.GetPoint().second].SetBounty(NONE);
		scores += 10;
		countOfEatenDEFAULTPoints++;
		break;
	case ENERGY:
		curLabyrinth[pacman.GetPoint().first][pacman.GetPoint().second].SetBounty(NONE);
		scores += 50;
		countOfEatenENERGYs++;
		for (auto& Evil : EvilsThatAlive) {
			Evil.SetState(SCARE);
		}
		break;
	}

	if (countOfEatenDEFAULTPoints == AMOUNT_OF_DEFAULTS && countOfEatenENERGYs == AMOUNT_OF_ENERGYS) {
		BeginLevel();
	}
}

void Level::SetPacmanDeath() {
	RemoveEvils();
	PlaceInEvils();
	pacman.RecreatePacman();
}

void Level::SetEvilsState(name_of_state setstate) {
	for (auto& Evil : EvilsThatAlive) {
		Evil.SetState(setstate);
	}
}

void Level::InitLevel(ifstream& fileWithLevel) {

	string line;
	int i, j;

	for (i = 0; getline(fileWithLevel, line); i++) {
		curLabyrinth.push_back(vector<Element>());
		backUpLabyrinth.push_back(vector<Element>());
		for (j = 0; j < line.size(); j++) {
			switch (line[j]) {
			case int('#') :
				curLabyrinth[i].emplace_back(false, NONE, make_pair(i, j));
				backUpLabyrinth[i].emplace_back(false, NONE, make_pair(i, j));
				break;

			case int('.') :
				curLabyrinth[i].emplace_back(true, DEFAULT, make_pair(i, j));
				backUpLabyrinth[i].emplace_back(true, DEFAULT, make_pair(i, j));
				break;

			case int('$') :
				curLabyrinth[i].emplace_back(true, ENERGY, make_pair(i, j));
				backUpLabyrinth[i].emplace_back(true, ENERGY, make_pair(i, j));
				break;

			default:
				curLabyrinth[i].emplace_back(true, NONE, make_pair(i, j));
				backUpLabyrinth[i].emplace_back(true, NONE, make_pair(i, j));
				break;

			}
		}
	}
	PlaceInEvils();
}

void Level::TimerFunc() {

	for (auto& Evil : EvilsThatAlive) {
		Evil.ChangeFunction();
		Evil.GetOutOfBox();
	}
}

void Level::Play() {
	TimerFunc();
	PacmanAction();
	EvilsActions();
}

