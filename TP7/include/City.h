/* Author: Lauren Rolan
 * File: City.h
 */
#ifndef CITY_H
#define CITY_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class City {
 private:
    string INSEE;
    string nom_commune;
    string code_postal;
    string coordonnees_GPS;
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
 	string getCoordonnees_GPS() const;

 	void setINSEE(const string & newINSEE);
 	void setNom_commune(const string & newNom_commune);
 	void setCode_postal(const string & newCode_postal);
 	void setPopulation(const string & newPopulation);
 	void setCoordonnees_GPS(const string & newCoordonnees_GPS);
 		
};

ostream & operator<<(ostream & os, const City & city);
const vector<City> & getCities(string fileName);

#endif