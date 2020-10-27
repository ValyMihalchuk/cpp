#pragma once
#include <string>
#include <vector>

using namespace std;
class mytree {
protected:
    std::string data;
    vector<mytree*> child;
public:
    mytree() { data = ""; }
	mytree(std::string& root);
	std::string GetData();
	void AddCh(mytree* child);
	int AmountOfCh();
	mytree* GetFirstCh();
	mytree* next_child();
};
