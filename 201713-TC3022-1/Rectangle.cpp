#include "Rectangle.h"



Rectangle::Rectangle()
{
	_width = 1.0;
	_height = 1.0;

}

Rectangle::Rectangle(double w, double h)
{
	_width = w;
	_height = h;

}

double Rectangle::GetWidth()
{

	return _width;
}

void Rectangle::SetWidth(double w)
{
	_width = w;

}

double Rectangle::GetHeight()

{
	return _height;
}

void Rectangle::SetHeight(double h)
{
	_height = h;

}


double Rectangle::GetArea()
{
	double area = _height*_width;
	return area;
}


double Rectangle::GetPerimeter()
{
	double perimeter = (_height*2)+(_width*2);
	return perimeter;
}
