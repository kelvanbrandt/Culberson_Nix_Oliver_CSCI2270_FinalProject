#include "Hangman.h"
#include "Mastermind.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void printMenu();

int main() {
    srand( time( NULL ) ); //allows for a new random choice every time later on.
    cout << "__Welcome to Minigames__" << endl << endl; // we can work on the name

    string user;
    Hangman HT; //instance of hangman class
    do {
        printMenu();
        getline( cin, user );
        cin.clear();

        if( user == "1" ) {
            cout << endl << "==Hangman==" << endl;
            string word = HT.setUpGame();
            HT.buildList( word );
            HT.gameplay(); //set up the round with the chosen word
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
