#pragma once
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
class Textures {
public:
    sf::Texture texture1 = sf::Texture();
    sf::Texture texture2 = sf::Texture();
    sf::Sprite panel1;
    sf::Sprite background1;
    Textures(sf::RenderWindow &window);
    void background(sf::RenderWindow &window);
    void panel(sf::RenderWindow &window);
};
