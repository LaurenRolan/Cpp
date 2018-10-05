/* Author: Lauren Sampaio
 * File: Matrix.cpp
 */
#include "Matrix.h"
#include <cmath>
#include <cstring>
#include <iostream>

Matrix::Matrix()
{
	std::cout << "+++Matrix()" << std::endl;
	this->lines = 0;
	this->cols = 0;
	this->data = nullptr;
}


Matrix::Matrix( int lines, int cols )
{
	this->lines = lines;
	this->cols = cols;
	this->data = (double*) malloc(sizeof(double) * (lines * cols)); 	
	std::cout << "+++Matrix(" << lines << ", " << cols << ")" << std::endl;
	std::cout << "\tthis <= " << this << "\t lines <= " << &lines << "\t cols <= " << &cols << std::endl;	
}

Matrix::Matrix( const Matrix & other)
{
	this->lines = other.lines;
	this->cols = other.cols;
	if(other.data)
		memcpy(this->data, other.data, sizeof(double) * other.lines * other.cols);
	else
		this->data = nullptr;
	std::cout << "rrrMatrix(" << this->lines << ", " << this->cols << ")" << std::endl;
	std::cout << "\tthis <= " << this << "\t other <= " << &other << std::endl;
}

Matrix::Matrix( Matrix && other)
{
	this->lines = other.lines;
	this->cols = other.cols;
	memcpy(this->data, other.data, lines * cols);
	other.data = nullptr;
	std::cout << "dddMatrix(" << this->lines << ", " << this->cols << ")" << std::endl;
	std::cout << "\tthis <= " << this << "\t other <= " << &other << std::endl;
}

Matrix::~Matrix()
{
	std::cout << "---Matrix(" << this->lines << ", " << this->cols << ")" << std::endl;
	if(this->data)
		delete[] this->data;
}

int Matrix::getLines() { return this->lines; }

int Matrix::getCols() { return this->cols; }


Matrix & Matrix::operator=(const Matrix & other)
{
	std::cout << "Lerreur est ici\n";
	if ( this == &other )
	{
		std::cout << "op=Matrix(" << this->lines << ", " << this->cols << ")" << std::endl;
		std::cout << "\tthis <= " << this << "\t other <= " << &other << std::endl;
		return *this;
	}
	else
	{
		std::cout << "Lerreur est ici\n";
		delete[] this->data;
		this->lines = other.lines;
		this->cols = other.cols;
		if(other.data)
			memcpy(this->data, other.data, sizeof(double) * other.lines * other.cols);
		else
			this->data = nullptr;
	}
	std::cout << "op=Matrix(" << this->lines << ", " << this->cols << ")" << std::endl;
	std::cout << "\tthis <= " << this << "\t other <= " << &other << std::endl;
	return *this;
}


Matrix & Matrix::operator=( Matrix && other)
{
	if ( this == &other )
	{
		std::cout << "op=Matrix(" << this->lines << ", " << this->cols << ")" << std::endl;
		std::cout << "\tthis <= " << this << "\t other <= " << &other << std::endl;
		return *this;
	}
	else
	{
		this->lines = other.lines;
		this->cols = other.cols;
		this->data = std::move(other.data);
		other.data = nullptr;
	}
	std::cout << "op=Matrix(" << this->lines << ", " << this->cols << ")" << std::endl;
	std::cout << "\tthis <= " << this << "\t other <= " << &other << std::endl;
	return *this;
}


Matrix Matrix::operator+(const Matrix & other)
{
	if(this->lines != other.lines || this->cols != other.cols)
		throw "Invalid size of matrices.\n";

	int m = this->lines, n = other.cols;
	Matrix result(m, n);

	for( int l = 0; l < m; l++ )
		for( int c = 0; c < n; c++ )
		{
			result.data[l*n+c] = this->data[l*n+c] + other.data[l*n+c];
		}
	std::cout << "op+Matrix()\n";
	return result;
}

Matrix Matrix::operator-(const Matrix & other)
{
	if(this->lines != other.lines || this->cols != other.cols)
		throw "Invalid size of matrices.\n";
	int m = this->lines, n = other.cols;
	Matrix result(m, n);

	for( int l = 0; l < m; l++ )
		for( int c = 0; c < n; c++ )
			result.data[l*n+c] = this->data[l*n+c] - other.data[l*n+c];

	return result;	
}

Matrix Matrix::operator*(const Matrix & other)
{
	if(this->cols != other.lines)
		throw "Invalid size of matrices.\n";
	int m = this->lines, n = other.cols;
	Matrix result(m, n);

	for( int l = 0; l < m; l++ )
	{
		for(int col = 0; col < n; col++)
		{	
			int cell = 0;
			for( int c = 0; c < n; c++ )
			{
				cell += this->data[l*n+c] * other.data[l*n+c];
			}
			result.data[l*n+col] = cell;
		}	
	}
	return result;
}

void Matrix::show()
{
	for(int l = 0; l < this->lines; l++)
	{
		std::cout << "[ ";
		for(int c = 0; c < this->cols; c++)
			std::cout << this->data[l * this->cols + c] << " ";
		std::cout << "]\n";
	}
}

void Matrix::fillWith(int value)
{
	for(int l = 0; l < this->lines; l++)
		for(int c = 0; c < this->cols; c++)
			this->data[l * this->cols + c] = value;
}