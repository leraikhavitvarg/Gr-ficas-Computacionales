#pragma once
#include <string>

class Rectangle
{


private:

	double _width;
	double _height;


public:
	Rectangle();
	Rectangle(double w, double h);
	double GetWidth();
	void SetWidth(double w);
	double GetHeight();
	void SetHeight(double h);
	double GetArea();
	double GetPerimeter();

};