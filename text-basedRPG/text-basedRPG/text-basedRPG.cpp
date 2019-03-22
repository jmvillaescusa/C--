#include "player.h"
#include <fstream>


int main()
{
	std::ifstream src("premise.txt");
	std::string name;
	while (!src.eof()) {
		std::getline(src, name); 
		if (src.eof()) {
			std::cout << name;
		}
		else {
			std::cout << name << std::endl;
		}
		
	}
	src.close();
	std::cin >> name;

	Player player;
	player.setName(name);
	player.ClearScreen();

	do {
		player.getCommand();
	} while (player.isRunning);

	return 0;
}