#pragma once

#include <iostream>

class Point
{
public:
	Point(double, double, double, double, double, int);

	double x, y;
	double r, g, b, a;

	void printColor();

	int index;
	~Point();
};

