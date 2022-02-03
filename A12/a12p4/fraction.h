// simple class for fractions
/*
CH-230-A
a12p4.cpp
Aditya Ojha
ad.ojha@jacobs-university.de
*/
#ifndef FRACTION_H_
#define FRACTION_H_

class Fraction {

private:						// internal implementation is hidden
	int num;					// numerator
	int den;					// denominator

	int gcd(int a, int b);		// calculates the gcd of a and b
	int lcm(int a, int b);

public:
	Fraction();					// empty constructor
	Fraction(int, int = 1); 	// constructor taking values for fractions and
	/*overloading of the << >> * / operators*/
	friend std::ostream& operator <<(std::ostream& out ,const Fraction &f );
	friend std::istream& operator >>(std::istream& in ,Fraction &f );
	Fraction operator<<(Fraction &);	
	Fraction operator*(Fraction);
	Fraction operator/(Fraction);
	
};


#endif /* FRACTION_H_ */
