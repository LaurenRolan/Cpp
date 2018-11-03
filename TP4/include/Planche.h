/* Author: Lauren Sampaio
 * File: Planche.h
 */
#ifndef PLANCHE_H
#define PLANCHE_H

#include <iostream>
#include "Compteur.h"
#include "Lanceur.h"
#include "Clou.h"

using namespace std;

class Planche {
public:
	Planche(int nCompteurs);
	~Planche();
	void simulation(int palets);
	static int getInstances();
	void afficher();
	
private:
	static int _instances;
	int _nCompteurs;
	Compteur *_terminal;
	Lanceur * _lanceur;
	Compteur ** _compteurs;
	Obstacle ** _table;
};

#endif