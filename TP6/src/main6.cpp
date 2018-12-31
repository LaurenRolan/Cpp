/* Author: Lauren Rolan
 * File: main6.cpp
 */

#include <iostream>
#include <iomanip> 
#include <map>

using namespace std;

typedef map<pair<int,int>, double> Tableau;

class Array : public Tableau
{
private:
	int _maxCol;
public:
	void setMaxCol(const int maxCol);
	int getMaxCol() const;
    double operator()(const int & row, const int & col) ;
	void setValue(const int & row, const int & col, const double & value) ;
};


ostream & operator<<(ostream &os, Array & array)
{
	for(int l = 0; l < array.rbegin()->first.first; l++)
	{
		for(int c = 0; c < array.getMaxCol(); c++)
		{
			os << setw(7);
			os << left;
			os << setprecision(3);
			os << array(l, c) << " ";
		}
		os << endl;
	}
	return os;
}

int Array::getMaxCol() const
{
	return _maxCol;
}

void Array::setMaxCol(const int maxCol)
{
	_maxCol = maxCol;
}

void Array::setValue(const int & row, const int & col, const double & value) 
{
	(*this)[make_pair(row, col)] = value;
}

double Array::operator()(const int & row, const int & col) 
{
	if(this->find( make_pair(row, col) ) != this->end())
	{
		return (*this)[make_pair(row, col)];
	}
	return 0.0;
}

void question61();
void question62();
void question63();


int main()
{

    /* Question 6.1 -- Ordre lexicographique */
    cout << "Question 6.1\n";
    question61();

    /* Question 6.2 --  l'operateur []*/
    cout << "Question 6.2\n";
    question62();

	/* Question 6.3 --  utilisation d'un tableau*/
	cout << "Question 6.3\n";
	question63();

    return 0;
}


void question61()
{

    if(make_pair(1, 10) < make_pair(2, 1))
    {
        cout << "(1, 10) < (2, 1)" << endl;
    }
    if(make_pair(0, 0) < make_pair(0, 10))
    {
        cout << "(0, 0) < (0, 10)" << endl;
    }
    if(make_pair(0, 0) < make_pair(0, 0))
    {
        cout << "(0, 0) < (0, 0)" << endl;
    }
    if(make_pair(1, 9.0) < make_pair(1, 8.5))
    {
        cout << "(1, 9.0) < (1, 8.5)" << endl;
    }
    if(make_pair(0, 0) != make_pair(0, 8))
    {
        cout << "(0, 0) != (0, 8)" << endl;
    }
    if(make_pair(0, 5) > make_pair(0, 5))
    {
        cout << "(0, 5) > (0, 5)" << endl;
    }
    if(make_pair(0, 5) < make_pair(0, 5))
    {
        cout << "(0, 5) < (0, 5)" << endl;
    }
    if(make_pair(0, 5) == make_pair(0, 5))
    {
        cout << "(0, 5) == (0, 5)" << endl;
    }
    if(make_pair("pomme", 10) > make_pair("tomate", 40))
    {
        cout << "(pomme, 10) > (tomate, 40)" << endl;
    }


}

void question62()
{
    map<int, double> tab;
    tab[10] = 5.0;
    tab[5] = 2.5;
    if(tab[0] == 0)
    {
        cout << tab.size() << endl;
    }
    if(tab[3] == 0)
    {
        cout << tab.size() << endl;
    }
}

void question63()
{
    Array array;
	
	array.setValue(0, 1, 4.5);
	array.setValue(0, 1, 6.5);
	array.setValue(1, 1, 5.5);
	array.setValue(2, 1, 4.5);
	array.setValue(3, 1, 6.5);
	array.setValue(0, 2, 4.5);
	array.setValue(0, 3, 6.5);
	array.setValue(1, 2, 5.5);
	array.setValue(2, 5, 4.5);
	array.setValue(3, 6, 6.5);
	
	
	cout << array(0,1) << endl;
	cout << array(2,2) << endl;
	cout << array.size() << endl;
	
	array.setMaxCol(7);
	cout << array;
}
