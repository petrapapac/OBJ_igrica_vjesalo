#include "UI.h"
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

void UI::displayWelcome() const {
    cout << "+---------------------------------+\n";
    cout << "|             HANG MAN            |\n";
    cout << "+---------------------------------+\n";
}

void UI::displayRules() const {
    cout << "\nPRAVILA IGRE:\n";
    cout << "- Pogadaj slova da otkrijes rijec\n";
    cout << "- Imas 6 pogresnih pokusaja\n";
    cout << "- Vec iskoristena slova su oznacena\n\n";
}

void UI::displayGame(const string& word, const set<char>& used, const Hangman& h) const {
    h.draw();
    cout << "+---------------------------------+\n";
    cout << "|        Available letters        |\n";
    cout << "+---------------------------------+\n";

    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (size_t i = 0; i < alphabet.size(); ++i) {
        char c = alphabet[i];
        if (used.count(tolower(c))) cout << c << "~ ";
        else cout << c << "  ";
        if ((i + 1) % 14 == 0) cout << endl;
    }
    cout << "\n+---------------------------------+\n";

    cout << "|         Guess the word          |\n";
    cout << "+---------------------------------+\n| ";
    for (char c : word) cout << c << " ";
    cout << "|\n+---------------------------------+\n";
}

string UI::getInput() const {
    cout << "Unesi slovo: ";
    string s;
    cin >> s;
    return s;
}

void UI::displayEnd(bool win, const string& word) const {
    cout << (win ? "\nPOBJEDA!\n" : "\nPORAZ!\n");
    cout << "Trazena rijec: " << word << endl;
}