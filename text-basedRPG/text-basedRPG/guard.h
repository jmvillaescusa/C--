#ifndef GUARD
#define GUARD

#include "enemy.h"

class Guard : public Enemy {
public:
	Guard();
	~Guard();
	
	//Fighting Commands
	void Attack();
	void Defend();

	void ShowStats();
	void BonusOn();
	void BonusOff();

protected:
	std::string potion = "potion";
	std::string key = "key";

public:
	//Getters
	std::string getPotion() { return potion; }
	std::string getKey() { return key; }
};
#endif // !GUARD
