// Constellation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
using namespace cimg_library;

int _tmain(int argc, _TCHAR* argv[])
{

	vector<vector<Point>> A = CImgWrapper::readFile("test1.bmp");//].printColor();

	A[116][66].printColor();

	std::cout << "Press any key to continue ... ";
	std::cin.get();

	return 0;
}

