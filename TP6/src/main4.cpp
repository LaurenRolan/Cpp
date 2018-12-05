/* Author: Lauren Rolan
 * File: main4.cpp
 */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

template <typename T>
vector<T> fill_vector(int min, int max)
{
    vector<T> v;
    for(int i = 0; i < 20; i++)
    {
        v.push_back(rand() % (max-min + 1) + min);
    }
    return v;
}

void fonction_de_tri()
{

    vector<int> v = fill_vector<int>(0, 100);
    priority_queue<int> pq;
    for(int i = 0; i < 20; i++)
    {
        pq.push(v[i]);
    }

    cout << "PQ = ";
    for(int i = 0; i < 20; i++)
    {
        cout << pq.top() << "  ";
        pq.pop();
    }
    cout << endl;
}

template <typename T>
void tri_fonction()
{
    vector<T> v = fill_vector<T>(33, 126);

    priority_queue<T> pq;
    for(int i = 0; i < 20; i++)
    {
        pq.push(v[i]);
    }

    cout << "PQ = ";
    for(int i = 0; i < 20; i++)
    {
        cout << pq.top() << "  ";
        pq.pop();
    }
    cout << endl;
}

template <typename T>
void tri_inverse_fonction()
{
    vector<T> v = fill_vector<T>(33, 126);

    priority_queue<T, vector<T>, greater<T>> pq;
    for(int i = 0; i < 20; i++)
    {
        pq.push(v[i]);
    }

    cout << "PQ = ";
    for(int i = 0; i < 20; i++)
    {
        cout << pq.top() << "  ";
        pq.pop();
    }
    cout << endl;
}

int main()
{
    /* Question a) -- vecteur et file de priorites */
    cout << "Question (a)\n";
    fonction_de_tri();

    /* Question b) -- Modele de fonction parametre */
    cout << "Question (b)\n";
    tri_fonction<char>();

    /* Question c) -- Ordre invertie */
    cout << "Question (c)\n";
    tri_inverse_fonction<int>();
    tri_inverse_fonction<char>();

    return 0;
}
