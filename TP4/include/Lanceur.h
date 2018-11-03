/* Author: Lauren Sampaio
 * File: Lanceur.h
 */
#ifndef LANCEUR_H
#define LANCEUR_H

#include <iostream>
#include "Obstacle.h"
using namespace std;

class Lanceur {
private:
	Obstacle * _premier;
public:
	Lanceur( Obstacle *premier );
	Lanceur( );
	~Lanceur();
	void lancer( int place );
	void setPremier( Obstacle *premier );
};

#endif