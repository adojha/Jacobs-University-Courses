/*
CH-230-A
a12p6.cpp
Aditya Ojha
ad.ojha@jacobs-university.de
*/
#ifndef _CIRCLE_H
#define _CIRCLE_H
#include "Area.h"

/*public and private properties for circle class*/
class Circle : public Area {
	public:
		Circle(const char *n, double a);
		~Circle();
		double calcArea() const;
		/*added for calculation of Perimeter*/
		double calcPerimeter() const;
	private:
		double radius;
};



#endif
