#pragma once

#include"C110152325_Character.h"
#include "C110152325_Functions.h"
#include"C110152325_Event.h"
#include"C110152325_include.h"

using namespace std;

class C110152325_Game{
public:
	C110152325_Game();
	virtual ~C110152325_Game();

	void map();
	void loginuser();
	void createNewUser();
	void initGame();
	void characterMenu();
	void mainMenu();
	void createNewCharacter();
	void saveCharacters();
	void loadCharacters();
	void inventoryEquip();
	void Travel();
	void levelUpCharacter();
	void selectCharacters();
	void Rest();


	inline bool getplaying() const { return this->playing; }
private:
	int choice;
	bool playing;

	int activeCharacter;
	vector<C110152325_Character> characters;
	string fileName;

	C110152325_dArr<C110152325_Enemy> enemies;
};

