#include "Mastermind.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Mastermind::Mastermind() {
	repeats = true;
}

Mastermind::~Mastermind() {}

void Mastermind::setDifficulty() {
	cout << endl << "Choose your difficulty." << endl <<
		"1. Simple" << endl <<
		" - 4 colors, 3 spaces, 8 guesses, no repeats" << endl <<
		"2. Normal" << endl <<
		" - 6 colors, 4 spaces, 12 guesses" << endl <<
		"3. Tough" << endl <<
		" - 8 colors, 5 spaces, 14 guesses" << endl;
	string user;
	while( user != "1" && user != "2" && user != "3" ) {
		getline( cin, user );
		if( user == "1" ) {
			colors = 4;
			spaces = 3;
			guesses = 8;
			repeats = false;
		} else if( user == "2" ) {
			colors = 6;
			spaces = 4;
			guesses = 12;
		} else if( user == "3") {
			colors = 8;
			spaces = 6;
			guesses = 14;
		} else
			cout << "Invalid input. Try again." << endl;
	}
}

void Mastermind::generateSolution() {
	srand( time( NULL ) );
	COLOR random;
	if( repeats )
		for( int i = 0; i < spaces; i ++ ) {
			random = ( COLOR ) ( rand() % colors );
			solution[ i ] = random;
		}
	else {
		COLOR colorList[ colors ];
		for( int i = 0; i < colors; i ++ )
			colorList[ i ] = ( COLOR ) i;
		int remaining = colors;
		for( int i = 0; i < spaces; i ++ ) {
			random = ( COLOR ) ( rand() % remaining );
			solution[ i ] = colorList[ random ];
			for( int j = random; j < remaining - 1; j ++ )
				colorList[ j ] = colorList[ j + 1 ];
			remaining --;
		}
	}
}

bool Mastermind::parceGuess( string _guess ) {
	if( _guess.length() != spaces ) {
		cout << "Invalid input. Try again." << endl;
		return false;
	}
	for( int i = 0; i < spaces; i ++ )
		switch( _guess[ i ] ) {
			case 'R':
				guess[ i ] = RED;
				break;
			case 'B':
				guess[ i ] = BLUE;
				break;
			case 'Y':
				guess[ i ] = YELLOW;
				break;
			case 'P': 
				guess[ i ] = PURPLE;
				break;
			case 'O':
				if( colors > 4 ) {
					guess[ i ] = ORANGE;
					break;
				}
			case 'G':
				if( colors > 4 ) {
					guess[ i ] = GREEN;
					break;
				}
			case 'I':
				if( colors > 6 ) {
					guess[ i ] = INDIGO;
					break;
				}
			case 'W':
				if( colors > 6 ) {
					guess[ i ] = WHITE;
					break;
				}
			default:
				cout << "Invalid input. Try again." << endl;
				return false;
		}
	return true;
}

int Mastermind::accuracy() {
	int colorplace = 0, coloronly = 0;
	int length = 0;
	int unmatchedS[ spaces ], unmatchedG[ spaces ];

	for( int i = 0; i < spaces; i ++ )
		if( solution[ i ] == guess[ i ] )
			colorplace ++;
		else {
			unmatchedG[ length ] = guess[ i ];
			unmatchedS[ length ] = solution[ i ];
			length ++;
		}
	for( int i = 0; i < length; i ++ )
		for( int j = 0; j < length; j ++ )
			if( unmatchedG[ i ] == unmatchedS[ j ] ) {
				unmatchedS[ j ] = ( COLOR ) -1;
				coloronly ++;
			}

	cout << "Correct color & location : " << colorplace << '.' << endl <<
					"Correct color            : " << coloronly << '.' << endl;

	return colorplace;
}

void Mastermind::gameplay() {
	setDifficulty();
	solution = new COLOR[ colors ];
	guess = new COLOR[ colors ];
	generateSolution();

	cout << endl << "RULES:" << endl <<
		"1. You have " << guesses << " guesses." << endl <<
		"2. There are " << spaces << " spaces in the code." << endl <<
		"3. Your colors to guess from are red, blue, yellow, ";
	if( colors == 4 )
		cout << "and purple.";
	else if( colors == 6 )
		cout << "purple," << endl <<
			"    orange, and green.";
	else if( colors == 8 )
		cout << "purple," << endl <<
			"    orange, green, indigo, and white.";
	cout << endl <<
		"4. Guess in the form \"RBYP\" if you think the code" << endl <<
		"    is red blue yellow purple in that order." << endl;

	string user;
	int used;
	for( used = 0; used < guesses; used ++ ) {
		cout << endl << "Guesses remaining: " << guesses - used << endl;
		do {
			getline( cin, user );
			cin.clear();
		} while( !parceGuess( user ) );
		if( accuracy() == spaces )
			break;
	}
	cout << endl;
	if( used < guesses )
		cout << "Good job, you only used " << used << " guesses" << endl <<
			"to find the right answer.";
	else {
		cout << "Turns out the code was ";
		for( int i = 0; i < spaces; i ++ ) {
			switch( solution[ i ] ) {
				case RED:
					cout << 'R';
					break;
				case BLUE:
					cout << 'B';
					break;
				case YELLOW:
					cout << 'Y';
					break;
				case PURPLE:
					cout << 'P';
					break;
				case ORANGE:
					cout << 'O';
					break;
				case GREEN:
					cout << 'G';
					break;
				case INDIGO:
					cout << 'I';
					break;
				case WHITE:
					cout << 'W';
					break;
				default:
					cout << '?';
					break;
			}
		}
	}
	cout << '.' << endl << "Better luck next time." << endl << endl;

	delete[] solution;
	delete[] guess;
}