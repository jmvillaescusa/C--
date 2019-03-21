#include "map.h"

void Map::Display() {
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
		return PLAYER;
	case 4:
		return DOOR;
	case 5:
		return ARMOR;
	case 6:
		return SWORD;
	}
}