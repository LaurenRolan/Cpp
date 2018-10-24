/* Author: Lauren Sampaio
 * File: Clou.h
 */

#include <iostream>
#include "Obstacle.h"
using namespace std;

class Clou : public Obstacle {
private:
  Obstacle * _prochaine[2];
  bool _sontFils[2];
public:
	Clou( const Obstacle *gauche, const Obstacle *droite );
	~Clou();
	bool filsGauche() { return _sontFils[0]; }
  	bool filsDroite() { return _sontFils[1]; }
  	Obstacle * getGauche() { return _prochaine[0]; };
  	Obstacle * getDroite() { return _prochaine[1]; };
};
