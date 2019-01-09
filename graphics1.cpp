// OpenGL/GLUT starter kit for Windows 7 and Visual Studio 2010
// Created spring, 2011
//
// This is a starting point for OpenGl applications.
// Add code to the "display" function below, or otherwise
// modify this file to get your desired results.
//
// For the first assignment, add this file to an empty Windows Console project
//		and then compile and run it as is.
// NOTE: You should also have glut.h,
// glut32.dll, and glut32.lib in the directory of your project.
// OR, see GlutDirectories.txt for a better place to put them.

#include <cmath>
#include <cstring>
#include "glut.h"
#include "Circle.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <vector>
#include <iostream>
#include "RGB.h"


// Global Variables (Only what you need!)
double screen_x = 700;
double screen_y = 500;
double x = 200;
double y = 150;
double dx = 0.1;
double dy = 0.7;
//NOT set because we are call it once per launch 
std::vector<Circle> tenCricles;
std::vector<RGB> tenColors;



/*Helper fucntions for Pro02*/
//generates a random integer in given range
double random(int min, int max) //range : [min, max)
{
	static bool first = true;
	if (first)
	{
		srand(time(NULL)); //seeding for the first time only!
		first = false;
	}
	return double (min + rand() % ((max + 1) - min));
}
//Generates 10 cricles with random x and y, random RPG colors 0-255 range. radius is between 15-50
std::vector<Circle> generateRandomCricle() {
	Circle newCricle01((random(25, int(screen_x-100))), random(25, int(screen_y- 100)), random(15, 50), (random(1, 12) / 10), (random(1, 10) / 12));
	Circle newCricle02((random(25, int(screen_x-100))), random(25, int(screen_y- 100)), random(15, 50), (random(1, 12) / 10), (random(1, 10) / 12));
	Circle newCricle03((random(25, int(screen_x-100))), random(25, int(screen_y- 100)), random(15, 50), (random(1, 12) / 10), (random(1, 10) / 12));
	Circle newCricle04((random(25, int(screen_x-100))), random(25, int(screen_y- 100)), random(15, 50), (random(1, 12) / 10), (random(1, 10) / 12));
	Circle newCricle05((random(25, int(screen_x-100))), random(25, int(screen_y- 100)), random(15, 50), (random(1, 12) / 10), (random(1, 10) / 12));
	Circle newCricle06((random(25, int(screen_x-100))), random(25, int(screen_y- 100)), random(15, 50), (random(1, 12) / 10), (random(1, 10) / 12));
	Circle newCricle07((random(25, int(screen_x-100))), random(25, int(screen_y- 100)), random(15, 50), (random(1, 12) / 10), (random(1, 10) / 12));
	Circle newCricle08((random(25, int(screen_x-100))), random(25, int(screen_y- 100)), random(15, 50), (random(1, 12) / 10), (random(1, 10) / 12));
	Circle newCricle09((random(25, int(screen_x-100))), random(25, int(screen_y- 100)), random(15, 50), (random(1, 12) / 10), (random(1, 10) / 12));
	Circle newCricle10((random(25, int(screen_x-100))), random(25, int(screen_y- 100)), random(15, 50), (random(1, 12) / 10), (random(1, 10) / 12));
	std::vector<Circle> cricles;
	cricles.push_back(newCricle10);
	cricles.push_back(newCricle09);
	cricles.push_back(newCricle08);
	cricles.push_back(newCricle07);
	cricles.push_back(newCricle06);
	cricles.push_back(newCricle05);
	cricles.push_back(newCricle04);
	cricles.push_back(newCricle03);
	cricles.push_back(newCricle02);
	cricles.push_back(newCricle01);
	return cricles;
}

std::vector<RGB> generateRandomColors() {
	RGB newColor01((random(1, 100)/100), (random(1, 100) / 100), (random(1, 100) / 100));
	RGB newColor02((random(1, 100) / 100), (random(1, 100) / 100), (random(1, 100) / 100));
	RGB newColor03((random(1, 100) / 100), (random(1, 100) / 100), (random(1, 100) / 100));
	RGB newColor04((random(1, 100) / 100), (random(1, 100) / 100), (random(1, 100) / 100));
	RGB newColor05((random(1, 100) / 100), (random(1, 100) / 100), (random(1, 100) / 100));
	RGB newColor06((random(1, 100) / 100), (random(1, 100) / 100), (random(1, 100) / 100));
	RGB newColor07((random(1, 100) / 100), (random(1, 100) / 100), (random(1, 100) / 100));
	RGB newColor08((random(1, 100) / 100), (random(1, 100) / 100), (random(1, 100) / 100));
	RGB newColor09((random(1, 100) / 100), (random(1, 100) / 100), (random(1, 100) / 100));
	RGB newColor10((random(1, 100) / 100), (random(1, 100) / 100), (random(1, 100) / 100));
	std::vector<RGB> colors;
	colors.push_back(newColor01);
	colors.push_back(newColor02);
	colors.push_back(newColor03);
	colors.push_back(newColor04);
	colors.push_back(newColor05);
	colors.push_back(newColor06);
	colors.push_back(newColor07);
	colors.push_back(newColor08);
	colors.push_back(newColor09);
	colors.push_back(newColor10);
	return colors;

}


// 
// Functions that draw basic primitives
//
void DrawCircle(double x1, double y1, double radius)
{
	glBegin(GL_POLYGON);
	for(int i=0; i<32; i++)
	{
		double theta = (double)i/32.0 * 2.0 * 3.1415926;
		double x = x1 + radius * cos(theta);
		double y = y1 + radius * sin(theta);
		glVertex2d(x, y);
	}
	glEnd();
}

//Draw and check position
void DrawandCheckCricles() {
	//std::cout << tenCricles.size() << std::endl;
	for (unsigned int i = 0; i < tenCricles.size(); i++) {
		//vector[i].doSomething();
		glColor3d(tenColors[i].getRed(), tenColors[i].getGreen(), tenColors[i].getBlue());
		
		//std::cout << tenColors[i].getRed() << std::endl;
		DrawCircle((tenCricles[i].getX() + tenCricles[i].getDeltaX()), (tenCricles[i].getY() + tenCricles[i].getDeltaY()), tenCricles[i].getRadius());
		if (tenCricles[i].getX()  + tenCricles[i].getDeltaX() + tenCricles[i].getRadius() >= screen_x) {
			//dx = -dx;
			tenCricles[i].setDeltaX(-1 * tenCricles[i].getDeltaX());
		}
		if (tenCricles[i].getX() + tenCricles[i].getDeltaX()  - tenCricles[i].getRadius() < 0) {
			tenCricles[i].setDeltaX(-1 * tenCricles[i].getDeltaX());
		}
		if (tenCricles[i].getY() + tenCricles[i].getDeltaY() + +tenCricles[i].getRadius() >= screen_y) {
			tenCricles[i].setDeltaY(-1 * tenCricles[i].getDeltaY());
			
		}
		if (tenCricles[i].getY() + tenCricles[i].getDeltaY() - tenCricles[i].getRadius() < 0) {
			tenCricles[i].setDeltaY(-1 * tenCricles[i].getDeltaY());
		}
		tenCricles[i].setX(tenCricles[i].getX() + tenCricles[i].getDeltaX());
		tenCricles[i].setY(tenCricles[i].getY() + tenCricles[i].getDeltaY());
	}
}
void DrawRectangle(double x1, double y1, double x2, double y2)
{
	glBegin(GL_QUADS);
	glVertex2d(x1,y1);
	glVertex2d(x2,y1);
	glVertex2d(x2,y2);
	glVertex2d(x1,y2);
	glEnd();
}

void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	glBegin(GL_TRIANGLES);
	glVertex2d(x1,y1);
	glVertex2d(x2,y2);
	glVertex2d(x3,y3);
	glEnd();
}

// Outputs a string of text at the specified location.
void DrawText(double x, double y, const char *string)
{
	void *font = GLUT_BITMAP_9_BY_15;

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
	
	int len, i;
	glRasterPos2d(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++) 
	{
		glutBitmapCharacter(font, string[i]);
	}

    glDisable(GL_BLEND);
}


//
// GLUT callback functions
//

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	// Test lines that draw all three shapes and some text.
	// Delete these when you get your code working.
	glColor3d(0,0,1);
	if (x + 50 + dx >= screen_x) {
		dx = -dx;
	}
	if (x + dx < 0) {
		dx = -dx;
	}
	if (y + 50 + dy >= screen_y) {
		dy = -dy;
	}
	if (y + dy < 0) {
		dy = -dy;
	}
	x += dx;
	y += dy;
	// draw x and the y, edge of TOP , edge of the left/right
	//Circle  thisCircle = generateRandomCricle();
	//DrawRectangle(x, y, x+50, y+50);
	//	glColor3d(0, 1, 0);
	//	DrawTriangle(300, 300, 350, 300, 350, 350);
	//	glColor3d(1, 0, 0);
	//	DrawCircle(50, 50, 30);
	//glColor3d(1, 1, 1);
	DrawandCheckCricles();
	//DrawCircle((thisCircle.getX() ), (thisCircle.getY() ), thisCircle.getRadius());

	glColor3d(0,0,0);
	//DrawText(10,100,"Can you see this black text and 3 blue shapes?");

	glutSwapBuffers();
	glutPostRedisplay();
}


// This callback function gets called by the Glut
// system whenever a key is pressed.
void keyboard(unsigned char c, int x, int y)
{
	switch (c) 
	{
		case 27: // escape character means to quit the program
			exit(0);
			break;
		case 'b':
			// do something when 'b' character is hit.
			break;
		default:
			return; // if we don't care, return without glutPostRedisplay()
	}

	glutPostRedisplay();
}


// This callback function gets called by the Glut
// system whenever the window is resized by the user.
void reshape(int w, int h)
{
	// Reset our global variables to the new width and height.
	screen_x = w;
	screen_y = h;

	// Set the pixel resolution of the final picture (Screen coordinates).
	glViewport(0, 0, w, h);

	// Set the projection mode to 2D orthographic, and set the world coordinates:
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);

}

// This callback function gets called by the Glut
// system whenever any mouse button goes up or down.
void mouse(int mouse_button, int state, int x, int y)
{
	if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{
	}
	if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
	{
	}
	if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) 
	{
	}
	if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_UP) 
	{
	}
	glutPostRedisplay();
}

// Your initialization code goes here.
void InitializeMyStuff()
{
}


int main(int argc, char **argv)
{
	tenCricles = generateRandomCricle();
	tenColors = generateRandomColors();
	glutInit(&argc, argv);
	//
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screen_x, screen_y);
	glutInitWindowPosition(50, 50);

	int fullscreen = 0;
	if (fullscreen) 
	{
		glutGameModeString("800x600:32");
		glutEnterGameMode();
	} 
	else 
	{
		glutCreateWindow("This appears in the title bar");
	}

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);

	glColor3d(0,0,0); // forground color
	glClearColor(1, 1, 1, 0); // background color
	InitializeMyStuff();

	glutMainLoop();

	return 0;
}
