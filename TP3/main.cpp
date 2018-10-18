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
void foo(Matrix);

int main()
{
	int choice = 0;
	std::cout << "Choisissez la partie (1, 2 ou 3)\n";
	std::cin >> choice;
	
	switch(choice)
	{
		case 1: part1(); break;
		case 2: part2(); break;
		case 3: part3(); break;
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

	Matrix trans = transpose(four);
	cout << trans;

	Matrix notSquare(5, 2);
	notSquare.fillOrder();
	trans = transpose(notSquare);
	cout << trans;
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
	
}

void foo(Matrix)
{}