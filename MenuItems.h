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
#include "PrintingWords.h"
#include "Word.h"

class MenuItems {
public:
    MenuItems(sf::RenderWindow &window, Menu menu);
    Menu menu;
    int typeFont;
    void menuTools(bool &isStart, sf::Event event, Key &key, PrintingWords &printingWords, std::vector<Word> &vec);
};

