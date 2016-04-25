#include "Hangman.h"
#include <iostream>
#include <fstream>

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

