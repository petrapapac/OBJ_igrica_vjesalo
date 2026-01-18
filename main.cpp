#include "UI.h"
#include "Hangman.h"
#include "Statistics.h"
#include "WordManager.h"

#include <iostream>
#include <set>
#include <cctype>

using namespace std;

int main() {
    UI ui;
    Hangman hangman;
    Statistics stats;
    WordManager wm;

    wm.loadWords("words.txt");

    char again = 'y';
    const int MAX_MISTAKES = 6;

    while (again == 'y' || again == 'Y') {

        hangman.reset();
        set<char> usedLetters;
        int mistakes = 0;

        ui.displayWelcome();
        ui.displayRules();

        int idx = 1;
        for (auto& c : wm.getCategories()) {
            cout << idx++ << ". " << c.first << endl;
        }
        int choice;
        cout << "Unesite broj kategorije: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Neispravan unos!\n";
            continue;
        }

        cin.ignore(10000, '\n');

        wm.chooseCategory(choice);
        wm.pickWord();


        while (mistakes < MAX_MISTAKES && !wm.guessed()) {

            ui.displayGame(wm.getHidden(), usedLetters, hangman);

            string input = ui.getInput();
            if (input.empty())
                continue;

            char letter = tolower(input[0]);

            if (!isalpha(letter)) {
                cout << "Unesite slovo abecede!\n";
                continue;
            }

            if (usedLetters.count(letter)) {
                cout << "Slovo je vec iskoristeno!\n";
                continue;
            }

            usedLetters.insert(letter);

            if (wm.hasLetter(letter)) {
                wm.reveal(letter);
            }
            else {
                mistakes++;
                hangman.addMistake();
            }
        }

        bool win = wm.guessed();
        ui.displayEnd(win, wm.getWord());

        if (win)
            stats.addWin();
        else
            stats.addLoss();

        stats.display();

        cout << "\nZelite igrati ponovno? (y/n): ";
        cin >> again;
        cin.ignore(10000, '\n');
        cout << endl;
    }

    cout << "Hvala na igri!\n";
    return 0;
}
