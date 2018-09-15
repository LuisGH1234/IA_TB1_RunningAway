#ifndef KNAPSACK
#define KNAPSACK

#include <vector>
#include <list>
#include <queue>

using namespace std;
using namespace System;

struct Item
{
	int id = 0;
	int costo = 0;
	int peso = 0;
	int beneficio = 0;
	bool selected = false;
	Item(int id,int costo, int peso, int beneficio) : id(id),costo(costo), peso(peso), beneficio(beneficio){}
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
		this->items = initItems();
	}
	Knapsack(int m)
	{
		this->pesoMax = m;
		this->items = initItems();

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

	void limpiarItems() {
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
		aux.push_back(Item(0,8, 5,3));
		aux.push_back(Item(1,7, 6,1));
		aux.push_back(Item(2,12, 10,3));
		aux.push_back(Item(3,6, 4,2));
		aux.push_back(Item(4,2, 1,2));
		aux.push_back(Item(5,3, 1,1));
//		std::random_shuffle(std::begin(aux), std::end(aux));
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
	String^ HillClimbing() 
	{
		found = false;
		vector<Item> aux;
		if (pesoMax > sumaPesoTotalItems())
			aux = items;
		else {
			HillClimbing(0, 0, {}, this->items);
			aux = _Mochila;
		}
		int sum = 0;
		String ^cad = gcnew String("");
		for (int i = 0; i < aux.size(); i++)
		{
			cad += "costo: " + aux[i].costo + " - peso: " + aux[i].peso + "\n";
			sum += aux[i].costo;
		}
		cad += "-----------------------\n" + sum + "\n";
		resetItems();
		resetItems(items);
		return cad;
	}

	int Mayor_Beneficio(vector<Item> items, vector<vector<int>> Grafo, int aux, int pesoacumulado, int peso)
	{
		int mayorbeneficio = -1;
		for (int i = 0; i <Grafo[aux].size(); i++)
			if (mayorbeneficio < items[Grafo[aux][i]].beneficio &&
				pesoacumulado + items[Grafo[aux][i]].peso <= peso && items[Grafo[aux][i]].selected==false)
				mayorbeneficio = items[Grafo[aux][i]].id;
		return mayorbeneficio;
	}

	String^ Ramificacion_Poda()
		{
		vector<int> VecRespuesta;
		int pesoacumulado = 0;
		int numItem;
		int aux;
		queue<int> q;
		vector<vector<int>> Grafo(items.size());

		int *incoming = new int[items.size()];
		for (int i = 0; i < items.size(); i++)
			incoming[i] = 0;
		for (int i = 0; i < items.size(); i++)
		{
			//	pesoacumulado = items[i].peso;
			for (int j = 0; j < items.size(); j++)
				if (i != j && items[i].beneficio < items[j].peso &&/* pesoacumulado*/items[i].peso + items[j].peso <= pesoMax)
				{
					//				pesoacumulado += items[j].peso;
					incoming[items[j].id]++;
					Grafo[items[i].id].push_back(items[j].id);
				}
		}
		for (int i = 0; i < items.size(); i++)
			if (incoming[i] == 0)
				q.push(i);
		int v;
		int mayorbeneficio;
		pesoacumulado = 0;
		int k = 0;
		vector<vector<int>> Tinocaso(q.size());
		while (!q.empty())
		{
			resetItems(items);
			aux = q.front();
			q.pop();
			pesoacumulado = items[aux].peso;
			mayorbeneficio = 0;
			items[aux].selected = true;
			Tinocaso[k].push_back(aux);
			while (1)
			{
				mayorbeneficio = Mayor_Beneficio(items, Grafo, aux, pesoacumulado, pesoMax);
				if (mayorbeneficio == -1) break;
				pesoacumulado += items[mayorbeneficio].peso;
				aux = mayorbeneficio;
				Tinocaso[k].push_back(aux);
				items[aux].selected = true;
			}
			k++;
		}
		mayorbeneficio = 0;
		int acumular = 0;
		int acumular2 = 0;
		for (int j = 0; j < Tinocaso[0].size(); j++)
			acumular += items[Tinocaso[0][j]].beneficio;

		for (int i = 1; i < Tinocaso.size(); i++)
		{
			acumular2 = 0;
			for (int j = 0; j < Tinocaso[i].size(); j++)
				acumular2 += items[Tinocaso[i][j]].beneficio;
			if (acumular2 > acumular)
			{
				acumular = acumular2;
				mayorbeneficio = i;
			}
		}
		int sum = 0;
		String^ cad = gcnew String("");
		for (int i = 0; i < Tinocaso[mayorbeneficio].size(); i++) {
			sum += items[Tinocaso[mayorbeneficio][i]].beneficio;
			cad += items[Tinocaso[mayorbeneficio][i]].id + " " + 
				"Beneficio: " + items[Tinocaso[mayorbeneficio][i]].beneficio + 
				" -peso: " + items[Tinocaso[mayorbeneficio][i]].peso +
				" -costo" + items[Tinocaso[mayorbeneficio][i]].costo + "\n";
		}
		cad += "-----------------------\n" + "		" + sum + "\n";
		resetItems();
		resetItems(items);
		return cad;
		}
};

#endif // !KNAPSACK