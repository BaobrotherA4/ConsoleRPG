#pragma once
#include"C110152325_include.h"
#include"C110152325_Item.h"

class C110152325_Weapon :
	public C110152325_Item
{
private:
	int damageMin;
	int damageMax;

public:
	C110152325_Weapon();
	C110152325_Weapon(int level, int rarity);
	C110152325_Weapon(int damageMin, int damageMax ,
		string name , int level , int buyValue ,
		int sellValue , int rarity );
	virtual ~C110152325_Weapon();


	virtual C110152325_Weapon* clone()const;


	string toString() const;

	inline int getDamageMin()const { return this->damageMin; }
	inline int getDamageMax()const { return this->damageMax; }


	static C110152325_dArr<string> names;
	static void initNames();

};

