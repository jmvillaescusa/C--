#ifndef BASESTATS
#define BASESTATS

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class BaseStats {
protected:
	int vitality;
	int strength;
	int defence;
	int speed;
	bool isAlive = true;

public:
	//Getters
	int getVitality() { return vitality; }
	int getStrength() { return strength; }
	int getDefence() { return defence; }
	int getSpeed() { return speed; }
	bool getAlive() { return isAlive; }

	//Setters
	void setVitality(int v) { vitality = v; }
	void setStrength(int st) { strength = st; }
	void setDefence(int d) { defence = d; }
	void setSpeed(int sp) { speed = sp; }
	void setAlive(bool a) { isAlive = a; }

	virtual void Attack() {};
	virtual void Defend() {};

	
};
#endif // !BASESTATS
