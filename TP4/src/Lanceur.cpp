 /* Author: Lauren Sampaio
 * File: Lanceur.cpp
 */
#include "Lanceur.h"

Lanceur::Lanceur( Obstacle *premier)
{ _premier = premier; }

Lanceur::Lanceur( ) { }

Lanceur::~Lanceur()
{ delete _premier; }