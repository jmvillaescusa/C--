/*
Questions
1. Planning for the program allows the programmers to save time and, sometimes, money. Without one, you and your team will struggle through the process and waste both time and money.

2. Utilizing comments in your program allows the reader to understand what is happening in the code.

3. - Easy to read
   - Short, but descriptive
   - Consistent

4. Int - score
       - lives
       - number of enemies
       - choice selection
   Char - 
   Double - health
          - timer
   Bool - program switch (on/off)
        - is the player alive
        - button presses

5. It's value will never change and programming makes it easier to understand (like point values)
*/
#include <iostream>
#include <string>

int main()
{
	//Projects

	// 1. Game Menu
	std::cout << "\tGame Menu" << std::endl;
	std::cout << "1. One player" << std::endl;
	std::cout << "2. Two players" << std::endl;
	std::cout << "3. Quit" << std::endl;

	int choice;
	std::cout << "\nEnter Choice: ";
	std::cin >> choice;

	if (choice == 1) {
		std::cout << "You chose one player" << std::endl;
	}
	else if (choice == 2) {
		std::cout << "You chose two players" << std::endl;
	}
	else if (choice == 3) {
		std::cout << "You exited the menu" << std::endl;
	}
	else {
		std::cout << "Invalid Choice" << std::endl;
	}
	std::cout << "======================================" << std::endl;
	

	// 2. Bonus Points
	const int CIVILIAN = 100;
	const int ENEMY = 50;

	int num1;
	int num2;
	std::cout << "Enter first number: ";
	std::cin >> num1;
	std::cout << "Enter second number: ";
	std::cin >> num2;

	std::cout << "\nYou've saved " << num1 << " civilians and destroyed " << num2 << " aliens.\n";
	std::cout << "Bonus points: " << (num1 * CIVILIAN) + (num2 * ENEMY) << std::endl;
	std::cout << "======================================" << std::endl;

	// 3. Average
	float score1;
	float score2;
	float score3;
	std::cout << "Enter first score: ";
	std::cin >> score1;
	std::cout << "Enter second score: ";
	std::cin >> score2;
	std::cout << "Enter third score: ";
	std::cin >> score3;

	double average = (score1 + score2 + score3) / 3.0;
	std::cout << "\nAverage score: " << average << std::endl;
	std::cout << "======================================" << std::endl;

	// 4. Dealing cards
	const int DECK = 52;
	int players;
	std::cout << "How many players are present? ";
	std::cin >> players;

	int dealt = DECK / players;
	int cardsLeft = DECK % players;
	std::cout << "\nCards dealt per person: " << dealt << std::endl;
	std::cout << "Cards leftover: " << cardsLeft << std::endl;
	std::cout << "======================================" << std::endl;

	// 5. Personalized story
	std::string lastName;
	int spells;
	int hours;
	std::string summon;

	std::cout << "\tWelcome to The Test\n" << std::endl;
	std::cout << "Please enter the following for a personalized story.\n\n";

	std::cout << "Enter your last name: ";
	std::cin >> lastName;
	std::cout << "Enter a positive number: ";
	std::cin >> spells;
	std::cout << "Enter another positive number: ";
	std::cin >> hours;
	std::cout << "Enter a noun: ";
	std::cin >> summon;
	std::cout << std::endl;

	int hoursSpent = hours * spells;
	std::cout << "Apprentice Wizard " << lastName << " hesitantly approached The Temple for the final test." << std::endl;
	std::cout << "The Apprentice had studied " << spells << " spells for " << hours << " hours each, toiling for a total of " << hoursSpent << " hours." << std::endl;
	std::cout << lastName << " only hoped that The Masters would ask for The Apprentice's favorite incarnation, The Summoning of the " << summon << "..." << std::endl;
	std::cout << "======================================" << std::endl;
	
	return 0;
}