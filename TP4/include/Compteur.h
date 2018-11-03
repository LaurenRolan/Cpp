/* Author: Lauren Sampaio
 * File: Compteur.h
 */
#ifndef COMPTEUR_H
#define COMPTEUR_H

#include <iostream>
#include "Obstacle.h"

using namespace std;

class Compteur : public Obstacle {
public:
	Compteur( );
	Compteur( Obstacle *prochaine );
	~Compteur( ) override;
	void setProchaine( Obstacle * prochaine );
    void recoitPalet( int place );
	void incCompteur();
	int getCompteur();
	
private:
	int _compteur;
  	bool _estPere;
};

#endif