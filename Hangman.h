#ifndef HANGMAN_H
#define HANGMAN_H
#include <iostream>

using namespace std;

class Hangman
{
    public:
        Hangman();
        ~Hangman();
        void buildArray();
        string setUpGame(int randomChoice);
        void gameplay(string word);
    protected:
    private:
        string wordArray[4213];
};

#endif // HANGMAN_H
