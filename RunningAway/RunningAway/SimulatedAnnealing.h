#ifndef SIMULATEDANNEALING
#define SIMULATEDANNEALING

#include <algorithm>
#include <map>
#include <vector>
#include <queue>

using namespace std;
using namespace System;

struct City {
	int x;
	int y;
	City(int x = 0, int y = 0) : x(x), y(y) {}
};

class SimulatedAnnealing {
private:
	///heuristica
	int distancia;
	map<int, City> tour;
	int *TActual, *TMejor, *TNuevo;
	priority_queue<int> sss;
public:
	SimulatedAnnealing() {}
	SimulatedAnnealing(vector<City> tour)
	{
		this->tour = GetMapTour(tour);
		TActual = new int[tour.size()];
		TNuevo = new int[tour.size()];
		TMejor = new int[tour.size()];
		initTArrays();
		///Barajear el Arreglo
		random_shuffle(std::begin(tour), std::end(tour));
	}
	~SimulatedAnnealing() {}

	map<int, City> GetMapTour(vector<City> tour)
	{
		map<int, City> aux;
		for (int i = 0; i < tour.size(); i++)
		{
			aux[i] = tour[i];
		}
		return aux;
	}

	void initTArrays() 
	{
		for (int i = 0; i < tour.size(); i++)
		{
			TActual[i] = i;
			TNuevo[i] = i;
			TMejor[i] = i;
		}
	}
	/*void Algoritmo() 
	{
		int randA = rand() % tour.size();
		int randB = rand() % tour.size();
		if (randA == randB) return;

		swap(tour[randA], tour[randB]);
	}*/
};

#endif // !SIMULATEDANNEALING
