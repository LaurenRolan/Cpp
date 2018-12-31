/* Author: Lauren Rolan
 * File: map.h
 */
#ifndef MAP_H
#define MAP_H
#include "City.h"

typedef std::function<pair<int, int>(pair<double, double>)> convertion;

int height_in_pixels(BoundingBox bb, int w);
convertion coordinates_to_pixels(BoundingBox bb, pair<int, int> taille);

#endif