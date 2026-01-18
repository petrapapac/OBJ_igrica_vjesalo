#pragma once
#include <string>
#include <set>
#include "Hangman.h"

class UI {
public:
    void displayWelcome() const;
    void displayRules() const;

    void displayGame(const std::string& word, const std::set<char>& used, const Hangman& h) const;

    std::string getInput() const;
    void displayEnd(bool win, const std::string& word) const;
};
#pragma once