#include "stdafx.h"
#include "CImgWrapper.h"


CImgWrapper::CImgWrapper()
{
}


CImgWrapper::~CImgWrapper()
{
}


std::vector<std::vector<Point>> CImgWrapper::readFile(char *)
{
	cimg_library::CImg<double> image("test1.bmp");

	std::vector<std::vector<Point>> A;

	for (int i = 0; i < image.width(); i++)
	{
		A.push_back(std::vector<Point>());

		for (int j = 0; j < image.height(); j++) {

			double *red = image.data(i, j, 0, 0);
			double *green = image.data(i, j, 0, 1);
			double *blue = image.data(i, j, 0, 2);

			A.back().push_back(Point(i, j, *red, *green, *blue, i*j + j));
		}
	}

	return A;
}
