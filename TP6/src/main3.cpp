/* Author: Lauren Rolan
 * File: main3.cpp
 */

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

template <typename T>
struct less {
    bool operator()( const T & a, const T & b) const
    {
        return a < b;
    }
};


int main(int argc, char ** argv)
{
    if(argc < 2)
    {
        cout << "Nombre invalide de parametres.\n";
        return 1;
    }

    set<char> counter;
    ifstream file(argv[1]);

    char c;
    while (file.get(c))
    {
        if(c != '\t' && c != ' ' && c != '\n')
        {
            counter.insert(c);
        }
    }

    file.close();

    cout << "Caracteres dans " << argv[1] << endl;
    set<char>::iterator it = counter.begin();
    while(it != counter.end())
    {
        cout << *it << "  ";
        it++;
    }
    cout << endl;
    return 0;
}
