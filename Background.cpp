#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include "Background.h"
#include "StarsBig.h"

Background::Background(std::string x){}

void Background::printingStars(std::vector<StarsBig> &vec, sf::RenderWindow &window, std::chrono::steady_clock::time_point &add){

    if (std::chrono::steady_clock::now() - add >= std::chrono::milliseconds (400)) {
        int randomHight = 0;
        randomHight = rand() % 55;
        vec.push_back(randomHight*10);

        add = std::chrono::steady_clock::now();
    }

    for(auto &i : vec){
        auto star = sf::CircleShape(1.3, 5);
        star.setFillColor(sf::Color::White);

        i.setPosition(i.position + i.velocity);
        star.setPosition(i.position);

        if (i.position.x >= window.getSize().x) {
            remove(i, vec);
        }
        window.draw(star);
    }

}
void Background::remove(StarsBig i, std::vector<StarsBig> &vec){
    for (auto itr = vec.begin(); itr != vec.end(); itr++) {
        if (i.getPosition() == (*itr).getPosition()) {
            vec.erase(itr);
        }
    }
}