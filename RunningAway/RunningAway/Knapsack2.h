#ifndef KNAPSACK2
#define KNAPSACK2

#include <vector>

using namespace std;
using namespace System;


using namespace std;
using namespace System;

struct Item
{
	int id = 0;
	int costo = 0;
	int peso = 0;
	int beneficio = 0;
	bool selected = false;
	Item(int id, int costo, int peso, int beneficio) : id(id), costo(costo), peso(peso), beneficio(beneficio) {}
};

class Knaspsack2 {
private:
	int pesoMax;
	vector<Item> items;
public:
	Knapsack2()
	{
		this->items = initItems();
	}
	Knapsack2(int m)
	{
		this->pesoMax = m;
		this->items = initItems();

	}
	Knapsack2(int pesoMax, vector<Item> items)
	{
		this->pesoMax = pesoMax;
		this->items = items;
	}
	~Knapsack2()
	{
		this->pesoMax = 0;
		this->items.clear();
	}

	void limpiarItems() {
		this->items.clear();
	}
	int GetPesoMax() { return this->pesoMax; }
	vector<Item> GetItems() { return this->items; }
//	vector<Item> GetMochila() { return this->_Mochila; }
	void SetPesoMax(int pesoMax) { this->pesoMax = pesoMax; }
	void SetItems(vector<Item> items) { this->items = items; }

	bool allSelected(vector<Item> items) {
		for (int i = 0; i < items.size(); i++)
		{
			if (items[i].selected == false)
				return false;
		}
		return true;
	}

	void resetItems() {
		for (int i = 0; i < items.size(); i++)
		{
			this->items[i].selected = false;
		}
	}

	vector<Item> resetItems(vector<Item> items) {
		for (int i = 0; i < items.size(); i++)
		{
			items[i].selected = false;
		}
		return items;
	}
private:
	vector<Item> initItems()
	{
		vector<Item> aux;
		aux.push_back(Item(0, 8, 5, 3));
		aux.push_back(Item(1, 7, 6, 1));
		aux.push_back(Item(2, 12, 10, 3));
		aux.push_back(Item(3, 6, 4, 2));
		aux.push_back(Item(4, 2, 1, 2));
		aux.push_back(Item(5, 3, 1, 1));
		return aux;
	}
};



#endif // !KNAPSACK2