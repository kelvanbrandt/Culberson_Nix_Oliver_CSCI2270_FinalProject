#include "Mastermind.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Mastermind::Mastermind() {
	solution = "";
	repeats = true;
}

Mastermind::~Mastermind() {}

void Mastermind::setDifficulty() {
	cout << endl << "Choose your difficulty." << endl <<
		"1. Simple" << endl <<
		" - 4 letters to choose from, 3 letters long, 8 guesses, no repeats" << endl <<
		"2. Normal" << endl <<
		" - 6 letters to choose from, 4 letters long, 12 guesses" << endl <<
		"3. Tough" << endl <<
		" - 8 letters to choose from, 5 letters long, 14 guesses" << endl;
	string user;
	while( user != "1" && user != "2" && user != "3" ) {
		getline( cin, user );
		if( user == "1" ) {
			letters = 4;
			spaces = 3;
			guesses = 8;
			repeats = false;
		} else if( user == "2" ) {
			letters = 6;
			spaces = 4;
			guesses = 12;
		} else if( user == "3") {
			letters = 8;
			spaces = 6;
			guesses = 14;
		} else
			cout << "Invalid input. Try again." << endl;
	}
}

void Mastermind::generateSolution() {
	srand( time( NULL ) );
	char random;
	if( repeats )
		for( int i = 0; i < spaces; i ++ )
			solution += rand() % letters + 'A';
	else {
		char letterList[ letters ];
		for( int i = 0; i < letters; i ++ )
			letterList[ i ] = i + 'A';
		int remaining = letters;
		for( int i = 0; i < spaces; i ++ ) {
			solution += letterList[ random = rand() % remaining ];
			for( int j = random; j < remaining - 1; j ++ )
				letterList[ j ] = letterList[ j + 1 ];
			remaining --;
		}
	}
}


bool Mastermind::parseGuess() {
	cout << "> ";
	getline( cin, guess );
	cin.clear();
	if( guess.length() != spaces ) {
		cout << "Invalid input. Try again." << endl;
		return false;
	}
	for( int i = 0; i < spaces; i ++ )
		if( guess[ i ] < 'A' || 'A' + letters <= guess[ i ] ) {
			cout << "Invalid input. Try again." << endl;
			return false;
		}
	return true;
}

int Mastermind::accuracy() {
	int letterplace = 0, letteronly = 0;
	int length = 0;
	int unmatchedS[ spaces ], unmatchedG[ spaces ];

	for( int i = 0; i < spaces; i ++ )
		if( solution[ i ] == guess[ i ] )
			letterplace ++;
		else {
			unmatchedG[ length ] = guess[ i ];
			unmatchedS[ length ] = solution[ i ];
			length ++;
		}
	for( int i = 0; i < length; i ++ )
		for( int j = 0; j < length; j ++ )
			if( unmatchedG[ i ] == unmatchedS[ j ] ) {
				unmatchedS[ j ] = ( char ) 0;
				letteronly ++;
			}

	cout << "Correct letter & location : " << letterplace << '.' << endl <<
					"Correct letter            : " << letteronly << '.' << endl;

	return letterplace;
}

void Mastermind::gameplay() {
	setDifficulty();
	generateSolution();

	cout << endl << "RULES:" << endl <<
		"1. You have " << guesses << " guesses to crack the code." << endl <<
		"2. The possible letters used are A";
	for( char i = 1; i < letters; i ++ )
		cout << ' ' << ( char ) ( i + 'A' );
	cout << endl << "3. There are " << spaces << " letters in the code and " <<
		( repeats ? "some letters may" : "the letters do not" ) << " repeat." <<
		endl << "4. Guess in the form \"";
	for( char i = 0; i < spaces; i ++ )
		cout << ( char ) ( i + 'A' );
	cout << "\"." << endl;

	int used;
	for( used = 0; used < guesses; used ++ ) {
		cout << endl << "Guesses remaining: " << guesses - used << endl;
		while( !parseGuess() ) {};
		if( accuracy() == spaces )
			break;
	}
	cout << endl;
	if( used < guesses )
		cout << "Good job, you only used " << used << " guesses" << endl <<
			"to find the right answer." << endl;
	else {
		cout << "Turns out the code was ";
		for( int i = 0; i < spaces; i ++ )
			cout << solution[ i ];
		cout << '.' << endl << "Better luck next time." << endl << endl;
	}
}
