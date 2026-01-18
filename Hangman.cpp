#include "Hangman.h"
#include <iostream>

using namespace std;

Hangman::Hangman() {
    mistakes = 0;
}

void Hangman::reset() {
    mistakes = 0;
}

void Hangman::addMistake() {
    mistakes++;
}

void Hangman::draw() const {
    if (mistakes == 0)
        return;

    cout << " ------\n";
    cout << " |    |\n";
    cout << " |    " << (mistakes >= 1 ? 'O' : ' ') << "\n";
    cout << " |   "
        << (mistakes >= 3 ? '/' : ' ')
        << (mistakes >= 2 ? '|' : ' ')
        << (mistakes >= 4 ? '\\' : ' ')
        << "\n";
    cout << " |   "
        << (mistakes >= 5 ? '/' : ' ')
        << " "
        << (mistakes >= 6 ? '\\' : ' ')
        << "\n";
    cout << " |\n_|_\n";
}
