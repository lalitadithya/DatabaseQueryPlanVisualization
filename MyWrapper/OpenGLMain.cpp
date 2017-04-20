#include "Dependecies\glew\glew.h"
#include "Dependecies\freeglut\freeglut.h"
#include "OpenGLMain.h"

vector<SqlQueryPlanNode> *nodeList;

void display_node(int x, int y, char *display_name) {
	glRectd(x, y, x + 5, y + 5);
	glRasterPos2d(x, y - 4);
	glutBitmapString(GLUT_BITMAP_HELVETICA_12, (unsigned char *)display_name);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	int x = 2, y = 50;

	for (int i = 0; i < nodeList->size(); i++) {
		display_node(x, y, nodeList->at(i).GetNodeName());
		x += 25;
	}

	glFlush();
}


void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 100.0, 0.0, 100.0);
}


void displayQueryPlan(vector<SqlQueryPlanNode> &nodes)
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