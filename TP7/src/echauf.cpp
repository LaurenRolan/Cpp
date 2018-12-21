/* Author: Lauren Rolan
 * File: string_functions.cpp
 */

#include "string_functions.h"
#include <iostream>
#include <ios>
#include <string>
#include <vector>
#include "City.h"

using namespace std;

void test_prefix();
void test_sufix();
void test_split();
void test_city_creation();
void test_city_file();
vector<int> fill_vector(int min, int max);

int main()
{
    /*
    test_prefix();
    test_sufix();
    test_split();
    test_city_creation();
    */
    test_city_file();
    return 0;
}

void test_city_file()
{
    vector<City> cities;
    std::cout << "Vecteur cree\n";
    getCities("communes.csv", cities);
    predicat isFrench = isInFrance();
    predicat isMetropole = isInMetropole();
    cout << isFrench(cities.front()) << " " << isMetropole(cities.front()) << endl;
    vector<City> metropolitan = filter(cities, isMetropole);
    for(City city : metropolitan)
    {
        cout << city;
    }

}

void test_city_creation()
{
    City a;
    a.setINSEE("testINSEE");
    a.setNom_commune("testCommune");
    a.setCode_postal("00000");
    a.setPopulation("1.000.000");
    a.setCoordonnees_GPS(make_pair(12.36,12.36));

    cout << a.getINSEE() << endl;
    cout << a.getNom_commune() << endl;
    cout << a.getCode_postal() << endl;
    cout << a.getPopulation() << endl;
    cout << a.getCoordonnees_GPS().first << " , " << a.getCoordonnees_GPS().second << endl;
    cout << a;
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
