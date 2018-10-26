/* Author: Lauren Sampaio
 * File: Compteur.cpp
 */

#include "Compteur.h"

Compteur::Compteur()
{ _compteur = 0; }

Compteur::Compteur( Obstacle *prochaine )
{
	_prochaine[0] = prochaine;
	if(!prochaine->hasPere())
	{
		prochaine->adopte();
		_estPere = true;
	}
	_compteur = 0;
}

void Compteur::setProchaine( Obstacle *prochaine ) 
{ _prochaine[0] = prochaine; }


void Compteur::incCompteur() 
{ _compteur++; }

int Compteur::getCompteur()
{ return _compteur; }