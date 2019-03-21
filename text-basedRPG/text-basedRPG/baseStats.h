#ifndef BASESTATS
#define BASESTATS

#include <iostream>

class BaseStats {
protected:
	int vitality;
	int strength;
	int defence;
	int speed;

public:
	//Getters
	int getVitality() { return vitality; }
	int getStrength() { return strength; }
	int getDefence() { return defence; }
	int getSpeed() { return speed; }

	//Setters
	void setVitality(int v) { vitality = v; }
	void setStength(int st) { strength = st; }
	void setDefence(int d) { defence = d; }
	void setSpeed(int sp) { speed = sp; }

	virtual void Attack() {};
	virtual void Defend() {};
};
#endif // !BASESTATS
