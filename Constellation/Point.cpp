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

double Point::distance(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
