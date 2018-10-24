/* Author: Lauren Sampaio
 * File: Planche.cpp
 */
#include "Planche.h"
#include "Clou.h"

Planche::Planche(int nCompteurs)
{
	_nCompteurs = nCompteurs;
	_table = new Obstacle * [ _nCompteurs ];
	_terminal = new Compteur;

	for(int i = 0; i < _nCompteurs; i++)
	{
		_table[i] = new Compteur();
		//_terminal
	}

	int n = _nCompteurs - 1;
	while(n) 
	{
		for(int i = 0; i < n; i++)
		{
			Obstacle * gauche = _table[i];
			Obstacle * droite = _table[i + 1];
			_table[i] = new Clou; //(gauche, droite)
		}
		n--;
	};
	_lanceur = Lanceur(_table[0]);
}

