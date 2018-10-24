/* Author: Lauren Sampaio
 * File: main.cpp
 */
#include "Planche.h"
#include <iostream>
#include <cmath>
using namespace std;

void part1();
void part2();
void part3();
void part4();
void foo(Matrix);

int main()
{
	int choice = 0;
	std::cout << "Choisissez la partie (1, 2, 3, 4)\n";
	std::cin >> choice;
	
	switch(choice)
	{
		case 1: part1(); break;
		case 2: part2(); break;
		case 3: part3(); break;
		case 4: part4(); break;    
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
    
    Matrix fourByFour(4,4);
    fourByFour(0,0) = 1;
    fourByFour(0,1) = 2;
    fourByFour(0,2) = 1;
    fourByFour(0,3) = 0;
    fourByFour(1,0) = 0;
    fourByFour(1,1) = 1;
    fourByFour(1,2) = 3;
    fourByFour(1,3) = 3;
    fourByFour(2,0) = 1;
    fourByFour(2,1) = 4;
    fourByFour(2,2) = 6;
    fourByFour(2,3) = 4;
    fourByFour(3,0) = 0;
    fourByFour(3,1) = 0;
    fourByFour(3,2) = 1;
    fourByFour(3,3) = 0;
    cout << fourByFour;
    cout << endl << fourByFour.determinant() << endl;
    cout << fourByFour.inverse();

    cout << "Hacking time!\n";
    double* hack = square[0];
    for(int i = 0; i < 9; i++)
        cout << hack[i] << " ";
    cout << endl;
}


void part4()
{
    for(int size=2; size < 10; size++)
    {
        Matrix square(size, size);
        try{
            square.fillRandom();
            cout << square;
            cout << square.inverse();
            cout << "Counter " << square.getCounter() << endl << endl;
            square.resetCounter();    
        }catch(DeterminantException& e)
        {
            cout << e.what();
            size--;
        }
        
    }
}

void foo(Matrix)
{}