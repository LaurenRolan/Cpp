/* Author: Lauren Sampaio
 * File: main.cpp
 */
 #include "Complex.h"
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
	Complex a(1.1, 2);
	a.show();

	Complex i(0, 1);
	i.show();

	Complex b(2, 4.4);
	b.show();

	std::cout << "BBBBBBB\n";
	b = product(a, i);
	b.show();

	Complex c(sum(a, b));
	c.show();

	c = sum(a, b);
	c.show();

	a = difference(a, b);
	a.show();

	b.exchange();
	b.show();

	b = 3.4;
	b.show();

	b = a + 5;
	b.show();
}

void part2()
{

}

void part3()
{
	Complex a(2, 5);
	a.show();

	Complex norm(normalized(a));
	norm.show();

	rotate(a, M_PI / 2);
	a.show();

	Complex z2(5, 2);
	Complex z22 = z2 * z2;
	Complex z1;
	z1 = biggestModule(z2, z22);
	z1.show();

	

}
