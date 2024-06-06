#include "C110152325_Character.h"


C110152325_Character:: ~C110152325_Character() {

}
C110152325_Character::C110152325_Character(){


	this->distanceTravelled = 0;

	this->gold = 0;

	this->name = "";
	this->level = 0;
	this->exp = 0;
	this->expNext = 0;

	this->strength = 0;
	this->vitality = 0;
	this->dexterity = 0;
	this->intelligence = 0;

	this->hp = 0;
	this->hpMax = 0;
	this->stamina = 0;
	this->staminaMax = 0;
	this->damageMax = 0;
	this->defence = 0;
	this->luck = 0;
	this->statPoints = 0;
	this->x;
	this->y;
}
C110152325_Character::C110152325_Character(string name, int distanceTravelled,
	int gold, int level,
	int exp, int strength, int vitality,
	int dexterity, int intelligence,
	int hp, int stamina, int statPoints,int x,int y) {


	this->distanceTravelled = distanceTravelled;

	this->gold = gold;

	this->name = name;
	this->level = level;
	this->exp = exp;
	this->expNext = 0;

	this->strength = strength;
	this->vitality = vitality;
	this->dexterity = dexterity;
	this->intelligence = intelligence;

	this->hp = hp;
	this->hpMax = 0;
	this->stamina = stamina;
	this->staminaMax = 0;
	this->damageMax = 0;
	this->defence = 0;
	this->luck = 0;
	this->x = x;
	this->y = y;
	this->statPoints = statPoints;

	this->updateStats();
}
void C110152325_Character::initialize(const string name) {

	this->distanceTravelled = 0;

	this->gold = 100;

	this->name = name;
	this->level = 1;
	this->exp = 0;
	
	this->strength = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->accuracy = 0;
	this->intelligence = 5;

	this->statPoints = 0;
	this->x = 0;
	this->y = 0;

	this->updateStats();

	

}

void C110152325_Character::printStats()  const{
	cout << "= ������ = " << endl;
	cout << "= �W�r�G " << this->name<<endl;
	cout << "= ���šG " <<this->level<< endl;
	cout << "= �g��ȡG " << this->exp <<" / " <<this->expNext<< endl;
	cout << "= ��O�I�G" << this->statPoints << endl;
	cout << endl;
	cout << "= �O�q�G " << this->strength << endl;
	cout << "= ���O�G " << this->vitality << endl;
	cout << "= �F�ӡG " << this->dexterity << endl;
	cout << "= ���O�G " << this->intelligence << endl;
	cout << "= ���B�G " << this->luck << endl;
	cout << endl;
	cout << "= ��q�G " << this->hp <<" / "<<this->hpMax << endl;
	cout << "= �@�O�G " << this->stamina << " / " << this->staminaMax << endl;
	cout << "= �����O�G " << this->damageMin << " ~ " << this->damageMax << endl;
	cout << "= ���m�O�G " << this->defence<<endl;
	cout << "= ��ǫסG " << this->accuracy << endl;
	cout << endl;
	cout << "= ���ʶZ���G" << this->distanceTravelled << endl;
	cout << "= �����G" << this->gold << endl;
	cout << endl;
	cout << "= �Z���G" << this->weapon.getname()
		<< "���šG" << this->weapon.getLevel()
		<< "�ˮ`�G" << this->weapon.getDamageMin() << " - " << this->weapon.getDamageMax() << endl;
	cout << "= �Y���G" << this->Armor_head.getname()
		<< "���šG" << this->Armor_head.getLevel()
		<< "���m�G" << this->Armor_head.getDefence() << endl;
	cout << "= �@�ҡG" << this->Armor_chest.getname()
		<< "���šG" << this->Armor_chest.getLevel()
		<< "���m�G" << this->Armor_chest.getDefence() << endl;
	cout << "= �@�L�G" << this->Armor_legs.getname()
		<< "���šG" << this->Armor_legs.getLevel()
		<< "���m�G" << this->Armor_legs.getDefence() << endl;
	cout << "= �c�l�G" << this->Armor_shoes.getname()
		<< "���šG" << this->Armor_shoes.getLevel()
		<< "���m�G" << this->Armor_shoes.getDefence() << endl;
}

void C110152325_Character::updateStats() {
	this->expNext = static_cast<int>((50 / 3) * ((pow(level, 3) -
		6 * pow(level, 2)) +
		17 * level - 12)) + 100;

	this->hpMax = (this->vitality * 2) + (this->strength / 2) + this->level *5+100;
	this->staminaMax = this->vitality + (this->strength / 2) + (this->dexterity / 3)+100;
	this->stamina = this->staminaMax+100;
	this->damageMin = this->strength * 2+100;
	this->damageMax = this->strength *2 + 2+100;
	this->defence = this->dexterity + (this->intelligence / 2)+100;
	this->accuracy = (this->dexterity / 2) + this->intelligence+100;
	this->luck = this->intelligence+100;
	this->hp = hpMax;
}

void C110152325_Character::addToStat(int stat, int value) {
	if (this->statPoints < value) {
		cout << "���~�I�S����������O�I�i�ɯšI" << endl;
	}
	else {
		switch (stat)
		{
		case 0:
			this->strength += value;
			break;
		case 1:
			this->vitality += value;
			break;
		case 2:
			this->dexterity += value;
			break;
		case 3:
			this->intelligence += value;
			break;
		case 4:
			this->luck += value;
			break;
		default:
			cout << "�S������O�i�ɯ�" << "\n";
			break;
		}
		this->statPoints--;
	}
	
}

void C110152325_Character::equipItem(unsigned index) {

	if (index < 0 || index > this->inventory.size()) {
		cout << "��ܪ��~���~!" << endl << endl;
	}
	else
	{
		C110152325_Weapon* w = nullptr;
		w = dynamic_cast<C110152325_Weapon*>(&this->inventory[index]);

		C110152325_Armor* a = nullptr;
		a = dynamic_cast<C110152325_Armor*>(&this->inventory[index]);
		if (w != nullptr) {
			this->weapon = *w;
		}
		else if (a != nullptr) {
			switch (a->getType())
			{
			case ArmorType::HEAD:
				this->Armor_head = *a;
				break;
			case ArmorType::CHEST:
				this->Armor_chest = *a;
				break;
			case ArmorType::LEGS:
				this->Armor_legs = *a;
				break;
			case ArmorType::SHOES:
				this->Armor_shoes = *a;
				break;
			default:
				cout << "�L�Ī��˳�����!" << endl << endl;
				break;
			}
		}
		else {
			cout << "���~!�L�k��J�˳���!";
		}
	}
}



void C110152325_Character::levelUp() {
	while(exp >= expNext) {
		exp -= expNext;
		level++;
		
		this->expNext =static_cast<int>((50 / 3) * ((pow(level, 3) -
				6 * pow(level, 2)) +
				17 * level - 12))+100;

		this->statPoints++;

	}
}

string C110152325_Character::getAsString() const{
	return name + " "
		+ to_string(distanceTravelled) + " "
		+ to_string(gold) + " "
		+ to_string(level) + " "
		+ to_string(exp) + " "
		+ to_string(strength) + " "
		+ to_string(vitality) + " "
		+ to_string(dexterity) + " "
		+ to_string(intelligence) + " "
		+ to_string(hp) + " "
		+ to_string(stamina) + " "
		+ to_string(statPoints) + " "
		+ to_string(x) + " "
		+ to_string(y);
}

string C110152325_Character::getInvAsString() {
	string inv;

	for (size_t i = 0; i < this->inventory.size(); i++)
	{
		inv += to_string(i) + "�G" + this->inventory[i].toString() + "\n";

	}
	return inv;
}

void C110152325_Character::map(int stat) {
	switch (stat)
	{
	case 0: 
		this->x = 0;
		this->y = 0;
		cout << "�A���Ҧb��m�G�D��" << endl;
		break;
	case 1:
		this->x = 0;
		this->y = 1;
		cout << "�A���Ҧb��m�G�˪L" << endl;
		break;
	case 2:
		this->x = 1;
		this->y = 0;
		cout << "�A���Ҧb��m�G�·t�j��" << endl;
		break;
	case 3:
		this->x = 0;
		this->y = -1;
		cout << "�A���Ҧb��m�G�a�U��" << endl ;      //
		break;
	case 4:
		this->x = -1;
		this->y = 0;
		cout << "�A���Ҧb��m�G����" << endl;      //
		break;
	default:
		break;
	}
}

void C110152325_Character::movecity(int stat) {
	switch (stat)
	{
	case 0:
		this->y +=1;
		if (y > 1 || x == -1 && y != 0 || x == 1 && y != 0) {
			cout << "�w�g�L�k�A���W���ʤF..." << endl;
			Sleep(500);
			y -= 1;
			break;
		}
		break;
	case 1:
		this->y -= 1;
		if (y < -1 || x == -1 && y != 0 || x == 1 && y != 0) {
			cout << "�w�g�L�k�A���U���ʤF..." << endl;
			Sleep(500);
			y += 1;
			break;
		}
		break;
	case 2:
		this->x -= 1;
		if (x < -1 || y == -1 && x != 0 || y == 1 && x != 0) {
			cout << "�w�g�L�k�A�������ʤF..." << endl;
			Sleep(500);
			x += 1;
			break;
		}
		break;
	case 3:
		this->x += 1;
		if (x > 1 || x == 1 && y != 0 || x == 1 && y != 0) {
			cout << "�w�g�L�k�A���k���ʤF..." << endl;
			Sleep(500);
			x -= 1;
			break;
		}
		break;
	default:
		break;
	}

}

void C110152325_Character::arrive() {
	if (this->x == 0 && this->y == 0) {
		cout << "�A���Ҧb��m�G�D��" << endl << endl;
	}
	else if (this->x == 1 && this->y == 0) {
		cout << "�A���Ҧb��m�G�·t�j��" << endl << endl;
	}
	else if (this->x == -1 && this->y == 0) {
		cout << "�A���Ҧb��m�G����" << endl << endl;
	}
	else if (this->x == 0 && this->y == 1) {
		cout << "�A���Ҧb��m�G�˪L" << endl << endl;
	}
	else if (this->x == 0 && this->y == -1) {
		cout << "�A���Ҧb��m�G�a�U��" << endl << endl;
	}
}

void C110152325_Character::takeDamage(const int damage) {
	this->hp -= damage;

	if (this->hp <= 0) {
		this->hp = 0;
	}
};
