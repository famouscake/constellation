#include "stdafx.h"
#include "CImgWrapper.h"


CImgWrapper::CImgWrapper()
{
}


CImgWrapper::~CImgWrapper()
{
}


std::vector<std::vector<Point>> CImgWrapper::readFile(char *filename)
{
	cimg_library::CImg<double> image(filename);

	std::vector<std::vector<Point>> A;
	
	for (int i = 0; i < image.height(); i++)
	{
		A.push_back(std::vector<Point>());

		for (int j = 0; j < image.width(); j++) {

			double *red = image.data(j, i, 0, 0);
			double *green = image.data(j, i, 0, 1);
			double *blue = image.data(j, i, 0, 2);

			A.back().push_back(Point(j, i, *red, *green, *blue, i*j + j));
		}
	}

	return A;
}
