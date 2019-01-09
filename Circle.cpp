#include "Circle.h"
// implementing the class itself starting with the contructor
Circle::Circle(double x, double y,double radius ,double dx, double dy) {
	this->x = x;
	this->y = y;
	this->radius = radius;
	this->deltax = dx;
	this->deltay = dy;
}
/*getters and setters */
double Circle::getX()
{
	return x;
}
void Circle::setX(double x)
{
	this->x = x;
}
double Circle::getY()
{
	return y;
}
void Circle::setY(double y)
{
	this->y = y;
}
double Circle::getRadius()
{
	return radius;
}
void Circle::setRadius(double radius)
{
	this->radius = radius;
}
double Circle::getDeltaX()
{
	return deltax;
}
void Circle::setDeltaX(double dx)
{
	this->deltax = dx;
}
double Circle::getDeltaY()
{
	return deltay;
}

void Circle::setDeltaY(double dy)
{
	this->deltay = dy;
}
