 /* Author: Lauren Sampaio
 * File: Lanceur.cpp
 */
#include "Lanceur.h"
#include <iostream>
using namespace std;

Lanceur::Lanceur( Obstacle *premier )
{
	_premier = premier; 
}

Lanceur::Lanceur( ) { }

Lanceur::~Lanceur( ) 
{
	cout << "---Lanceur()\n"; 
	delete _premier; 
}

void Lanceur::setPremier( Obstacle *premier )
{ _premier = premier; }

void Lanceur::lancer( int place )
{
	_premier->recoitPalet( place );
}