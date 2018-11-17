/* Author: Lauren Sampaio
 * File: main.cpp
 */
#include "Planche.h"
#include <iostream>
#include <cmath>
using namespace std;

extern bool showTrace;

void part1();
void part2();

int main()
{
	int choice = 0;
	std::cout << "Choisissez la partie (1, 2)\n";
	std::cin >> choice;
	
	switch(choice)
	{
		case 1: part1(); break;
		case 2: part2(); break; 
		default: break;
	}
}

void setShowTrace()
{
	char afficher;
	cout << "Afficher position courrant (O/N)?\t";
	cin >> afficher;
	if(afficher == 'O' || afficher == 'o')
	{
		showTrace = true;
	}
	else
	{
		showTrace = false;
	}
}

void part1()
{
	int compteurs, palets;
	cout << "# de compteurs:\t";
	cin >> compteurs;
	Planche planche(compteurs);
	cout << "# de palets:\t";
	cin >> palets;
	setShowTrace();
	planche.simulation(palets);
	cout << "# de instances: " << planche.getInstances() << endl;
}

void part2()
{
	int compteurs, palets;
	cout << "# de compteurs:\t";
	cin >> compteurs;
	Planche planche(compteurs);
	planche.afficher();
}
