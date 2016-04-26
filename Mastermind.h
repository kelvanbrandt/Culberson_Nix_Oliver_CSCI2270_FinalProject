#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <string>

enum COLOR : char { RED, BLUE, YELLOW, PURPLE, ORANGE, GREEN, INDIGO, WHITE };

class Mastermind {
	COLOR * solution, * guess;
	bool repeats;
	int colors, spaces, guesses;
	
	public:
		Mastermind();
		~Mastermind();
		void setDifficulty();
		void generateSolution();
		bool parceGuess( std::string );
		int accuracy();
		void gameplay();
};

#endif // MASTERMIND_H