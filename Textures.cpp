#include "SFML/Graphics/Texture.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Textures.h"
#include "SFML/Graphics/Sprite.hpp"

Textures::Textures(sf::RenderWindow &window){
    if (!texture1.loadFromFile("C:\\Users\\szymo\\Desktop\\LeyoutTyper.png"))
        std::cout << "error while loading image\n";
    panel1 = sf::Sprite(texture1);
    panel1.setPosition(0, window.getSize().y - (window.getSize().y / 6.15));

    if(!texture2.loadFromFile("C:\\Users\\szymo\\Desktop\\background2.png"))
        std::cout<<"error while loading image\n";
    background1 = sf::Sprite(texture2);

}
void Textures::background(sf::RenderWindow &window){
    window.draw(background1);
}
void Textures::panel( sf::RenderWindow &window ){

    window.draw(panel1);
}
