#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class WordsFromFile {
public:
    WordsFromFile(std::string x);

    std::vector<std::vector<std::string>> wordsHolder;
    std::vector<std::string> words;
    std::string word;
    std::string fileName;


    void load();
};

