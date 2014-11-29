#pragma once

#include "Point.h"

class HullPoint
{
public:
	Point point;

	HullPoint *next;
	HullPoint *prev;

	HullPoint(Point);

	static double Distance(HullPoint, HullPoint);
	~HullPoint();
};

