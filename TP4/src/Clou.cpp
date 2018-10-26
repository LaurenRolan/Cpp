/* Author: Lauren Sampaio
 * File: Clou.cpp
 */
#include "Clou.h"

Clou::Clou( Obstacle *gauche, Obstacle *droite )
{
	_prochaine[0] = gauche;
	if(!gauche->hasPere())
	{
		gauche->adopte();
		_sontFils[0] = true;
	}

	_prochaine[1] = droite;
	if(!droite->hasPere())
	{
		droite->adopte();
		_sontFils[1] = true;
	}

}

Clou::Clou() 
{ 
	_prochaine[0] = nullptr;
	_prochaine[1] = nullptr;
}