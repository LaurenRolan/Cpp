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

private:
	int _nCompteurs;
	Compteur *_terminal;
	Lanceur _lanceur;
	Obstacle ** _table;
};

#endif