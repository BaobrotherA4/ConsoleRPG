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
	cout << "�X�{�ĤH!" << endl;
	for (size_t i = 0; i < enemies.size(); i++)
	{
		cout << i << "�G "
			<< "���šG" << enemies[i].getLevel() << " - "
			<< "��q�G" << enemies[i].getHp() << "/" << enemies[i].getHpMax() << " - "
			<< "���m�O�G" << enemies[i].getDefence() << " - "
			<< "��ǫסG" << enemies[i].getAccuracy() << " - "
			<< "�ˮ`�G" << enemies[i].getDamageMin() << " ~ " << enemies[i].getDamageMax()
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
			cout << "= �A���^�X =" << endl<<endl;
			cout << "�Ы��UENTER����~��..." << "\n" << endl;;
			cin.get();
			system("cls");

re:			cout << "* �԰��}�l *" << endl << endl;
			cout << "��q�G " << character.getHp() << "/" << character.getHpMax() << endl<<endl;
			cout << "0: �k�]" << endl;
			cout << "1: ����" << endl;
			cout << "2: ���m" << endl;
			cout << "3: �ϥιD��" << endl;

			cout << endl << "�A����ܡG";
			cin >> choice;

			while (cin.fail() || choice > 3 || choice < 0) {

				cout << "��J���~�I" << endl;
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
				cout << "* ��ܼĤH *" << endl << endl;
ke:				for (size_t i = 0; i < enemies.size(); i++)
				{
					cout << i << "�G "
						<< "���šG" << enemies[i].getLevel() << " - "
						<< "��q�G" << enemies[i].getHp() << "/" << enemies[i].getHpMax() << " - "
						<< "���m�O�G" << enemies[i].getDefence() << " - "
						<< "��ǫסG" << enemies[i].getAccuracy() << " - "
						<< "�ˮ`�G" << enemies[i].getDamageMin() << " ~ " << enemies[i].getDamageMax()
						<< endl;
				}
				cout << endl << "�A����ܡG";
				cin >> choice;

				while (cin.fail() || choice > enemies.size() || choice < 0) {

					cout << "��J���~�I" << endl;
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
				cout << "�����Y��G " << combatRollPlayer << endl;
				//Sleep(500);
				cout << "�ĤH�Y��G " << combatRollEnemy << endl<<endl;

				if (combatRollPlayer > combatRollEnemy) {
					//Sleep(500);
					cout << "�����ؼ�!" << endl << endl;

					damage = character.getDamage();
					enemies[choice].takeDamage(damage);

					cout << "�A���X�F" << damage << "�I�ˮ`�I" << endl << endl;

					if (!enemies[choice].isAlive()) {
						cout << "�A���˼ĤH�F!" << endl << endl;
						gainExp = enemies[choice].getExp();
						character.gainExp(gainExp);
						gainGold = rand() % enemies[choice].getLevel() * 10 + 1;
						character.gainGold(gainGold);
						cout << "�A�w��o" << gainExp << "�g��" << endl << endl;
						cout << "�A�w��o" << gainGold << "����" << endl << endl;

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
								cout << "�����Z��!"<<endl;
							}
							else {
								C110152325_Armor tempA(character.getLevel(), rand() % 5);
								character.addItem(tempA);
								cout << "�����˳�!"<<endl;
							}
						}
						enemies.remove(choice);
					}
				}
				else {
					//Sleep(500);
					cout << "�S����!" << endl << endl;
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
			
			cout << "= �ĤH���^�X =" << endl;
			cout << "�Ы��UENTER����~��..." << "\n" << endl;;
			cin.get();
			system("cls");

			for (size_t i = 0; i < enemies.size(); i++) {
				cout << "�Ы��UENTER����~��..." << endl << endl;;
				cin.get();
				system("cls");

				cout << "�ĤH�G" << i << endl << endl;

				combatTotal = enemies[i].getAccuracy() + character.getDefence();
				EnemyTotal = enemies[i].getDefence() / (double)combatTotal * 100;
				playerTotal = character.getDefence() / (double)combatTotal * 100;
				combatRollPlayer = rand() % playerTotal + 1;
				combatRollEnemy = rand() % EnemyTotal + 1;
				cout << "�����Y��G " << combatRollPlayer << endl;
				//Sleep(500);
				cout << "�ĤH�Y��G " << combatRollEnemy << endl << endl;

				if (combatRollPlayer < combatRollEnemy) {
					//Sleep(500);
					cout << "�����ؼ�!" << endl << endl;

					damage = enemies[i].getDamage();
					character.takeDamage(damage);

					cout << "�ĤH���X�F" << damage << "�I�ˮ`�I" << endl << endl;
					cout << "��q�G " << character.getHp() << "/" << character.getHpMax() << endl<<endl;
					if (!character.isAlive()) {
						cout << "�A�Q���ˤF!" << endl << endl;
						playerDefeated = true;
					}
				}
				else {
					//Sleep(500);
					cout << "�S����!" << endl << endl;
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