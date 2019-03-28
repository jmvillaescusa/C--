#include "guard.h"

Guard::Guard() {
	vitality = 20;
	strength = 7;
	defence = 3;
	speed = 15;
} Guard::~Guard() {};

void Guard::Attack(int&vit) {
	std::cout << "The Guard attacks!\n";
	vit -= getStrength();
};
void Guard::Defend(int&str) {
	std::cout << "The Guard raises the shield!\n";
	vitality = vitality + defence - str;
};

void Guard::ShowStats() {
	std::cout << "VIT | " << vitality << std::endl;
	std::cout << "STR | " << strength << std::endl;
	std::cout << "DEF | " << defence << std::endl;
	std::cout << "SPE | " << speed << std::endl;
};