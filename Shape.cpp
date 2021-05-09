#include<iostream>
#include"Shape.hpp"
using namespace std;
Shape::Shape(const int &width, const int &height)
{
	this->width = width ;
	this->height = height;
	this->edges = 0;
	this->arr = nullptr;

}
int Shape::getEdges()
{
	return this->edges;
}
int Shape::getWidth()
{
	return this->width;
}
int Shape::getHeight()
{
	return this->height;
}
char ** Shape::getDisplayChars()
{
	return arr;
}
void Shape::display()
{
	for (int row = 0; row < getHeight(); row++)
	{
		for (int col = 0; col < getWidth(); col++)
		{
			std::cout << arr[row][col];
			if (col + 1 != getWidth())
			{
				std::cout << " ";

			}
		}
		cout << endl;
	}

}
void Shape::rotateRight()
{
	if (height==width)
	{
		// Traverse each cycle
		for (int i = 0; i < height / 2; i++) {
			for (int j = i; j < width - i - 1; j++) {

				// Swap elements of each cycle
				// in clockwise direction
				int temp = arr[i][j];
				arr[i][j] = arr[height - 1 - j][i];
				arr[height - 1 - j][i] = arr[height - 1 - i][height - 1 - j];
				arr[height - 1 - i][height - 1 - j] = arr[j][height - 1 - i];
				arr[j][height - 1 - i] = temp;
			}
		}

	}
	else
	{
		char ** transposeMatrix = new char*[width];
		for (int i = 0; i < width; i++)
		{
			transposeMatrix[i] = new char[height];
			for (size_t j = 0; j < height; j++)
			{
				transposeMatrix[i][j] = ' ';
			}
		}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				transposeMatrix[j][i] = arr[i][j];
			}
		}
		if (arr != nullptr)
		{
			for (int i = 0; i < height; i++)
			{
				delete arr[i];
			}
			delete arr;
		}
		arr = nullptr;
		int h = this->height;
		this->height = width;
		this->width = h;
		
		setDisplayChars(transposeMatrix);
		this->reflect('y');

	}
	
}//rotate by 90 degrees
void Shape::rotateLeft()
{
	if (height==width)
	{
		for (int i = 0; i < height / 2; i++) {
			for (int j = i; j < width - i - 1; j++) {

				//Store the right value aheightd start the rotatioheight from here
				int temp = arr[i][j];

				// Move values from right to top
				arr[i][j] = arr[j][height - 1 - i];

				// Move values from bottom to right
				arr[j][height - 1 - i] = arr[height - 1 - i][height - 1 - j];

				// Move values from left to bottom
				arr[height - 1 - i][height - 1 - j] = arr[height - 1 - j][i];

				// Assigheight temp to left
				arr[height - 1 - j][i] = temp;
			}
		}

	}
	else
	{
		char ** transposeMatrix = new char*[width];
		for (int i = 0; i < width; i++)
		{
			transposeMatrix[i] = new char[height];
			for (size_t j = 0; j < height; j++)
			{
				transposeMatrix[i][j] = ' ';
			}
		}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				transposeMatrix[j][i] = arr[i][j];
			}
		}
		if (arr != nullptr)
		{
			for (int i = 0; i < height; i++)
			{
				delete arr[i];
			}
			delete arr;
		}
		arr = nullptr;
		int h = this->height;
		this->height = width;
		this->width = h;

		setDisplayChars(transposeMatrix);
		this->reflect('x');

	}
	

}//rotate bj 90 degrees
void Shape::reflect(char axis)
{
	if (axis == 'x' || axis== 'X')
	{
		int newRowheight = height - 1;
		for (int i = 0; i <= height/2; i++)
		{
			for (int j = 0; j <width ; j++)
			{
				char temp = arr[i][j];
				arr[i][j] = arr[newRowheight][j];
				arr[newRowheight][j] = temp;
			}
			newRowheight--;
			if (newRowheight==i)
			{
				break;
			}
		}
	}
	if (axis == 'y' || axis == 'Y')
	{
		int newColumnWidth = width - 1;
		int newWidth = width / 2;
		for (int i = 0; i <newWidth; i++)
		{
			for (int j = 0; j <height; j++)
			{
				char temp = arr[j][i];
				arr[j][i] = arr[j][newColumnWidth];
				arr[j][newColumnWidth] = temp;
			}
			
			newColumnWidth--;
		}
	}



}
void Shape::setDisplayChars(char **display)
{

	if (arr!=nullptr)
	{
		for (int i = 0; i < height; i++)
		{
			delete arr[i];
		}
		delete arr;
	}
	else
	{
		arr = new char*[height];
		for (int i = 0; i < height; i++)
		{
			arr[i] = new char[width];
			for (int j = 0; j < width; j++)
			{
				arr[i][j] = ' ';
			}
		}

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				arr[i][j] = display[i][j];
			}
		}


	}
	
}

void Shape::setEdges(const int& edges)
{ 
	this->edges = edges;
}
void Shape::setWidth(const int& new_width)
{
	this->width = new_width;
}
void Shape::setHeight(const int &new_height)
{
	this->height = new_height;

}