#pragma once

#include"glu.h"
#include"my_tree.h"

using namespace std;



void start(string& structure);
void DrawString(std::string& str);
void renderScene(void);
void proccessMouse(int button, int state, int x, int y);

class menu_mytree : public mytree {
private:
	vector<point> button = vector<point>(2);
	void(menu_mytree::* action)(void) = &menu_mytree::pass;
	void pass() { return; }
    void ButtonInit(float w, float h);
    void DrawName(menu_mytree* ptr);
public:
    menu_mytree() : mytree() {}
    menu_mytree(std::string& s) : mytree(s) {
        if (s.find('(') != string::npos) {
            this->action = &menu_mytree::ToDialog;
        }
    }
    bool ASearch(string& ans); 
    void ToDialog();
    void DrawCh(float w, float h);
    void ToClick(point p);
};



class text {
private:
    std::string str;

    menu_mytree* MakeTree(std::string& s);

    vector<text> GetSubMenu (std::string& tmp, char d1 = ' ', char d2 = ' ');
    string GetFirstCh(string& child);
    string::iterator SearchSeparator(string& s);
    string GetFirstBrack(string& s, char d1, char d2);

public:
    text() { str = string(); }
    text(string& init) { str = init; }

    menu_mytree* MakeTree() { return MakeTree(str); }
};

extern menu_mytree* m;
