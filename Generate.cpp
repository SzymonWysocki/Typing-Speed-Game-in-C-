#include "PrintingWords.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Word.h"
#include "Generate.h"
#include "WordsFromFile.h"


Generate::Generate(WordsFromFile wordsFromFile) : wordsFromFile(wordsFromFile) {
    lasstSpawn = 0;
    secendLastSpawn = 0;
}

void Generate::generate(std::vector<Word> &vec, int lvl, sf::RenderWindow &window, std::chrono::steady_clock::time_point &add) {
    if (std::chrono::steady_clock::now() - add >= std::chrono::milliseconds(250)) {
        int randomHight = 0;
        randomHight = rand() % 55;

        int randomIndex = 0;
        randomIndex = rand() % 103;

        if ((randomHight > (lasstSpawn + 20) || randomHight < (lasstSpawn - 20)) &&
            (randomHight > (secendLastSpawn + 20) || randomHight < (secendLastSpawn - 20))) {

            auto isPrinted = bool(false);

            for (auto i: vec) {
                if (i.getWordString() == wordsFromFile.wordsHolder[lvl][randomIndex]) {
                    isPrinted = true;
                    break;
                }
            }
            if (!isPrinted) {
                vec.push_back(Word(wordsFromFile.wordsHolder[lvl][randomIndex], randomHight));
            }
        }
        secendLastSpawn = lasstSpawn;
        lasstSpawn = randomHight;
        add = std::chrono::steady_clock::now();
    }

}