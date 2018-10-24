/* Author: Lauren Sampaio
 * File: Planche.h
 */
#include <iostream>
#include "Compteur.h"
#include "Lanceur.h"

using namespace std;

class Planche {
private:
	int _nCompteurs;
	Compteur _terminal;
	Lanceur _lanceur;
	Obstacle ** _table;
	void creerPlanche();
public:
	Planche(int nCompteurs);
	~Planche();
};