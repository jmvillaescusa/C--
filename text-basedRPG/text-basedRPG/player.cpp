#include "player.h"
#include "guard.h"
#include "guardDog.h"
#include "map.h"

Map m;
Guard guard;
GuardDog guardDog;

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
void Player::FightGuard() {
	while (isAlive && guard.isAlive) {
		if (vitality <= 0) {
			isAlive = false;
		}
		else {
			getFightCommand();
			std::cout << name << ": " << vitality << "        Guard: " << guard.getVitality() << std::endl;
			srand(static_cast<unsigned int>(time(0)));
			int command = (rand() % 2) + 1;
			if (command == 1) {
				guard.Attack();
				vitality -= guard.getStrength();
			}
			else if (command == 2) {
				guard.Defend();
			}
		}
	}
	if (!isAlive) {
		
	}
}

//Movement
void Player::MoveUp() { 
	p_Pos = &posY;
	if (m.world[*p_Pos - 1][posX] == 1) {
		*p_Pos -= 0;
		ClearScreen();

		std::cout << "There is an impenetrable wall in the way.";
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

		std::cout << "There is an impenetrable wall in the way.";
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
		std::cout << "There is an impenetrable wall in the way.";
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
		std::cout << "There is an impenetrable wall in the way.";
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
			std::cout << name << " encountered a Guard!\n";
			FightGuard();
		}
		else if (enemy == 2) {
			std::cout << name << " encountered a Guard Dog!\n";
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
		std::cout << "The inventory is full!";
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
			ClearScreen();
			std::cout << name << " has picked up a sword. " << name << "'s strength has increased.";
			++itemCount;
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
			ClearScreen();
			std::cout << name << " has picked up some armor. " << name << "'s defence has increased.";
			++itemCount;
		}
		else {
			ClearScreen();
			std::cout << "There is nothing to pick up.";
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
		std::cout << "There is nothing to remove.";
	}
	else {
		ViewInventory();
		int itemIndex;
		std::cout << "Which item to remove? (enter the index number) ";
		std::cin >> itemIndex;
		ClearScreen();
		p_Item = &inventory[itemIndex];

		if (isalpha(itemIndex)) {
			std::cout << "Please enter the index number.";
		}
		else if (*p_Item == "sword") {
			if (posX == armorPosX && posY == armorPosY) {
				std::cout << "There seems to be something on the floor already";
			}
			else {
				std::cout << "Removed " << *p_Item << ". " << name << "'s strength decreased.";
				setStrength(10);
				swordPosX = posX;
				swordPosY = posY;
				*p_Item = "";
				--itemCount;
			}
		}
		else if (*p_Item == "armor") {
			if (posX == swordPosX && posY == swordPosY) {
				std::cout << "There seems to be something on the floor already";
			}
			else {
				std::cout << "Removed " << *p_Item << ". " << name << "'s defence decreased.";
				setDefence(5);
				armorPosX = posX;
				armorPosY = posY;
				*p_Item = "";
				--itemCount;
 			}
		}
		else if (itemIndex >= 0 && itemIndex <= 3)  {
			std::cout << "Removed " << *p_Item << ". ";
			*p_Item = "";
			--itemCount;
		}
		else {
			std::cout << "Invalid Input.";
		}
		StatBonus();
	}
};
int Player::StatBonus() {
	for (int i = 0; i <= 4; i++) {
		if (inventory[i] == "sword") {
			for (int j = 0; j < 4; j++) {
				if (inventory[j] == "armor") {
					guard.BonusOn();
					setVitality(40);
					setLuck(15);
					return getVitality(), getLuck();
				}
			}
		}
		else if (inventory[i] == "armor"){
			for (int j = 0; j < inventory->size(); j++) {
				if (inventory[j] == "sword") {
					guard.BonusOn();
					setVitality(40);
					setLuck(15);
					return getVitality(), getLuck();
				}
			}
		}
		else {
			guard.BonusOff();
			setVitality(25);
			setLuck(5);
			return getVitality(), getLuck();
		}
	}
};
void Player::CheckStats() {
	ClearScreen();
	std::cout << "Name     | " << name << std::endl;
	std::cout << "Vitality | " << vitality << std::endl;
	std::cout << "Strength | " << strength << std::endl;
	std::cout << "Defence  | " << defence << std::endl;
	std::cout << "Speed    | " << speed << std::endl;
	std::cout << "Luck     | " << luck << std::endl;
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
	else if (c == 'h') { Help();  }
	else if (c == 'j') { }
	else if (c == 'q') { 
		isRunning = false; 
		std::cout << std::endl << "Thanks for playng!\n";
	}
	else { std::cout << "Invalid Input "; }
};
void Player::getFightCommand() {
	ClearScreen();
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
}

void Player::ClearScreen() {
	system("CLS");
	m.Display();
	std::cout << std::endl;
};