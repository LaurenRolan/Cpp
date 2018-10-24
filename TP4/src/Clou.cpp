/* Author: Lauren Sampaio
 * File: Clou.cpp
 */
#include "Clou.h"

Clou::Clou( const Obstacle *gauche, const Obstacle *droite )
{
	_prochaine[0] = gauche;
	_prochaine[1] = droite;
	if(!gauche->aPere())
	{
		gauche->adopte();
		_sontFils[0] = true;
	}
	if(!droite->aPere())
	{
		droite->adopte();
		_sontFils[1] = true;
	}
}

