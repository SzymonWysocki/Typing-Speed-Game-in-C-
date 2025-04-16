#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "SFML/Graphics/Font.hpp"

class Fonts {
    public:
    Fonts();

    const std::vector<sf::Font> &getVec() const;

    sf::Font font1;
    sf::Font font2;
    sf::Font font3;
    std::vector<sf::Font> vec;
};

