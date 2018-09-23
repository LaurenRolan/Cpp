/* @file: porte.cpp
   @author: Lauren Sampaio
*/

#include <iostream>
using namespace std;

bool & porte(bool x, bool y)
{
	static bool resultat = x && y;
	bool &ref = resultat;
	return ref;
}

int main()
{
	porte(true,false) = false;
	porte(false,true) = false;
	porte(true,true) = true;
	porte(false,false) = false;
	
	if (porte(true,true)) 
		cout << "OK" << endl;
	else
		cout << porte(true,true);
}