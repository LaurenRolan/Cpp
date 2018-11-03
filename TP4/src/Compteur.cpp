/* Author: Lauren Sampaio
 * File: Compteur.cpp
 */

#include "Compteur.h"
#include <iostream>
using namespace std;

Compteur::Compteur()
{
	_instances++; 
	_compteur = 0; 
}

Compteur::Compteur( Obstacle *prochaine ) : Obstacle(prochaine, nullptr)
{
	_instances++;
	_compteur = 0;
}

Compteur::~Compteur( )
{
	cout << "---Compteur()\n";
	if(filsGauche())
	{
		delete _prochaine[0];
	}
}

void Compteur::setProchaine( Obstacle *prochaine ) 
{ _prochaine[0] = prochaine; }


void Compteur::incCompteur() 
{ _compteur++; }

int Compteur::getCompteur()
{ return _compteur; }

void Compteur::recoitPalet(int place)
{
	incCompteur();
	for(int i = 0; i < place; i++)
	{
		cout << "  ";
	}
	cout << "o\n";
    if( _prochaine[0] != nullptr )
    {
    	_prochaine[0]->recoitPalet(place - 1);
    }
}