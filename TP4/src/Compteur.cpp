/* Author: Lauren Sampaio
 * File: Compteur.cpp
 */

#include "Compteur.h"
#include <iostream>
using namespace std;

extern bool showTrace;

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
	if(filsGauche())
	{
		delete _prochaine[0];
	}
}

void Compteur::setProchaine( Obstacle *prochaine ) 
{ _prochaine[0] = prochaine; }


void Compteur::incCompteur() 
{ _compteur++; }

void Compteur::rstCompteur()
{ _compteur = 0; }

int Compteur::getCompteur()
{ return _compteur; }

void Compteur::recoitPalet(int place)
{
	incCompteur();
	if(showTrace)
	{
		for(int i = 0; i < place; i++)
		{
			cout << "  ";
		}
		cout << "o\n";
	}
	
    if( _prochaine[0] != nullptr )
    {
    	_prochaine[0]->recoitPalet(place - 1);
    }
}

void Compteur::afficher( int place )
{
	cout << " o ";
	//Si est feuille
    if(!filsDroite())
    {
        cout << endl;
        for(int i = 0; i < place; i++)
        {
            cout << "   ";
        }    
    }
    else
    {
    	cout << endl;
        for(int i = 0; i < place; i++)
        {
            cout << "   ";
        }
        cout << " o \n";
    }
}