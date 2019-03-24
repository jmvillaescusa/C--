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
		m.world[*p_Pos][posX] = 2;
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
		m.world[posY][*p_Pos] = 2;
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
	else if (m.world[*p_Pos + 1][posX] == 5 || m.world[*p_Pos + 1][posX] == 6) {
		*p_Pos += 0;
		ClearScreen();
		std::cout << std::endl << "There is something blocking the way.";
	}
	else {
		m.world[*p_Pos][posX] = 2;
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
	else if (m.world[posY][*p_Pos + 1] == 5 || m.world[posY][*p_Pos + 1] == 6) {
		*p_Pos += 0;
		ClearScreen();
		std::cout << std::endl << "There is something blocking the way.";
	}
	else if (m.world[posY][*p_Pos + 1] == 4) {
		*p_Pos += 0;
		ClearScreen();
		std::cout << std::endl << name << " tries to open the door. The door is locked and doesn't open.";
	}
	else {
		m.world[posY][*p_Pos] = 2;
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

//Inventory Maanagement
int *p_Item = 0;
void Player::PickUp() { 
	if (m.world[posY + 1][posX] == 6 || m.world[posY][posX + 1] == 6) {
	}
};
void Player::ViewInventory() { };
void Player::RemoveItem() { };

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
	std::cout << "\nWhat do you like to do? ";
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