#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>



class StarsBig {
public:
    StarsBig(double h);
    void setPosition(const sf::Vector2f &position);

    const std::string &getWordString() const;

    const sf::Vector2f &getPosition() const;

    double hight;

    std::string wordString;
    sf::Vector2f position;
    sf::Vector2f velocity;
};

