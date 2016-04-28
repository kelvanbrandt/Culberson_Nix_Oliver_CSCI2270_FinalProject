This project is the work of Chuck Culberson, Hayden Nix, and Alexander Oliver.

This project is for our CSCI 2270 class in order to use our C++ skills to bring together a functional project.

In brainstorming, we have come up with:
	1. Casual game with mechanics resembling 2048.
	2. Purely storage related program that has similarities to previous assignments/storage.
		-Game storage
		-Athletic Training App
		-Homework Scheduling
	3. Puzzle game idea.


And our decision of a project is:

	Hangman & Mastermind

And this is what it is in detail:
	
	Guess letters to find the computer generated word, get inside the mind of this computer as you try to figure out not only what word or phrase is going through its circuits, but also the 4 part randomly generated letter password to get its prize.

Hangman:For Hangman our program chooses a random word from a list of thousands of words. The user is allowed 5 incorrect guesses, any more and they lose. As they guess letters they are informed whether their guess was correct or wrong and if it is correct it is displayed where the letter appears in the word.  The game goes until either all 5 incorrect guesses are used or the user guesses the word. -Builds an Array of the words
-Builds a linked list to traverse the letters of each word 
-Uses a struct to store bool for word foundMastermind:For mastermind the user is given the option to choose from three difficulty levels: Simple, Normal, and Tough. The more difficult the mode, the more letters there are for the computer to choose from and the more spaces the user needs to guess.
-Builds arrays to store all values eg. locations, letters, etc.Our program is capable of running in Code::Blocks and is completely self contained, not requiring any third party libraries (it does require the nounList.cpp to be included in the program’s folder). It will run on any environment that compiles C++ and accepts C++11 libraries. 

The only bug we are experiencing at the moment occurs after the user plays a game of hangman. After the game ends it is suppose to print the menu and ask for an input but instead it prints the menu twice.INSTRUCTIONS FOR RUNNING (through terminal, assuming git is downloaded):
	1. In terminal on your local machine, navigate to your desktop (cd Desktop/)
	
	2. Type git clone “https://github.com/scoopaldish/Culberson_Nix_Oliver_CSCI2270_FinalProject.git”

	3. Navigate into file (cd Culberson_Nix_Oliver_CSCI2270_FinalProject/)

	4. Type “g++ -std=c++11 Hangman.cpp -c” and click enter (if you have not downloaded g++ you will be asked to now

	5. Type “g++ -std=c++11 Mastermind.cpp -c” and click enter

	6. Type “g++ -std=c++11 Hangman.o Mastermind.o main.cpp -o Game” and click enter
	
	7. Type “./Game” and click enter

	8. Have fun!!!!