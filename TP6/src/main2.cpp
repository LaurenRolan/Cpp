/* Author: Lauren Rolan
 * File: main2.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

int main(int, char *[])
{
    /* Exercice 2 -- taille et capacite d'un vecteur */
    vector<double> v;
    for(int i = 0; i < 3000; i++)
    {
        v.push_back((double)i);
        cout << "It: " << i << "  Cap: " << v.capacity() << endl;
    }
}
