/* Author: Lauren Sampaio
 * File: Complex.cpp
 */
#include "Complex.h"
#include <cmath>
#include <iostream>

Complex::Complex()
{
	std::cout << "+++Complex()" << std::endl;
	this->re = 0;
	this->im = 0;
}


Complex::Complex( double re, double im )
{
	std::cout << "+++Complex(" << re << ", " << im << ")" << std::endl;
	std::cout << "this <= " << this << "\t re <= " << &re << "\t im <= " << &im << std::endl;
	this->re = re;
	this->im = im;	
}

Complex::Complex( const Complex & other)
{
	this->re = other.re;
	this->im = other.im;
	std::cout << "rrrComplex(" << this->getReal() << ", i*" << this->getImaginary() << ")" << std::endl;
	std::cout << "this <= " << this << "\t other <= " << &other << std::endl;
}

double Complex::getImaginary()
{
	return this->im;	
}

double Complex::getReal()
{
	return this->re;
}

double Complex::getArgument()
{
	double argument;
	argument = sqrt(pow(this->im, 2) + pow(this->re, 2));
	return argument;
}

double Complex::getModule()
{
	double modulus;
	modulus = atan(this->im / this->re);
	return modulus;
}

void Complex::show()
{
	std::cout << this->re << " + i*" << this->im << std::endl; 
}

void Complex::exchange()
{
	double temp;
	temp = this->im;
	this->im = this->re;
	this->re = temp;
}

Complex sum( Complex arg1, Complex arg2 )
{
	double im, re;
	im = arg1.getImaginary() + arg2.getImaginary();
	re = arg1.getReal() + arg2.getReal();
	Complex result(re, im);
	return result;
}

Complex difference( Complex arg1, Complex arg2 )
{
	double im, re;
	im = arg1.getImaginary() - arg2.getImaginary();
	re = arg1.getReal() - arg2.getReal();
	Complex result(re, im);
	return result;
}

Complex product( Complex arg1, Complex arg2 )
{
	double im, re;
	im = (arg1.getImaginary() * arg2.getReal()) + (arg2.getImaginary() * arg1.getReal());
	re = (arg1.getImaginary() * arg2.getImaginary()) - (arg2.getReal() * arg1.getReal());
	Complex result(re, im);
	return result;
}

Complex & Complex::operator=(const Complex & other)
{
	if ( this == &other )
	{
		std::cout << "op=Complex(" << this->getReal() << ", i*" << this->getImaginary() << ")" << std::endl;
		std::cout << "this <= " << this << "\t other <= " << &other << std::endl;
		return *this;
	}
	else
	{
		this->re = other.re;
		this->im = other.im;
	}
	std::cout << "op=Complex(" << this->getReal() << ", i*" << this->getImaginary() << ")" << std::endl;
	std::cout << "this <= " << this << "\t other <= " << &other << std::endl;
	return *this;
}

Complex & Complex::operator=(const double & re)
{
	this->re = re;
	this->im = 0;
	std::cout << "op=Complex(" << this->getReal() << ", i*" << this->getImaginary() << ")" << std::endl;
	std::cout << "this <= " << this << "\t re <= " << &re << std::endl;
	return *this;
}

Complex Complex::operator+(const Complex & other)
{
	return sum(other, *this);
}

Complex Complex::operator-(const Complex & other)
{
	return difference(other, *this);	
}

Complex Complex::operator*(const Complex & other)
{
	return product(other, *this);
}

Complex Complex::operator+(const double & re)
{
	this->re += re;
	return *this;
}

Complex Complex::operator-(const double & re)
{
	this->re -= re;
	return *this;
}

Complex Complex::operator*(const double & re)
{
	this->re *= re;
	return *this;
}

Complex normalized( Complexe complexe )
{
	Complex norm;
	//TODO
}

Complex rotate( Complexe complexe, double angle )
{
	//TODO
}

Complex biggestModule( Complexe arg1, Complexe arg2 )
{
	//TODO
}
