#include "C110152325_Armor.h"


C110152325_dArr<string> C110152325_Armor::names;

void C110152325_Armor::initNames() {
	C110152325_Armor::names.push("�t�]�Y��");    //�C�h
	C110152325_Armor::names.push("�t�]�@��");
	C110152325_Armor::names.push("�t�]��M");
	C110152325_Armor::names.push("�t�]���u");
	C110152325_Armor::names.push("�s���Y��");    //�C�h
	C110152325_Armor::names.push("�s���@��");
	C110152325_Armor::names.push("�s���M");
	C110152325_Armor::names.push("�s�⤧�u");
	
	C110152325_Armor::names.push("�_�I���Y��");    //�}�b��
	C110152325_Armor::names.push("�_�I���@��");
	C110152325_Armor::names.push("�_�I�̤�M");
	C110152325_Armor::names.push("�_�I�̤��u");
	C110152325_Armor::names.push("�y���Y��");
	C110152325_Armor::names.push("�y���@��");
	C110152325_Armor::names.push("�y����M");
	C110152325_Armor::names.push("�y�����u");
	
	C110152325_Armor::names.push("���L�Y��");    //���]
	C110152325_Armor::names.push("���L�Z��");
	C110152325_Armor::names.push("���L��M");
	C110152325_Armor::names.push("���L���u");
	C110152325_Armor::names.push("��l�H�Y��");
	C110152325_Armor::names.push("��l�H�@��");
	C110152325_Armor::names.push("��l�H��M");
	C110152325_Armor::names.push("��l�H���u");
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
		this->typeStr = "�Y��";
			break;
	case ArmorType::CHEST:
		this->typeStr = "�ݥ�";
			break;
	case ArmorType::LEGS:
		this->typeStr = "�@�L";
			break;
	case ArmorType::SHOES:
		this->typeStr = "�c�l";
			break;
	default:
		this->typeStr = "���~!";
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
		+ " ����G"
		+ this->typeStr
		+ " ���šG"
		+ to_string(this->getLevel())
		+ " �~��G"
		+ to_string(this->getRarity())
		+ " ���m�O�G"
		+ to_string(this->defence);

	return str;
}