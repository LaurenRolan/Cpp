 /* Author: Lauren Sampaio
 * File: Matrix.cpp
 */
#include "Matrix.h"
#include "MatrixExceptions.h"
#include <cmath>
#include <cstring>

//Dummy functions
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

void Matrix::fillRandom()
{
    for(int l = 0; l < _lines; l++)
		for(int c = 0; c < _cols; c++)
			_data[l * _cols + c] = rand() % 100;
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

int Matrix::getLines() const { return _lines; }

int Matrix::getCols() const { return _cols; }


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
		cout << "do=Matrix(" << _lines << ", " << _cols << ")" << endl;
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
	cout << "do=Matrix(" << _lines << ", " << _cols << ")" << endl;
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

 Matrix Matrix::operator-( ) const
 {
     for( int l = 0; l < _lines; l++ )
		for( int c = 0; c < _cols; c++ )
			_data[l*_cols+c] = -_data[l*_cols+c];
     return *this;
 }

Matrix Matrix::operator*(const Matrix & other)
{
	if(_cols != other._lines)
		throw "Invalid size of matrices.\n";
	int m = _lines, n = other._cols;
	Matrix result(m, n);

	for( int l = 0; l < m; l++ )
		for(int col = 0; col < n; col++)
		{	
			int cell = 0;
			for( int c = 0; c < n; c++ )
				cell += _data[l*n+c] * other._data[l*n+c];
			result._data[l*n+col] = cell;
		}	
	return result;
}

Matrix Matrix::operator*( const double & value )
{
    for( int l = 0; l < _lines; l++ )
        for( int c = 0; c < _cols; c++ )
            _data[l * _cols + c] *= value;
    return *this;
}

double & Matrix::operator()( const int & i, const int & j ) const
{ return _data[i * _cols + j]; }

 double & Matrix::operator[]( const int & index) const
 {
     if(index >= _cols)
         throw "Invalid index\n";
     return _data[index];
 }
double * Matrix::operator[]( const int & row)
{
    if(row >= _lines)
        throw "Invalid index.\n";
    return &_data[row * _cols];
}

ostream & operator<<( ostream &os, const Matrix &matrix )
{
    for(int l = 0; l < matrix.getLines(); l++)
	{
		os << "[ ";
		for(int c = 0; c < matrix.getCols(); c++)
			os << matrix(l, c) << " ";
		os << "]\n";
	}
    return os;
}
istream & operator>>( istream &is, const Matrix &matrix )
{
    for(int l = 0; l < matrix.getLines(); l++)
		for(int c = 0; c < matrix.getCols(); c++)
			is >> matrix(l, c);
    return is;
}

Matrix Matrix::minorMatrix(const int & row, const int & col)
{
    Matrix min(_lines-1, _cols - 1);
    int cc = 0;
    int lc = 0;
    for(int l = 0; l < _lines; l++)
        for(int c=0; c < _cols; c++)
        {
            if(c != col && l != row)
            {
                min(lc, cc) = _data[l * _cols + c];
                cc++;
                if(cc==_cols-1)
                {
                    lc++;
                    cc = 0;
                }
            }
        }
    cout << min;
    return min;
}

Matrix Matrix::transpose ()
{
	Matrix trans(_cols, _lines);
	for( int l = 0; l < _lines; l++ )
		for ( int c = 0; c < _cols; c++ )
			trans(c, l) = _data[l * _cols + c];
	return trans;
}

double Matrix::cofactor(const int & row, const int & column)
{
    
}

Matrix Matrix::comatrix()
{
    Matrix co(_cols, _lines);
	for( int l = 0; l < _lines; l++ )
		for ( int c = 0; c < _cols; c++ )
			co(c, l) = cofactor(l, c);
	return co;
}

Matrix Matrix::inverse()
{
    if(_lines != _cols)
        throw InversionException();
	double det = determinant();
    if(det == 0)
        throw DeterminantException();
    
	return comatrix().transpose() * (1 / det);
}

double Matrix::determinant()
{
    if(_lines != _cols)
        throw "Must be square matrix.\n";
    if(_lines == 1)
        return _data[0];
    if(_lines == 2)
        return _data[0]*_data[3] - _data[1]*_data[2];
    double det = 0;
    for(int p = 0; p < _cols; p++)
    {
        Matrix current = minorMatrix(0, p);
        if(p%2 == 0)
            det += current.determinant();
        else
            det -= current.determinant();
    }
	return det;
}