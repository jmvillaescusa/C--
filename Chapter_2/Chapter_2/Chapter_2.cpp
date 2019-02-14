/*
	Questions
	1. 
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	// Exercises
    // 1. Menu Chooser
	/*std::cout << "Difficulty Levels\n\n";
	std::cout << "1 - Easy\n";
	std::cout << "2 - Normal\n";
	std::cout << "3 - Hard\n\n";
	
	enum difficulty {EASY, NORMAL, HARD};
	difficulty myDifficulty;
	int choice;
	std::cout << "Choice: ";
	std::cin >> choice;

	if (choice == 1) {
		myDifficulty = EASY;
	}
	else if (choice == 2) {
		myDifficulty = NORMAL;
	}
	if (choice == 3) {
		myDifficulty = HARD;
	}

	switch (myDifficulty) {
	case EASY:
		std::cout << "You picked Easy.\n";
		break;
	case NORMAL:
		std::cout << "You picked Normal.\n";
		break;
	case HARD:
		std::cout << "You picked Hard.\n";
		break;
	default:
		std::cout << "You made an illegal choice.\n";
	}*/

	/*	2. - while(x) is a infinite loop
	       - the code must have a garentee false statement for it to end the loop
	       - example: while (x < 11) */

	// Guess My Number
	/*srand(static_cast<unsigned int>(time(0)));
	int secretNumber = rand() % 100 + 1;
	int tries = 0;
	int guess;

	std::cout << "\nWelcome to Guess My Number\n";

	do {
		std::cout << "Enter a guess: ";
		std::cin >> guess;
		++tries;

		if (guess > secretNumber) {
			std::cout << "Too high!\n\n";
		}
		else if (guess < secretNumber) {
			std::cout << "Too low!\n\n";
		}
		else {
			std::cout << "\nThat's it! You got it in " << tries << " guesses!\n";
		}
	} while (guess != secretNumber);*/

	// 3. Guess My Number 2.0
	int low = 50;
	int high = 100;
	int guess;
	int tries = 0;
	int myNumber;

	std::cout << "Welcome to Guess My Number 2.0!" << std::endl;
	std::cout << "Please Enter a number from 1 - 100 so that I can guess it.\n" << std::endl;

	std::cout << "Your number: ";
	std::cin >> myNumber;
	std::cout << "\n";

	do {
		++tries;
		guess = high - low;
		std::cout << guess << std::endl;

		if (guess > myNumber) {

		}
		else if (guess < myNumber) {

		}
		else {
			std::cout << "\nThat's it! I got it in " << tries << " guesses!\n";
		}
		
	} while (guess != myNumber);

	return 0;
}