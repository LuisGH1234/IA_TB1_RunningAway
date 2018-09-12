#include <iostream>
#include <vector>

using namespace std;

vector<Item> _Mochila;
int pesoMax = 16;
bool found = false;

struct Item
{
	int costo = 0;
	int peso = 0;
	bool selected = false;
	Item(int costo, int peso) : costo(costo), peso(peso) {}
};

vector<Item> initItems() {
	vector<Item> aux;
	aux.push_back(Item(8,5));
	aux.push_back(Item(7,6));
	aux.push_back(Item(12,10));
	aux.push_back(Item(6,4));
	aux.push_back(Item(2,1));
	aux.push_back(Item(3,1));
	return aux;
}

bool allSelected(vector<Item> items) {
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i].selected == false)
			return false;
	}
	return true;
}

vector<Item> resetItems(vector<Item> items) {
	for (int i = 0; i < items.size(); i++)
	{
		items[i].selected = false;
	}
	return items;
}

void HillClimbing(int pesoActual, int pos, vector<Item> mochila, vector<Item> items)
{
	if (found == true) return;
	if (pesoActual == pesoMax) {
		found = true;
		_Mochila = mochila;
	}
	if (pos >= items.size() || allSelected(items) == true || items[pos].selected == true) 
		return;

	mochila.push_back(items[pos]);
	items[pos].selected = true;
	pesoActual += items[pos].peso;

	if (pesoActual > pesoMax) return;

	for (int i = 0; i < items.size(); i++)
	{
		HillClimbing(pesoActual, i, mochila, items);
		if (found == true) return;
	}
	HillClimbing(0, pos + 1, {}, resetItems(items));
}

int main()
{
	HillClimbing(0, 0, {}, initItems());
	cout << endl << endl;
	for (int i = 0; i < _Mochila.size(); i++)
	{
		cout << "costo: " << _Mochila[i].costo << " - peso: " << _Mochila[i].peso << endl;
	}
	cin.get();
	return 0;
}


