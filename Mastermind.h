#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <string>

class Mastermind {
	std::string solution, guess;
	bool repeats;
	int letters, spaces, guesses;
	
	public:
		Mastermind();
		~Mastermind();
		void setDifficulty();
		void generateSolution();
		bool parseGuess();
		int accuracy();
		void gameplay();
};

#endif // MASTERMIND_H
