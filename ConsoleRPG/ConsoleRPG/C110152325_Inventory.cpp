#include "C110152325_Inventory.h"

C110152325_Inventory::C110152325_Inventory() {
	this->cap = 5;
	this->nrOfItems = 0;
	this->itemArr = new C110152325_Item * [cap];
	this->initialize();
}

C110152325_Inventory::~C110152325_Inventory()
{
	for (size_t i = 0; i < this->nrOfItems; i++) {
		delete this->itemArr[i];
	}
	delete[] this->itemArr;
}

C110152325_Inventory::C110152325_Inventory(const C110152325_Inventory& obj) {
	this->cap = obj.cap;
	this->nrOfItems = obj.nrOfItems;
	this->itemArr = new C110152325_Item * [this->cap];

	for (size_t i = 0; i < this->nrOfItems; i++) {
		this->itemArr[i] = obj.itemArr[i]->clone();
	}

	initialize(this->nrOfItems);
}

C110152325_Item& C110152325_Inventory::operator[](const int index) {
	if (index < 0 || index >= this->nrOfItems)
		throw("BAD INDEX!");

	return *this->itemArr[index];
}

void C110152325_Inventory::expand() {
	this->cap *= 2;

	C110152325_Item**tempArr = new C110152325_Item *[this->cap];

	for (size_t i = 0; i < this->nrOfItems; i++) {
		tempArr[i] = this->itemArr[i];
	}

	delete[] this->itemArr;
	this->itemArr = tempArr;
	this->initialize(this->nrOfItems);
}

void C110152325_Inventory::initialize(const int from) {
	for (size_t i = from; i < cap; i++) {
		this->itemArr[i] = nullptr;
	}

}

void C110152325_Inventory::addItem(const C110152325_Item& item) {
	if (this->nrOfItems >= this->cap) {
		expand();
	}

	this->itemArr[this->nrOfItems++] = item.clone();
}


void C110152325_Inventory::removeItem(int index) {

}