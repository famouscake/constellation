#pragma once

#include <vector>
#include "Point.h"

class CImgWrapper
{
public:
	CImgWrapper();
	~CImgWrapper();

	static std::vector<std::vector<Point>> readFile(char *);

};

