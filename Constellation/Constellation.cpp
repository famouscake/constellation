// Constellation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
using namespace cimg_library;


int _tmain(int argc, _TCHAR* argv[])
{

	vector<vector<Point>> A = CImgWrapper::readFile("stars1.bmp");//].printColor();

	vector<Point> stars = Stars::getStars(A);


	ConvexHullAlgorithm::maxThreads = std::thread::hardware_concurrency();
	sort(stars.begin(), stars.end(), [](const Point &a,const Point &b){ return a.x < b.x; });

	cout << endl;
	for (Point x : stars){
		cout << (x).x << ", " << (x).y << endl;// " " << x->index << endl;
		//(*x).printColor();
		//cout << endl;
	}

	ConvexHullAlgorithm charlie(stars, 0, stars.size()-1);
	thread t(&ConvexHullAlgorithm::Start, &charlie);
	t.join();


	cout << endl;

	for (Point x : charlie.OutputPoints) {
		cout << ((x).x) << ", " << -((x).y) << endl;
	}


	std::cout << "Press any key to continue ... ";
	std::cin.get();

	return 0;
}

