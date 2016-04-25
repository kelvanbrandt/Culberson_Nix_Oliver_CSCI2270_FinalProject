#include "Hangman.h"
#include "Mastermind.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void printMenu();
Hangman HT;

int main() {
    cout << "__Welcome to Minigames__" << endl << endl; // we can work on the name

    string user;
    do {
        printMenu();
        getline( cin, user );
        cin.clear();

        if( user == "1" ) { // Hoenigman
            cout << endl << "==Hangman==" << endl;
            HT.buildArray();
            // ideas:
            // let's make an encoded list of words in another file
            // I'm thinking just an XOR encoded list so people can't just look at it and know all the words
        } else if( user == "2" ) { // Mastermind
            cout << endl << "==Mastermind Memory==" << endl;
            // implement rand() for this
        } else if( user != "3" ) // accepts all invalid input
            cout << "Please enter a valid input." << endl;
    } while( user != "3" );

    cout << "Thanks for playing!!" << endl;

    return 0;
}

void printMenu() {
    cout << "Choose a game:" << endl <<
            "1. Hangman" << endl <<
            "2. Mastermind Memory" << endl <<
            "3. Quit" << endl;
}
