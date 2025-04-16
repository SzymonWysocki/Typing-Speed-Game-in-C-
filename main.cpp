#include <iostream>
#include <ranges>
#include <vector>
#include <fmt/core.h>
#include <SFML/Graphics.hpp>
#include "WordsFromFile.h"
#include "PrintingWords.h"
#include "Generate.h"
#include "Word.h"
#include "Background.h"
#include "StarsBig.h"
#include "Key.h"
#include "Textures.h"
#include "Menu.h"
#include "MenuItems.h"
#include "Fonts.h"

auto main() -> int {

    bool isMenu = true;
    bool isOver = false;
    bool isStart = true;

    WordsFromFile wordsFromFile("a");
    Key key("a");
    Background background1("x");
    Fonts fonts = Fonts();



    Generate generate(wordsFromFile);

    //https://en.cppreference.com/w/cpp/chrono/steady_clock/now
    std::chrono::steady_clock::time_point add;
    std::chrono::steady_clock::time_point add1;
    std::chrono::steady_clock::time_point add3;

    auto vecBackground = std::vector<StarsBig>();
    auto vec = std::vector<Word>();

    auto window = sf::RenderWindow(
            sf::VideoMode({1300, 800}), "Test",
            sf::Style::Default, sf::ContextSettings(0, 0, 8)
    );

    Textures textures(window);
    PrintingWords printingWords(wordsFromFile.wordsHolder, window, fonts.getVec());
    Menu menu(fonts.getVec());
    MenuItems menuItems(window, menu);

    auto word1 = std::string();
    auto counter = int(0);

    while (window.isOpen()) {

        auto event = sf::Event();
        while (window.pollEvent(event)) {
            switch (event.type) {

                case sf::Event::Closed:
                    window.close();

                case sf::Event::TextEntered:

                    auto letter = char();
                    auto wordTemp = std::string();

                    letter = (char) event.text.unicode;

                    if (event.text.unicode == '\b' && word1.size() > 0) {
                        word1 = word1.erase(word1.size() - 1, 1);
                    } else {
                        if(letter > 27){
                            wordTemp = word1 + letter;
                            word1 = wordTemp;
                        }
                    }
                    if (printingWords.remove(word1, vec)) {
                        printingWords.counter++;
                        word1.clear();
                    }
            }
        }

        if (key.isMenu()) {

            if(!isStart){
                window.clear();
                menu.printMenu1(window);
            } else{
                window.clear();
                menu.printMenu2(window, menuItems.typeFont);
            }

            background1.printingStars(vecBackground, window, add3);
            window.display();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {

                    if(printingWords.isOver1()){
                        PrintingWords newPrinting = PrintingWords(wordsFromFile.wordsHolder, window, fonts.getVec());
                        printingWords = newPrinting;
                        Generate newGenerate = (wordsFromFile);
                        generate = newGenerate;
                        generate =  Generate(wordsFromFile);
                        Key newKey = Key("a");
                        key = newKey;

                        add = std::chrono::steady_clock::now();
                        add1 = std::chrono::steady_clock::now();
                        add3 = std::chrono::steady_clock::now();

                        vec.clear();
                    } else{
                        menuItems.menuTools(isStart, event, key, printingWords, vec);
                    }

                }
            }
        } else {

            window.clear();

            if (!printingWords.isOver1()) {
                generate.generate(vec, key.lvlChange(), window, add);
                textures.background(window);
                textures.panel(window);
                background1.printingStars(vecBackground, window, add3);
                printingWords.printSpeed(window, key.speedChange());
                printingWords.printLength(window, key.lvlChange());
                printingWords.printTimer(window, add1);
                printingWords.wordsMoveing(vec, window, key.speedChange(), menuItems.typeFont);
                printingWords.wordTyping(window, word1);
                printingWords.counterPrint(window);
                printingWords.lifePrint(window);
                window.display();
            } else {
                printingWords.printOver(window, event, key, isStart);
                background1.printingStars(vecBackground, window, add3);
                window.display();
            }
        }
    }
}
