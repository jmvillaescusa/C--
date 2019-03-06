/*
Questions
1. Branches help the programmer create different results depending on the player's input
   In some games, depending on the players actions, can trigger a certain ending

2. It is recommended to try to do the least amount of nesting to avoid making the coding complicated

3. Flowcharts are diagram showing the logical flow of steps in a prosses;
   It's a good way to visually see code, instead of using pseudocode

4. Random number generator (RNG for short) can add an element of suprise to gamers, making it a more engaging experience
   But if your game has an over abundance of RNG, that game may not be fun

5. Use the the average of the minimum and maximum values
   If the number is greater than the average, maximum becomes average minus 1
   Otherwise, if number is lesser than the average, minimum becomes average plus 1
   Repeat the process until the average is the number
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	//Projects 

	// 1. Enter a score
	/*int score = 0;
	std::cout << "Enter a score: ";
	std::cin >> score;

	if (score < 0) {
		std::cout << "That's not a legal score!\n";
	}
	else if (score >= 0 && score <= 999) {
		std::cout << "Nothing to brag about.\n";
	}
	else if (score > 999 && score <= 9999) {
		std::cout << "Good Score.\n";
	}
	else if (score > 9999) {
		std::cout << "Very impressive!\n";
	}*/

	// 2. Guess My Number 2.0
	/*srand(static_cast<unsigned int>(time(0)));
	const int MAX_NUMBER = 100;
	int secretNumber = (rand() % MAX_NUMBER) + 1;
	
	int tries = 5;
	int guess;

	std::cout << "\tWelcome to Guess My Number 2.0\n\n";
	std::cout << "Guess my secret number between 1 and " << MAX_NUMBER << ".\n";
	std::cout << "You have " << tries << " tries left.\n\n";

	do {
		std::cout << "Enter a guess: ";
		std::cin >> guess;

		if (guess > secretNumber) {
			std::cout << "Too high!\n";
			tries--;
			std::cout << "You have " << tries << " tries left.\n\n";
		}
		else if (guess < secretNumber) {
			std::cout << "Too low!\n";
			tries--;
			std::cout << "You have " << tries << " tries left.\n\n";
		}
		else {
			std::cout << "You win!\n";
		}

		if (tries == 0) {
			std::cout << "Game Over! You ran out of tries.\n";
			std::cout << "The number was " << secretNumber << ".\n";
		}
	} while (guess != secretNumber && tries > 0);*/

	// 3. Psudocode for Guess Your Number
	/*
	Assign low = 0, high = 100, guess, tries = 0, and myNumber int datatypes
	Introduce user to game and rules
	Tell the user to input myNumber from 1 - 100
	Start loop while the guess does not equall myNumber
		Increment tires
		Assign guess to (high + low)/2
		If myNumber is greater than the guess
			Assign the high to guess minus 1
		Or if myNumber is lesser than the guess
			Assign the low to guess plus 1
		Otherwise
			Tell the user that you got it in tries
	*/

	// 4. Guess Your Number
	/*int low = 0;
	int high = 100;
	int guess;
	int tries = 0;
	int myNumber;

	std::cout << "Welcome to Guess Your Number!\n";
	std::cout << "Please Enter a number from 1 - 100 so that I can guess it.\n\n";

	std::cout << "Your number: ";
	std::cin >> myNumber;
	std::cout << std::endl;

	do {
		++tries;
		guess = (high + low) / 2;
		std::cout << guess << std::endl;

		if (guess > myNumber) {
			high = guess - 1;
		}
		else if (guess < myNumber) {
			low = guess + 1;
		}
		else {
			std::cout << "\nThat's it! I got it in " << tries << " guesses!\n";
		}

	} while (guess != myNumber);*/

	// 5. Nim
	int sticks = 13;
	bool playerTurn = true; // true - Player One, false - Player Two
	int input;

	std::cout << "\tWelcome to a game of Nim\n\n";
	std::cout << "Take turns picking up sticks!\n";
	std::cout << "The objective is to be the one that picks up the last stick\n";
	std::cout << "But you can only pick 1 - 4 stick up per turn\n";

	do {
		std::cout << "\nThere are " << sticks << " left."<< std::endl;

		if (playerTurn) {
			std::cout << "Player 1, how many would you like to take? ";
			std::cin >> input;
			if (input <= 0 || input > 4) {
				std::cout << "Invalid input\n\n";
			}
			else {
				sticks = sticks - input;
				if (sticks > 0) {
					playerTurn = false;
				}
				else {
					playerTurn = true;
				}
			}
		}
		else {
			std::cout << "Player 2, how many would you like to take? ";
			std::cin >> input;
			if (input <= 0 || input > 4) {
				std::cout << "Invalid input\n\n";
			}
			else {
				sticks = sticks - input;
				if (sticks > 0) {
					playerTurn = true;
				}
				else {
					playerTurn = false;
				}
			}
		}
	} while (sticks > 0);

	if (playerTurn) {
		std::cout << "\nPlayer 1 Wins!\n";
	}
	else {
		std::cout << "\nPlayer 2 Wins!\n";
	}

	return 0;
}