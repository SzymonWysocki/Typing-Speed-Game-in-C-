#include "Word.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>

Word::Word(std::string word, double h): wordString(word), hight(h){


    this -> position = sf::Vector2f(x, y);
    this -> velocity = sf::Vector2f(0.00, 0.0f);
}

void Word::setPosition(const sf::Vector2f &position) {
    Word::position = position;
}

void Word::setVelocity(const sf::Vector2f &velocity) {
    Word::velocity = velocity;
}

const std::string &Word::getWordString() const {
    return wordString;
}

void Word::setX(float x) {
    Word::x = x;
}

void Word::setY(float y) {
    Word::y = y;
}
