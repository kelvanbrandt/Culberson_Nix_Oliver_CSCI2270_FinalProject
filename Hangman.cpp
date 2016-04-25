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

void Hangman::setUpGame(int randomChoice){
    string word = wordArray[randomChoice]; //random word from the built array
    cout<<"\nThe computer has selected a random word"<<endl;

    for (int i = 0; i < word.size(); i++){ //this shows the spaces of the word
        cout<<"_";
    }
    cout<<endl<<endl;

    cout<<"You must guess the letters to complete the word"<<endl;
    cout<<"You are allowed 5 incorrect guesses"<<endl;
}

