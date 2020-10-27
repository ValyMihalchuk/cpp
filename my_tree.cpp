
#pragma once

#include "my_tree.h"
#include <string>
#include <vector>


mytree::mytree(std::string& root){
	data = root;
}

std::string mytree::GetData() { 
	return data; 
}
void mytree::AddCh(mytree* ch) { 
	child.push_back(ch);
}
int mytree::AmountOfCh() { 
	return child.size();
}
mytree* mytree::GetFirstCh() { 
	return child[0]; 
}
mytree* mytree::next_child() {
		static int counter = 0;
		if (counter < child.size() - 1) {
			return child[++counter];
		}
		counter = 0;
		return NULL;
	}
