#ifndef HANGMAN_H
#define HANGMAN_H
#include <iostream>

using namespace std;

struct Letter {
    char key;
    bool found;
    letter * next;
    
    Letter();
    Letter( char );
};

class Hangman {
    Letter * letArray;
    
    public:
        Hangman();
        ~Hangman();
        string setUpGame( int );
        void buildWord( string );
        void gameplay( letter * );
};

#endif // HANGMAN_H
