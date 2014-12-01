#pragma once

#include <vector>
#include "Point.h"
#include <algorithm>

class Stars
{
public:
	Stars();
	~Stars();

	static std::vector<Point> getStars(std::vector<std::vector<Point>> A);
	static std::vector<std::vector<Point>> getStars2();
	static void DFS_Visit(int, int, int);
	static void DFS_Visit2(int, int);	

	static void printB(int **);

	static int **B;
	static int *B2;
	static int N, M;


	static std::vector<Point> allStars;
	static std::vector<std::vector<Point>> groupedStars;
};

