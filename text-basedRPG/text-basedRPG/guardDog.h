#ifndef GUARDDOG
#define GUARDDOG

#include "enemy.h"

class GuardDog : public Enemy {
public:
	GuardDog();
	~GuardDog();

	//Fighting Commands
	void Attack();
	void Defend();
};
#endif // !GUARDDOG