#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Word.h"
#include <cmath>
#include <chrono>
#include "Menu.h"
#include "Key.h"

class PrintingWords {
public:
    PrintingWords(std::vector<std::vector<std::string>> &import, sf::RenderWindow &window, std::vector<sf::Font> vecFont);
    bool remove(std::string toRemove, std::vector<Word> &vec);
    void wordsMoveing(std::vector<Word> &vec, sf::RenderWindow &window, float speed, int fontMode);
    void wordTyping(sf::RenderWindow &window, std::string word);
    void counterPrint(sf::RenderWindow &window);
    void printTimer(sf::RenderWindow &window, std::chrono::steady_clock::time_point &add);
    void printLength(sf::RenderWindow &window, int lvl);
    void printSpeed(sf::RenderWindow &window, float speed);
    bool life(Word i, std::vector<Word> &vec);
    void lifePrint(sf::RenderWindow &window);
    void printOver(sf::RenderWindow &window, sf::Event &event,Key &key, bool &isStart);

    bool isOver1() const;
    int counter = 0;
    float time;
    sf::Font font;
    std::vector<std::vector<std::string>> wordsHolder;
    int lifeCount;
    int lifeCountTemp;
    bool isOver;
    bool isMenu = false;
    std::vector<sf::Font> vecFont;
    sf::Font chosenFont;
    sf::Texture texture = sf::Texture();
    sf::Sprite panelOver;
};
