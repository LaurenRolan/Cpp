/* Author: Lauren Sampaio
 * File: Clou.cpp
 */
#include "Clou.h"
#include <iostream>
using namespace std;

extern bool showTrace;

Clou::Clou( Obstacle *gauche, Obstacle *droite ) : Obstacle(gauche, droite)
{ _instances++; }

Clou::Clou() 
{ 
    _instances++;
	_prochaine[0] = nullptr;
	_prochaine[1] = nullptr;
}

Clou::~Clou()
{
	if(filsGauche())
	{
		delete _prochaine[0];
	}
	if(filsDroite())
	{
		delete _prochaine[1];
	}
}

void Clou::recoitPalet(int place)
{
    if(showTrace)
    {
        for(int i = 0; i < place; i++)
        {
            cout << "  ";
        }
        cout << "x \n";
    }
	if( _prochaine[0] != nullptr && _prochaine[1] != nullptr )
    {
    	if(rand() % 100 >= 50)
    	{
    		_prochaine[0]->recoitPalet(place - 1);
    	}
    	else
    	{
    		_prochaine[1]->recoitPalet(place + 1);	
    	}
    }
    else if( _prochaine[0] == nullptr )
    {
    	_prochaine[1]->recoitPalet(place + 1);
    }
    else
    {
    	_prochaine[0]->recoitPalet(place - 1);	
    }
}

void Clou::afficher( int place )
{
    cout << " x ";
    //Si est dans la derniere colonne
    if(filsDroite() && !filsGauche())
    {
        _prochaine[1]->afficher( place );
    }
    else
    {
        _prochaine[1]->afficher( place );
        _prochaine[0]->afficher( place + 1 );
    }
}