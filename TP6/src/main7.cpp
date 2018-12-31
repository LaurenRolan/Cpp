/* Author: Lauren Rolan
 * File: main7.cpp
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <ios>

using namespace std;

template <typename T>
bool containsSequence(T beg1, T end1, T beg2, T end2);

template <typename T>
void roundPermutation(T beg, T end);

template <typename T>
void printSequence(T beg, T end);

void part1();
void part2();

int main()
{
	part1();
	part2();
	
	return 0;
}


void part1()
{
	vector<int> v;
	vector<int> u;
	vector<int> w;
	vector<int> z;
	
	
    for(int i = 0; i < 20; i++)
    {
        v.push_back(i);
    }
	for(int i = 0; i < 10; i++)
    {
        u.push_back(i);
    }
	for(int i = 20; i < 50; i++)
    {
        z.push_back(i);
    }
		
	cout << boolalpha;
	cout << containsSequence(u.begin(), u.end(), v.begin(), v.end()) << endl;
	cout << containsSequence(w.begin(), w.end(), v.begin(), v.end()) << endl;
	cout << containsSequence(z.begin(), z.end(), v.begin(), v.end()) << endl;
}

void part2()
{
	vector<int> v;
	for(int i = 5; i < 20; i++)
    {
        v.push_back(i);
    }
	
	cout << "Sans permutation: \n";
	printSequence(v.begin(), v.end());
	
	cout << "Avec permutation: \n";
	roundPermutation(v.begin(), v.end());
	printSequence(v.begin(), v.end());
	roundPermutation(v.begin(), v.end());
	printSequence(v.begin(), v.end());
	roundPermutation(v.begin(), v.end());
	printSequence(v.begin(), v.end());
	roundPermutation(v.begin() + 3, v.begin() + 6);
	printSequence(v.begin(), v.end());
	
}


template <typename T>
bool containsSequence(T beg1, T end1, T beg2, T end2)
{
	while ( beg1 != end1 && beg2 != end2 ) {
		if(*beg1 == *beg2)
		{
			++beg1;
		}
		++beg2;
	}
	return (beg1 == end1);
}

template <typename T>
void roundPermutation(T beg, T end)
{
	typename iterator_traits<T>::value_type last = *beg;
	
	T init = beg;
	T current = init;
	current++;
	
	while(current != end)
	{
		*init = *current;
		++current;
		++init;
	}
	*init = last;
}

template <typename T>
void printSequence(T beg, T end)
{
	while(beg != end)
	{
		cout << *beg << " ";
		++beg;
	}
	cout << endl;
}