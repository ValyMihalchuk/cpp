#pragma once
#include"draw_menu.h"
#include <iostream>
#include <fstream>




int main(int argc, char** argv) {
	string str;
	ifstream in("menu.txt");
	getline(in, str);
	in.close();
	
	start(str);

	return 0;
}
