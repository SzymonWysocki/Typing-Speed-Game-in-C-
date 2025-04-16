#pragma once
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Font.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Menu {
public:
    Menu(std::vector<sf::Font> vecFont);
    sf::Texture texture1 = sf::Texture();
    sf::Texture texture2 = sf::Texture();
    sf::Texture texture3 = sf::Texture();
    sf::Texture texture4 = sf::Texture();
    sf::Texture texture5 = sf::Texture();
    sf::Texture texture6 = sf::Texture();
    sf::Texture texture7 = sf::Texture();
    sf::Sprite panel1;

    sf::Sprite resume;
    sf::Sprite save;
    sf::Sprite leaderboard;
    sf::Sprite load;
    sf::Sprite newGame;
    sf::Sprite fontPlace;
    sf::Font font;
    std::vector<sf::Font> vecFont;
    bool start = true;
    void printMenu1(sf::RenderWindow &window);
    void printMenu2(sf::RenderWindow &window, int fontMode);
};

