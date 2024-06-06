#pragma once
#include"C110152325_include.h"
#include "C110152325_Character.h"
#include"C110152325_Enemy.h"
#include"C110152325_Puzzle.h"

class C110152325_Event
{
private:
	int nr0fEvents;

public:
	C110152325_Event();
	virtual ~C110152325_Event();
	void generateEvent(C110152325_Character &character,C110152325_dArr<C110152325_Enemy>& enemies);

	void enemyEncouter(C110152325_Character& character, C110152325_dArr<C110152325_Enemy>& enemies);

};

