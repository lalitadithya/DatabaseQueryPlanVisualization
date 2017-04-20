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
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	display_node(10, 10, "Hi");

	glFlush();
}


void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 20.0, 0.0, 20.0);
}


void displayQueryPlan(list<SqlQueryPlanNode> &nodes)
{
	int argc = 0;
	char *argv[] = { 0 };
	nodeList = &nodes;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutCreateWindow("SQL Query Plan");

	glutDisplayFunc(display);
	init();

	glutMainLoop();
}