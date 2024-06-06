#include "C110152325_Item.h"


C110152325_Item::C110152325_Item() {
	this->name = "EMPTY";
	this->level = 0;
	this->buyValue = 0;
	this->sellValue = 0;
	this->rarity = 0;
}

C110152325_Item::C110152325_Item(int level,int rarity) {
	this->name = "RANDOM";
	this->level = rand() % level +1;
	this->rarity = rarity;
	this->buyValue = level * this->rarity * 10;
	this->sellValue = this->buyValue / 2;

}

C110152325_Item::C110152325_Item(string name,int level,int buyValue,int sellValue,int rarity) {
	this->name = name;
	this->level = level;
	this->buyValue = buyValue;
	this->sellValue = sellValue;
	this->rarity = rarity;
}

C110152325_Item::~C110152325_Item() {

}