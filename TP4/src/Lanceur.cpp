 /* Author: Lauren Sampaio
 * File: Lanceur.cpp
 */
#include "Lanceur.h"

Lanceur::Lanceur(const Obstacle *premier)
{
	_premier = premier;
}

Lanceur::~Lanceur()
{
	delete _premier;
}