#ifndef MASTERMIND_H
#define MASTERMIND_H

enum COLOR : char { RED, GREEN, YELLOW, BLUE, ORANGE, INDIGO, VIOLET, WHITE };

class Mastermind {
    COLOR * solution, * guess;
    
    public:
        Mastermind();
        ~Mastermind();
        void setDifficulty();
        void generateSolution();
        void print();
        void gameplay();
};

#endif // MASTERMIND_H
