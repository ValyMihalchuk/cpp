#pragma once
#include "SetUpAndLibs.h"
#include "Element.h"
#include "Pacman.h"
#include "Evil.h"


enum STATE_OF_GAME {
	BEGIN,
	PLAY,
	DEATH,
	NEXT_LEVEL,
	END
};


class Level {
private:
	int scores, PacmanLifes;
	Table curLabyrinth;
	Table backUpLabyrinth;
	vector <Evil> EvilsThatAlive;
	vector <Evil> EvilsThatDead;
	Pacman pacman;
	int doubleEvilScores; 
	int levelStage;
	int countOfEatenDEFAULTPoints, countOfEatenENERGYs, 
		countOfEatenFruits;
	void TimerFunc();
	void RemoveEvils();
	void PlaceInEvils();
	void BeginLevel();
	void SetPacmanDeath();
	void BeginGame();
	void EvilsActions();
	void PacmanAction();
	void SetEvilsState(name_of_state setstate);
public:

	Level();
	void InitLevel(ifstream& fileWithLevel);
	void Play();
	void ChangePacmandir(const dirs& dir) {pacman.ChangeDir(dir);}
	const Pacman& GetPacman() {return pacman;}
	const Table& GetLabyrinth() {return curLabyrinth;}
	const vector<Evil>& GetEvilsThatAlive() {return EvilsThatAlive;}
	const vector<Evil> GetEvilsThatDead() {return EvilsThatDead;}
	const int GetScores() {return scores;}
	const int GetPacmanLifes() {return PacmanLifes;}
};
