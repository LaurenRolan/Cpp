/* Author: Lauren Sampaio
 * File: Matrix.h
 */

class Matrix {
private:
	int lines;
	int cols;
	double * data;

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

	int getCols();
	int getLines();

	//Dummy functions
	void show();
	void fillWith(int value);
};

