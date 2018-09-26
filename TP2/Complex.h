/* Author: Lauren Sampaio
 * File: Complex.h
 */

class Complex {
private:
	double im;
	double re;

public:
	Complex();
	Complex( double re, double im );
	Complex( const Complex & other);
	~Complex();

	Complex & operator=(const Complex & other);
	Complex operator+(const Complex & other);
	Complex operator-(const Complex & other);
	Complex operator*(const Complex & other);

	Complex & operator=(const double & re);
	Complex operator+(const double & re);
	Complex operator-(const double & re);
	Complex operator*(const double & re);

	double getImaginary();
	double getReal();

	double getArgument();
	double getModule();

	void show();
	void exchange();
};

Complex sum( Complex arg1, Complex arg2 );
Complex difference( Complex arg1, Complex arg2 );
Complex product( Complex arg1, Complex arg2 );

Complex normalized( Complexe complexe );
Complex rotate( Complexe complexe, double angle );
Complex normalized( Complexe arg1, Complexe arg2 );


