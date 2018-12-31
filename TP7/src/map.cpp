/* Author: Lauren Rolan
 * File: map.cpp
 */

#include "map.h"
#include "City.h"

int height_in_pixels(BoundingBox bb, int w)
{
	double height_bb = bb.max_latitude - bb.min_latitude;
	double width_bb = bb.max_longitude - bb.min_longitude;
	double ratio = width_bb / height_bb;
	return (int) (w / ratio);
}

convertion coordinates_to_pixels(BoundingBox bb, pair<int, int> taille)
{
	//TODO
}