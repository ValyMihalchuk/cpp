#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Points{
private:
	std::vector< int > points;
public:
	void Clear(){ points.clear(); }
	void Push(int x, int y){points.push_back(x); points.push_back(y);}
	int GetPoint(int i) { return points[i]; }
	size_t GetSize() { return points.size(); }

};

