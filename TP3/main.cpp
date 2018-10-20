/* Author: Lauren Sampaio
 * File: main.cpp
 */
 #include "Matrix.h"
#include <iostream>
#include <cmath>
using namespace std;

void part1();
void part2();
void part3();
void part4();
void part5();
void foo(Matrix);

int main()
{
	int choice = 0;
	std::cout << "Choisissez la partie (1, 2, 3, 4 ou 5)\n";
	std::cin >> choice;
	
	switch(choice)
	{
		case 1: part1(); break;
		case 2: part2(); break;
		case 3: part3(); break;
		case 4: part4(); break;
		case 5: part5(); break;        
		default: break;
	}
}

void part1()
{
	Matrix empty;
	cout << empty;

	
	Matrix square(3, 3);
	square.fillWith(3);
	cout << square;
    
	Matrix copied = square;
	cout << copied;
	
	empty = copied + square;
	cout << empty;
    
    cout << "Minus\n";
    empty = -square;
    cout << empty;
    
    empty = empty * -1;
    cout << empty;
    
    Matrix small(2, 2);
    cin >> small;
    cout << small;
    
    Matrix four(4, 4);
	four.fillOrder();
	cout << four;
	cout << four(3, 3) << endl;

	Matrix trans = four.transpose();
	cout << trans;

	Matrix notSquare(5, 2);
	notSquare.fillOrder();
	cout << notSquare.transpose();
}

void part2()
{
	Matrix a, b, c;
    Matrix d = a * b;
    c = a * b;
    foo(c*c);
}

void part3()
{
	Matrix square(3,3);
    square(0,0) = 1;
    square(1,1) = 2;
    square(2,2) = 3;
    cout << square;
    cout << square.determinant();
    cout << square.inverse();
}


void part4()
{
    
}
void part5()
{
    
}

void foo(Matrix)
{}