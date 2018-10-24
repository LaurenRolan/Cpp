/* Author: Lauren Sampaio
 * File: Compteur.cpp
 */

#include "Compteur.h"

Compteur::Compteur( const Obstacle *prochaine )
{
	_prochaine = prochaine;
	if(!prochaine->aPere())
	{
		prochaine->adopte();
		_estPere = true;
	}
	_compteur = 0;
}

