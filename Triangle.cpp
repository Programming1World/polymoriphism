#include<iostream>
#include"Triangle.hpp"
using namespace std;
Triangle::Triangle(const int& side) :Shape(side, side)
{
	setEdges(3);

	// Populate 2D array with empty chars
	char **arr = new char *[getHeight()];
	for (int row = 0; row < getHeight(); row++)
	{
		arr[row] = new char[getWidth()];
		for (int col = 0; col < getWidth(); col++)
		{
			arr[row][col] = ' ';
		}
	}
	char ascii_counter = 48;
	for (int row = 0; row < getHeight(); row++)
	{
		for (int col = 0; col < getWidth(); col++)
		{
			if (row == getHeight() - 1 || col == 0 ||row== col)
			{
				arr[row][col] = ascii_counter;
				ascii_counter++;
			}
			if (ascii_counter > 126)
			{
				ascii_counter = 48;
			}
		}
	}
	setDisplayChars(arr);

}
double Triangle::getSurfaceArea()
{
	double area = getHeight()*getWidth();
	area = area / 2.0;
	return area;
}
double Triangle::get3DVolume(const double& depth)
{ 
	double area = getSurfaceArea();
	double V = area*depth;
	return V;
}