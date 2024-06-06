#pragma once
#include"C110152325_include.h"

class C110152325_Enemy
{
private:
	int level;
	int hp;
	int hpMax;
	int damageMin;
	int damageMax;
	float dropChance;
	int defence;
	int accuracy;


public:
	C110152325_Enemy(int level = 0);
	virtual ~C110152325_Enemy();

	inline bool isAlive() { return this->hp > 0; }
	string getAsString()const;
	void takeDamage(int damage);

	inline int getLevel()const { return this->level; }
	inline int getDamage()const { return rand() % (this->damageMax - this->damageMin + 1) + this->damageMin; }
	inline int getExp()const { return this->level * 100; }
	inline int getHp()const { return this->hp; }
	inline int getDamageMin()const { return this->damageMin; }
	inline int getDamageMax()const { return this->damageMax; }
	inline int getHpMax()const { return this->hpMax; }
	inline int getDefence()const { return this->defence; }
	inline int getAccuracy()const { return this->accuracy; }

};

