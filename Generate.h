#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Word.h"
#include "WordsFromFile.h"

class Generate {
public:
    Generate(WordsFromFile wordsFromFile);
    void generate(std::vector<Word> &vec, int lvl, sf::RenderWindow &window, std::chrono::steady_clock::time_point &add);
    //void pause(std::vector<Word> &vec, int lvl, sf::RenderWindow &window,std::chrono::steady_clock::time_point &add);
    WordsFromFile wordsFromFile;

    int lasstSpawn;
    int secendLastSpawn;
};

