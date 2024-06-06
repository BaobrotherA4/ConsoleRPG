#pragma once
#include"C110152325_include.h"

using namespace std;
class C110152325_Item
{
private:
	string name;
	int level;
	int buyValue;
	int sellValue;
	int rarity;
public:
	C110152325_Item();
	C110152325_Item(int level,int rarity);
	C110152325_Item(string name , int level,
		int buyValue ,
		int sellValue ,
		int rarity);
	virtual ~C110152325_Item();

	inline string  debugPrint() const { return this->name; }
	virtual C110152325_Item* clone()const = 0;
	virtual string toString()const = 0;

	inline const string& getname() const { return this->name;}
	inline const int& getLevel() const { return this->level;}
	inline const int& getBuyValue() const { return this->buyValue;}
	inline const int& getSellValue() const { return this->sellValue;}
	inline const int& getRarity() const { return this->rarity;}

	//Modifiers
	inline void setName(string name) { this->name = name; }
	
};
enum rarity {
	common =0,
	uncommon,
	rare,
	legendary,
	mythic
};
