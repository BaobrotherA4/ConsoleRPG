#include "C110152325_Weapon.h"

C110152325_dArr<string> C110152325_Weapon::names;

void C110152325_Weapon::initNames() {
	C110152325_Weapon::names.push("原木刀");
	C110152325_Weapon::names.push("闡釋者");
	C110152325_Weapon::names.push("逐闇者");
	C110152325_Weapon::names.push("若水");
	C110152325_Weapon::names.push("落霞");
	C110152325_Weapon::names.push("冬極白星");
	C110152325_Weapon::names.push("赤角石潰杵");
	C110152325_Weapon::names.push("以理服人");
	C110152325_Weapon::names.push("狼的末路");
}

C110152325_Weapon::C110152325_Weapon()
	:C110152325_Item()
{
	this->damageMax = 0;
	this->damageMin = 0;
}

C110152325_Weapon::C110152325_Weapon(int level, int rarity)
	:C110152325_Item(level,rarity)
{
	this->damageMax = rand() % (level * (rarity+1));
	this->damageMax += (rarity + 1) * 5;
	this->setName(C110152325_Weapon::names[rand() % C110152325_Weapon::names.size()]);

	if (rarity == 3)
		this->damageMax += level * 5;
	else if (rarity == 4)
		this->damageMax += level * 10;

	this->damageMin = this->damageMax / 2;
}

C110152325_Weapon::C110152325_Weapon(int damageMin, int damageMax, string name, int level, int buyValue, int sellValue, int rarity)
	:C110152325_Item(name, level, buyValue, sellValue, rarity)
{
	this->damageMin = damageMin;
	this->damageMax = damageMax;
}

C110152325_Weapon::~C110152325_Weapon() {

}

C110152325_Weapon* C110152325_Weapon::clone()const {
	return new C110152325_Weapon(*this);
}

string C110152325_Weapon::toString()const
{
	string str =
		this->getname()
		+ " 等級： "
		+ to_string(this->getLevel())
		+ " 品質： "
		+ to_string(this->getRarity())
		+ " 傷害： "
		+ to_string(this->damageMin)
		+ "~"
		+ to_string(this->damageMax)
		+ " 售價： "
		+ to_string(this->getSellValue());


		
	return str;
}