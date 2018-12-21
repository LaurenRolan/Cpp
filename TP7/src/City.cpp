/* Author: Lauren Rolan
 * File: City.cpp
 */
#include "City.h"
#include "string_functions.h"
#include <fstream>

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

vector<City> & filter(vector<City> & cities, predicat function)
{
	vector<City> result;
	for(City city : cities)
	{
		if(function(city))
		{
			result.push_back(city);
		}
	}
	return result;
}