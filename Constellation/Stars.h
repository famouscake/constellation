#pragma once

#include <vector>
#include "Point.h"

class Stars
{
public:
	Stars();
	~Stars();

	static std::vector<Point> getStars(std::vector<std::vector<Point>> A);
	static void DFS_Visit(int, int, int);

	static void printB(int **);

	static int **B;
	static int N, M;
};

