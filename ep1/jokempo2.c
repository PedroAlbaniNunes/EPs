// Write a program that implements the game known as rock, paper, scissors. This time, the game will be played between 
// a human user (player) and the computer over N rounds, where N is a constant previously defined in the code (use #define 
// to define the constant). In each round, the human chooses an option between rock, paper, and scissors, and your program 
// should display the result of the match on the screen: human wins, computer wins, or a tie. At the end of the N rounds, 
// your program should display:

//  -   The number of human wins
//  -   The number of computer wins
//  -   The number of ties

// Requirements:

//  -   To simulate the computer's choices, you must use random number generation (function rand()).
//  -   The computer chooses the rock option with a 50% probability; the other options are chosen with a 25% probability each.
//  -   Create a function that generates the computer's move following the logic mentioned above.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define ROUNDS 4 //define the number of rounds that will be played


int choose() //fuction to randonmizer the number
{ 
    int machineChoice = (rand() % 100) + 1; //make the variable pick randomicaclly a number between 1 and 100 
    if (machineChoice < 50) //to make the 0 (number to Rock) be 50% chance
    {
        return 0;
    }
    else if ((machineChoice >= 50) && (machineChoice < 75)) // to make the 1 and 2 (number to Paper and Scissor respectively) be 25% each
    {
        return 1;
    }
    else 
    {
        return 2;
    }
}

int main() // main function
{
    
    int humanChoise, machineChoice, wins, losses, draws; // variable declaration
    wins = 0; // make the "Wins" variable = 0
    losses = 0; // make the "Losses" variable = 0 
    draws = 0; // make the "Draws" variable = 0
    srand(time(NULL)); //initialize the random number generator
    printf("Hello human, let's play a game of Rocks, Paper and Scissor. \n"); // call the user to play the game 
    for (int i = 0; i < ROUNDS; i++) // start of the for loop, starting with i = 0 and ending when i = ROUNDS, that is defined in the start if the code
    {
    printf("Pick a number between 0 and 2\n"); // teaches the user what numbers they can pick
    scanf("%i", &humanChoise);
        if ((humanChoise == 0) && ((choose(NULL) == 0))) // if the user choice is the same as the machine, the game is a draw
        {
            draws += 1;
        }
        else if (((humanChoise == 0) && (choose(NULL) == 2)) || ((humanChoise == 1) && (choose(NULL) == 0)) || ((humanChoise == 2) && (choose(NULL) == 1))) // if the user choice 
        // something that beats the machine choice, the game is a win for the user
        {
            wins += 1;
        }
        else // in every other case, the game is a win for the machine
        {
            losses += 1;
        }

    }

    printf("Human's victory number = %i\n", wins); // output the number of user wins
    printf("Machine's victory number = %i\n", losses); // output the number of machine wins
    printf("Draw's victory number = %i\n", draws); // output the number of draws

    system("pause");
    return 0;
    
}