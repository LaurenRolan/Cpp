/* Author: Lauren Rolan
 * File: main.cpp
 */
#include <iostream>
#include <ios>
#include <string>
#include <vector>

#include "City.h"
#include "string_functions.h"
#include "map.h"
#include "RGBImage.h"

using namespace std;

void test_prefix();
void test_sufix();
void test_split();
void test_city_creation();
void test_city_file();
void test_map_functions();
void france(string outputFile);
void metro(string outputFile);
void single(string outputFile);
void city(string outputFile);

int get_population(const vector<City> & cities);

vector<int> fill_vector(int min, int max);

int main(int argc, char** argv)
{
    /*
    test_prefix();
    test_sufix();
    test_split();
    test_city_creation();
    test_city_file();
	test_map_functions();
	*/
	if(argc > 2)
	{
		string choice = argv[1];
		string outputFile = argv[2];
		
		if(isSufix(choice, "france"))
		{
			france(outputFile);
		} 
		else if(isSufix(choice, "metro"))
		{
			metro(outputFile);
		}
		else if(isSufix(choice, "city"))
		{
			city(outputFile);
		}
		else if(isSufix(choice, "single"))
		{
			single(outputFile);
		}
	}
	else { exit(0); }
    return 0;
}


void france(string outputFile)
{
	vector<City> cities;
    getCities("communes.csv", cities);
	BoundingBox bb = get_bounding_box(cities);
	RGBImage france(300, 300);
	france.fill(100);
	drawing draw = draw_village(bb);
	draw_village_vector(france, cities, false, draw);
	france.savePPM(outputFile);
}
void metro(string outputFile)
{
	vector<City> cities;
    getCities("communes.csv", cities);
	
	predicat get_metropole = isInMetropole();
	vector<City> * commune = filter(cities, get_metropole);
	BoundingBox bb = get_bounding_box((*commune));
	
	RGBImage france(300, 300);
	france.fill(100);
	drawing draw = draw_village(bb);
	draw_village_vector(france, cities, true, draw);
	france.savePPM(outputFile);
}
void single(string outputFile)
{
	
}
void city(string outputFile)
{
	
}

void test_map_functions()
{
	vector<City> cities;
    getCities("communes.csv", cities);
	
	vector<City> * commune = filter(cities, [](const City & c){
							if(c.getINSEE().find("14") == 0)
								return true;
							return false;});
							
	BoundingBox bb = get_bounding_box((*commune));
	
	cout << "Latitude:\t" << bb.max_latitude << "\t...\t" << bb.min_latitude << endl;
	cout << "Longitude:\t" << bb.max_longitude << "\t...\t" << bb.min_longitude << endl;
	
	cout << "Testing get pixels:  ";
	cout << height_in_pixels(bb, 100) << endl;
	
	convertion find_middle = coordinates_to_pixels(bb, make_pair(100, 100));
	pair<int, int> pixel = find_middle(make_pair(49.1015, -0.35321));
	cout << pixel.first << " x " << pixel.second << endl;
	
	RGBImage img(100, 80);
	drawing ville = draw_village(bb);
	ville(commune->front(), make_pair(100, 100), img);
	ville(commune->back(), make_pair(100, 100), img);
	img.savePPM("teste.ppm");
	
	
	BoundingBox bb2 = get_bounding_box(cities);
	RGBImage france(300, 300);
	const int width = france.width();
	const int height = france.height();
	cout << width << "  " << height << endl;
	drawing draw = draw_village(bb2);
	draw_village_vector(france, cities, false, draw);
	france.savePPM("villes.ppm");
}

void test_city_file()
{
    vector<City> cities;
    std::cout << "Vecteur cree\n";
    getCities("communes.csv", cities);
    predicat isFrench = isInFrance();
    predicat isMetropole = isInMetropole();
    cout << isFrench(cities.front()) << " " << isMetropole(cities.front()) << endl;
	vector<City> * metropolitan = filter(cities, isMetropole);
	
	cout << get_population(cities) << endl;
	vector<City> * commune = filter(cities, [](const City & c){
							if(c.getINSEE().find("14") == 0)
								return true;
							return false;});
	for(City c : * commune)
	{
		cout << c << endl;
	}
	BoundingBox bb = get_bounding_box((*commune));
	cout << "Latitude:\t" << bb.max_latitude << "\t...\t" << bb.min_latitude << endl;
	cout << "Longitude:\t" << bb.max_longitude << "\t...\t" << bb.min_longitude << endl;
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
