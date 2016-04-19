#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

bool quitSwitch = false; //quitting the main menu, while loop
int userChoice = 0;

int main()
{
    cout<<"__Welcome to Minigames__\n"<<endl; //we can work on the name

    while (!quitSwitch){

        cout<<"Choose a game: "<<endl;
        cout<<"1. Hangman"<<endl;
        cout<<"2. Mastermind Memory"<<endl;
        cout<<"3. Quit"<<endl;
        cin>>userChoice;

        if (userChoice == 1){    //Hangman
            cout<<"\n==Hangman=="<<endl;
        }

        else if (userChoice == 2){   //Mastermind
            cout<<"\n==Mastermind Memory=="<<endl;
        }

        else if (userChoice == 3){   //Quit
            cout<<"Thanks for playing!!"<<endl;
            quitSwitch = true;
        }

        else {    //Invalid Entry
            cout<<"Please enter a valid input."<<endl;
        }


   }



}
