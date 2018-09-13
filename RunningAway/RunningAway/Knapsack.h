#ifndef KNAPSACK
#define KNAPSACK

#include <vector>

using namespace std;
using namespace System;

struct Item
{
	int costo = 0;
	int peso = 0;
	bool selected = false;
	Item(int costo, int peso) : costo(costo), peso(peso) {}
};

class Knapsack {
private:
	int pesoMax;
	bool found;
	vector<Item> items;
	vector<Item> _Mochila;

public:
	Knapsack()
	{
		this->pesoMax = 0;
	}
	Knapsack(int pesoMax, vector<Item> items)
	{
		this->pesoMax = pesoMax;
		this->items = items;
	}
	~Knapsack() 
	{
		this->pesoMax = 0;
		this->items.clear();
	}

	int GetPesoMax() { return this->pesoMax; }
	vector<Item> GetItems() { return this->items; }
	vector<Item> GetMochila() { return this->_Mochila; }
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
		aux.push_back(Item(8, 5));
		aux.push_back(Item(7, 6));
		aux.push_back(Item(12, 10));
		aux.push_back(Item(6, 4));
		aux.push_back(Item(2, 1));
		aux.push_back(Item(3, 1));
		return aux;
	}

	void HillClimbing(int pesoActual, int pos, vector<Item> mochila, vector<Item> items)
	{
		if (found == true) return;
		if (pesoActual == pesoMax) {
			//se encontro la solucion y guardo el resultado
			found = true;
			_Mochila = mochila;
		}
		if (pos >= items.size() || allSelected(items) == true || items[pos].selected == true)
			return;

		mochila.push_back(items[pos]);
		items[pos].selected = true;
		bool *p = &items[pos].selected;
		pesoActual += items[pos].peso;

		if (pesoActual > pesoMax) return;

		for (int i = 0; i < items.size(); i++)
		{
			//empiezo a ramificar
			//el elemento raiz se empieza a probar con otros elementos
			HillClimbing(pesoActual, i, mochila, items);
			if (found == true) return;
		}

		*p = false;
		pesoActual -= items[pos].peso;
		mochila.pop_back();
		HillClimbing(pesoActual, ++pos, mochila, items);
	}

	int sumaPesoTotalItems() 
	{
		int aux = 0;
		for (int i = 0; i < items.size(); i++)
		{
			aux += items[i].peso;
		}
		return aux;
	}
public:
	vector<Item> HillClimbing() 
	{
		if (pesoMax > sumaPesoTotalItems())
			return items;
		HillClimbing(0, 0, {}, initItems());
		String ^cad = gcnew String("");
		for (int i = 0; i < _Mochila.size(); i++)
		{
			cad += "costo: " + _Mochila[i].costo + " - peso: " + _Mochila[i].peso + "\n";
		}
		return _Mochila;
	}
};

#endif // !KNAPSACK