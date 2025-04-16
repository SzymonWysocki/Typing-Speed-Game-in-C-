#include "PrintingWords.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Word.h"
#include "Key.h"
#include <cmath>
#include <iomanip>
#include <thread>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <format>

PrintingWords::PrintingWords(std::vector<std::vector<std::string>> &import,sf::RenderWindow &window, std::vector<sf::Font> vecFont): wordsHolder(import){
    this -> vecFont = vecFont;
    this -> time = 0;
    this ->lifeCount = 0;
    this ->lifeCountTemp = 10;
    this -> isOver = false;
    this -> font;

    if (!texture.loadFromFile("../assets/GameOver.png"))
        std::cout << "error while loading image\n";
    panelOver = sf::Sprite(texture);
    panelOver.setPosition(0 ,0);
    if (!font.loadFromFile("../assets/Lotion-Regular.ttf")) {
        std::cout << "Failed to load font.\n";
        }
    }

bool PrintingWords::isOver1() const {
    return isOver;
}


void PrintingWords::wordsMoveing(std::vector<Word> &vec, sf::RenderWindow &window, float speed, int fontMode) {
    for (auto &i: vec) {

        auto text = sf::Text(i.getWordString(), vecFont[fontMode], 30);
        auto velocity1 = sf::Vector2f(speed, 0.0f);

        text.setFillColor(sf::Color::Green);
        i.setVelocity(velocity1);
        i.setPosition(i.position + i.velocity);
        text.setPosition(i.position);


        if(i.position.x > window.getSize().x*0.65) {
            text.setFillColor(sf::Color::Yellow);
        }
        if(i.position.x > window.getSize().x*0.8) {
            text.setFillColor(sf::Color::Red);
        }

        if (i.position.x >= window.getSize().x) {
            this -> isOver = life(i, vec);
        }
        window.draw(text);

    }

}
bool PrintingWords::life(Word i ,std::vector<Word> &vec) {
    this -> lifeCount++;
    for (auto itr = vec.begin(); itr != vec.end(); itr++) {
        if (i.getWordString().compare((*itr).wordString) == 0) {
            vec.erase(itr);
        }
    }
    if(this->lifeCount == lifeCountTemp){
        return true;
    }
    return false;
}
void PrintingWords::lifePrint(sf::RenderWindow &window) {
    auto text = sf::Text(std::to_string(this->lifeCount) + "/"+ std::to_string(lifeCountTemp), font);
    text.setPosition(window.getSize().x / 2.63, window.getSize().y / 1.15);
    window.draw(text);
}

void PrintingWords::wordTyping(sf::RenderWindow &window, std::string word) {

    std::chrono::steady_clock::time_point add;
    auto text = sf::Text(word ,font , 35);
    text.setPosition(window.getSize().x / 20, window.getSize().y - (window.getSize().y/9.2));

    window.draw(text);
    {
        auto text1 = sf::Text("_", font, 35);
        text1.setPosition(text.getPosition().x + (word.size() * 18.5), text.getPosition().y);
        window.draw(text1);
    }
};

void PrintingWords::counterPrint(sf::RenderWindow &window) {
    auto text = sf::Text(std::to_string(counter), font);
    text.setPosition(window.getSize().x / 2.63, window.getSize().y / 1.085);

    window.draw(text);
}

void PrintingWords::printOver(sf::RenderWindow &window, sf::Event &event, Key &key, bool &isStart){

    if(!isMenu){
        window.draw(panelOver);
    } else {
        key.setMenuStatus(true);
    }

    if(event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button == sf::Mouse::Left){
            isMenu = true;
            isStart = true;
        }
    }
}

void PrintingWords::printTimer(sf::RenderWindow &window, std::chrono::steady_clock::time_point &add){

    if (std::chrono::steady_clock::now() - add >= std::chrono::milliseconds (100)) {
        time += 1;
        add = std::chrono::steady_clock::now();
    }

    auto text = sf::Text(std::format("{:.1f}", time/10), font);
    text.setPosition(window.getSize().x /1.9, window.getSize().y / 1.15);
    window.draw(text);
}

void PrintingWords::printLength(sf::RenderWindow &window, int lvl){
    auto text = sf::Text(std::to_string(lvl + 5) ,font , 35);
    text.setPosition(window.getSize().x / 1.67, window.getSize().y / 1.085);
    window.draw(text);
}

bool PrintingWords::remove(std::string toRemove, std::vector<Word> &vec) {

    auto isRemoved = bool(false);

    for (auto itr = vec.begin(); itr != vec.end(); itr++) {
        if (toRemove.compare((*itr).wordString) == 0) {
            vec.erase(itr);
            itr--;
            isRemoved = true;
        }
    }
    return isRemoved;
}

void PrintingWords::printSpeed(sf::RenderWindow &window, float speed){
    auto text = sf::Text(std::to_string(int(speed*100)) + " / 6", font);
    text.setPosition(window.getSize().x / 1.35, window.getSize().y / 1.15);
    window.draw(text);
}