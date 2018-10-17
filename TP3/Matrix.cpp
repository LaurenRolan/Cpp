 /* Author: Lauren Sampaio
 * File: Matrix.cpp
 */
#include "Matrix.h"
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

//Dummy functions
void Matrix::show()
{
	for(int l = 0; l < _lines; l++)
	{
		cout << "[ ";
		for(int c = 0; c < _cols; c++)
			cout << _data[l * _cols + c] << " ";
		cout << "]\n";
	}
}

void Matrix::fillWith(int value)
{
	for(int l = 0; l < _lines; l++)
		for(int c = 0; c < _cols; c++)
			_data[l * _cols + c] = value;
}

void Matrix::fillOrder()
{
	for(int l = 0; l < _lines; l++)
		for(int c = 0; c < _cols; c++)
			_data[l * _cols + c] = l * _cols + c;
}

//Main functions
Matrix::Matrix()
{
	cout << "+++Matrix()" << endl;
	_lines = 0;
	_cols = 0;
	_data = nullptr;
}


Matrix::Matrix( int lines, int cols )
{
	_lines = lines;
	_cols = cols;
	_data = new double[ lines * cols]; 	
	cout << "+++Matrix(" << _lines << ", " << _cols << ")" << endl;
	cout << "\tthis <= " << this << "\t lines <= " << &_lines << "\t cols <= " << &cols << endl;	
}

Matrix::Matrix( const Matrix & other)
{
	_lines = other._lines;
	_cols = other._cols;
	_data = new double[ _lines * _cols]; 
	if(other._data)
		memcpy(_data, other._data, sizeof(double) * other._lines * other._cols);
	else
		_data = nullptr;
	cout << "rrrMatrix(" << _lines << ", " << _cols << ")" << endl;
	cout << "\tthis <= " << this << "\t other <= " << &other << endl;
}

Matrix::Matrix( Matrix && other)
{
	_lines = other._lines;
	_cols = other._cols;
	// Copeir le pointeur de other
	_data = other._data;
	other._lines = 0;
	other._cols = 0;
	other._data = nullptr;
	cout << "dddMatrix(" << _lines << ", " << _cols << ")" << endl;
	cout << "\tthis <= " << this << "\t other <= " << &other << endl;
}

Matrix::~Matrix()
{
	cout << "---Matrix(" << _lines << ", " << _cols << ")" << endl;
	delete[] _data;
}

int Matrix::getLines() { return _lines; }

int Matrix::getCols() { return _cols; }


Matrix & Matrix::operator=(const Matrix & other)
{
	if ( this == &other )
	{
		cout << "op=Matrix(" << _lines << ", " << _cols << ")" << endl;
		cout << "\tthis <= " << this << "\t other <= " << &other << endl;
		return *this;
	}
	else
	{
		delete[] _data;
		_lines = other._lines;
		_cols = other._cols;
		_data = new double[ _lines * _cols]; 
		if(other._data)
			memcpy(_data, other._data, sizeof(double) * other._lines * other._cols);
		else
			_data = nullptr;
	}
	cout << "op=Matrix(" << _lines << ", " << _cols << ")" << endl;
	cout << "\tthis <= " << this << "\t other <= " << &other << endl;
	return *this;
}


Matrix & Matrix::operator=( Matrix && other)
{
	if ( this == &other )
	{
		cout << "ro=Matrix(" << _lines << ", " << _cols << ")" << endl;
		cout << "\tthis <= " << this << "\t other <= " << &other << endl;
		return *this;
	}
	else
	{
		_lines = other._lines;
		_cols = other._cols;
		_data = other._data; //copier le pointeur
		other._data = nullptr;
		other._lines = 0;
		other._cols = 0;
	}
	cout << "ro=Matrix(" << _lines << ", " << _cols << ")" << endl;
	cout << "\tthis <= " << this << "\t other <= " << &other << endl;
	return *this;
}


Matrix Matrix::operator+(const Matrix & other)
{
	if(_lines != other._lines || _cols != other._cols)
		throw "Invalid size of matrices.\n";

	int m = _lines, n = other._cols;
	Matrix result(m, n);

	for( int l = 0; l < m; l++ )
		for( int c = 0; c < n; c++ )
			result._data[l*n+c] = _data[l*n+c] + other._data[l*n+c];

	cout << "op+Matrix()\n";
	return result;
}

Matrix Matrix::operator-(const Matrix & other)
{
	if(_lines != other._lines || _cols != other._cols)
		throw "Invalid size of matrices.\n";
	int m = _lines, n = other._cols;
	Matrix result(m, n);

	for( int l = 0; l < m; l++ )
		for( int c = 0; c < n; c++ )
			result._data[l*n+c] = _data[l*n+c] - other._data[l*n+c];

	return result;	
}

Matrix Matrix::operator*(const Matrix & other)
{
	if(_cols != other._lines)
		throw "Invalid size of matrices.\n";
	int m = _lines, n = other._cols;
	Matrix result(m, n);

	for( int l = 0; l < m; l++ )
	{
		for(int col = 0; col < n; col++)
		{	
			int cell = 0;
			for( int c = 0; c < n; c++ )
				cell += _data[l*n+c] * other._data[l*n+c];
			result._data[l*n+col] = cell;
		}	
	}
	return result;
}

double Matrix::operator()( int const & i, int const & j ) const
{ return _data[i * _cols + j]; }

double & Matrix::operator()( const int & i, const int & j )
{ return _data[i * _cols + j]; }


Matrix transpose (Matrix matrix)
{
	Matrix trans(matrix.getCols(), matrix.getLines());
	for( int l = 0; l < matrix.getLines(); l++ )
		for ( int c = 0; c < matrix.getCols(); c++ )
			trans(c, l) = matrix(l, c);
	return trans;
}

Matrix inverse (Matrix matrix)
{
	Matrix inv(matrix.getCols(), matrix.getLines());
	double modulus = modulus(matrix);

	return inv;
}

double modulus(Matrix matrix)
{
	
}