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

void Hangman::visual(int wrongGuess)
{
    if (wrongGuess==5)
            {
            cout<<"  ____    "<<endl;
            cout<<" |   |    "<<endl;
            cout<<" O   |    "<<endl;
            cout<<"     |    "<<endl;
            cout<<"     |    "<<endl;
            cout<<" ____|____"<<endl;}
            else if (wrongGuess==4)
            {
            cout<<"  ____    "<<endl;
            cout<<" |   |    "<<endl;
            cout<<" O   |    "<<endl;
            cout<<" |   |    "<<endl;
            cout<<"     |    "<<endl;
            cout<<" ____|____"<<endl;}
            else if (wrongGuess==3)
            {
            cout<<"  ____    "<<endl;
            cout<<" |   |    "<<endl;
            cout<<" O   |    "<<endl;
            cout<<" |/  |    "<<endl;
            cout<<"     |    "<<endl;
            cout<<" ____|____"<<endl;}
            else if (wrongGuess==2)
            {
            cout<<"  ____    "<<endl;
            cout<<" |   |    "<<endl;
            cout<<" O   |    "<<endl;
           cout<<"\\|/  |    "<<endl;
            cout<<"     |    "<<endl;
            cout<<" ____|____"<<endl;}
            else if (wrongGuess==1)
            {
            cout<<"  ____    "<<endl;
            cout<<" |   |    "<<endl;
            cout<<" O   |    "<<endl;
           cout<<"\\|/  |    "<<endl;
           cout<<"  \\  |    "<<endl;
            cout<<" ____|____"<<endl;}
            else if (wrongGuess==0)
            {
            cout<<"  ____    "<<endl;
            cout<<" |   |    "<<endl;
            cout<<" O   |    "<<endl;
           cout<<"\\|/  |    "<<endl;
           cout<<" /\\  |    "<<endl;
            cout<<" ____|____"<<endl;}
}

void Hangman::gameplay(letter* word){
    letter *temp = word;
    int wrongGuess = 5;
    char guess;
    bool finished = false;
    while (wrongGuess != -1){
        temp = word;
        bool found = false;
        cout<<endl<<"Guess a letter: ";
        cin>>guess;
        cin.clear();
        cout<<"==============================================="<<endl;
        while(temp){
            finished = true;
            if (temp->key == guess){
                found = true;
                temp->found = true;
            }
            temp = temp->next;
        }
        temp = word;
        if (found){
            cout<<"\nNICE GUESS!!"<<endl<<endl;
            while (temp){
                if (temp->found == false){
                    finished = false;
                }
                temp = temp->next;
            }
            temp = word;
            while (temp){
                if (temp->found){
                    cout<<temp->key;
                }
                else {
                    cout<<"_";
                }
            temp = temp->next;
            }
            cout<<endl;
            cout<<"\nWrong tries remaining: "<<wrongGuess<<endl;
            cout<<"Previous tries: ";
            for (int i = 0; i < 5; i++){
                cout<<guessedLetters[i]<<" ";
            }
            cout<<endl;
            temp = word;

        }
        else if (!found){
            cout<<"Sorry, nope."<<endl;
	    visual(wrongGuess);
            addPreviousTry(guess);
            while (temp){
                if (!temp->found){
                    finished = false;
                }
                temp = temp->next;
            }
            temp = word;
            while (temp){
                if (temp->found){
                    cout<<temp->key;
                }
                else {
                    cout<<"_";
                }
            temp = temp->next;
            }
            cout<<endl;
            wrongGuess--;
            if (wrongGuess != -1){
                cout<<"\nWrong tries remaining: "<<wrongGuess<<endl;
                cout<<"Previous wrong tries: ";
            for (int i = 0; i < 5; i++){
                cout<<guessedLetters[i]<<" ";
            }
            cout<<endl;
        }

    }
    if (finished){
            cout<<"\nGREAT JOB, YOU WIN"<<endl<<endl;
            cout<<"==============================================="<<endl;
            for (int i = 0; i < 5; i++ ){
            guessedLetters[i]=NULL;}
            break;
        }
}
if (wrongGuess == -1){
    temp = word;
    cout<<"\nGAME OVER"<<endl<<endl;
    cout<<"The correct word: ";
    for (int i = 0; i < 5; i++ ){
        guessedLetters[i]=NULL;
    }
    while (temp){
        cout<<temp->key;
        temp = temp->next;
    }

    cout<<endl<<"==============================================="<<endl<<endl;
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
void Hangman::addPreviousTry(char letter){
    for (int i = 0; i < 5; i ++){
        if (guessedLetters[i] == NULL){
            guessedLetters[i] = letter;
            break;
        }
    }


}
