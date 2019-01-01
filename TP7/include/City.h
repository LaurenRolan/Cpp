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

typedef struct {
	double max_latitude  =   90;
	double min_latitude  =  -90;
	double max_longitude =  180;
	double min_longitude = -180;
} BoundingBox;

typedef std::function<bool(const City &)> predicat;

ostream & operator<<(ostream & os, const City & city);
void getCities(string fileName, vector<City> & result);

predicat isInFrance();
predicat isInMetropole();
predicat isInDep(string dep);

string get_department(const vector<City> & cities, string name);
vector<City> * filter(const vector<City> & cities, predicat function);
int get_population(const vector<City> & cities);
BoundingBox get_bounding_box(const vector<City> & cities);

#endif