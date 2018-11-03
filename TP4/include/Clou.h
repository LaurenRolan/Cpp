/* Author: Lauren Sampaio
 * File: Clou.h
 */
#ifndef CLOU_H
#define CLOU_H

#include <iostream>
#include "Obstacle.h"
using namespace std;

class Clou : public Obstacle {

public:
	Clou( Obstacle *gauche, Obstacle *droite );
	Clou( );
	~Clou( ) override;
    void recoitPalet( int place );
};

#endif