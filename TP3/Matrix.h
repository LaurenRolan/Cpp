/* Author: Lauren Sampaio
 * File: Matrix.h
 */

class Matrix {
private:
	int _lines;
	int _cols;
	double * _data;

public:
	Matrix(); //Constr. par default
	Matrix( int lines, int cols );	//
	Matrix( const Matrix & other);  // Recopie
	Matrix( Matrix && other);  // Deplacement
	~Matrix();

	Matrix & operator=( const Matrix & other);
	Matrix & operator=( Matrix && other);

	Matrix operator+( const Matrix & other);
	Matrix operator-( const Matrix & other);
	Matrix operator*( const Matrix & other);

	double operator()( const int & i, const int & j ) const;
	double & operator()( const int & i, const int & j );

	int getCols();
	int getLines();

	//Dummy functions
	void show();
	void fillWith(int value);
	void fillOrder();
};

Matrix transpose (Matrix matrix);  // Est ce const?
Matrix inverse (Matrix matrix);
double modulus (Matrix matrix);