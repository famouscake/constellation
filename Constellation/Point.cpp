#include "stdafx.h"
#include "Point.h"

Point::Point(double x, double y, double r, double g, double b)
{
	this->x = x;
	this->y = y;
	this->r = r;
	this->g = g;
	this->b = b;
}

Point::~Point()
{
}

void Point::printColor()
{
	std::cout << "(" << this->r << " , " << this->g << " , " << this->b << ")";
}
