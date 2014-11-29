// Constellation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
using namespace cimg_library;

int **B;
int N, M;

void DFS_Visit(int x, int y, int t ) {
	B[x][y] = t;

	for (int i = -1; i <= 1 ; i++) {
		for (int j = -1; j <= 1; j++) {
			if ((x + i) < N && (x + i) >= 0 && (y + j) < M && (y + j) >= 0 && B[x + i][y + j] == 1) {
				DFS_Visit(x + i, y + j, t);
			}
		}
	}
}

void printB(int **B)
{
	for (int i = 0; i < N; i++) {
		cout << endl;
		for (int j = 0; j < M ;  j++) {
			cout << B[i][j] << " ";
		}
	}

}

int _tmain(int argc, _TCHAR* argv[])
{

	vector<vector<Point>> A = CImgWrapper::readFile("test1.bmp");//].printColor();

	//A[242][137].printColor();


	N = A.size();
	M = A.back().size();


	cout << N << " " << M;

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

	//printB(B);
	
	//vector<Point> C();
	std::vector<Point*> stars;

	int z = 2;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (B[i][j] == 1) {
				DFS_Visit(i, j, z);
				Point *a = new Point(A[i][j].x, A[i][j].y, A[i][j].r, A[i][j].g, A[i][j].b, z-1);
				stars.push_back(a);
				z++;
			}
		}
	}

	cout << endl;
	for (Point *x : stars){
		cout << (*x).x << ", " << (*x).y << " "<< x->index << endl;
		//(*x).printColor();
		cout << endl;
	}

	ConvexHullAlgorithm::maxThreads = std::thread::hardware_concurrency();
	sort(stars.begin(), stars.end(), [](Point *a, Point *b){ return a->x < b->x; });

	ConvexHullAlgorithm charlie(stars, 0, 5);
	thread t(&ConvexHullAlgorithm::Start, &charlie);
	t.join();


	for (Point *x : charlie.OutputPoints) {
		cout << (*x).x << ", " << (*x).y << endl;
	}


	std::cout << "Press any key to continue ... ";
	std::cin.get();

	return 0;
}

