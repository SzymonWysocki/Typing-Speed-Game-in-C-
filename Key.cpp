#include "Key.h"
#include "SFML/Window/Keyboard.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

Key::Key(std::string a){
}

float Key::speedChange() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F1) && toClikF1){
        toClikF1 = false;
        if(speed > 0.01){
            speed -= 0.01;
        }
        std::cout << speed;
    }
    if( !(sf::Keyboard::isKeyPressed(sf::Keyboard::F1))){
        toClikF1 = true;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F2) && toClikF2){
        toClikF2 = false;
        if(speed < 0.055)
            speed += 0.01;
    }
    if( !(sf::Keyboard::isKeyPressed(sf::Keyboard::F2))){
        toClikF2 = true;
    }
    return speed;
}
int Key::lvlChange(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F3) && toClikF3){
        toClikF3 = false;
        if(lvl > 0){
            lvl--;
        }
    }
    if( !(sf::Keyboard::isKeyPressed(sf::Keyboard::F3))){
        toClikF3 = true;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F4) && toClikF4){
        toClikF4 = false;
        if(lvl < 1)
            lvl++;
    }
    if( !(sf::Keyboard::isKeyPressed(sf::Keyboard::F4))){
        toClikF4 = true;
    }
    return lvl;
}

void Key::setMenuStatus(bool menuStatus) {
    Key::menuStatus = menuStatus;
}

bool Key::isMenu(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        menuStatus = true;
    }
    return menuStatus;
}
