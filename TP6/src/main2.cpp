/* Author: Lauren Rolan
 * File: main1.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

int main(int, char *[])
{
    vector<int> v;
    for(int i = 0; i < 3000; i++)
    {
        v.push_back(i);
        cout << "It: " << i << "  Cap: " << v.capacity() << endl;
    }
}
