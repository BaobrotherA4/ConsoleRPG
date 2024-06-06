#include "C110152325_Enemy.h"

C110152325_Enemy::C110152325_Enemy(int level){
	this->level = level;
	this->hpMax = level * 10;
	this->hp = this->hpMax;
	this->damageMin = this->level * 1;
	this->damageMax = this->level * 2;
	this->dropChance = rand() % 100 + 1;
	this->defence = rand() % level* 4 + 1;
	this->accuracy = rand() % level*4 + 1;

}

C110152325_Enemy::~C110152325_Enemy() {

}

string C110152325_Enemy::getAsString()const {
	return "等級： " + to_string(this->level) + "\n" +
		"血量： " + to_string(this->hp) + "/" + to_string(this->hpMax) + "\n" +
		"傷害： " + to_string(this->damageMin) + "~" + to_string(this->damageMax) + "\n" +
		"防禦： " + to_string(this->defence) + "\n" +
		"準確率： " + to_string(this->accuracy) + "\n" +
		"掉落機會：" + to_string(this->dropChance) + "\n";

}

void C110152325_Enemy::takeDamage(int damage) {
	this->hp -= damage;

	if (this->hp <= 0) {
		this->hp = 0;
	}

};

