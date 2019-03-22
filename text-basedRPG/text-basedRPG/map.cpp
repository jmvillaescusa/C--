#include "map.h"

void Map::Display() {
	std::cout << std::endl << "========================================================================\n";
	std::cout << "========================================================================\n";
	char temp;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 45; j++) {
			temp = MapIndex(world[i][j]);
			std::cout << temp;
		}
		std::cout << std::endl;
	}
}
char Map::MapIndex(int temp) {
	switch (temp) {
	case 0:
		return NOTHING;
	case 1:
		return WALL;
	case 2:
		return SPACE;
	case 3:
		return AVATAR;
	case 4:
		return DOOR;
	case 5:
		return ARMOR;
	case 6:
		return SWORD;
	}
}