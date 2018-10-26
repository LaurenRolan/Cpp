/* Author: Lauren Sampaio
 * File: Obstacle.h
 */
#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>
using namespace std;

class Obstacle {
public:
  Obstacle();
  virtual ~Obstacle();
  void virtual recoitPalet() = 0;

  void setGauche( Obstacle *gauche);
  void setDroite( Obstacle *droite);
  Obstacle * getGauche();
  Obstacle * getDroite();
  bool filsGauche(); 
  bool filsDroite();

  bool hasPere();
  void adopte();

protected:
  bool _aPere;
  Obstacle * _prochaine[2];
  bool _sontFils[2];
};

#endif