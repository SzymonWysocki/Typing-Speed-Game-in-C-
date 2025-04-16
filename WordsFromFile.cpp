#include "WordsFromFile.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <fmt/ranges.h>


WordsFromFile::WordsFromFile(std::string x){

    for(int i = 1; i <=2; i++){
        fileName = "../assets/slowa" + std::to_string(i) + ".txt";
        std::fstream file = std::fstream(fileName);

        while(file >> word){
            words.push_back(word);
        }
        wordsHolder.push_back(words);
        words = {};
    }
}

void WordsFromFile::load(){
    for(auto i : wordsHolder[1]){
        fmt::println("{}", i);
    }
}