/* Author: Lauren Rolan
 * File: main1.cpp
 */

#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <stack>
#include <iterator>

using namespace std;

void fill_and_print_vector()
{
    srand(time(NULL));
    vector<int> v;

    for(int i = 0; i < 20; i++)
    {
        v.push_back(rand() % 100);
    }

    vector<int>::iterator it = v.begin();
    cout << "Vector v = ";
    while(it != v.end())
    {
        cout << *it << "  ";
        it++;
    }
    cout << endl;
}

void fill_and_print_set()
{
    srand(time(NULL));
    set<int> s;

    for(int i = 0; i < 20; i++)
    {
        s.insert(rand() % 100);
    }

    set<int>::iterator it = s.begin();
    cout << "Set s = ";
    while(it != s.end())
    {
        cout << *it << "  ";
        it++;
    }
    cout << endl;

}

void test_stack()
{
    srand(time(NULL));
    stack<int> s;

    for(int i = 0; i < 20; i++)
    {
        s.push(rand() % 100);
    }

    /*
     * La creation d'un iterateur a partir d'un stack genere l'erreur
     * ''iterator is not a member of stack''

    stack<int>::iterator it = s.begin();
    cout << "Stack s = ";
    while(it != s.end())
    {
        cout << *it << "  ";
        it++;
    }

    */
    cout << "Stack s = ";
    for(int i = 0; i < 20; i++)
    {
        cout << s.top() << "  ";
        s.pop();
    }
    cout << endl;

}

int main(int, char *[])
{
    /* Question a) -- creation et parcours d'un vecteur; */
    cout << "Question (a)\n";
    fill_and_print_vector();

    /* Question b) -- modele de la fonction precedente */
    cout << "Question (b)\n";
    fill_and_print_set();

    /* Question c) -- test du stack */
    cout << "Question (c)\n";
    test_stack();

    return 0;
}
