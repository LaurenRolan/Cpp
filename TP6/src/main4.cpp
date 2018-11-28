/* Author: Lauren Rolan
 * File: main4.cpp
 */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

void fonction_de_tri()
{
    vector<int> v;
    for(int i = 0; i < 20; i++)
    {
        v.push_back(rand() % 100);
    }

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
    vector<T> v;
    for(int i = 0; i < 20; i++)
    {
        v.push_back(rand() % 100);
    }

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
    /* Question a) -- vecteur et file de priorites*/
    cout << "Question (a)\n";
    fonction_de_tri();

    /* Question b) -- */
    cout << "Question (b)\n";
    tri_fonction<char>();

    return 0;
}
