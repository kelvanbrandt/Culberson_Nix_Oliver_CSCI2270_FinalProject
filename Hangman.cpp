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

void Hangman::gameplay(letter* word){
    int wrongGuess = 5;
    char guess;
    while (wrongGuess != -1){
        bool found = false;
        cout<<endl<<"Guess a letter: ";
        cin>>guess;
        cin.ignore();

    }


}
letter* Hangman::buildList(string word){
    letter *head = new letter(word[0]);
    letter *temp = head;
    for (int i = 1; i < word.size();i++){
        letter *add = new letter(word[i]);
        add->previous = temp;
        temp->next = add;
        temp = temp->next;
    }
    temp->next = NULL;

    return head;
}
