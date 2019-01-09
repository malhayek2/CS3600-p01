#pragma once
// defining a cricle header
class RGB {
public:
	// default constructor that takes x, y coords and the change in X and Y. 
	RGB(double red, double green, double blue);
	double getRed();
	void setRed(int red);
	double getGreen();
	void setGreen(int green);
	double getBlue();
	void setBlue (int blue);


protected:
	double red;
	double green;
	double blue;


}; 
