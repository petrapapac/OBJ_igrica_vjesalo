#include "WordManager.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void WordManager::loadWords(const string& filename) {
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        size_t pos = line.find(':');
        if (pos == string::npos) continue;

        string cat = line.substr(0, pos);
        string rest = line.substr(pos + 1);

        vector<string> words;
        size_t start = 0, end;
        while ((end = rest.find(',', start)) != string::npos) {
            words.push_back(rest.substr(start, end - start));
            start = end + 1;
        }
        words.push_back(rest.substr(start));
        categories[cat] = words;
    }
    srand(time(nullptr));
}

void WordManager::chooseCategory(int choice) {
    int i = 1;
    for (auto& c : categories) {
        if (i == choice) {
            selectedCategory = c.first;
            return;
        }
        i++;
    }
}

void WordManager::pickWord() {
    auto& words = categories[selectedCategory];
    secretWord = words[rand() % words.size()];
    hiddenWord = "";
    for (char c : secretWord)
        hiddenWord += (c == ' ' ? ' ' : '_');
}

bool WordManager::hasLetter(char letter) const {
    return secretWord.find(letter) != string::npos;
}

void WordManager::reveal(char letter) {
    for (size_t i = 0; i < secretWord.size(); i++)
        if (secretWord[i] == letter)
            hiddenWord[i] = letter;
}

bool WordManager::guessed() const {
    return hiddenWord == secretWord;
}

const string& WordManager::getHidden() const { return hiddenWord; }
const string& WordManager::getWord() const { return secretWord; }
