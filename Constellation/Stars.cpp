#include "stdafx.h"
#include "Stars.h"

int ** Stars::B = nullptr;
int *Stars::B2 = nullptr;
int Stars::M = 0;
int Stars::N = 0;

std::vector<std::vector<Point>> Stars::groupedStars = std::vector<std::vector<Point>>();
std::vector<Point> Stars::allStars = std::vector<Point>();

Stars::Stars()
{
}


Stars::~Stars()
{
}


std::vector<std::vector<Point>> Stars::getStars2()
{
	N = allStars.size();
	B2 = new int[N];

	for (int i = 0; i < N; i++)	{
		B2[i] = 0;
	}

	int br = 0;
	for (int i = 0; i < N; i++)	{
		if (B2[i] == 0)
			DFS_Visit2(i, ++br);
	}

	int max = 0;

	for (int i = 0; i < N; i++)	{
		if (B2[i] > B2[max])
			max = i;
	}

	std::vector<std::vector<Point>> A;
	for (int i = 1; i <= B2[max]; i++) {
		A.push_back(std::vector<Point>());

		for (int j = 0; j < N; j++)	{
			if (B2[j] == i)
				A.back().push_back(allStars[j]);
		}
	}



	return A;
}

void Stars::DFS_Visit2(int x, int z) {
	
	B2[x] = z;

	for (int i = 0; i < N; i++)	{
		if ( i!=x && B2[i] == 0 && Point::distance(allStars[i], allStars[x]) < 80)
			DFS_Visit2(i, z);
	}

}


std::vector<Point> Stars::getStars(std::vector<std::vector<Point>> A)
{
	N = A.size();
	M = A.back().size();

	B = new int*[N];
	for (int i = 0; i < N; i++) {
		B[i] = new int[M];
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j].r > 0) {
				B[i][j] = 1;// A[i][j].r;
			}
			else {
				B[i][j] = 0;
			}
		}
	}

	std::vector<Point> stars;

	int z = 2;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (B[i][j] == 1) {
				stars.push_back(A[i][j]);
				DFS_Visit(i, j, z++);				
			}
		}
	}

	allStars = stars;
	return stars;
}


void Stars::DFS_Visit(int x, int y, int t) {
	B[x][y] = t;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if ((x + i) < N && (x + i) >= 0 && (y + j) < M && (y + j) >= 0 && B[x + i][y + j] == 1) {
				DFS_Visit(x + i, y + j, t);
			}
		}
	}
}

void Stars::printB(int **B)
{
	for (int i = 0; i < N; i++) {
		std::cout << std::endl;
		for (int j = 0; j < M; j++) {
			std::cout << B[i][j] << " ";
		}
	}

}
