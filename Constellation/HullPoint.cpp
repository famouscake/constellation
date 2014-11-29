#include "stdafx.h"
#include "HullPoint.h"


HullPoint::HullPoint(Point _point) : point(_point), next(this), prev(this)
{

}


HullPoint::~HullPoint()
{
}
