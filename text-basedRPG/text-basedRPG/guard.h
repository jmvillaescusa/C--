#ifndef GUARD
#define GUARD

#include "baseStats.h"

class Guard : public BaseStats {
public:
	Guard();
	~Guard();
	
	//Fighting Commands
	void Attack();
	void Defend();

private:
	std::string potion = "potion";
	std::string key = "key";

public:
	//Getters
	std::string getPotion() { return potion; }
	std::string getKey() { return key; }
};
#endif // !GUARD
