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
    // Menu Chooser
	/*std::cout << "Difficulty Levels\n\n";
	std::cout << "1 - Easy\n";
	std::cout << "2 - Normal\n";
	std::cout << "3 - Hard\n\n";
	
	int choice;
	std::cout << "Choice: ";
	std::cin >> choice;

	switch (choice) {
	case 1:
		std::cout << "You picked Easy.\n";
		break;
	case 2:
		std::cout << "You picked Normal.\n";
		break;
	case 3:
		std::cout << "You picked Hard.\n";
		break;
	default:
		std::cout << "You made an illegal choice.\n";
	}*/

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

	return 0;
}