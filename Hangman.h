#ifndef HANGMAN_H
#define HANGMAN_H
#include <iostream>

using namespace std;

struct letter{
    char key = NULL;
    bool found = false;
    letter* next = NULL;
    letter* previous = NULL;

    letter(){};

    letter(char type){
        key = type;

    }

};


class Hangman
{
    public:
        Hangman();
        ~Hangman();
        void buildArray();
        string setUpGame(int randomChoice);
	void visual(int wrongGuess);
        void gameplay(letter* word);
        letter* buildList(string word);
        void addPreviousTry(char letter);
    protected:
    private:
        string wordArray[4213];
        char guessedLetters[5];
};

#endif // HANGMAN_H
