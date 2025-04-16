#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>

class Word {
public:
    Word(std::string word, double h);

    void setPosition(const sf::Vector2f &position);

    void setVelocity(const sf::Vector2f &velocity);

    const std::string &getWordString() const;

    void setX(float x);

    void setY(float y);

    double hight;
    std::string wordString;
    sf::Vector2f position;
    sf::Vector2f velocity;

    float x = -100.0;
    float y = hight*10;
};

