/* Author: Lauren Sampaio
 * File: Compteur.h
 */
#ifndef COMPTEUR_H
#define COMPTEUR_H

#include <iostream>
#include "Obstacle.h"

using namespace std;

class Compteur : public virtual Obstacle {
public:
	Compteur( );
	Compteur( Obstacle *prochaine );
	void setProchaine( Obstacle * prochaine );
	void incCompteur();
	int getCompteur();

private:
	int _compteur;
  	bool _estPere;
};

#endif