#ifndef GUARDDOG
#define GUARDDOG

#include "baseStats.h"

class GuardDog : public BaseStats {
public:
	GuardDog();
	~GuardDog();

	//Fighting Commands
	void Attack();
	void Defend();
};
#endif // !GUARDDOG