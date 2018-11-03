/* Author: Lauren Sampaio
 * File: Clou.cpp
 */
#include "Clou.h"
#include <iostream>
using namespace std;

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
    cout << "---Clou()\n";
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
    for(int i = 0; i < place; i++)
    {
        cout << "  ";
    }
    cout << "x \n";

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