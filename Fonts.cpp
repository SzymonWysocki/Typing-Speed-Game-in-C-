#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Fonts.h"

Fonts::Fonts(){
    this -> font1.loadFromFile("../assets/Lotion-Regular.ttf");
    this -> font2.loadFromFile("../assets/Pixellari.ttf");
    this -> font3.loadFromFile("../assets/Adventure.otf");
    vec.push_back(font1);
    vec.push_back(font2);
    vec.push_back(font3);
}

const std::vector<sf::Font> &Fonts::getVec() const {
    return vec;
}
