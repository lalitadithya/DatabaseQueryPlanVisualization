#include "Dependecies\glew\glew.h"
#include "Dependecies\freeglut\freeglut.h"
#include "OpenGLMain.h"

list<SqlQueryPlanNode> *nodeList;

void display_node(int x, int y, char *display_name) {
	glRectd(x, y, x + 1, y + 1);
	glRasterPos2d(x, y-0.5);
	glutBitmapString(GLUT_BITMAP_HELVETICA_12, (unsigned char *)display_name);
}


void display()
{
	// clear the buffer
	glClear(GL_COLOR_BUFFER_BIT);

	// set the color
	glColor3f(1.0f, 0.0f, 0.0f);

	display_node(10, 10, "Hi");

	// flush the frame buffer
	glFlush();
}


void init()
{
	// set the backgroud color
	glClearColor(0.0, 0.0, 0.0, 0.0);

	// set the ortho space
	gluOrtho2D(0.0, 20.0, 0.0, 20.0);
}


void displayQueryPlan(list<SqlQueryPlanNode> &nodes)
{
	int argc = 0;
	char *argv[] = { 0 };

	nodeList = &nodes;

	// initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// create the window
	glutInitWindowSize(500, 500);
	glutCreateWindow("SQL Query Plan");

	// initialize the callbacks
	glutDisplayFunc(display);

	// initialize the variables
	init();

	// main loop 
	glutMainLoop();
}