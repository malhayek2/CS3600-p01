#include "RGB.h"

RGB::RGB(double red, double green, double blue)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
}

double RGB::getRed()
{
	return red;
}

void RGB::setRed(int red)
{
	this->red = red;
}

double RGB::getGreen()
{
	return green;
}

void RGB::setGreen(int green)
{
	this->green = green;
}

double RGB::getBlue()
{
	return blue;
}

void RGB::setBlue(int blue)
{
	this->blue = blue;
}
