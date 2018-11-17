/* Author: Lauren Sampaio
 * File: Obstacle.cpp
 */
#include "Obstacle.h"
#include <iostream>
using namespace std;


bool showTrace;
int Obstacle::_instances = 0;

Obstacle::Obstacle() {  }
Obstacle::~Obstacle() {  }

int Obstacle::getInstances()
{
	return _instances;
}

Obstacle::Obstacle(Obstacle* gauche, Obstacle* droite)
{
	setGauche(gauche);
	setDroite(droite);
}

bool Obstacle::hasPere() 
{ return _aPere; }

void Obstacle::adopte() 
{ _aPere = true; }

void Obstacle::setGauche( Obstacle *gauche )
{
	if(gauche == nullptr)
	{
		return;
	}
	_prochaine[0] = gauche;
	if(!gauche->hasPere())
	{
		gauche->adopte();
		_sontFils[0] = true;
	}
}

void Obstacle::setDroite( Obstacle *droite )
{
	if(droite == nullptr)
	{
		return;
	}
	_prochaine[1] = droite;
	if(!droite->hasPere())
	{
		droite->adopte();
		_sontFils[1] = true;
	}	
}

bool Obstacle::filsGauche() 
{ return _sontFils[0]; }

bool Obstacle::filsDroite() 
{ return _sontFils[1]; }

Obstacle * Obstacle::getGauche() 
{ return _prochaine[0]; }

Obstacle * Obstacle::getDroite() 
{ return _prochaine[1]; }

void Obstacle::recoitPalet( int place ) { }

void Obstacle::afficher( int place ) { }