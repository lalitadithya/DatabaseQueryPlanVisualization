#include "Dependecies\glew\glew.h"
#include "Dependecies\freeglut\freeglut.h"
#include "OpenGLMain.h"

SqlQueryPlanNode *nodeList;
int treesize1 = 0;

void display_node(int x, int y, char *display_name) 
{
	glRectd(x, y, x + 5, y + 5);
	glRasterPos2d(x, y - 4);
	glutBitmapString(GLUT_BITMAP_HELVETICA_12, (unsigned char *)display_name);
}


void display_plan(SqlQueryPlanNode *root, int x, int y)
{
	display_node(x, y, root->GetNodeName());
	x += 20;
	for (int i = 0; i < root->GetChildren()->size(); i++)
	{
		display_plan(&root->GetChildren()->at(i), x, y);
		y -= 10;
	}
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	int x = 2, y = 50;

	display_plan(nodeList, x, y);

	glFlush();
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	gluOrtho2D(0.0, 100.0, 0.0, 100.0);
}


void displayQueryPlan(SqlQueryPlanNode *root, int size)
{
	int argc = 0;
	char *argv[] = { 0 };
	nodeList = root;
	treesize1 = size;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
	glutCreateWindow("SQL Query Plan");

	glutDisplayFunc(display);
	init();

	glutMainLoop();
}