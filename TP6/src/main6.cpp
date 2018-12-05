/* Author: Lauren Rolan
 * File: main6.cpp
 */

#include <iostream>
#include <map>

using namespace std;

typedef map<pair<int,int>, double> Tableau;

class Array : Tableau
{
public:
    double operator()(const int row, const int col);

};

void question61();
void question62();
void question63();


int main()
{

    /* Question 6.1 -- Ordre lexicographique */
    cout << "Question 6.1\n";
    question61();

    /* Question 6.2 --  l'operateur []*/
    cout << "Question 6.2\n";
    question62();



    return 0;
}


void question61()
{

    if(make_pair(1, 10) < make_pair(2, 1))
    {
        cout << "(1, 10) < (2, 1)" << endl;
    }
    if(make_pair(0, 0) < make_pair(0, 10))
    {
        cout << "(0, 0) < (0, 10)" << endl;
    }
    if(make_pair(0, 0) < make_pair(0, 0))
    {
        cout << "(0, 0) < (0, 0)" << endl;
    }
    if(make_pair(1, 9.0) < make_pair(1, 8.5))
    {
        cout << "(1, 9.0) < (1, 8.5)" << endl;
    }
    if(make_pair(0, 0) != make_pair(0, 8))
    {
        cout << "(0, 0) != (0, 8)" << endl;
    }
    if(make_pair(0, 5) > make_pair(0, 5))
    {
        cout << "(0, 5) > (0, 5)" << endl;
    }
    if(make_pair(0, 5) < make_pair(0, 5))
    {
        cout << "(0, 5) < (0, 5)" << endl;
    }
    if(make_pair(0, 5) == make_pair(0, 5))
    {
        cout << "(0, 5) == (0, 5)" << endl;
    }
    if(make_pair("pomme", 10) > make_pair("tomate", 40))
    {
        cout << "(pomme, 10) > (tomate, 40)" << endl;
    }


}

void question62()
{
    map<int, double> tab;
    tab[10] = 5.0;
    tab[5] = 2.5;
    if(tab[0] == 0)
    {
        cout << tab.size() << endl;
    }
    if(tab[3] == 0)
    {
        cout << tab.size() << endl;
    }
}

void question63()
{
    Array<Tableau>
}
