#ifndef KNAPSACK
#define KNAPSACK

#include <vector>

using namespace std;

struct Item
{
	int costo;
	int peso;
};

class Knapsack {
private:
	int pesoMax;
	vector<Item> items;
	vector<Item> mochila;

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
	vector<Item> GetMochila() { return this->mochila; }
	void SetPesoMax(int pesoMax) { this->pesoMax = pesoMax; }
	void SetItems(vector<Item> items) { this->items = items; }

	void HillClimbing(int pesoActual = 0, int pos = 0)
	{
		if (pesoActual == pesoMax) return;


	}
};

#endif // !KNAPSACK