#include "C110152325_Game.h"

C110152325_Game::C110152325_Game() {
	choice = 0;
	playing = true;
	activeCharacter = 0;
	fileName = "C110152325_character.txt";
}

C110152325_Game::~C110152325_Game() {

}
//Fuctions
void C110152325_Game::initGame() {
	ifstream in;
	in.open("C110152325_character.txt");

	C110152325_Weapon::initNames();
	C110152325_Armor::initNames();

	if (in.is_open())
		this->loadCharacters();
	else{
		createNewCharacter();
		this->saveCharacters();
	}

	in.close();
	/*cout << "*** �w��Ө�RPG�@�� ***" << endl << endl;
	cout << "0�G �n�J" << endl;
	cout << "1�G ���U" << endl;
	cout << "2�G �����C��" << endl;
	int choice;
	cout << endl << "��ܡG";
	cin >> choice;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "��J���~�I" << "\n";
		cout << endl << "��ܡG";
		cin >> choice;
	}
	switch (choice)
	{
	case 0:
		loginuser();
		break;
	case 1:
		system("cls");
		
		break;

	case 2:
		playing = false;
		break;

	default:
		break;
	}*/
}

void C110152325_Game::mainMenu() {

	cout << "�Ы��UENTER����~��..." << "\n";
	cin.get();
	system("cls");

	if (this->characters[activeCharacter].isAlive()) {
		if (this->characters[activeCharacter].getExp() >= this->characters[activeCharacter].getExpNext())
		{
		this->characters[activeCharacter].levelUp();
		cout << "���ߧA�ɵ���" << this->characters[activeCharacter].getLevel() << "��!" << endl << endl;

		}

		cout << "* �C���j�U *" << endl << endl;
		cout << "�ϥΨ���G" << characters[activeCharacter].getName() << " Nr."
			<< this->activeCharacter + 1 << "/" << this->characters.size() << endl << endl;

		characters[activeCharacter].arrive();
		cout << endl;

		cout << "0: �����C��" << endl;
		cout << "1: �n�X" << endl;
		cout << "2: �Ȧ�" << endl;
		cout << "3: �ө�" << endl;
		cout << "4: ���U��" << endl;
		cout << "5: �j�Ư�O" << endl;
		cout << "6: ������" << endl;
		cout << "7: �Ыب���" << endl;
		cout << "8: �x�s" << endl;
		cout << "9: �d�ݨ������" << endl;
		cout << "10: ��ܨ���" << endl;
		cout << "11: map" << endl;
		cout << "12: �d�ݥ]�]" << endl;
		cout << endl;


		cout << endl << "��ܡG ";
		cin >> this->choice;
		cout << endl;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "��J���~�I" << "\n";
			cout << endl << "��ܡG";
			cin >> this->choice;
		}

		cin.ignore(100, '\n');
		cout << endl;

		switch (this->choice)
		{
		case 0:
			playing = false;
			this->saveCharacters();
			break;


		case 1:
			system("cls");
			initGame();
			break;
		case 2:
			Travel();
			break;
		case 4:
			Rest();
			break;
		case 5:
			system("cls");
			levelUpCharacter();
			break;

		case 6:
			system("cls");
			this->characterMenu();
			break;

		case 7:
			createNewCharacter();
			saveCharacters();
			break;

		case 8:
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << "�x�s�����I" << endl;
			saveCharacters();
			break;

		case 9:
			loadCharacters();
			break;

		case 10:
			selectCharacters();
			break;
		case 11:
			map();
			break;
		case 12:
			cout<<this->characters[this->activeCharacter].getInvAsString();
			break;
		default:
			break;
		}
	}
	else
	{
		cout << "* �A���F�A�nŪ���O���ɶ�? *" << endl << endl;
		cout << "0�G �O" << endl;
		cout << "1�G �_" << endl;
		cout << endl << "��ܡG ";
		cin >> this->choice;
		cout << endl;

		while (cin.fail() || this->choice>1 || this->choice<0) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "��J���~�I" << "\n";
			cout << endl << "��ܡG";
			cin >> this->choice;
		}

		cin.ignore(100, '\n');
		cout << endl;

		if (this->choice == 0)
			this->loadCharacters();
		else
		{
			playing = false;
		}
	}
 }

void C110152325_Game::createNewUser() {
	/*string username = "";
	string password = "";
	string name = "";
	int choice;
re:
	cout << "�b���G";
	cin >> username;
	cout << "�K�X�G";
	cin >> password;

	for (size_t i = 0; i < this->characters.size(); i++)
	{
		while (username == this->characters[i].getUsername()) {
			cout << "������b���w�s�b�I" << endl;
			Sleep(500);
			system("cls");
			goto re;
		}
	}
	system("cls");
	cout << "* ���¾�~ *" << endl << endl;
	cout << "0�G���]" << endl;
	cout << "1: �}�b��" << endl;
	cout << "2: �C�h" << endl << endl;

	cout << "��ܡG";
	cin >> choice;

	while (cin.fail() || choice > 2) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "��J���~�I" << endl;
		cout << endl << "��ܡG";
		cin >> choice;
	}

	switch (choice)
	{
	case 0:
		system("cls");
		cout << "�п�J���]���W�r�G";
		cin >> name;
		system("cls");
		cout << "�[�����еy��";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		break;
	case 1:
		system("cls");
		cout << "�п�J�}�b�⪺�W�r�G";
		cin >> name;
		system("cls");
		cout << "�[�����еy��";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		break;
	case 2:
		system("cls");
		cout << "�п�J�C�h���W�r�G";
		cin >> name;
		system("cls");
		cout << "�[�����еy��";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		break;
	default:
		break;
	}
	bool exists = false;

	for (size_t i = 0; i < this->characters.size(); i++)
	{
		while (name == this->characters[i].getName()) {
			cout << "������W�٤w�s�b�I" << endl;
			cout << "����W�١G";
			getline(cin, name);
		}
	}
	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].initialize(username, password, name);
	ofstream outFile(fileName);
	if (outFile.is_open()) {
		for (size_t i = 0; i < characters.size(); i++) {
			outFile << characters[i].getAsString() << "\n";
		}
	}
	outFile.close();*/
}

void C110152325_Game::createNewCharacter() {
	string name="";
	int choice;
	system("cls");
	cout << "* ���¾�~ *" << endl << endl;
	cout << "0�G���]" << endl;
	cout << "1: �}�b��" << endl;
	cout << "2: �C�h" << endl << endl;

	cout << "��ܡG";
	cin >> choice;

	while (cin.fail() || choice > 2) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "��J���~�I" << endl;
		cout << endl << "��ܡG";
		cin >> choice;
	}

	switch (choice)
	{
	case 0:
		system("cls");
		cout << "�п�J���]���W�r�G";
		cin >> name;
		system("cls");
		cout << "�[�����еy��";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		break;
	case 1:
		system("cls");
		cout << "�п�J�}�b�⪺�W�r�G";
		cin >> name;
		system("cls");
		cout << "�[�����еy��";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		break;
	case 2:
		system("cls");
		cout << "�п�J�C�h���W�r�G";
		cin >> name;
		system("cls");
		cout << "�[�����еy��";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		break;
	default:
		break;
	}
	bool exists = false;

	for (size_t i = 0; i < this->characters.size(); i++)
	{	
		while (name == this->characters[i].getName()) {
			cout << "������W�٤w�s�b�I" << endl;
			cout << "����W�١G";
			getline(cin, name);
		}
		//username = this->characters[i].getUsername();
		//password = this->characters[i].getPassword();
	}
	characters.push_back(C110152325_Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].initialize(name);

}

void C110152325_Game::saveCharacters() {
	ofstream outFile(fileName);
	if (outFile.is_open()) {
		for (size_t i = 0; i < characters.size(); i++) {
			outFile << characters[i].getAsString()<<"\n";
		}
	}
	outFile.close();
}

void C110152325_Game::loadCharacters() {

	ifstream inFile(fileName);
	string name = "";
	int count=0;
	int distanceTravelled = 0;
	int gold = 0;
	int level=0;
	int exp = 0;
	int strength = 0;
	int vitality = 0;
	int dexterity = 0;
	int intelligence = 0;
	int hp = 0;
	int stamina = 0;
	int statPoints = 0;
	int x = 0;
	int y = 0;
	this->characters.clear();
	string line = "";
	stringstream str;
	if (inFile.is_open()) {
		while (getline(inFile, line)) {
			str.str(line);
			str >> name;
			str >> distanceTravelled;
			str >> gold;
			str >> level;
			str >> exp;
			str >> strength;
			str >> vitality;
			str >> dexterity;
			str >> intelligence;
			str >> hp;
			str >> stamina;
			str >> statPoints;
			str >> x;
			str >> y;

				C110152325_Character temp(name, distanceTravelled, gold, level,
					exp, strength, vitality, dexterity, intelligence,
					hp, stamina, statPoints,x,y);
				this->characters.push_back(C110152325_Character(temp));
				cout << "����" << name << "�w�����C" << endl;
				str.clear();
			}
		}		
	inFile.close();

	if (this->characters.size() <= 0) {
		throw "���~! �L����s�������I";
	}
}

void C110152325_Game::Travel() {
	this->characters[activeCharacter].travel();

	C110152325_Event ev;
	ev.generateEvent(this->characters[activeCharacter], this->enemies);
}

void C110152325_Game::levelUpCharacter() {
	this->characters[activeCharacter].levelUp();
	if (this->characters[activeCharacter].getstatpoint()) {
		cout << "�A��" << this->characters[activeCharacter].getstatpoint() << "�I��O�i�H���t�I" << endl << endl;

		cout << "�п�ܷQ�j�ƪ���O�G" << endl << endl;
		cout << "0�G �O�q" << endl;
		cout << "1�G ���O" << endl;
		cout << "2�G �F��" << endl;
		cout << "3�G ���O" << endl;
		cout << "4�G ���B" << endl << endl;
		cout << "��ܡG";
		cin >> this->choice;

		while (cin.fail() || this->choice > 4) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "��J���~�I" << endl;
			cout << endl << "��ܡG";
			cin >> this->choice;
		}

		cin.ignore(100, '\n');
		cout << endl;

		switch (this->choice)
		{
		case 0:
			this->characters[activeCharacter].addToStat(0,1);
			cout << "�O�q�j�Ʀ��\�I" << endl;
			break;
		case 1:
			this->characters[activeCharacter].addToStat(1,1);
			cout << "���O�j�Ʀ��\�I" << endl;
			break;
		case 2:
			this->characters[activeCharacter].addToStat(2,1);
			cout << "�F�ӱj�Ʀ��\�I" << endl;
			break;
		case 3:
			this->characters[activeCharacter].addToStat(3,1);
			cout << "���O�j�Ʀ��\�I" << endl;
			break;
		case 4:
			this->characters[activeCharacter].addToStat(4,1);
			cout << "���B�j�Ʀ��\�I" << endl;
			break;
		default:
			break;
		}
	}
	else {

	}
}

void C110152325_Game::characterMenu() {
	do
	{
		system("cls");

		cout << "= �ӤH��� =" << endl << endl;
		characters[activeCharacter].printStats();
		cout << endl;
		cout << "�п�ܭn���}..." << endl;
		cout << "0�G��^" << endl;
		cout << "1�G�I�]" << endl;
		cout << "2�G�˳���" << endl<<endl;

		cout << "��ܡG";
		cin >> this->choice;

		while (cin.fail() || this->choice > 2 || this->choice < 0) {
			cout << "��J���~�I" << "\n";
			cin.clear();
			cin.ignore(100, '\n');
			
			cout << "�п�ܭn���}..." << endl;
			cout << "0�G��^" << endl;
			cout << "1�G�I�]" << endl;
			cout << "2�G�˳���" << endl << endl;
			cout << endl << "��ܡG";
			cin >> this->choice;
		}

		cin.ignore(100, '\n');
		cout << endl;

		switch (this->choice)
		{
		case 0:
			break;
		case 1:
			cout << this->characters[this->activeCharacter].getInvAsString();
		case 2:
			cout << this->characters[this->activeCharacter].getInvAsString();
			cout << this->characters[this->activeCharacter].equipItem(0);
		default:
			break;
		}
		if (this->choice > 0) {
			cout << "�Ы��UENTER����~��..." << "\n";
			cin.get();
		}

	} while (this->choice > 0); 


}


//�˳���
void C110152325_Game::inventoryEquip(){

}

//�a��
void C110152325_Game::map() { //�a��
rm:	system("cls");
	cout << "*    �@�ɦa��        *" << endl << endl;
	cout << "       �˪L           " << endl;
	cout << "        |             " << endl;
	cout << " ����X�D���X�·t�j�� " << endl;
	cout << "        |             " << endl;
	cout << "      �a�U��          " << endl << endl;

	int choice;
	this->characters[activeCharacter].arrive();
	cout << "* ��ܤ覡 *" << endl << endl;
	cout << "0�G ����" << endl;
	cout << "1�G �ǰe" << endl;
	cout << "2�G ��^" << endl << endl;
	cout << "�A����ܡG";
	cin >> choice;
	while (cin.fail() || choice > 2) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "��J���~�I" << endl;
		cout << endl << "�A����ܡG";
		cin >> choice;
	}
	switch (choice)
	{
	case 0://����
		cout << "* ��ܤ�V *" << endl << endl;//
		cout << "0�G�W" << endl;
		cout << "1�G�U" << endl;
		cout << "2�G��" << endl;
		cout << "3�G�k" << endl << endl;
		cout << "�A����ܡG";
		cin >> choice;

		while (cin.fail() || choice > 3) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "��J���~�I" << endl;
			cout << endl << "��ܡG";
			cin >> choice;
		}
		cin.ignore(100, '\n');
		cout << endl;
		this->characters[activeCharacter].movecity(choice);
		goto rm;
	case 1: //�ǰe
		cout << "* �п�ܭn�ǰe���a�� *" << endl << endl;
		cout << "0�G�D��" << endl;
		cout << "1�G�˪L" << endl;
		cout << "2�G�·t�j��" << endl;
		cout << "3�G�a�U��" << endl;
		cout << "4�G����" << endl << endl;
		cout << "�A����ܡG";
		cin >> choice;
		while (cin.fail() || choice > 4) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "��J���~�I" << endl;
			cout << endl << "�A����ܡG";
			cin >> choice;
		}
		cin.ignore(100, '\n');
		cout << endl;
		this->characters[activeCharacter].map(choice);
		goto rm;
	case 2: //��^
		mainMenu();
		break;
	default:
		break;
	}
	
}

//��ܨ���
void C110152325_Game::selectCharacters() {
	cout << "����C��G" << endl << endl;
	for (size_t i = 0; i < this->characters.size(); i++)
	{
		cout << i << "�G  " << characters[i].getName() << " ���šG " << characters[i].getLevel() << endl;
	}

	cout << "��ܨ���G";
	cin >> this->choice;

	while (cin.fail() || this->choice >= characters.size() || choice < 0) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "��J���~�I" << endl;
		cout << endl << "��ܨ���G";
		cin >> this->choice;
	}

	cin.ignore(100, '\n');
	cout << endl;

	activeCharacter = this->choice;
	activeCharacter = choice;
	cout << this->characters[this->activeCharacter].getName() << "��ܦ��\�I" << endl << endl;
}

//�n�J
void C110152325_Game::loginuser() {
//	string username = "";
//	string password = "";
//	string name = "";
//	int choice;
//	int activeCharacter;
//re:
//	cout << "�b���G";
//	cin>>username;
//	cout << "�K�X�G";
//	cin>>password;
//
//	for (size_t i = 0; i < this->characters.size(); i++)
//	{
//		while (username == characters[i].getUsername() && password == characters[i].getPassword()) {
//			cout << "�K�X���~!" << endl;
//			Sleep(500);
//			system("cls");
//			goto re;
//		}
//		activeCharacter = i;
//		cout << activeCharacter;
//	}
//	system("cls");
//	selectCharacters(activeCharacter);
}

//���U��
void C110152325_Game::Rest() {
	int restCost = this->characters[this->activeCharacter].getHpMax() - this->characters[this->activeCharacter].getHp();
	cout << "= ���U�� =" << endl << endl;
	cout << "�A�N�|�I�X�N���G";
	cout << restCost << endl;
	cout << endl << "�A�������G";
	cout << this->characters[this->activeCharacter].getGold() << endl << endl;

	if (this->characters[this->activeCharacter].getGold() < restCost) {
		cout << "�A�S�����i�H��I!" << endl << endl;
	}
	else{
	}

	cout << endl << endl << "�T�w�n�𮧶�?" << endl;
	cout << "0�G �O" << endl;
	cout << "1�G �_" << endl << endl;

	cin >> this->choice;

	while (cin.fail() || this->choice > 1 || this->choice < 0) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "��J���~�I" << "\n";
		cout << endl << "��ܡG";
		cin >> this->choice;
	}

	cin.ignore(100, '\n');
	cout << endl;

	if (this->choice == 0) {
		this->characters[this->activeCharacter].restHp();
		this->characters[this->activeCharacter].payGold(restCost);
	}
}