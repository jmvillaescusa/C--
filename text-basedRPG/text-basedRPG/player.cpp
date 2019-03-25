#include "player.h"
#include "map.h"

Player::Player() {
	name = "";
	vitality = 25;
	strength = 10;
	defence = 5;
	speed = 30;
	luck = 5;
	posX = 3;
	posY = 2;

	swordPosX = 6;
	swordPosY = 14;
	armorPosX = 43;
	armorPosY = 13;
} Player::~Player() {};

//Fighting Commands
void Player::Attack() {}
void Player::Defend() {}
void Player::UsePotion() {}
void Player::Flee() {}

//Movement
int *p_Pos = 0;
Map m;
void Player::MoveUp() { 
	p_Pos = &posY;
	if (m.world[*p_Pos - 1][posX] == 1) {
		*p_Pos -= 0;
		ClearScreen();

		std::cout << std::endl << "There is an impenetrable wall in the way.";
	}
	else {
		if (m.world[*p_Pos][posX] == m.world[swordPosY][swordPosX]) {
			m.world[*p_Pos][posX] = 6;
		}
		else if (m.world[*p_Pos][posX] == m.world[armorPosY][armorPosX]) {
			m.world[*p_Pos][posX] = 5;
		}
		else {
			m.world[*p_Pos][posX] = 2;
		}
		*p_Pos -= 1;
		m.world[*p_Pos][posX] = 3;
		ClearScreen();

		std::cout << std::endl << name << " traverses through the keep.";
	}
};
void Player::MoveLeft() { 
	p_Pos = &posX;
	if (m.world[posY][*p_Pos - 1] == 1) {
		*p_Pos -= 0;
		ClearScreen();

		std::cout << std::endl << "There is an impenetrable wall in the way.";
	}
	else {
		if (m.world[posY][*p_Pos] == m.world[swordPosY][swordPosX]) {
			m.world[posY][*p_Pos] = 6;
		}
		else if (m.world[posY][*p_Pos] == m.world[armorPosY][armorPosX]) {
			m.world[posY][*p_Pos] = 5;
		}
		else {
			m.world[posY][*p_Pos] = 2;
		}
		*p_Pos -= 1;
		m.world[posY][*p_Pos] = 3;
		ClearScreen();

		std::cout << std::endl << name << " traverses through the keep.";
	}
};
void Player::MoveDown() { 
	p_Pos = &posY;
	if (m.world[*p_Pos + 1][posX] == 1) {
		*p_Pos += 0;
		ClearScreen();
		std::cout << std::endl << "There is an impenetrable wall in the way.";
	}
	else {
		if (m.world[*p_Pos][posX] == m.world[swordPosY][swordPosX]) {
			m.world[*p_Pos][posX] = 6;
		}
		else if (m.world[*p_Pos][posX] == m.world[armorPosY][armorPosX]) {
			m.world[*p_Pos][posX] = 5;
		}
		else {
			m.world[*p_Pos][posX] = 2;
		}
		*p_Pos += 1;
		m.world[*p_Pos][posX] = 3;
		ClearScreen();

		std::cout << std::endl << name << " traverses through the keep.";
	}
};
void Player::MoveRight() { 
	p_Pos = &posX;
	if (m.world[posY][*p_Pos + 1] == 1) {
		*p_Pos += 0;
		ClearScreen();
		std::cout << std::endl << "There is an impenetrable wall in the way.";
	}
	else if (m.world[posY][*p_Pos + 1] == 4) {
		*p_Pos += 0;
		ClearScreen();
		std::cout << std::endl << "The door is locked.";
	}
	else {
		if (m.world[posY][*p_Pos] == m.world[swordPosY][swordPosX]) {
			m.world[posY][*p_Pos] = 6;
		}
		else if (m.world[posY][*p_Pos] == m.world[armorPosY][armorPosX]) {
			m.world[posY][*p_Pos] = 5;
		}
		else {
			m.world[posY][*p_Pos] = 2;
		}
		*p_Pos += 1;
		m.world[posY][*p_Pos] = 3;
		ClearScreen();
		std::cout << std::endl << name << " traverses through the keep.";
	}
};

void Player::CheckStats() {
	ClearScreen();
	std::cout << "\nName     | " << name << std::endl;
	std::cout << "Vitality | " << vitality << std::endl;
	std::cout << "Strength | " << strength << std::endl;
	std::cout << "Defence  | " << defence << std::endl;
	std::cout << "Speed    | " << speed << std::endl;
	std::cout << "Luck     | " << luck << std::endl;
}

//Inventory Management
std::string *p_Item = 0;
int numItems = 0;
void Player::PickUp() { 
	//Picks up a sword
	if (m.world[posY + 1][posX] == 6 || m.world[posY][posX + 1] == 6) {
		if (m.world[posY + 1][posX] == 6) {
			m.world[posY + 1][posX] = 2;
		}
		else if (m.world[posY - 1][posX] == 6) {
			m.world[posY - 1][posX] = 2;
		}
		else if (m.world[posY][posX + 1] == 6) {
			m.world[posY][posX + 1] = 2;
		}
		else if (m.world[posY][posX - 1] == 6) {
			m.world[posY][posX - 1] = 2;
		}
		else if (m.world[posY][posX] == m.world[swordPosY][swordPosX]) {
			m.world[posY][posX - 1] = 2;
		}
		swordPosX = -1;
		swordPosY = -1;
		inventory[numItems++] = "sword";
		ClearScreen();
		std::cout << std::endl << name << " has picked up a sword. " << name << "'s strength has increased.";
		setStrength(20);
	}
	//Picks up armor
	else if (m.world[posY + 1][posX] == 5 || m.world[posY][posX + 1] == 5) { 
		if (m.world[posY + 1][posX] == 5) {
			m.world[posY + 1][posX] = 2;
		}
		else if (m.world[posY - 1][posX] == 5) {
			m.world[posY - 1][posX] = 2;
		}
		else if (m.world[posY][posX + 1] == 5) {
			m.world[posY][posX + 1] = 2;
		}
		else if (m.world[posY][posX - 1] == 5) {
			m.world[posY][posX - 1] = 2;
		}
		else if (m.world[posY][posX] == m.world[armorPosY][armorPosX]) {
			m.world[posY][posX - 1] = 2;
		}
		armorPosX = -1;
		armorPosY = -1;
		inventory[numItems++] = "armor";
		ClearScreen();
		std::cout << std::endl << name << " has picked up some armor. " << name << "'s defence has increased.";
		setDefence(7);
	}
	else {
		ClearScreen();
		std::cout << "There is nothing to pick up.\n";
	}
};
void Player::ViewInventory() {
	ClearScreen();
	std::cout << "\nIndex  Item\n";
	std::cout << "==================\n";
	for (int i = 0; i < MAX_ITEMS; i++) {
		std::cout << i << "      " << inventory[i] << std::endl;
	}
};
void Player::RemoveItem() { 
	ClearScreen();
	if (inventory[0] == " "){
		std::cout << "\nThere is nothing to remove.";
	}
	else {
		ViewInventory();
		int itemIndex;
		std::cout << "\nWhich item to remove? (enter the index number) ";
		std::cin >> itemIndex;
		ClearScreen();
		p_Item = &inventory[itemIndex];
		std::cout << "\nRemoved " << *p_Item << ". ";
		if (*p_Item == "sword") {
			std::cout << name << "'s strength decreased.";
			setStrength(10);
			swordPosX = posX;
			swordPosY = posY;
		}
		else if (*p_Item == "armor") {
			std::cout << name << "'s defence decreased.";
			setDefence(5);
			armorPosX = posX;
			armorPosY = posY;
		}
		*p_Item = " ";
		numItems -= 1;
	}
};

//View Commands
void Player::Help() {
	ClearScreen();
	std::cout << "\n'w' - move up\n";
	std::cout << "'a' - move left\n";
	std::cout << "'s' - move down\n";
	std::cout << "'d' - move right\n";
	std::cout << "'c' - view stats\n";
	std::cout << "'p' - pick up an item\n";
	std::cout << "'i' - view inventory\n";
	std::cout << "'u' - use a potion\n";
	std::cout << "'r' - remove an item\n";
	std::cout << "'q' - quit game\n";

};
void Player::getCommand() {
	char c;
	std::cout << "\nCommand: ";
	std::cin >> c;

	if (c == 'w') { MoveUp(); }
	else if (c == 'a') { MoveLeft(); }
	else if (c == 's') { MoveDown(); }
	else if (c == 'd') { MoveRight(); }
	else if (c == 'c') { CheckStats(); }
	else if (c == 'p') { PickUp(); }
	else if (c == 'i') { ViewInventory(); }
	else if (c == 'u') { UsePotion(); }
	else if (c == 'r') { RemoveItem(); }
	else if (c == 'h') { Help();  }
	else if (c == 'q') { 
		isRunning = false; 
		std::cout << std::endl << "Thanks for playng!\n";
	}
	else { std::cout << "Invalid Input "; }
}

void Player::ClearScreen() {
	system("CLS");
	m.Display();
}