#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	// if/else statements
	/*int health = 100;

	if (health > 100) {
		std::cout << "if" << std::endl;
	}
	else {
		std::cout << "else" << std::endl;
	}*/

	// switch case
	/*switch (health) {
		case 10:
			std::cout << "case 10" << std::endl;
			break;

		case 50:
			std::cout << "case 50" << std::endl;
			break;

		case 100:
			std::cout << "case 100" << std::endl;
			break;

		default:
			std::cout << "default" << std::endl;
	}*/

	// while/do while loops
	/*int i = 0;
	while (i < 100) {
		std::cout << i << std::endl;	
		i++;
	}
	do {
		std::cout << i << std::endl;
		i++;
	} while (i < 100);*/

	// random number generator
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber = rand() % 100 + 1; //Generate a range from 1 - 100
	std::cout << randomNumber << std::endl;

    return 0; 
}