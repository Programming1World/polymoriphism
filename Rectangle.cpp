#include<iostream>
#include"Rectangle.hpp"
using namespace std;
Rectangle::Rectangle(const int& width, const int& height) : Shape(width, height)
{
	setEdges(4);

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
			if (row == 0 || row == getHeight() - 1 || col == 0 || col == getWidth()-1)
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
double Rectangle::getSurfaceArea()
{
	double area = this->getHeight()*getWidth();
	return area;
}
double Rectangle::get3DVolume(const double &depth)
{
	double area = getSurfaceArea();
	double volu = area*depth;
	return volu;
}
