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
  Obstacle(Obstacle* gauche, Obstacle* droite);
  virtual ~Obstacle();

  void setGauche( Obstacle *gauche);
  void setDroite( Obstacle *droite);
  Obstacle * getGauche();
  Obstacle * getDroite();
  bool filsGauche(); 
  bool filsDroite();

  bool hasPere();
  void adopte();

  virtual void recoitPalet( int place );
  
  static int getInstances();

protected:
  static int _instances;
  bool _aPere;
  Obstacle * _prochaine[2];
  bool _sontFils[2];
};

#endif