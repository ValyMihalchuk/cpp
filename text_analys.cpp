#pragma once
#include "draw_menu.h"
#include "my_tree.h"
menu_mytree* m;

menu_mytree* text::MakeTree(std::string& s) {
    vector<text> mlist = this->GetSubMenu(s, '[', ']');

    menu_mytree* menu_1 = new menu_mytree();
    if (mlist[0].str.size() == 0) {
        return menu_1;
    }
    menu_mytree* menu_2 = new menu_mytree(mlist[0].str);
    for (int i = 1; i < mlist.size(); i++) {
        menu_2->AddCh(MakeTree(mlist[i].str));
    }
    return menu_2;
}

vector<text> text::GetSubMenu (std::string& s, char d1, char d2) {
    vector<text> el; 
    string name = s.substr(0, s.find_first_of(d1));
    el.push_back(text(name));
    if (s.size() == 0)
        return el;
    string tmp = GetFirstBrack(s, d1, d2);
    string ch;

    do {
        ch = GetFirstCh(tmp);
        el.push_back(ch);
    } while (ch != tmp);

    return el;
}

string text::GetFirstCh(string& s) {
    string::iterator pos = SearchSeparator(s);
    if (pos == s.end()) {
        return s;
    }
    string t = s.substr(0, pos - s.begin());
    s.erase(s.begin(), pos + 1);
    return t;
}

string::iterator text::SearchSeparator(string& s) {
    int count = 0;
    for (auto p = s.begin(); p < s.end(); p++) {
        if (*p == '[' || *p == '(')
            count++;
        else if (*p == ']' || *p == ')')
            count--;
        else if (*p == ',' && count == 0)
            return p;
    }
    return s.end();
}

string text::GetFirstBrack(string& s, char d1, char d2) {
    int op = s.find_first_of(d1);
    int cl = s.find_last_of(d2);
    return s.substr(op + 1, cl - op - 1);
}

