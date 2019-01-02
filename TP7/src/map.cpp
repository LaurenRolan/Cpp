/* Author: Lauren Rolan
 * File: map.cpp
 */

#include "map.h"
#include "City.h"
#include "string_functions.h"

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

drawing draw_village(unsigned char r, unsigned char g, unsigned char b)
{
	return [r, g, b] (const City & city, pair<int, int> size, RGBImage & img, BoundingBox bb) {
		convertion get_coord = coordinates_to_pixels(bb, size);
		pair<int, int> coord = get_coord(city.getCoordonnees_GPS());
		img.drawCircle(coord.first, coord.second, 1, r, g, b);
	};

}

drawing draw_circle(unsigned char r, unsigned char g, unsigned char b, int ray)
{
	return [r,g,b,ray] (const City & c, pair<int, int> p, RGBImage & img, BoundingBox bb) {
		convertion get_coord = coordinates_to_pixels(bb, p);
		pair<int, int> coord = get_coord(c.getCoordonnees_GPS());
		img.drawCircle(coord.first, coord.second, ray, r, g, b);
		img.fillCircle(coord.first, coord.second, ray, r, g, b);
	};
}

drawing draw_department(string name)
{
	return [name] (const City & c, pair<int, int> p, RGBImage & img, BoundingBox bb) {
		drawing draw;
		if(name == c.getNom_commune())
		{
			draw = draw_circle(50, 100, 200, 5);
		} else {
			draw = draw_village(200, 100, 50);
		}
		draw(c, p, img, bb);
	};
}

drawing draw_all_deps( map<int, unsigned int> & colors)
{
	return [colors] (const City & c, pair<int, int> p, RGBImage & img, BoundingBox bb) {
		string department = c.getINSEE().substr(0, 2);
		int dep = stoi(department);
		unsigned int color = colors.at(dep);
		drawing draw = draw_village(color, color % 100, color % 50);
		draw(c, p, img, bb);
	};
}

drawing draw_all_villes()
{
	return [] (const City & c, pair<int, int> p, RGBImage & img, BoundingBox bb)
	{
		vector<string> nom = split(c.getNom_commune(), " ");
		
		//if(isSufix(c.getNom_commune(), "VILLE"))
		for(auto it = nom.begin(); it != nom.end(); it++)
		{
			if(isSufix(*it, "VILLE"))
			{
				drawing draw = draw_village(100, 25, 250);
				draw(c, p, img, bb);
				break;
			}
		}
	};
}

drawing draw_population( pair<int, int> limits )
{
	return [limits] (const City & c, pair<int, int> p, RGBImage & img, BoundingBox bb)
	{
		double population = normalize((double) limits.first, (double) limits.second, stod(c.getPopulation()));
		drawing draw = draw_village(265 * population, 265 - 265 * population, 100);
		draw(c, p, img, bb);
	};
}

void draw_village_vector(RGBImage & img, const vector<City> & cities, bool tight, drawing draw, BoundingBox bb)
{
	if(tight)
	{
		bb = get_bounding_box(cities);
	}
	
	int width = img.width();
	int height = height_in_pixels(bb, width);
	
	img.resize(width, height);
	//img.fill(100);
	
	for(City city : cities)
	{
		draw(city, make_pair(width, height), img, bb);
	}
}