#include "Hangman.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

Hangman::Hangman()
{
    //ctor
}

Hangman::~Hangman()
{
    //dtor
}

void Hangman::buildArray(){
    int arrayPosition = 0;
    ifstream inFile ("nounList.txt");
    while (getline(inFile,wordArray[arrayPosition])){
        arrayPosition++;
    }
}

string Hangman::setUpGame(int randomChoice){
    string word = wordArray[randomChoice]; //random word from the built array
    cout<<"\nThe computer has selected a random word"<<endl;

    for (int i = 0; i < word.size(); i++){ //this shows the spaces of the word
        cout<<"_";
    }
    cout<<endl<<endl;

    cout<<"You must guess the letters to complete the word"<<endl;
    cout<<"You are allowed 5 incorrect guesses"<<endl;
    return word;
}

void Hangman::gameplay(string word){
    int wrongGuess = 5;
    char guess;
    while (wrongGuess != -1){
        bool found = false;
        cout<<endl<<"Guess a letter: ";
        cin>>guess;
        cin.ignore();
        for (int i = 0; i <= word.size(); i++){
            if (guess == word[i]){
                found = true;
                break;
            }
        }
        if (found){
            //find all occurances and print out word with newly filled in spaces
        }
        else {
            //subtract one of the wrong guess, print word as is, change wrong letter list
        }
    }


}

