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
#include "MenuItems.h"
#include "PrintingWords.h"

MenuItems::MenuItems(sf::RenderWindow &window, Menu menu): menu(menu) {
    this -> typeFont = 0;
}

void MenuItems::menuTools(bool &isStart, sf::Event event, Key &key, PrintingWords &printingWords, std::vector<Word> &vec){
    if(!isStart){
        if(menu.resume.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            key.setMenuStatus(false);

        }if(menu.save.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {

            std::ofstream file("save.txt");
            file << printingWords.time << ","<< printingWords.counter << "," << printingWords.lifeCount << "\n";
            for(auto i : vec){
                file << i.position.x << "," << i.position.y << "," << i.wordString << "\n";
            }
        }

    }else{
        if(menu.newGame.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            key.setMenuStatus(false);
            isStart = false;

        }if(menu.fontPlace.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
            if(typeFont == 2)
                typeFont = 0;
            else
                typeFont++;
        }if(menu.load.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){

            auto file = std::fstream("../assets/save.txt");
            auto line = std::string();
            std::string word = "";
            int counter = 0;
            while (std::getline(file, line)) {
                counter ++;
                if(counter == 1) {
                    word = "";
                    int index = 0;
                    for (auto i = 0; i < line.size(); i++) {
                        if (line[i] == ',') {
                            index++;

                            if(index == 1)
                                printingWords.time = std::stoi(word);

                            if(index == 2)
                                printingWords.counter = std::stoi(word);
                            word = "";
                        } else
                            word += line[i];
                    }
                    if(word != "")
                        printingWords.lifeCount = std::stoi(word);
                }else{
                    word = "";
                    int index = 0;
                    int x = 0;
                    int y = 0;
                    for (auto i = 0; i < line.size(); i++) {
                        if (line[i] == ',') {
                            index++;

                            if(index == 1)
                                x = std::stof(word);

                            if(index == 2)
                                y = std::stof(word);

                            word = "";
                        } else
                            word += line[i];
                    }
                    Word word1 = Word(word, y);
                    word1.setPosition(sf::Vector2f(x, y));
                    vec.push_back(word1);
                }

            }
            key.setMenuStatus(false);
            isStart = false;
        }
    }
}
