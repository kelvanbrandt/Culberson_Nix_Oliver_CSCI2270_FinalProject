#include "Hangman.h"
#include "Mastermind.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printMenu();
Hangman HT; //instance of hangman class

int main() {
    srand(time(NULL)); //allows for a new random choice every time later on.
    cout << "__Welcome to Minigames__" << endl << endl; // we can work on the name

    string user;
    do {
        printMenu();
        getline( cin, user );
        cin.clear();

        if( user == "1" ) {
            cout << endl << "==Hangman==" << endl;
            HT.buildArray();                            //build an array from nounList
            int randomChoice = rand() % 4213 + 0;       //select a random number 0 - arraySize
            string word = HT.setUpGame(randomChoice);
            letter *playWord = HT.buildList(word);
            HT.gameplay(playWord); //set up the round with the chosen word
        } else if( user == "2" ) { // Mastermind
            cout << endl << "==Mastermind Memory==" << endl;
            Mastermind M;
            M.gameplay();
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
