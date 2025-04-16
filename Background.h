#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "StarsBig.h"

class Background {
public:
    Background(std::string x);
    void printingStars(std::vector<StarsBig> &vec, sf::RenderWindow &window, std::chrono::steady_clock::time_point &add);
    void remove(StarsBig i, std::vector<StarsBig> &vec);
};

