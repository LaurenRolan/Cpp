/* Author: Lauren Sampaio
 * File: Lanceur.h
 */

#include <iostream>
#include "Obstacle.h"
#include "Lanceur.h"
using namespace std;

class Lanceur {
private:
	Obstacle * _premier;
public:
	Lanceur(const Obstacle *premier);
	~Lanceur();
};

