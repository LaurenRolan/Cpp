/* Author: Lauren Rolan
 * File: main5.cpp
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

template <typename K>
struct less {
    bool operator()( const K & a, const K & b) const
    {
        return a < b;
    }
};

int main()
{
    map<string, int> age;
    age["Abigail"] = 35;
    age["Clovis"] = 25;
    age["ana"] = 15;
    age["Bert"] = 46;
    age["bertie"] = 31;
    map<string, int>::iterator it = age.begin();

    while(it != age.end())
    {
        cout << it->first << "/" << it->second << "  ";
        it++;
    }


    return 0;
}
