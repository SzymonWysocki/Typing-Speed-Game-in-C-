#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
class Key {
public:
    Key(std::string a);

    float speedChange();
    int lvlChange();

    void setMenuStatus(bool menuStatus);
    bool isMenu();

    bool menuStatus = true;
    int lvl = 0;
    float speed = float(0.03);
    bool toClikF1 = true;
    bool toClikF2 = true;
    bool toClikF3 = true;
    bool toClikF4 = true;
};
