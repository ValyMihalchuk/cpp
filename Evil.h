#pragma once
#include "SetUpAndLibs.h"
#include "Game.h"
#include "Pacman.h"
#include "Element.h"



enum name_of_state {
	REGULAR,
	SCARE,
	RELAX
};

enum name_of_Pacman_action {
	EAT,
	EATTEN,
	NO
};

class Evil : public Game {
private:
	name_of_state state;
	bool inBox;
	float MinDistance(const xy& src, const xy& dst) {
		return (sqrt(pow(src.second - dst.second, 2) + pow(src.first - dst.first, 2)));
	}
	void SearchToDist(const Table& labyrinth, const xy& destination);
	name_of_Pacman_action SearchPacman(const Table& labyrinth, const Pacman& Pacman);
	name_of_Pacman_action SearchHome(const Table& labyrinth, const Pacman& Pacman);
	name_of_Pacman_action ActionWithPacman(const Pacman& Pacman);

public:
	Evil() : Game(make_pair(13.0f, 14.0f), STAY) { state = REGULAR; inBox = true;}
	void GetOutOfBox();
	void ChangeFunction();
	name_of_Pacman_action Move(const Table& labyrinth, const Pacman& Pacman);
	void SetEvilDeath() {inBox = true; ChangePoint(make_pair(13.0f, 14.0f));}
	void SetState(const name_of_state& State) {state = State;}
	const name_of_state GetState() { return state; }
	const bool InBox() {return inBox;}
	void GetInBoxState(bool state) {inBox = state;}

};
