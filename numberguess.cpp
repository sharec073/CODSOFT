// TASK-1: NUMBER GUESSING GAME
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{   
    //Activate random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Generate random number between 1 and 100
    int secretNumber = rand() % 100+1;
    cout<<"Welcome to Number Guessing Game!"<<endl;
    cout<<"I have chosen a number between 1 and 100. Try guessing it...!"<<endl;
    int userGuess;
    int attempts=0;
    while(true)
    {
        //Get the user's guess as input
        cout<<"Enter your guess: ";
        cin>>userGuess;
        attempts++;
        //Check if the guess is correct
        if(userGuess==secretNumber){
            cout<<"Congratulations! You guessed the correct number "<<secretNumber<<" in "<<attempts<<" attempts."<<endl;
            break;
        }
        else if(userGuess < secretNumber){
            cout<<"Too low... Try again..."<<endl;
        }
        else{
            cout<<"Too high... Try again..."<<endl;
        }
    }
    return 0;
}