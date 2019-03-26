#ifndef PLAYER
#define PLAYER

#include "baseStats.h"
#include <string>


class Player : public BaseStats {
public:
	bool isRunning = true;
	Player();
	~Player();

	//Fighting Commands
	void Attack();
	void Defend();
	void UsePotion();
	void Flee();

	//Map Commands
	void MoveUp();
	void MoveLeft();
	void MoveDown();
	void MoveRight();
	void CheckStats();
	void PickUp();
	void ViewInventory();
	void RemoveItem();
	void Help();
	void getCommand();

	int VitalityBonus();

	void ClearScreen();

private:
	std::string name;
	int posX;
	int posY;
	int luck;

	int swordPosX;
	int swordPosY;
	int armorPosX;
	int armorPosY;

	const int MAX_ITEMS = 4;

public:
	//Getter
	int getLuck() { return luck; }
	std::string getName() { return name; }

	//Setter
	void setLuck(int l) { luck = l; }
	void setName(std::string n) { name = n; }

	std::string inventory[4];
};
#endif // !PLAYER

