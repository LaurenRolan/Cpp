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

bool in_bounding_box(pair<double, double> coord, BoundingBox bb)
{
	return !(coord.first > bb.max_latitude || coord.first < bb.min_latitude ||
			coord.second > bb.max_longitude || coord.second < bb.min_longitude);
}

double normalize(double max_value, double min_value, double current_value)
{
	return ((current_value - min_value) / (max_value - min_value));
}

convertion coordinates_to_pixels(BoundingBox bb, pair<int, int> taille)
{
	return [bb, taille](pair<double, double> coord) {
		if(in_bounding_box(coord, bb))
		{
			int h_drawing = height_in_pixels(bb, taille.second);
			int w_drawing = taille.second;
			
			double lat_norm = normalize(bb.max_latitude, bb.min_latitude, coord.first);
			double lon_norm = normalize(bb.max_longitude, bb.min_longitude, coord.second);
			
			int x = (int) (w_drawing * lon_norm);
			int y = (int) h_drawing - (h_drawing * lat_norm);
			
			return make_pair(x, y);
		}
		return make_pair(0,0);
	};
}

drawing draw_village(BoundingBox bb)
{
	return [bb] (const City & c, pair<int, int> p, RGBImage & img) {
		convertion get_coord = coordinates_to_pixels(bb, p);
		pair<int, int> coord = get_coord(c.getCoordonnees_GPS());
		img.drawCircle(coord.first, coord.second, 1, 10, 25, 40);
	};

}

drawing draw_circle(unsigned char r, unsigned char g, unsigned char b, int ray)
{
	return [r,g,b,ray] (const City & c, pair<int, int> p, RGBImage & img) {
		img.drawCircle(p.first, p.second, ray, r, g, b);
		img.fillCircle(p.first, p.second, ray, r, g, b);
	};
}

void draw_village_vector(RGBImage & img, const vector<City> & cities, bool tight, drawing draw)
{
	BoundingBox bb;
	if(tight)
	{
		bb.max_latitude =   90;
		bb.min_latitude =  -90;
		bb.max_longitude =  180;
		bb.min_longitude = -180;
	} else {
		bb = get_bounding_box(cities);
	}
	
	for(City city : cities)
	{
		draw(city, make_pair(img.width(), img.height()), img);
	}
}