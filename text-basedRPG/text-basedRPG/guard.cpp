#include "guard.h"

Guard::Guard() {
	vitality = 20;
	strength = 7;
	defence = 3;
	speed = 15;
} Guard::~Guard() {};

void Guard::Attack() {
	std::cout << "The Guard attacks!\n";
};
void Guard::Defend() {
	std::cout << "The Guard raises the shield!\n";
	vitality += defence;
};

void Guard::ShowStats() {
	std::cout << "VIT | " << vitality << std::endl;
	std::cout << "STR | " << strength << std::endl;
	std::cout << "DEF | " << defence << std::endl;
	std::cout << "SPE | " << speed << std::endl;
};

void Guard::BonusOn() {
	setVitality(35);
	setStrength(12);
	setDefence(5);
};
void Guard::BonusOff() {
	setVitality(20);
	setStrength(7);
	setDefence(3);
}