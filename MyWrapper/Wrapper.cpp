#include "Dependecies\glew\glew.h"
#include "Dependecies\freeglut\freeglut.h"
/*
* GLUT function to draw the ouput
*/
void display()
{
	// clear the buffer
	glClear(GL_COLOR_BUFFER_BIT);

	// set the color
	glColor3f(1.0f, 0.0f, 0.0f);

	// draw the point
	glBegin(GL_POINTS);
	glVertex2f(10, 10);
	glEnd();

	// flush the frame buffer
	glFlush();
}

/*
* Helper method to initialize the required variables and GLUT
*/
void init()
{
	// set the backgroud color
	glClearColor(0.0, 0.0, 0.0, 0.0);

	// set the ortho space
	gluOrtho2D(0.0, 20.0, 0.0, 20.0);
}
extern "C"
{
	__declspec(dllexport) void DisplayHelloFromDLL()
	{
		int argc = 0;
		char *argv[] = { 0 };
		// initialize GLUT
		glutInit(&argc, argv);


		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

		// create the window
		glutInitWindowSize(500, 500);
		glutCreateWindow("Points");

		// initialize the callbacks
		glutDisplayFunc(display);

		// initialize the variables
		init();

		// main loop 
		glutMainLoop();
	}
}