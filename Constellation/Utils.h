#pragma once

#include <vector>
#include "Point.h"
#include <ctime>
#include <iomanip>
class Utils
{
public:
	Utils();
	~Utils();

	static std::vector<Point*> generatePoints(int, int);
};

