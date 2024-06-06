#include "C110152325_Event.h"

C110152325_Event::C110152325_Event() {
	this->nr0fEvents = 2;
}

C110152325_Event::~C110152325_Event() {

}	

void C110152325_Event::generateEvent(C110152325_Character& character, C110152325_dArr<C110152325_Enemy>& enemies){
	int i =	0;

	switch (i)
	{
	case 0:
		enemyEncouter(character, enemies);
		break;
	default:
		break;
	}
}
void C110152325_Event::enemyEncouter(C110152325_Character& character, C110152325_dArr<C110152325_Enemy>& enemies) {

	bool playerTurn = false;

	int coinToss = rand() % 2;
	int choice;

	if (coinToss == 1)
		playerTurn = true;
	else
		playerTurn = false;

	bool escape = false;
	bool playerDefeated = false;
	bool enemiesDefeated = false;

	int nrOfEnemies = rand() % 5+1;
	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies.remove(i);
	}

	for (size_t i = 0; i < nr0fEvents; i++)
	{
		
		enemies.push(C110152325_Enemy(character.getLevel() + rand() % 3));
	}
	cout << "出現敵人!" << endl;
	for (size_t i = 0; i < enemies.size(); i++)
	{
		cout << i << "： "
			<< "等級：" << enemies[i].getLevel() << " - "
			<< "血量：" << enemies[i].getHp() << "/" << enemies[i].getHpMax() << " - "
			<< "防禦力：" << enemies[i].getDefence() << " - "
			<< "精準度：" << enemies[i].getAccuracy() << " - "
			<< "傷害：" << enemies[i].getDamageMin() << " ~ " << enemies[i].getDamageMax()
			<< endl;
	}


	int damage = 0;
	int gainExp = 0;
	int gainGold = 0;
	int playerTotal = 0;
	int EnemyTotal = 0;
	int combatTotal = 0;
	int combatRoll = 0;
	int combatRollPlayer = 0;
	int combatRollEnemy = 0;

	while (!escape && !playerDefeated && !enemiesDefeated) {

		if (playerTurn && !playerDefeated) {
			cout << "= 你的回合 =" << endl<<endl;
			cout << "請按下ENTER鍵來繼續..." << "\n" << endl;;
			cin.get();
			system("cls");

re:			cout << "* 戰鬥開始 *" << endl << endl;
			cout << "血量： " << character.getHp() << "/" << character.getHpMax() << endl<<endl;
			cout << "0: 逃跑" << endl;
			cout << "1: 攻擊" << endl;
			cout << "2: 防禦" << endl;
			cout << "3: 使用道具" << endl;

			cout << endl << "你的選擇：";
			cin >> choice;

			while (cin.fail() || choice > 3 || choice < 0) {

				cout << "輸入錯誤！" << endl;
				Sleep(500);
				system("cls");
				cin.clear();
				cin.ignore(100, '\n');
				goto re;
			}
			cin.ignore(100, '\n');
			cout << endl;

			switch (choice)
			{
			case 0:
				escape = true;
				break;

			case 1:
				cout << "* 選擇敵人 *" << endl << endl;
ke:				for (size_t i = 0; i < enemies.size(); i++)
				{
					cout << i << "： "
						<< "等級：" << enemies[i].getLevel() << " - "
						<< "血量：" << enemies[i].getHp() << "/" << enemies[i].getHpMax() << " - "
						<< "防禦力：" << enemies[i].getDefence() << " - "
						<< "精準度：" << enemies[i].getAccuracy() << " - "
						<< "傷害：" << enemies[i].getDamageMin() << " ~ " << enemies[i].getDamageMax()
						<< endl;
				}
				cout << endl << "你的選擇：";
				cin >> choice;

				while (cin.fail() || choice > enemies.size() || choice < 0) {

					cout << "輸入錯誤！" << endl;
					Sleep(500);
					cin.clear();
					cin.ignore(100, '\n');
					goto ke;
				}
				cin.ignore(100, '\n');
				cout << endl;

				combatTotal = enemies[choice].getDefence() + character.getAccuracy();
				EnemyTotal = enemies[choice].getDefence() /(double) combatTotal * 100;
				playerTotal =  character.getAccuracy()/(double)combatTotal * 100;
				combatRollPlayer = rand() % playerTotal+1;
				combatRollEnemy = rand() % EnemyTotal+1;

				
				//Sleep(500);
				cout << "角色擲骰： " << combatRollPlayer << endl;
				//Sleep(500);
				cout << "敵人擲骰： " << combatRollEnemy << endl<<endl;

				if (combatRollPlayer > combatRollEnemy) {
					//Sleep(500);
					cout << "打中目標!" << endl << endl;

					damage = character.getDamage();
					enemies[choice].takeDamage(damage);

					cout << "你打出了" << damage << "點傷害！" << endl << endl;

					if (!enemies[choice].isAlive()) {
						cout << "你打倒敵人了!" << endl << endl;
						gainExp = enemies[choice].getExp();
						character.gainExp(gainExp);
						gainGold = rand() % enemies[choice].getLevel() * 10 + 1;
						character.gainGold(gainGold);
						cout << "你已獲得" << gainExp << "經驗" << endl << endl;
						cout << "你已獲得" << gainGold << "金幣" << endl << endl;

						int roll = rand() % 100 + 1;
						int rarity = -1;

						if (roll > 20) {
							rarity = 0;           //common

							roll = rand() % 100 + 1;
							if (roll > 30) {
								rarity = 1;       //uncommon

								roll = rand() % 100 + 1;
								if (roll > 50) {
									rarity = 2;   //rare

									roll = rand() % 100 + 1;
									if (roll > 70) {
										rarity = 3;

										roll = rand() % 100 + 1;
										if (roll > 90) {
											rarity = 4;
										}
									}
								}
							}
						}

						if (roll >= 0) {
							roll = rand() % 100 + 1;
							if (roll > 50) {
								C110152325_Weapon tempw(character.getLevel(), rand() % 5);
								character.addItem(tempw);
								cout << "掉落武器!"<<endl;
							}
							else {
								C110152325_Armor tempA(character.getLevel(), rand() % 5);
								character.addItem(tempA);
								cout << "掉落裝備!"<<endl;
							}
						}
						enemies.remove(choice);
					}
				}
				else {
					//Sleep(500);
					cout << "沒打中!" << endl << endl;
				}
				break;
			case 2:
				break;

			case 3:
				break;

			default:
				break;
			}
				playerTurn = false;
		}
		else if (!playerTurn && !escape && !enemiesDefeated)
		{
			
			cout << "= 敵人的回合 =" << endl;
			cout << "請按下ENTER鍵來繼續..." << "\n" << endl;;
			cin.get();
			system("cls");

			for (size_t i = 0; i < enemies.size(); i++) {
				cout << "請按下ENTER鍵來繼續..." << endl << endl;;
				cin.get();
				system("cls");

				cout << "敵人：" << i << endl << endl;

				combatTotal = enemies[i].getAccuracy() + character.getDefence();
				EnemyTotal = enemies[i].getDefence() / (double)combatTotal * 100;
				playerTotal = character.getDefence() / (double)combatTotal * 100;
				combatRollPlayer = rand() % playerTotal + 1;
				combatRollEnemy = rand() % EnemyTotal + 1;
				cout << "角色擲骰： " << combatRollPlayer << endl;
				//Sleep(500);
				cout << "敵人擲骰： " << combatRollEnemy << endl << endl;

				if (combatRollPlayer < combatRollEnemy) {
					//Sleep(500);
					cout << "打中目標!" << endl << endl;

					damage = enemies[i].getDamage();
					character.takeDamage(damage);

					cout << "敵人打出了" << damage << "點傷害！" << endl << endl;
					cout << "血量： " << character.getHp() << "/" << character.getHpMax() << endl<<endl;
					if (!character.isAlive()) {
						cout << "你被打倒了!" << endl << endl;
						playerDefeated = true;
					}
				}
				else {
					//Sleep(500);
					cout << "沒打中!" << endl << endl;
				}
				//system("cls");
			}

			playerTurn = true;
		}
		if (!character.isAlive()) {

				playerDefeated = true;
			}
			if (enemies.size() <= 0) {
				enemiesDefeated = true;

			}

	}
			
}