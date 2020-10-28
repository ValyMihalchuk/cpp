#include "stdafx.h"
#include "Evil.h"

void Evil::SearchToDist(const Table& labyrinth, const xy& destination) {

	if (MinDistance(make_pair(GetPoint().first - 1, GetPoint().second), destination) < MinDistance(GetPoint(), destination)
		&& labyrinth[GetPoint().first - 1][GetPoint().second].IsEmpty() && GetDir() != DOWN) {
		ChangePoint(make_pair(GetPoint().first - 1, GetPoint().second));
		ChangeDir(TOP);
		return;
	}

	if (MinDistance(make_pair(GetPoint().first + 1, GetPoint().second), destination) < MinDistance(GetPoint(), destination)
		&& labyrinth[GetPoint().first + 1][GetPoint().second].IsEmpty() && GetDir() != TOP) {
		ChangePoint(make_pair(GetPoint().first + 1, GetPoint().second));
		ChangeDir(DOWN);
		return;
	}

	if (MinDistance(make_pair(GetPoint().first, GetPoint().second - 1), destination) < MinDistance(GetPoint(), destination)
		&& labyrinth[GetPoint().first][GetPoint().second - 1].IsEmpty() && GetDir() != RIGHT) {
		ChangePoint(make_pair(GetPoint().first, GetPoint().second - 1));
		ChangeDir(LEFT);
		return;
	}

	if (MinDistance(make_pair(GetPoint().first, GetPoint().second + 1), destination) < MinDistance(GetPoint(), destination)
		&& labyrinth[GetPoint().first][GetPoint().second + 1].IsEmpty() && GetDir() != LEFT) {
		ChangePoint(make_pair(GetPoint().first, GetPoint().second + 1));
		ChangeDir(RIGHT);
		return;
	}

	Game::Move(labyrinth);

}

void Evil::GetOutOfBox() {
	if (inBox) {
		static int curTicks = 0;
		curTicks++;
		if (curTicks % TIME_OF_Recreate == 0) {
			state = REGULAR;
			inBox = false;
			ChangePoint(make_pair(11.0, 14.0));
			curTicks = 0;
			return;
		}
	}
	return;
}

void Evil::ChangeFunction() {
	static int curTicks = 0;
	curTicks++;
	switch (state) {
	case SCARE:
		if (curTicks % TIME_OF_Scare == 0) {
			state =REGULAR;
			curTicks = 0;
			return;
		}
		break;
	case REGULAR:
		if (curTicks % TIME_OF_Regular == 0) {
			state = RELAX;
			curTicks = 0;
			return;
		}
		break;
	case RELAX:
		if (curTicks % TIME_OF_Relax == 0) {
			state = REGULAR;
			curTicks = 0;
			return;
		}
		break;
	}
	return;
}
