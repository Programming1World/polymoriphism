#ifndef TRIANGLE_H
#define TRIANGLE_H
#include"Shape.hpp"
class Triangle :public Shape
{
public:
	Triangle(const int& side);
	double getSurfaceArea();
	double get3DVolume(const double& depth);



};
//#include"Shape.cpp"
//#include"Triangle.cpp"
#endif
