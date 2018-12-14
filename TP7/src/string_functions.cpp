/* Author: Lauren Rolan
 * File: string_functions.cpp
 */

#include "string_functions.h"
#include <iostream>
#include <ios>
#include <string>
#include <vector>

using namespace std;

void test_prefix();
void test_sufix();
void test_split();
vector<int> fill_vector(int min, int max);

int main()
{
    test_prefix();
    test_sufix();
    test_split();

    return 0;
}

void test_prefix()
{
    vector<int> a = fill_vector(0, 30);
    vector<int> b = fill_vector(5, 30);
    vector<int> c = fill_vector(0, 10);
    vector<int> d;

    cout << boolalpha;
    cout << "b est prefix de a? " << isPrefix(b.begin(), b.end(), a.begin(), a.end()) << endl;
    cout << "c est prefix de a? " << isPrefix(c.begin(), c.end(), a.begin(), a.end()) << endl;
    cout << "d est prefix de a? " << isPrefix(d.begin(), d.end(), a.begin(), a.end()) << endl;
}

void test_sufix()
{
    string a = "Hello world";
    string b = "world";
    string c = "the world";
    string d = "";

    cout << boolalpha;
    cout << "b est sufix de a? " << isSufix(b, a) << endl;
    cout << "c est sufix de a? " << isSufix(c, a) << endl;
    cout << "d est sufix de a? " << isSufix(d, a) << endl;
    cout << "a est sufix de a? " << isSufix(a, a) << endl;
}

void test_split()
{
    string hi = "Hello the world\n";
    string hi_sep = " ";
    vector<string> hi_result = split(hi, hi_sep);

    string truc = "Truc##Bidule##Machin";
    string truc_sep = "#Bidule#";
    vector<string> truc_result = split(truc, truc_sep);

    for(string result : hi_result)
    {
        cout << result << "  ";
    }
    cout << endl;

    for(string result : truc_result)
    {
        cout << result << "  ";
    }
    cout << endl;
}

vector<int> fill_vector(int min, int max)
{
     vector<int> v;
     for(int i = min; i < max; i++)
     {
         v.push_back(i);
     }
     return v;
}
