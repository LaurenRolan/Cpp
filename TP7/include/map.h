/* Author: Lauren Rolan
 * File: map.h
 */
#ifndef MAP_H
#define MAP_H
#include "City.h"
#include "RGBImage.h"
#include <vector>
#include <map>

typedef std::function<pair<int, int>(pair<double, double>)> convertion;
typedef std::function<void (const City &, pair<int, int>, RGBImage &, BoundingBox)> drawing;

bool in_bounding_box(pair<double, double> coord, BoundingBox bb);
int height_in_pixels(BoundingBox bb, int w);
double normalize(double max_value, double min_value, double current_value);

convertion coordinates_to_pixels(BoundingBox bb, pair<int, int> taille);
drawing draw_village(unsigned char r, unsigned char g, unsigned char b);
drawing draw_department(string dep);
drawing draw_circle(unsigned char r, unsigned char g, unsigned char b, int ray);
drawing draw_all_deps(map<int, unsigned int> & colors);
drawing draw_all_villes();
drawing draw_population( pair<int, int> limits );

void draw_village_vector(RGBImage & img, const vector<City> & cities, bool tight, drawing draw, BoundingBox bb);

#endif