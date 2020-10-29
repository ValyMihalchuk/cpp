#pragma once

#include <vector>

//#include "Header.h"

#include "Painting.h"



Painting* paint = new Painting;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	paint->init();
	StartMenu(*paint);
	return 0;
}