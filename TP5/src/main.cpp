/* Author: Lauren Sampaio
 * File: main.cpp
 */
#include "Set.h"
#include "SetOfDouble.h"
#include <iostream>
#include <cmath>
using namespace std;

void part1();
void part2();

int main()
{
	int choice = 0;
	std::cout << "Choisissez la partie (1, 2)\n";
	std::cin >> choice;
	
	switch(choice)
	{
		case 1: part1(); break;
		case 2: part2(); break; 
		default: break;
	}
}

void part1()
{
	cout << "------SetOfDouble Functions------\n";
	cout << "---Check if empty\n";
	SetOfDouble empty;
	cout << "Empty? " << empty.isEmpty() << endl;
	
	cout << "---Check insert\n";
	SetOfDouble set1(10);
	set1.insert(9);
	set1.insert(5);
	set1.insert(11);
	set1.flush(cout);
	cout << "Contains 9: " << set1.contains(9) << endl;
	cout << "Contains 6: " << set1.contains(6) << endl;
	
	cout << "---Check subset\n";
	SetOfDouble set2(9);
	set2.insert(10);
	set2.flush(cout);
	cout << "Set2 is subset of Set1? " << set2.isSubsetOf(set1) << endl;
	SetOfDouble set3(11);
	set3.flush(cout);
	cout << "Set3 is subset of Set1? " << set3.isSubsetOf(set1) << endl;
	SetOfDouble set4(5);
	set4.flush(cout);
	cout << "Set4 is subset of Set1? " << set4.isSubsetOf(set1) << endl;
	cout << "Set2 is subset of Set4? " << set2.isSubsetOf(set4) << endl;
	
	cout << "---Check remove\n";
	cout << "Removing 5 from Set1\n";
	set1.remove(5);
	set1.flush(cout);
	cout << "Removing 5 from Set1 (must return error)\n";
	set1.remove(5);
	set1.flush(cout);
	cout << "Removing 10 from Set1\n";
	set1.remove(10);
	set1.flush(cout);
	cout << "Removing 11 from Set1\n";
	set1.remove(11);
	set1.flush(cout);
	cout << "Removing 9 from Set1\n";
	set1.remove(9);
	set1.flush(cout);
	cout << "Removing 9 from Set1 (must return error)\n";
	set1.remove(9);
	set1.flush(cout);
	
	cout << "---Check insert subset\n";
	cout << "Set3 ";
	set3.flush(cout);
	cout << "Inserting Set2 in Set3\n";
	set2.insertInto(set3);
	cout << "Set2 ";
	set2.flush(cout);
	cout << "Set3 ";
	set3.flush(cout);
	
	cout << "---Check remove subset\n";
	cout << "Set2 ";
	set2.flush(cout);
	cout << "Set3 ";
	set3.flush(cout);
	cout << "Removing Set2 from Set3\n";
	set2.removeFrom(set3);
	cout << "Set2 ";
	set2.flush(cout);
	cout << "Set3 ";
	set3.flush(cout);
	
	cout << "---Check operator=\n";
	cout << "Set2 = Set3\n";
	set2 = set3;
	set2.flush(cout);
	cout << " = ";
	set3.flush(cout);
	cout << "Set3 = Set1\n";
	set3 = set1;
	set3.flush(cout);
	cout << " = ";
	set1.flush(cout);
	cout << "Set1 = Set2\n";
	set1 = set2;
	set1.flush(cout);
	cout << " = ";
	set2.flush(cout);
	
	cout << "---Check recopie\n";
	SetOfDouble set5(set4);
	set5.flush(cout);
	
}

void part2()
{
	SetOfDouble set1;
	set1.insert(1);
	set1.insert(2);
	set1.insert(3);
	SetOfDouble set11;
	set11.insert(1);
	set11.insert(2);
	set11.insert(3);
	SetOfDouble set2;
	set2.insert(4);
	set2.insert(5);
	set2.insert(6);
	SetOfDouble set3;
	set3.insert(3);
	set3.insert(4);
	cout << "------Extra Functions------\n";
	cout << "---Check equals and ==\n";
	if(equals(set1, set3))
	{
		cout << "Will never happen.\n";
	}
	if(set3 == set3)
	{
		cout << "Set3 is equals to Set3\n";
	}
	if(equals(set1, set11))
	{
		cout << "Set1 == Set11\n";
	}
	cout << "---Check > and <\n";
	if(set1 > set3)
	{
		cout << "Set1 is bigger than Set3\n";
	}
	if(set3 < set2)
	{
		cout << "Set2 is bigger than Set3\n";
	}
	
}
