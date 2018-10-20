/* Author: Lauren Sampaio
 * File: MatrixExceptions.h
 */
#include <iostream>
#include <exception>
using namespace std;

class InversionException : public exception {
public:
   const char * what () const throw () {
      return "InversionException: matrice non-carree.\n";
   }
};

class IndexException : public exception {
public:
    const char * what () const throw () {
      return "IndexException: indices invalides.\n";
   }
};

class SizeException : public exception {
public:
    const char * what () const throw () {
      return "SizeException: matrices de tailles incompatibles.\n";
   }
};

class DeterminantException : public exception {
public:
    const char * what () const throw () {
      return "DeterminantException: determinant nul.\n";
   }
};