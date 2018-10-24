/* Author: Lauren Sampaio
 * File: Obstacle.h
 */
#include <iostream>
using namespace std;

class Obstacle {
private:
  bool _aPere;

public:
  virtual Obstacle();
  virtual ~Obstacle(); //appele le bon destructeur
  void virtual recoitPalet();
  bool aPere() { return _aPere; }
  void adopte() { _aPere = true; }
}
