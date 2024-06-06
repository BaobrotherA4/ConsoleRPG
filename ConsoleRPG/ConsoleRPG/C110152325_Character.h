#pragma once

#include"C110152325_include.h"
#include"C110152325_Inventory.h"
#include"C110152325_Enemy.h"
#include"C110152325_Puzzle.h"

using namespace std;

class C110152325_Character
{
public:
	C110152325_Character();
	C110152325_Character(string name, int distanceTravelled,
		int gold, int level,
		int exp, int strength, int vitality,
		int dexterity, int intelligence,
		int hp, int stamina, int statPoints, int x, int y);
	virtual ~C110152325_Character();

	//Fuctions
	void initialize(const string name);
	void printStats() const;
	void map(int stat);
	void movecity(int stat);
	void arrive();
	void levelUp();
	string getAsString() const;
	string getInvAsString();
	void updateStats();
	void addToStat(int stat, int value);
	void equipItem(unsigned index);
	inline void restHp() { this->hp = this->hpMax; }
	void addItem(const C110152325_Item& item) { this->inventory.addItem(item); }

	//Accessors
	inline const int& getDistTravel() const { return this->distanceTravelled; }
	inline const string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getExp() const { return this->exp; }
	inline const int& getExpNext() const { return this->expNext; }
	inline const int& getHp() const { return this->hp; }
	inline const int& getHpMax() const { return this->hpMax; }
	inline const bool& isAlive() { return this->hp > 0; }
	inline const int& getStamina() const { return this->stamina; }
	inline const int& getDamageMin() const { return this->damageMin; }
	inline const int& getDamageMax() const { return this->damageMax; }
	inline const int& getDamage() const { return rand() % (this->damageMax - this->damageMin + 1) + this->damageMin; }
	inline const int& getDefence() const { return this->defence; }
	inline const int& getAccuracy() const { return this->accuracy; }
	inline const int& getstatpoint() const { return this->statPoints; }
	inline const int& getGold() const { return this->gold; }
	inline const int& getX() const { return this->x; }
	inline const int& getY() const { return this->y; }
	//Modifier
	inline void setDisTravelled(const int& distance) { this->distanceTravelled = distance; }
	inline void travel() { this->distanceTravelled++; }
	inline void gainExp(const int exp) { this->exp += exp; }
	inline void gainGold(const int gold) { this->gold += gold; }
	inline void payGold(const int gold) { this->gold -= gold; }
	void takeDamage(const int damage);


private:
	int distanceTravelled;

	C110152325_Inventory inventory;
	C110152325_Weapon weapon;
	C110152325_Armor Armor_head;
	C110152325_Armor Armor_chest;
	C110152325_Armor Armor_legs;
	C110152325_Armor Armor_shoes;
	int gold;

	string name;
	int level;
	int exp;
	int expNext;

	int strength;
	int vitality;
	int dexterity;
	int intelligence;

	int hp;
	int hpMax;
	int stamina;
	int staminaMax;
	int damageMin;
	int damageMax;
	int defence;
	int accuracy;
	int luck;

	int statPoints;
	int x;
	int y;
};

