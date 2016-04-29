#include "Hangman.h"
#include "Mastermind.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char printMenu();
Hangman HT; //instance of hangman class
Mastermind M;

int main() {
    srand(time(NULL)); //allows for a new random choice every time later on.
    cout << "__Welcome to Minigames__" << endl << endl;
    char option;
    string word;
    int randomChoice;
    letter *playWord = new letter;

    do{
        option = printMenu();
        switch(option){
            case '1':   cout << endl << "==Hangman==" << endl;
                        HT.buildArray();                            //build an array from list of words
                        randomChoice = rand() % 4213 + 0;       //select a random number for the word array
                        word = HT.setUpGame(randomChoice);	//uses random number to set up game with random word
                        playWord = HT.buildList(word);	//breaks word into a linked list of structs to determine if found and print
                        HT.gameplay(playWord); //play the round with the chosen word
                        break;

            case '2':   cout << endl << "==Mastermind Memory==" << endl;
                        M.gameplay();	//contains all functions for mastermind game
                        break;

            default:    cout << "Thanks for playing!!" << endl;

        }
    }while(option != '3');

    return 0;
}

char printMenu() {
    char option;
    cout << "Choose a game:" << endl <<
            "1. Hangman" << endl <<
            "2. Mastermind Memory" << endl <<
            "3. Quit" << endl;
            cin >> option;
            return option;
}
