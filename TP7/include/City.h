/* Author: Lauren Rolan
 * File: City.h
 */
#ifndef CITY_H
#define CITY_H
#include <string>
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

class City {
 private:
    string INSEE;
    string nom_commune;
    string code_postal;
    pair<double, double> coordonnees_GPS;
    string population;
 public:
 	City(City && other);
 	City() = default;
 	City(const City & other) = default;
 	City & operator=(City && other);
 	City & operator=(const City & other);

 	string getINSEE() const;
 	string getNom_commune() const;
 	string getCode_postal() const;
 	string getPopulation() const;
 	pair<double, double> getCoordonnees_GPS() const;

 	void setINSEE(const string & newINSEE);
 	void setNom_commune(const string & newNom_commune);
 	void setCode_postal(const string & newCode_postal);
 	void setPopulation(const string & newPopulation);
 	void setCoordonnees_GPS(const pair<double, double> & newCoordonnees_GPS);
 		
};

ostream & operator<<(ostream & os, const City & city);
void getCities(string fileName, vector<City> & result);

typedef std::function<bool(const City &)> predicat;

predicat isInFrance();
predicat isInMetropole();

vector<City> filter(vector<City> & cities, predicat function);

#endif