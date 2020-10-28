#include "stdafx.h"
#include "Evil.h"


name_of_Pacman_action Evil::SearchPacman(const Table& labyrinth, const Pacman& Pacman) {
	SearchToDist(labyrinth, Pacman.GetPoint());
	return ActionWithPacman(Pacman);
}

name_of_Pacman_action Evil::SearchHome(const Table& labyrinth, const Pacman& Pacman) {
	SearchToDist(labyrinth, make_pair(1.0f, 27.0f));
	return ActionWithPacman(Pacman);
}

name_of_Pacman_action Evil::ActionWithPacman(const Pacman& Pacman) {

	if (GetPoint() == Pacman.GetPoint()) {

		if (state == SCARE) {
			return EATTEN;
		}

		if (state == REGULAR || state == RELAX) {
			return EAT;
		}

	}
}
name_of_Pacman_action Evil::Move(const Table& labyrinth, const Pacman& Pacman) {

	if (state == SCARE || state == RELAX) {
		return(SearchHome(labyrinth, Pacman));
	}

	else if (state == REGULAR) {
		return(SearchPacman(labyrinth, Pacman));
	}

}