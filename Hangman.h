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
    protected:
    private:
        string wordArray[4213];
};

#endif // HANGMAN_H
