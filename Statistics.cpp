#include "Statistics.h"
#include <iostream>

using namespace std;

Statistics::Statistics() {
    games = wins = losses = 0;
}

void Statistics::addWin() {
    wins++;
    games++;
}

void Statistics::addLoss() {
    losses++;
    games++;
}

void Statistics::display() const {
    cout << "\nSTATISTIKA:\n";
    cout << "Igre: " << games << endl;
    cout << "Pobjede: " << wins << endl;
    cout << "Porazi: " << losses << endl;
}
