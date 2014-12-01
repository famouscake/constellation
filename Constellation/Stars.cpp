#include "stdafx.h"
#include "Stars.h"

int ** Stars::B = nullptr;
int Stars::M = 0;
int Stars::N = 0;

Stars::Stars()
{
}


Stars::~Stars()
{
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
