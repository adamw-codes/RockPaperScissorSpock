//============================================================================
// Name        : RockPaperScissorsLizardSpock.cpp
// Author      : Adam M. Wajahat
// Description : A program that a user can play Rock, Paper, Scissors, Lizard, and Spock against. Once each game is over, the program asks if the user wants to play again. When the user is done
// 				 wants to stop playing then the program displays how many games the user won and lost.
//============================================================================

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;

// defining all the functions needed
void display_menu();
int random_choice();
int get_user_response();
int compare_choices(int, int);
void score_keeper(int);
int play_again();
// global variable of won and lost games
int won_games;
int lost_games;
// global array for names of the choices
string choices[5] = {"rock", "paper", "scissors", "lizard", "spock"};

int main() {

while(true){
	// calls on and gets returned value from the random_choice which randomly chooses a number between 1 and 5
	int random_pick = random_choice();
	// calls on the display_menu function to display all the choices for the user
	display_menu();
	// calls on and gets returned value from the get_user_response which tells what choice the user picked
	int user_pick = get_user_response();
	// calls on and gets returned value from the compare_choice which tells which player won
	int win_or_lost = compare_choices(user_pick, random_pick);
	// in case there is a tie the program enters this loop where it runs the game again
	while(win_or_lost == 0){
		// calls on and gets returned value from the random_choice which randomly chooses a number between 1 and 5
		random_pick = random_choice();
		// calls on the display_menu function to display all the choices for the user
		display_menu();
		// calls on and gets returned value from the get_user_response which tells what choice the user picked
		user_pick = get_user_response();
		// calls on and gets returned value from the compare_choice which tells which player won
		win_or_lost = compare_choices(user_pick, random_pick);
	}
	// uses the returned value as an argument for the score_keeper function that keeps track of won and lost games
	score_keeper(win_or_lost);
	// calls on and gets returned value from the play_again which tells if the user wants to play again or not
	int answer = play_again();
	// if the returned value from play_again is 3(which is the return value for the user picking no), the program will end the game and display hwo many times the user lost and won
	if(answer == 3){
			// displays prompt thanking the user
			cout << "Thank you for playing" << endl;
			// calls on global variables won_games and lost_games
			cout << "We played " << won_games + lost_games << " games. Of those games, you won " << won_games << " game(s) and lost " << lost_games << " game(s)." << endl;
			exit(0);
		}
}

		return 0;
}

// function to display the user's menu
void display_menu(){
	// prompts the user to pick a value between 1 or 5, each representing a choice
	cout << "Welcome to Rock, Paper, Scissors, Lizard, Spock" << endl;
	cout << "Play against me! To start select a choice from the options below." << endl;
	cout << setw(10) << left << "Rock" << setw(10) << "1" << endl;
	cout << setw(10) << left << "Paper" << setw(10) << "2" << endl;
	cout << setw(10) << left << "Scissors" << setw(10) << "3" << endl;
	cout << setw(10) << left << "Lizard" << setw(10) << "4" << endl;
	cout << setw(10) << left << "Spock" << setw(10) << "5" << endl;
	cout << setw(10) << left << "Enter a number between 1-5" << endl;
}

// function to read in user's response and validate it
int get_user_response(){
	// declaring variable user_pick to store the choice in
	int user_pick;
	// gets user input
	cin >> user_pick;
	// if the user picks a value that is either less than 1 or greater than 5, then the program will enter this loop
	while(user_pick < 1 || user_pick > 5){
		// displays prompt that says the user has picked an invalid choice
		cout << "That isn't a number between 1 and 5. Please choose again." << endl;
		// gets another input from user
		cin >> user_pick;
	}
	// returns user_pick to be passed onto later functions
	return user_pick;
	exit (0);
}

// function to choose a random number 1 to 5
int random_choice(){
	// declaring variable random_pick to store the choice in
	int random_pick;
	// declaring the seed for the random function
	srand(time(NULL));
	// picking a random number between the numbers 1 and 5 and storing in random_pick
	random_pick = rand() % 5 + 1;
	// returns random_pick to be passed onto later functions
	return random_pick;
}

// function that tells whether the user won or lost
int compare_choices(int answer, int random){
	// declaring variable win_or_loss to store the value that is to be returned to say who won
	int win_or_loss;

	// if the user and the program pick the same choice then it goes to a tie
	if(answer == random){
		// gives prompt that it is a tie
		cout << "We picked the same choice. Lets go again" << endl;
		// sets the returned value to be 0
		win_or_loss = 0;
		return win_or_loss;
	}
	// if the user beats the program
	else if((answer == 1 && random == 3) ||
			(answer == 1 && random == 4) ||
			(answer == 2 && random == 1) ||
			(answer == 2 && random == 5) ||
			(answer == 3 && random == 4) ||
			(answer == 3 && random == 2) ||
			(answer == 4 && random == 2) ||
			(answer == 4 && random == 5) ||
			(answer == 5 && random == 3) ||
			(answer == 5 && random == 1)
											){
		// gives prompt that the user has won and uses the global array to show what choice the user picked and the program picked
		cout << "You beat me! I picked " << choices[random-1] << " and you picked " << choices[answer-1] << endl;
		// sets returned value to 1
		win_or_loss = 1;
		return win_or_loss;

	}
	// if the program beats the user
	else if((answer == 3 && random == 1) ||
			(answer == 4 && random == 1) ||
			(answer == 1 && random == 2) ||
			(answer == 5 && random == 2) ||
			(answer == 4 && random == 3) ||
			(answer == 2 && random == 3) ||
			(answer == 2 && random == 4) ||
			(answer == 5 && random == 4) ||
			(answer == 3 && random == 5) ||
			(answer == 1 && random == 5)
											){
		// gives the prompt that the program has won and uses the global array to show what choice the user picked and the program picked
		cout << "Ha! I beat you! I picked " << choices[random-1] << " and you picked " << choices[answer-1] << endl;
		// sets returned value to 2
		win_or_loss = 2;
		return win_or_loss;
	}
}

// function to keep score of wins and losses
void score_keeper(int win_or_loss){
	// if the value given from the win_or_loss argument is 1 then the user won and the global won_games variable is incremented
	if(win_or_loss == 1){
		won_games++;
	}
	// if the value given from the win_or_loss argument is 2 then the user lost and the global lost_games variable is incremented
	else if(win_or_loss == 2){
		lost_games++;
	}
}

// function that determines whether the user wants to play again
int play_again(){
	// defined variable that stores the user's choice
	char yes_no;
	// gives the user the prompt on whether they want to play again or not
	cout << "Do you want to play again? Enter y for yes and n for no." << endl;
	// stores the user's input
	cin >> yes_no;
	// loops that runs until a 'n' or 'y' is entered which breaks it
	while(true){
	// if the user  entered 'y' then the program returns a 1 and ends the loop
	if(yes_no == 'y'){
		return 1;
	}
	// if the user  entered 'n' then the program returns a 3 and ends the loop
	else if(yes_no == 'n'){
		return 3;
	}
	// if the user entered anything else the program asks for a value to be returned
	else{
		cout << "Please only enter a y or n for yes or no respectively." << endl;
		cin >> yes_no;
		}
	}
}

