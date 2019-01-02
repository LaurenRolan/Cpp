/* Author: Lauren Rolan
 * File: City.cpp
 */
#include "City.h"
#include "string_functions.h"
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iterator>

City::City(City && other)
{
	code_postal = move(other.code_postal);
	nom_commune = move(other.nom_commune);
	population = move(other.population);
	coordonnees_GPS = move(other.coordonnees_GPS);
	INSEE = move(other.INSEE);
}

City & City::operator=(City && other)
{
	if(this == &other)
	{
		return *this;
	}
	code_postal = move(other.code_postal);
	nom_commune = move(other.nom_commune);
	population = move(other.population);
	coordonnees_GPS = move(other.coordonnees_GPS);
	INSEE = move(other.INSEE);
	return *this;

}

City & City::operator=(const City & other)
{
	if(this == &other)
	{
		return *this;
	}
	code_postal = other.getCode_postal();
	nom_commune = other.getNom_commune();
	population = other.getPopulation();
	coordonnees_GPS = other.getCoordonnees_GPS();
	INSEE = other.getINSEE();
	return *this;
}

string City::getINSEE() const { return INSEE; }
string City::getNom_commune() const { return nom_commune; }
string City::getCode_postal() const { return code_postal; }
string City::getPopulation() const { return population; }
pair<double, double> City::getCoordonnees_GPS() const { return coordonnees_GPS; }

void City::setINSEE(const string & newINSEE) { INSEE = newINSEE; }
void City::setNom_commune(const string & newNom_commune) { nom_commune = newNom_commune; }
void City::setCode_postal(const string & newCode_postal) { code_postal = newCode_postal; }
void City::setPopulation(const string & newPopulation) { population = newPopulation; }
void City::setCoordonnees_GPS(const pair<double, double> & newCoordonnees_GPS) { coordonnees_GPS = newCoordonnees_GPS; }

ostream & operator<<(ostream & os, const City & city)
{
	os << "-----------------------------------------\n";
	os << "--INSEE: " << city.getINSEE();
	os << "\t--Commune: " << city.getNom_commune();
	os << endl;
	os << "--Population: " << city.getPopulation();
	os << "\t--Coordonnees: " << city.getCoordonnees_GPS().first << " , ";
	os << city.getCoordonnees_GPS().second;
	os << endl;
	os << "--Code postal: " << city.getCode_postal() << endl;
	return os;
}

void getCities(string fileName, std::vector<City> & result)
{
	ifstream fileStream(fileName);
	string line;
	getline(fileStream, line);
	while(getline(fileStream, line))
	{
		vector<string> city_info = split(line, ";");
		City current;
		auto it = city_info.begin();
		current.setINSEE(*it++);
		current.setNom_commune(*it++);
		current.setCode_postal(*it++);
		string coordonnees = *it++;
		vector<string> gps = split(coordonnees, ", ");
		current.setCoordonnees_GPS(make_pair(std::stod(gps.front()), std::stod(gps.back())));
		current.setPopulation(*it++);
		result.push_back(current);
	}
}

predicat isInFrance()
{
	return [](const City &) { return true; };
}

predicat isInMetropole()
{
	return [](const City & c) { 
		return (c.getCoordonnees_GPS().first >= 40 && c.getCoordonnees_GPS().first <= 55); 
	};
}

predicat isInDep(string dep)
{
	return [dep](const City & c){
		if(c.getINSEE().find(dep) == 0)
			return true;
		return false;
	};
}

vector<City> * filter(const vector<City> & cities, predicat function)
{
	vector<City> * result = new vector<City>;
	for_each(cities.begin(), cities.end(), 
							[result, function](const City & c) {
								if(function(c))
								{
									result->push_back(c);
							}});
	return result;
}

int get_population(const vector<City> & cities)
{
	vector<int> population;
    transform(cities.begin(), cities.end(), back_inserter(population),
                   [](const City & c) -> int {
					   if(c.getCoordonnees_GPS().second <= 0)
					   { return stoi(c.getPopulation()); }
					   return 0;
					   });
    int sum = accumulate(population.begin(), population.end(), 0);
	return sum;
}

BoundingBox get_bounding_box(const vector<City> & cities)
{
	BoundingBox bb;
	
	bb.max_latitude = (*max_element(cities.begin(), cities.end(), [](const City & a, const City & b) -> bool
								{return a.getCoordonnees_GPS().first < b.getCoordonnees_GPS().first;})).getCoordonnees_GPS().first;
	bb.min_latitude = (*min_element(cities.begin(), cities.end(), [](const City & a, const City & b) -> bool
								{return a.getCoordonnees_GPS().first < b.getCoordonnees_GPS().first;})).getCoordonnees_GPS().first;
								
	bb.max_longitude = (*max_element(cities.begin(), cities.end(), [](const City & a, const City & b) -> bool
								{return a.getCoordonnees_GPS().second < b.getCoordonnees_GPS().second;})).getCoordonnees_GPS().second;
	bb.min_longitude = (*min_element(cities.begin(), cities.end(), [](const City & a, const City & b) -> bool
								{return a.getCoordonnees_GPS().second < b.getCoordonnees_GPS().second;})).getCoordonnees_GPS().second;

	return bb;
}

string get_department(const vector<City> & cities, string name)
{
	string dep;
	for(City city : cities)
	{
		if(city.getNom_commune() == name)
		{
			dep = city.getINSEE().substr(0, 2);
		}
	}
	return dep;
}

pair<int, int> get_max_min_population(const vector<City> & cities)
{
	int max_value, min_value;
	max_value = stoi((*max_element(cities.begin(), cities.end(), [](const City & a, const City & b) -> bool
								{return stoi(a.getPopulation()) < stoi(b.getPopulation());})).getPopulation());
	min_value = stoi((*min_element(cities.begin(), cities.end(), [](const City & a, const City & b) -> bool
								{return stoi(a.getPopulation()) < stoi(b.getPopulation());})).getPopulation());
	return make_pair(max_value, min_value);
}