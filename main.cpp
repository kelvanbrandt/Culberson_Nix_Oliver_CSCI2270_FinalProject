#include "Hangman.h"
#include "Mastermind.h"
<<<<<<< HEAD

=======
#include <cstdlib>
>>>>>>> origin/master
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printMenu();
Hangman HT; //instance of hangman class

int main() {
    srand(time(NULL)); //allows for a new random choice every time later on.
    cout << "__Welcome to Minigames__" << endl << endl; 

    string user;
    do {
        printMenu();
        getline( cin, user );
        cin.clear();

        if( user == "1" ) {
            cout << endl << "==Hangman==" << endl;
            HT.buildArray();                            //build an array from list of words

            int randomChoice = rand() % 4213 + 0;       //select a random number for the word array
            string word = HT.setUpGame(randomChoice);	//uses random number to set up game with random word

            letter *playWord = HT.buildList(word);	//breaks word into a linked list of structs to determine if found and print

            HT.gameplay(playWord); //play the round with the chosen word

        } else if( user == "2" ) { // Mastermind
            cout << endl << "==Mastermind Memory==" << endl;
            Mastermind M;
<<<<<<< HEAD
            M.gameplay();
        } else if( user != "3" ) // accepts all invalid input
=======

            M.gameplay();	//contains all functions for mastermind game

        } else if( user != "3" ) // accepts all invalid input 
>>>>>>> origin/master
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
