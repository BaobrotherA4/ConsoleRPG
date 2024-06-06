#pragma once
#include"C110152325_Weapon.h"
#include"C110152325_Armor.h"
#include"C110152325_include.h"

class C110152325_Inventory
{
private:
	int cap;
	int nrOfItems;
	C110152325_Item **itemArr;
	void expand();
	void initialize(const int from = 0);

public:
	C110152325_Inventory();
	~C110152325_Inventory();
	C110152325_Inventory(const C110152325_Inventory &obj);
	inline int size()const { return this->nrOfItems;};
	C110152325_Item& operator[](const int index);
	void addItem(const C110152325_Item &item);
	void removeItem(int index);
	inline void debugPrint() const {
		for (size_t i = 0; i < this->nrOfItems; i++) {
			cout << this->itemArr[i]->debugPrint ()<< endl;
		}
	}

};

