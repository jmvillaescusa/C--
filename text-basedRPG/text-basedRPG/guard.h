#ifndef GUARD
#define GUARD

#include "enemy.h"

class Guard : public Enemy {
public:
	Guard();
	~Guard();
	
	//Fighting Commands
	void Attack(int&vit);
	void Defend(int&str);

	void ShowStats();

protected:
	std::string potion = "potion";
	std::string key = "key";

public:
	//Getters
	std::string getPotion() { return potion; }
	std::string getKey() { return key; }
};
#endif // !GUARD
