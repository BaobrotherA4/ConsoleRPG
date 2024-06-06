#pragma once
#include"C110152325_include.h"
#include "C110152325_Item.h"


enum ArmorType{ HEAD = 0, CHEST,LEGS,SHOES};



class C110152325_Armor :
	public C110152325_Item
{
private:
	int type;
	string typeStr;
	int defence;

public:
	C110152325_Armor();
	C110152325_Armor(int level, int rarity);
	C110152325_Armor(int type , int defence ,
		string name , int level , int buyValue ,
		int sellValue , int rarity );
	virtual ~C110152325_Armor();

	virtual C110152325_Armor* clone()const;

	string toString() const;

	inline int getDefence()const { return this->defence; }
	inline int getType()const { return this->type; }

	static C110152325_dArr<string> names;
	static void initNames();
};

