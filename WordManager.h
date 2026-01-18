#pragma once
#include <map>
#include <vector>
#include <string>

class WordManager {
private:
    std::map<std::string, std::vector<std::string>> categories;
    std::string selectedCategory;
    std::string secretWord;
    std::string hiddenWord;

public:
    void loadWords(const std::string& filename);
    void chooseCategory(int choice);
    void pickWord();
    bool hasLetter(char letter) const;
    void reveal(char letter);
    bool guessed() const;
    const std::string& getHidden() const;
    const std::string& getWord() const;
    const std::map<std::string, std::vector<std::string>>& getCategories() const { return categories; }
};
