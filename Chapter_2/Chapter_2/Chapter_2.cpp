/*
	Questions
	1. Looping lets the programmer repeat executable code without having to write it again
	   Programming without loops makes the code much more longer than usual

	2. Switch statements are able to test int, char, and enum datatypes
	   Any other types must be used with if/else statements

	3. Omitting breaks after a case statment makes the program continue the switch statment until it reaches the end of that statement,
	   a default, or a break
	   Its often recommended to have a break per case statement

	4. Use a while loop when the variable has value before the loop
	   
	5. In any arcade-esque games, they check if the player has less than 0 lives
	   The player is given (oftenly) 3 lives at the start of the game
	   As long as the player has more than 0 lives, the game loop continues
	   Once the player loses all 3 lives, the game goes to a game over screen, breaking out of the loop
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	// Exercises
    // 1. Menu Chooser
	std::cout << "Difficulty Levels\n\n";
	std::cout << "1 - Easy\n";
	std::cout << "2 - Normal\n";
	std::cout << "3 - Hard\n\n";
	
	enum difficulty {EASY = 1, NORMAL = 2, HARD = 3};
	difficulty myDifficulty;
	int choice;
	std::cout << "Choice: ";
	std::cin >> choice;

	switch (choice) {
	case 1:
		myDifficulty = EASY;
		std::cout << "You picked Easy.\n";
		break;
	case 2:
		myDifficulty = NORMAL;
		std::cout << "You picked Normal.\n";
		break;
	case 3:
		myDifficulty = HARD;
		std::cout << "You picked Hard.\n";
		break;
	default:
		std::cout << "You made an illegal choice.\n";
	}

	/*
	2. - while(x) is a infinite loop
	   - the code must have a garentee false statement for it to end the loop
	   - example: while (x < 11) 
	*/

	// 3. Guess My Number 2.0
	int low = 0;
	int high = 100;
	int guess;
	int tries = 0;
	int myNumber;

	std::cout << "\n\nWelcome to Guess My Number 2.0!" << std::endl;
	std::cout << "Please Enter a number from 1 - 100 so that I can guess it.\n" << std::endl;

	std::cout << "Your number: ";
	std::cin >> myNumber;
	std::cout << "\n";

	do {
		++tries;
		guess = (high + low)/2;
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
		
	} while (guess != myNumber);

	return 0;
}