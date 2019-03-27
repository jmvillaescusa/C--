#ifndef PLAYER
#define PLAYER

#include "baseStats.h"

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
	void FightGuard();

	void getFightCommand();
	void viewFightCommand();

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

	void RandomChance();

	int StatBonus();

	void ClearScreen();

private:
	std::string name;
	int posX;
	int posY;
	int luck;

	int swordPosX;
	int swordPosY;
	std::string sword = "sword";

	int armorPosX;
	int armorPosY;
	std::string armor = "armor";

	int itemCount = 0;
	const int MAX_ITEMS = 4;

	int *p_Pos = 0;
	std::string *p_Item = 0;

public:
	//Getter
	int getLuck() { return luck; }
	std::string getName() { return name; }

	std::string getSword() { setStrength(20); return sword; }
	std::string getArmor() { setDefence(7); return armor;  }

	//Setter
	void setLuck(int l) { luck = l; }
	void setName(std::string n) { name = n; }

	std::string inventory[4];
};
#endif // !PLAYER

