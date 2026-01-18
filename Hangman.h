#ifndef _HANGMAN
#define _HANGMAN


class Hangman {
private:
    int mistakes;

public:
    Hangman();

    void reset();
    void addMistake();
    void draw() const;
};
#endif 