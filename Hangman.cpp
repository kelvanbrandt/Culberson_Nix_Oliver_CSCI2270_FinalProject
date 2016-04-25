#include "Hangman.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

#define WORDS 4213

Letter::Letter() {
    key = NULL;
    found = false;
    next = NULL;
    previous = NULL;
};

Letter::Letter( char _letter ) {
    Letter();
    key = _letter;
}

Hangman::Hangman() {}

Hangman::~Hangman() {}

string Hangman::setUpGame() {
    string word;
    {
        ifstream inFile( "nounList.txt" );
        int random = rand() % WORDS;
        for( int i = 0; i < random; i ++ ) {
            getline( inFile, word );
        }
        inFile.close();
    }

    cout<<"\nThe computer has selected a random word"<<endl;

    for( int i = 0; i < word.size(); i ++) //this shows the spaces of the word
        cout<<"_";
    
    cout<<endl<<endl;

    cout<<"You must guess the Letters to complete the word"<<endl;
    cout<<"You are allowed 5 incorrect guesses"<<endl;
    return word;
}

void Hangman::buildWord( string word ) {
    letArray = new Letter( word[ 0 ] );
    Letter * temp = letArray;
    for( int i = 1; i < word.size(); i ++ ) {
        temp->next = new Letter( word[ i ] );
        temp = temp->next;
    }
    temp->next = NULL;

    return head;
}

void Hangman::gameplay() {
    Letter * temp;
    int wrongGuess = 5;
    char guess;
    bool finished = false;
    while( wrongGuess != -1 && !finished ) {
        temp = letArray;
        bool found = false;
        cout<<endl<<"Guess a Letter: ";
        cin>>guess;
        cin.clear();
        cout<<"------------------------------"<<endl<<endl;
        while( temp ) {
            finished = true;
            if( temp->key == guess ) {
                found = true;
                temp->found = true;
            }
            temp = temp->next;
        }
        temp = letArray;
        if( found ) {
            cout<<"\nNICE GUESS!!"<<endl<<endl;
            while( temp ) {
                if( !temp->found )
                    finished = false;
                temp = temp->next;
            }
            cout<<"\nWrong guesses remaining: "<<wrongGuess<<endl<<endl;
            cout<<"==========================="<<endl<<endl;
            temp = letArray;
        } else {
            cout<<"\nSorry, nope."<<endl<<endl;
            while( temp ) {
                if( !temp->found )
                    finished = false;
                temp = temp->next;
            }
            temp = letArray;
            wrongGuess--;
            if( wrongGuess != -1 ) {
                cout<<"\nWrong guesses remaining: "<<wrongGuess<<endl<<endl;
                cout<<"==========================="<<endl<<endl;
            }
        }
        while( temp ) {
            if( temp->found )
                cout<<temp->key;
            else
                cout<<"_";
            temp = temp->next;
        }
        cout<<endl;
        if( finished )
            cout<<"GREAT JOB, YOU WIN"<<endl<<endl;
    }
    Letter * deleter;
    temp = letArray;
    while( temp ) {
        deleter = temp;
        temp = temp->next;
        delete deleter;
    }
}
