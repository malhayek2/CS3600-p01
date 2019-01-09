#pragma once
// defining a cricle header
class Circle {
public:
	// default constructor that takes x, y coords and the change in X and Y. 
	Circle(double x, double y, double radius, double dx, double dy);
	double getX();
	void setX(double x);
	double getY();
	void setY(double y);
	double getRadius();
	void setRadius(double radius);
	double getDeltaX();
	void setDeltaX(double dx);
	double getDeltaY();
	void setDeltaY(double dy);

protected:
	double x;
	double y;
	double deltax;
	double deltay;
	double radius;

};