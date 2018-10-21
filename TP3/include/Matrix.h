/* Author: Lauren Sampaio
 * File: Matrix.h
 */

#include <iostream>
using namespace std;

class Matrix {
private:
	int _lines;
	int _cols;
	double * _data;
    static int _counter;
public:
	Matrix(); //Constr. par default
	Matrix( int lines, int cols );	//
	Matrix( const Matrix & other );  // Recopie
	Matrix( Matrix && other );  // Deplacement
	~Matrix();

	Matrix & operator=( const Matrix & other );
	Matrix & operator=( Matrix && other );

	Matrix operator+( const Matrix & other );
	Matrix operator-( const Matrix & other );
    Matrix operator-( ) const;
	Matrix operator*( const Matrix & other );
    Matrix operator*( const double & value );
	
    double & operator[]( const int & index) const;
    double * operator[]( const int & row);
	double & operator()( const int & i, const int & j ) const;

	int getCols() const;
	int getLines() const;
    
    double determinant();
    double cofactor(const int & row, const int & column);
    Matrix minorMatrix(const int & row, const int & column);
    Matrix inverse();
    Matrix comatrix();
    Matrix transpose();
    
    void resetCounter();
    int getCounter();

	//Dummy functions
	void fillWith(int value);
	void fillOrder();
    void fillRandom();
};

ostream & operator<<( ostream &os, const Matrix &matrix );
istream & operator>>( istream &is, const Matrix &matrix );