/* Author: Lauren Sampaio
 * File: main.cpp
 */
 #include "Matrix.h"
#include <iostream>
#include <cmath>

void part1();
void part2();
void part3();

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
	empty.show();

	Matrix square(3, 3);
	square.fillWith(3);
	square.show();
	
	Matrix copied = square;
	copied.show();
	
	empty = copied + square;
	empty.show();

}

void part2()
{

}

void part3()
{
	
}
