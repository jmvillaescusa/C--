#include "player.h"
#include "guard.h"
#include "guardDog.h"
#include "map.h"

Map m;

Player::Player() {
	name = "";
	vitality = 25;
	health = 25;
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
void Player::Attack() {
	std::cout << name << " attacks!\n";
	getStrength();
};
void Player::Defend() {
	std::cout << name << " defends!\n";
	vitality += getDefence();
};
void Player::UsePotion() {
	bool isThereAny = false;
	for (int i = 0; i < 3; i++) {
		p_Item = &inventory[i];
		if (*p_Item == "potion") {
			isThereAny = true;
			if (health == vitality) {
				ClearScreen();
				std::cout << name << "'s health is already max.\n";
			}
			else {
				health = vitality;
				ClearScreen();
				std::cout << name << " uses the " << *p_Item << ". Health regenerated.\n";
				*p_Item = "";
			}
		}
	}
	if (!isThereAny) {
		ClearScreen();
		std::cout << "Out of potions.\n";
	}
};
void Player::Flee() {};
/*void Player::FightGuard(Guard &g) {
	while (getAlive() && g.getAlive()) {
		ClearScreen();
		std::cout << name << " encountered a Guard!\n";
		std::cout << "HP: " << vitality << "          HP: " << g.getVitality() << std::endl;
		if (getVitality() <= 0) {
			setAlive(false);
		}
		else if (g.getVitality() <= 0) {
			g.setAlive(false);
		}
		else {
			getFightCommand();
			srand(static_cast<unsigned int>(time(0)));
			int command = (rand() % 2) + 1;
			if (command == 1) {
				g.Attack(vitality);
			}
			else if (command == 2) {
				g.Defend(strength);
			}
		}
	}
	if (!isAlive) {
		ClearScreen();
		std::cout << name << " is slain in battle!\n";
		std::cout << "GAME OVER!\n";
		isRunning = false;
	}
	else if (!g.getAlive()) {
		ClearScreen();
		std::cout << name << " defeated the Guard!\n";
	}
};*/

//Movement
void Player::MoveUp() { 
	p_Pos = &posY;
	if (m.world[*p_Pos - 1][posX] == 1) {
		*p_Pos -= 0;
		ClearScreen();

		std::cout << "There is an impenetrable wall in the way.\n";
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
		RandomChance();
	}
};
void Player::MoveLeft() { 
	p_Pos = &posX;
	if (m.world[posY][*p_Pos - 1] == 1) {
		*p_Pos -= 0;
		ClearScreen();

		std::cout << "There is an impenetrable wall in the way.\n";
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
		RandomChance();
	}
};
void Player::MoveDown() { 
	p_Pos = &posY;
	if (m.world[*p_Pos + 1][posX] == 1) {
		*p_Pos += 0;
		ClearScreen();
		std::cout << "There is an impenetrable wall in the way.\n";
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
		RandomChance();
	}
};
void Player::MoveRight() { 
	p_Pos = &posX;
	if (m.world[posY][*p_Pos + 1] == 1) {
		*p_Pos += 0;
		ClearScreen();
		std::cout << "There is an impenetrable wall in the way.\n";
	}
	else if (m.world[posY][*p_Pos + 1] == 4) {
		*p_Pos += 0;
		ClearScreen();
		std::cout << "The door is locked.";
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
		RandomChance();
	}
};
void Player::RandomChance() {
	srand(static_cast<unsigned int>(time(0)));
	int randChance = (rand() % luck) + 1;

	if (randChance % 5 == 0) {
		srand(static_cast<unsigned int>(time(0)));
		int enemy = (rand() % 2) + 1;

		if (enemy == 1) {
			std::cout << name << " hears some guards talking at a distance.\n";
		}
		else if (enemy == 2) {
			std::cout << name << " see a guard dog sleeping soundly, and try to walk pass by it.\n";
		}
	}
	else {
		std::cout << name << " traverses through the keep.\n";
	}
}

//Inventory Management
void Player::PickUp() { 
	//Picks up a sword
	if (itemCount == MAX_ITEMS) {
		std::cout << "The inventory is full!\n";
	}
	else {
		if (m.world[posY + 1][posX] == 6 || m.world[posY][posX + 1] == 6 || m.world[posY - 1][posX] == 6 || m.world[posY][posX - 1] == 6 || posX == swordPosX && posY == swordPosY) {
			if (posX == swordPosX && posY == swordPosY) {
				m.world[posY][posX] = 2;
			}
			else if (m.world[posY - 1][posX] == m.world[swordPosY][swordPosX]) {
				m.world[posY - 1][posX] = 2;
			}
			else if (m.world[posY][posX + 1] == m.world[swordPosY][swordPosX]) {
				m.world[posY][posX + 1] = 2;
			}
			else if (m.world[posY][posX - 1] == m.world[swordPosY][swordPosX]) {
				m.world[posY][posX - 1] = 2;
			}
			else if (m.world[posY + 1][posX] == m.world[swordPosY][swordPosX]) {
				m.world[posY + 1][posX] = 2;
			}
			swordPosX = -1;
			swordPosY = -1;
			inventory[0] += getSword();
			++itemCount;
			ClearScreen();
			std::cout << name << " has picked up a sword. " << name << "'s strength has increased.\n";
		}
		//Picks up armor
		else if (m.world[posY + 1][posX] == 5 || m.world[posY][posX + 1] == 5 || m.world[posY - 1][posX] == 5 || m.world[posY][posX - 1] == 5 || posX == armorPosX && posY == armorPosY) {
			if (m.world[posY][posX] == m.world[armorPosY][armorPosX]) {
				m.world[posY][posX] = 2;
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
			else if (m.world[posY + 1][posX] == 5) {
				m.world[posY + 1][posX] = 2;
			}
			armorPosX = -1;
			armorPosY = -1;
			inventory[1] = getArmor();
			++itemCount;
			ClearScreen();
			std::cout << name << " has picked up some armor. " << name << "'s defence has increased.\n";
		}
		else {
			ClearScreen();
			std::cout << "There is nothing to pick up.\n";
		}
		StatBonus();
	}
};
void Player::ViewInventory() {
	ClearScreen();
	std::cout << "Index  Item\n";
	std::cout << "==================\n";
	for (int i = 0; i < MAX_ITEMS; i++) {
		std::cout << i << "      " << inventory[i] << std::endl;
	}
};
void Player::RemoveItem() { 
	ClearScreen();
	if (itemCount == 0) {
		std::cout << "There is nothing to remove.\n";
	}
	else {
		ViewInventory();
		std::cout << "Which item to remove? (enter the index number) ";

		char itemIndex;
		std::cin >> itemIndex;

		if (isalpha(itemIndex)) {
			ClearScreen();
			std::cout << "Please enter the index number.\n";
		}
		else if (isdigit(itemIndex)) {
			int index = itemIndex - '0';
			
			p_Item = &inventory[index];
			if (*p_Item == "sword") {
				ClearScreen();
				if (posX == armorPosX && posY == armorPosY) {
					std::cout << "There seems to be something on the floor already\n";
				}
				else {
					std::cout << "Dropped the " << *p_Item << ". " << name << "'s strength decreased.\n";
					setStrength(10);
					swordPosX = posX;
					swordPosY = posY;
					*p_Item = "";
					--itemCount;
				}
			}
			else if (*p_Item == "armor") {
				if (posX == swordPosX && posY == swordPosY) {
					ClearScreen();
					std::cout << "There seems to be something on the floor already\n";
				}
				else {
					--itemCount;
					ClearScreen();
					std::cout << "Removed the " << *p_Item << ". " << name << "'s defence decreased.\n";
					setDefence(5);
					armorPosX = posX;
					armorPosY = posY;
					*p_Item = "";
				}
			}
			else if (index >= 0 && index <= 3) {
				ClearScreen();
				if (*p_Item == "") {
					std::cout << "There is nothing in that spot.\n";
				}
				else {
					--itemCount;
					std::cout << "Removed " << *p_Item << ". ";
					*p_Item = "";
				}
			}
			else {
				ClearScreen();
				std::cout << "Invalid input\n";
			}
		StatBonus();
		if (health >= vitality) {
			health = vitality;
		}
		}
	}
};

//Stat Functions
void Player::CheckStats() {
	ClearScreen();
	std::cout << "Name | " << name << std::endl;
	std::cout << "VIT  | " << health << " / " << vitality << std::endl;
	std::cout << "STR  | " << strength << std::endl;
	std::cout << "DEF  | " << defence << std::endl;
	std::cout << "SPE  | " << speed << std::endl;
	std::cout << "LUK  | " << luck << std::endl;
};
int Player::StatBonus() {
	for (int i = 0; i < 3; i++) {
		if (inventory[i] == "sword") {
			for (int j = 0; j < 3; j++) {
				if (inventory[j] == "armor") {
					setVitality(40);
					setLuck(15);
					return vitality, luck;
				}
			}
		}
		else if (inventory[i] == "armor") {
			for (int j = 0; j < 3; j++) {
				if (inventory[j] == "sword") {
					setVitality(40);
					setLuck(15);
					return vitality, luck;
				}
			}
		}
		else {
			setVitality(25);
			setLuck(5);
			return vitality, luck;
		}
	}
};

//View Commands
void Player::Help() {
	ClearScreen();
	std::cout << "List of Commands\n=====================\n";
	std::cout << "'w' - move up\n";
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
	else if (c == 'h') { Help(); }
	else if (c == 'q') { 
		isRunning = false; 
		std::cout << std::endl << "Thanks for playng!\n";
	}
	else { ClearScreen(); std::cout << "Invalid Input\n"; }
};
/*void Player::getFightCommand() {
	viewFightCommand();
	int i;
	std::cout << "\n What should " << name << " do? ";
	std::cin >> i;

	     if (i == 1) { Attack(); }
	else if (i == 2) { Defend(); }
	else if (i == 3) { UsePotion(); }
	else if (i == 4) { Flee(); }
}
void Player::viewFightCommand() {
	std::cout << "1. Attack      2. Defend\n";
	std::cout << "3. Use Potion  4. Flee\n\n";
}*/

void Player::ClearScreen() {
	system("CLS");
	m.Display();
	std::cout << std::endl;
};