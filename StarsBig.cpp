#include "StarsBig.h"

StarsBig::StarsBig(double h):hight(h){
    this -> position = sf::Vector2f(-100.f, hight);
    this -> velocity = sf::Vector2f(0.3, 0.0f);
}

void StarsBig::setPosition(const sf::Vector2f &position) {
    StarsBig::position = position;
}

const sf::Vector2f &StarsBig::getPosition() const {
    return position;
}
