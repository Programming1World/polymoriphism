#ifndef RECTANGLE_H
#define RECTANGLE_H
#include"Shape.hpp"
class Rectangle :public Shape
{
public:
	Rectangle(const int& width, const int& height);
    double getSurfaceArea();
	double get3DVolume(const double &depth);

	



};
//#include"Shape.cpp"
//#include"Rectangle.cpp"
#endif
