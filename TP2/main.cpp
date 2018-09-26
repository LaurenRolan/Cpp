/* Author: Lauren Sampaio
 * File: main.cpp
 */
 #include "Complex.h"
#include <iostream>

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
	Complex a(1.1, 2);
	a.show();

	Complex b(2, 4.4);
	b.show();

	Complex c(sum(a, b));
	c.show();

	c = sum(a, b);
	c.show();

	a = difference(a, b);
	a.show();

	b = product(a, c);
	b.show();

	b.exchange();
	b.show();

	b = 3.4;
	b.show();

	b = a + 5;
	b.show();
}

void part2();
void part3();