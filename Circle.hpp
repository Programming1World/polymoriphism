#ifndef CIRCLE_H
#define CIRCLE_H
#include"Shape.hpp"
class Circle :public Shape
{
public:
	Circle(const int& diameter);
	double getSurfaceArea();
	double get3DVolume(const double& depth);



};
//#include"Shape.cpp"
//#include"Circle.cpp"
#endif
