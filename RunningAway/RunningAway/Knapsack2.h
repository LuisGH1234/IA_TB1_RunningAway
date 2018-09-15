#ifndef KNAPSACK2
#define KNAPSACK2


#include <vector>
#include <time.h>

using namespace std;
using namespace System;


using namespace std;
using namespace System;
/*
struct Item
{
	int id = 0;
	int costo = 0;
	int peso = 0;
	int beneficio = 0;
	bool selected = false;
	Item(int id, int costo, int peso, int beneficio) : id(id), costo(costo), peso(peso), beneficio(beneficio) {}
};
*/
class Knapsack2 {
private:
	int pesoMax;
	int dineroMax;
	vector<Item> items;
public:
	Knapsack2()
	{
		this->items = initItems();
	}
	Knapsack2(int pesoMax, int dineroMax)
	{
		this->pesoMax = pesoMax;
		this->items = initItems();
		this->dineroMax = dineroMax;
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
	void SetPesoMax_SetDineroMx(int pesoMax, int dineroMax) { this->pesoMax = pesoMax; this->dineroMax = dineroMax; }
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

void hillclimbing(int dinero, int peso, int posicion,vector<Item> &items, int k)
	{
		if (dinero == 0 || k == items.size() || peso == 0)
			return;
		if (dinero - items[k].costo >= 0 && items[k].selected == false && k != posicion && peso - items[k].peso >= 0)
		{
			peso -= items[k].peso;
			dinero -= items[k].costo;
			items[k].selected = true;
		}
		hillclimbing(dinero, peso, posicion, items, k + 1);
	}


public:
	String^ HillClimbing()
	{
		srand(time(NULL));
//		int dinero, peso; // Dinero = $24, peso = 16kg
		int aleatorio;
		Item aux(0,0,0,0);
		do {
			aleatorio = rand() % items.size();
		} while (dineroMax < items[aleatorio].peso, pesoMax < items[aleatorio].peso);
		items[aleatorio].selected = true;
		for (int i = 1; i < items.size(); i++)
			for (int j = 0; j < items.size()-1; j++)
				if (items[i].costo > items[j].costo)
				{
					aux = items[i];
					items[i] = items[j];
					items[j] = aux;
		/*			if (items[j].selected == true)
						aleatorio = j;*/
				}
		for (int i = 0; i < items.size(); i++)
			if (items[i].selected == true)
				aleatorio = i;
		hillclimbing(dineroMax - items[aleatorio].costo, pesoMax - items[aleatorio].peso, aleatorio, items, 0);
		int sumCosto = 0;
		int sumPeso = 0;
		String^ cad = gcnew String("");
		for (int i = 0; i < items.size(); i++)
			if (items[i].selected)
			{
				sumCosto += items[i].costo;
				sumPeso += items[i].peso;
				cad+="Costo: " +items[i].costo + " Peso: " + items[i].peso +"\n";
			}
		cad += "---------------------- - \n" + sumCosto + "    " + sumPeso + "\n";
		resetItems();
		return cad;
	}
};

#endif // !KNAPSACK2