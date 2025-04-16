#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Font.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Menu.h"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Window/Event.hpp"


Menu::Menu(std::vector<sf::Font> vecFont):vecFont(vecFont){


    if (!font.loadFromFile("../assets/Lotion-Regular.ttf")) {
        std::cout << "Failed to load font.\n";
    }

    if (!texture1.loadFromFile("../assets/Menu.png"))
        std::cout << "error while loading image\n";
    panel1 = sf::Sprite(texture1);
    panel1.setPosition(0, 0);

    if (!texture2.loadFromFile("../assets/resume.png"))
        std::cout << "error while loading image\n";
    resume = sf::Sprite(texture2);
    resume.setPosition(375, 280);

    if (!texture3.loadFromFile("../assets/save.png"))
        std::cout << "error while loading image\n";
    save = sf::Sprite(texture3);
    save.setPosition(375, 480);

    if (!texture4.loadFromFile("../assets/newGame.png"))
        std::cout << "error while loading image\n";
    newGame = sf::Sprite(texture4);
    newGame.setPosition(375, 250);

    if (!texture5.loadFromFile("../assets/loadGame.png"))
        std::cout << "error while loading image\n";
    load = sf::Sprite(texture5);
    load.setPosition(375, 370);

    if (!texture6.loadFromFile("../assets/fontPlace.png"))
        std::cout << "error while loading image\n";
    fontPlace = sf::Sprite(texture6);
    fontPlace.setPosition(375, 490);

    if (!texture7.loadFromFile("../assets/leaderboard.png"))
        std::cout << "error while loading image\n";

    leaderboard = sf::Sprite(texture7);
    leaderboard.setPosition(375, 610);
}

void Menu::printMenu1(sf::RenderWindow &window){
    window.draw(panel1);
    window.draw(resume);
    window.draw(save);

}

void Menu::printMenu2(sf::RenderWindow &window, int fontMode){
    auto text = sf::Text("Choose font", vecFont[fontMode], 60);
    text.setPosition(465, 492);

    window.draw(panel1);
    window.draw(newGame);
    window.draw(load);
    window.draw(fontPlace);
    window.draw(leaderboard);
    window.draw(text);
}
