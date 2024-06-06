#include "C110152325_Armor.h"


C110152325_dArr<string> C110152325_Armor::names;

void C110152325_Armor::initNames() {
	C110152325_Armor::names.push("暗夜頭盔");    //劍士
	C110152325_Armor::names.push("暗夜護甲");
	C110152325_Armor::names.push("暗夜手套");
	C110152325_Armor::names.push("暗夜之靴");
	C110152325_Armor::names.push("新手頭盔");    //劍士
	C110152325_Armor::names.push("新手護甲");
	C110152325_Armor::names.push("新手手套");
	C110152325_Armor::names.push("新手之靴");
	
	C110152325_Armor::names.push("冒險者頭盔");    //弓箭手
	C110152325_Armor::names.push("冒險者護甲");
	C110152325_Armor::names.push("冒險者手套");
	C110152325_Armor::names.push("冒險者之靴");
	C110152325_Armor::names.push("流浪頭盔");
	C110152325_Armor::names.push("流浪護甲");
	C110152325_Armor::names.push("流浪手套");
	C110152325_Armor::names.push("流浪之靴");
	
	C110152325_Armor::names.push("岩尊頭盔");    //原魔
	C110152325_Armor::names.push("岩尊鎧甲");
	C110152325_Armor::names.push("岩尊手套");
	C110152325_Armor::names.push("岩尊之靴");
	C110152325_Armor::names.push("原始人頭盔");
	C110152325_Armor::names.push("原始人護甲");
	C110152325_Armor::names.push("原始人手套");
	C110152325_Armor::names.push("原始人之靴");
}

C110152325_Armor::C110152325_Armor() 
	:C110152325_Item()
{
	this->defence = 0;
}

C110152325_Armor::C110152325_Armor(int level, int rarity) 
	:C110152325_Item(level,rarity)
{
	this->defence = rand() % (level * rarity);
	this->defence += rarity * 5;
	this->type = rand() % 4;

	switch (this->type)
	{
	case ArmorType::HEAD:
		this->typeStr = "頭盔";
			break;
	case ArmorType::CHEST:
		this->typeStr = "胸甲";
			break;
	case ArmorType::LEGS:
		this->typeStr = "護腿";
			break;
	case ArmorType::SHOES:
		this->typeStr = "鞋子";
			break;
	default:
		this->typeStr = "錯誤!";
			break;
	}

	this->setName(C110152325_Armor::names[rand() % C110152325_Armor::names.size()]);
	if (rarity == 3)
		this->defence += level * 5;
	if (rarity == 4)
		this->defence += level * 10;
}

C110152325_Armor::C110152325_Armor(int type, int defence, string name, int level, int buyValue, int sellValue, int rarity)
	:C110152325_Item(name, level, buyValue, sellValue, rarity)
{
	this->type = type;
	this->defence = defence;
}

C110152325_Armor::~C110152325_Armor() {

}

C110152325_Armor* C110152325_Armor::clone()const {
	return new C110152325_Armor(*this);
}

string C110152325_Armor::toString() const
{
	string str =
		this->getname()
		+ " 部件："
		+ this->typeStr
		+ " 等級："
		+ to_string(this->getLevel())
		+ " 品質："
		+ to_string(this->getRarity())
		+ " 防禦力："
		+ to_string(this->defence);

	return str;
}