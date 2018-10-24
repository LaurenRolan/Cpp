/* Author: Lauren Sampaio
 * File: Compteur.h
 */

#include <iostream>
#include "Obstacle.h"

using namespace std;

class Compteur : public Obstacle {
private:
  Obstacle * _prochaine;
  int _compteur;
  bool _estPere;
public:
	Compteur() { _compteur = 0; };
	Compteur(const Obstacle *prochaine);
	void incCompteur() { _compteur++; }
	int getCompteur() { return _compteur; }
};
