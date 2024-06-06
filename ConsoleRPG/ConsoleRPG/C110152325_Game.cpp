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
	/*cout << "*** 歡迎來到RPG世界 ***" << endl << endl;
	cout << "0： 登入" << endl;
	cout << "1： 註冊" << endl;
	cout << "2： 結束遊戲" << endl;
	int choice;
	cout << endl << "選擇：";
	cin >> choice;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "輸入錯誤！" << "\n";
		cout << endl << "選擇：";
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

	cout << "請按下ENTER鍵來繼續..." << "\n";
	cin.get();
	system("cls");

	if (this->characters[activeCharacter].isAlive()) {
		if (this->characters[activeCharacter].getExp() >= this->characters[activeCharacter].getExpNext())
		{
		this->characters[activeCharacter].levelUp();
		cout << "恭喜你升等至" << this->characters[activeCharacter].getLevel() << "等!" << endl << endl;

		}

		cout << "* 遊戲大廳 *" << endl << endl;
		cout << "使用角色：" << characters[activeCharacter].getName() << " Nr."
			<< this->activeCharacter + 1 << "/" << this->characters.size() << endl << endl;

		characters[activeCharacter].arrive();
		cout << endl;

		cout << "0: 結束遊戲" << endl;
		cout << "1: 登出" << endl;
		cout << "2: 旅行" << endl;
		cout << "3: 商店" << endl;
		cout << "4: 坐下休息" << endl;
		cout << "5: 強化能力" << endl;
		cout << "6: 角色資料" << endl;
		cout << "7: 創建角色" << endl;
		cout << "8: 儲存" << endl;
		cout << "9: 查看角色紀錄" << endl;
		cout << "10: 選擇角色" << endl;
		cout << "11: map" << endl;
		cout << "12: 查看包包" << endl;
		cout << endl;


		cout << endl << "選擇： ";
		cin >> this->choice;
		cout << endl;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "輸入錯誤！" << "\n";
			cout << endl << "選擇：";
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
			cout << "儲存完畢！" << endl;
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
		cout << "* 你死了，要讀取記錄檔嗎? *" << endl << endl;
		cout << "0： 是" << endl;
		cout << "1： 否" << endl;
		cout << endl << "選擇： ";
		cin >> this->choice;
		cout << endl;

		while (cin.fail() || this->choice>1 || this->choice<0) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "輸入錯誤！" << "\n";
			cout << endl << "選擇：";
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
	cout << "帳號：";
	cin >> username;
	cout << "密碼：";
	cin >> password;

	for (size_t i = 0; i < this->characters.size(); i++)
	{
		while (username == this->characters[i].getUsername()) {
			cout << "此角色帳號已存在！" << endl;
			Sleep(500);
			system("cls");
			goto re;
		}
	}
	system("cls");
	cout << "* 選擇職業 *" << endl << endl;
	cout << "0：原魔" << endl;
	cout << "1: 弓箭手" << endl;
	cout << "2: 劍士" << endl << endl;

	cout << "選擇：";
	cin >> choice;

	while (cin.fail() || choice > 2) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "輸入錯誤！" << endl;
		cout << endl << "選擇：";
		cin >> choice;
	}

	switch (choice)
	{
	case 0:
		system("cls");
		cout << "請輸入原魔的名字：";
		cin >> name;
		system("cls");
		cout << "加載中請稍後";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		break;
	case 1:
		system("cls");
		cout << "請輸入弓箭手的名字：";
		cin >> name;
		system("cls");
		cout << "加載中請稍後";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		break;
	case 2:
		system("cls");
		cout << "請輸入劍士的名字：";
		cin >> name;
		system("cls");
		cout << "加載中請稍後";
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
			cout << "此角色名稱已存在！" << endl;
			cout << "角色名稱：";
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
	cout << "* 選擇職業 *" << endl << endl;
	cout << "0：原魔" << endl;
	cout << "1: 弓箭手" << endl;
	cout << "2: 劍士" << endl << endl;

	cout << "選擇：";
	cin >> choice;

	while (cin.fail() || choice > 2) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "輸入錯誤！" << endl;
		cout << endl << "選擇：";
		cin >> choice;
	}

	switch (choice)
	{
	case 0:
		system("cls");
		cout << "請輸入原魔的名字：";
		cin >> name;
		system("cls");
		cout << "加載中請稍後";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		break;
	case 1:
		system("cls");
		cout << "請輸入弓箭手的名字：";
		cin >> name;
		system("cls");
		cout << "加載中請稍後";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		break;
	case 2:
		system("cls");
		cout << "請輸入劍士的名字：";
		cin >> name;
		system("cls");
		cout << "加載中請稍後";
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
			cout << "此角色名稱已存在！" << endl;
			cout << "角色名稱：";
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
				cout << "角色" << name << "已紀錄。" << endl;
				str.clear();
			}
		}		
	inFile.close();

	if (this->characters.size() <= 0) {
		throw "錯誤! 無角色存取紀錄！";
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
		cout << "你有" << this->characters[activeCharacter].getstatpoint() << "點能力可以分配！" << endl << endl;

		cout << "請選擇想強化的能力：" << endl << endl;
		cout << "0： 力量" << endl;
		cout << "1： 活力" << endl;
		cout << "2： 靈敏" << endl;
		cout << "3： 智力" << endl;
		cout << "4： 幸運" << endl << endl;
		cout << "選擇：";
		cin >> this->choice;

		while (cin.fail() || this->choice > 4) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "輸入錯誤！" << endl;
			cout << endl << "選擇：";
			cin >> this->choice;
		}

		cin.ignore(100, '\n');
		cout << endl;

		switch (this->choice)
		{
		case 0:
			this->characters[activeCharacter].addToStat(0,1);
			cout << "力量強化成功！" << endl;
			break;
		case 1:
			this->characters[activeCharacter].addToStat(1,1);
			cout << "活力強化成功！" << endl;
			break;
		case 2:
			this->characters[activeCharacter].addToStat(2,1);
			cout << "靈敏強化成功！" << endl;
			break;
		case 3:
			this->characters[activeCharacter].addToStat(3,1);
			cout << "智力強化成功！" << endl;
			break;
		case 4:
			this->characters[activeCharacter].addToStat(4,1);
			cout << "幸運強化成功！" << endl;
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

		cout << "= 個人資料 =" << endl << endl;
		characters[activeCharacter].printStats();
		cout << endl;
		cout << "請選擇要打開..." << endl;
		cout << "0：返回" << endl;
		cout << "1：背包" << endl;
		cout << "2：裝備欄" << endl<<endl;

		cout << "選擇：";
		cin >> this->choice;

		while (cin.fail() || this->choice > 2 || this->choice < 0) {
			cout << "輸入錯誤！" << "\n";
			cin.clear();
			cin.ignore(100, '\n');
			
			cout << "請選擇要打開..." << endl;
			cout << "0：返回" << endl;
			cout << "1：背包" << endl;
			cout << "2：裝備欄" << endl << endl;
			cout << endl << "選擇：";
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
			cout << "請按下ENTER鍵來繼續..." << "\n";
			cin.get();
		}

	} while (this->choice > 0); 


}


//裝備欄
void C110152325_Game::inventoryEquip(){

}

//地圖
void C110152325_Game::map() { //地圖
rm:	system("cls");
	cout << "*    世界地圖        *" << endl << endl;
	cout << "       森林           " << endl;
	cout << "        |             " << endl;
	cout << " 城鎮—主城—黑暗大陸 " << endl;
	cout << "        |             " << endl;
	cout << "      地下城          " << endl << endl;

	int choice;
	this->characters[activeCharacter].arrive();
	cout << "* 選擇方式 *" << endl << endl;
	cout << "0： 移動" << endl;
	cout << "1： 傳送" << endl;
	cout << "2： 返回" << endl << endl;
	cout << "你的選擇：";
	cin >> choice;
	while (cin.fail() || choice > 2) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "輸入錯誤！" << endl;
		cout << endl << "你的選擇：";
		cin >> choice;
	}
	switch (choice)
	{
	case 0://移動
		cout << "* 選擇方向 *" << endl << endl;//
		cout << "0：上" << endl;
		cout << "1：下" << endl;
		cout << "2：左" << endl;
		cout << "3：右" << endl << endl;
		cout << "你的選擇：";
		cin >> choice;

		while (cin.fail() || choice > 3) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "輸入錯誤！" << endl;
			cout << endl << "選擇：";
			cin >> choice;
		}
		cin.ignore(100, '\n');
		cout << endl;
		this->characters[activeCharacter].movecity(choice);
		goto rm;
	case 1: //傳送
		cout << "* 請選擇要傳送的地方 *" << endl << endl;
		cout << "0：主城" << endl;
		cout << "1：森林" << endl;
		cout << "2：黑暗大陸" << endl;
		cout << "3：地下城" << endl;
		cout << "4：城鎮" << endl << endl;
		cout << "你的選擇：";
		cin >> choice;
		while (cin.fail() || choice > 4) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "輸入錯誤！" << endl;
			cout << endl << "你的選擇：";
			cin >> choice;
		}
		cin.ignore(100, '\n');
		cout << endl;
		this->characters[activeCharacter].map(choice);
		goto rm;
	case 2: //返回
		mainMenu();
		break;
	default:
		break;
	}
	
}

//選擇角色
void C110152325_Game::selectCharacters() {
	cout << "角色列表：" << endl << endl;
	for (size_t i = 0; i < this->characters.size(); i++)
	{
		cout << i << "：  " << characters[i].getName() << " 等級： " << characters[i].getLevel() << endl;
	}

	cout << "選擇角色：";
	cin >> this->choice;

	while (cin.fail() || this->choice >= characters.size() || choice < 0) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "輸入錯誤！" << endl;
		cout << endl << "選擇角色：";
		cin >> this->choice;
	}

	cin.ignore(100, '\n');
	cout << endl;

	activeCharacter = this->choice;
	activeCharacter = choice;
	cout << this->characters[this->activeCharacter].getName() << "選擇成功！" << endl << endl;
}

//登入
void C110152325_Game::loginuser() {
//	string username = "";
//	string password = "";
//	string name = "";
//	int choice;
//	int activeCharacter;
//re:
//	cout << "帳號：";
//	cin>>username;
//	cout << "密碼：";
//	cin>>password;
//
//	for (size_t i = 0; i < this->characters.size(); i++)
//	{
//		while (username == characters[i].getUsername() && password == characters[i].getPassword()) {
//			cout << "密碼錯誤!" << endl;
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

//坐下休息
void C110152325_Game::Rest() {
	int restCost = this->characters[this->activeCharacter].getHpMax() - this->characters[this->activeCharacter].getHp();
	cout << "= 坐下休息 =" << endl << endl;
	cout << "你將會付出代價：";
	cout << restCost << endl;
	cout << endl << "你的金幣：";
	cout << this->characters[this->activeCharacter].getGold() << endl << endl;

	if (this->characters[this->activeCharacter].getGold() < restCost) {
		cout << "你沒有錢可以支付!" << endl << endl;
	}
	else{
	}

	cout << endl << endl << "確定要休息嗎?" << endl;
	cout << "0： 是" << endl;
	cout << "1： 否" << endl << endl;

	cin >> this->choice;

	while (cin.fail() || this->choice > 1 || this->choice < 0) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "輸入錯誤！" << "\n";
		cout << endl << "選擇：";
		cin >> this->choice;
	}

	cin.ignore(100, '\n');
	cout << endl;

	if (this->choice == 0) {
		this->characters[this->activeCharacter].restHp();
		this->characters[this->activeCharacter].payGold(restCost);
	}
}