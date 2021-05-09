#ifndef SHAPE_H
#define SHAPE_H
class Shape{
	int width, height, edges;
	char **arr;
public:
	// getters
	int getEdges();
	int getWidth();
	int getHeight();
	char **getDisplayChars();
	Shape(const int & width, const int & height);

	// Setters
	void setEdges(const int& edges);
	void setWidth(const int& new_width);
	void setHeight(const int &new_height);
	void setDisplayChars(char **display);
	void rotateRight();   //rotate by 90 degrees
	void rotateLeft();   //rotate by 90 degrees
	void reflect(char axis);    //reflect over x or y axis

	// Pure Virtual Methods (no implementation)
	virtual double getSurfaceArea() = 0;
	virtual double get3DVolume(const double& depth) = 0;

	// Display - //iterate through 2D array and print chars
	void display();

};
//#include"Shape.cpp"
#endif
