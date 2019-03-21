#ifndef PLAYER
#define PLAYER

#include "baseStats.h"
#include <string>

class Player : public BaseStats {
public:
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
	void PickUp();
	void ViewInventory();
	void Usepotion(char temp);
	void RemoveItem();
	void Help();

private:
	int luck;
	std::string name;

public:
	//Getter
	int getLuck() { return luck; }
	std::string getName() { return name; }

	//Setter
	void setLuck(int l) { luck = l; }
	void setName(std::string n) { name = n; }

	std::string inventory[4] = {};
};
#endif // !PLAYER

