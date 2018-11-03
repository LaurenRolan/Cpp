/* Author: Lauren Sampaio
 * File: Planche.cpp
 */
#include "Planche.h"
#include <iostream>
using namespace std;

int Planche::_instances = 0;

Planche::Planche( int nCompteurs )
{
	_nCompteurs = nCompteurs;
	_compteurs = new Compteur * [ _nCompteurs ];
	_table = new Obstacle * [ _nCompteurs ];
	_terminal = new Compteur;

	if(_nCompteurs == 1)
	{
		_table[0] = _terminal;
		_compteurs[0] = _terminal;
	}
	else
	{
		for(int i = 0; i < _nCompteurs; i++)
		{
			Compteur * current = new Compteur;
			_table[i] = current;
			_table[i]->setGauche( _terminal );
			_table[i]->setDroite( nullptr );
			_compteurs[i] = current;
			_compteurs[i]->setGauche( _terminal );
			_compteurs[i]->setDroite( nullptr );
		}
	}

	int n = _nCompteurs - 1;
	while(n) 
	{
		for(int i = 0; i < n; i++)
		{
			Obstacle * gauche = _table[i];
			Obstacle * droite = _table[i + 1];
			_table[i] = new Clou;
			_table[i]->setGauche( gauche );
			_table[i]->setDroite( droite );
		}
		n--;
	};
	_lanceur = new Lanceur;
	_instances++;
	_lanceur->setPremier(_table[0]);
	_instances += _table[0]->getInstances();
}

Planche::~Planche()
{
	cout << "---Planche()\n";
	delete _lanceur;
	delete [] _compteurs;
	delete [] _table;
}

void Planche::simulation( int palets )
{
	for(int round = 0; round < palets; round++)
	{
		cout << "\nRound " << round << endl;
		for(int i = 0; i <_nCompteurs * 2 - 1; i++)
			cout << "  ";
		cout << "v\n";
		_lanceur->lancer( _nCompteurs * 2 - 1 );
	}
	cout << "Round(c0)(" << _terminal->getCompteur() << ", " << _terminal->getCompteur() << ")\n";
	for(int i = 0; i < _nCompteurs; i++)
	{
		cout << "Round(c"<< i+1 << ")(" << _compteurs[i]->getCompteur() << ", " << _terminal->getCompteur() << ")\n";
	}
}

int Planche::getInstances()
{
	return _instances;
}

void Planche::afficher()
{
	for(int i = 0; i <_nCompteurs * 2 - 1; i++)
			cout << "  ";
	cout << "v\n";
}