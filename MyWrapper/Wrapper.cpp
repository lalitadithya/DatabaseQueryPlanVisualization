#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include "SqlQueryPlanNode.h"
#include "OpenGLMain.h"

using namespace std;

SqlQueryPlanNode *AddNodeToTree(SqlQueryPlanNode *root, int parent_id, int id, SqlQueryPlanNode *toAdd) 
{
	if (root == NULL) 
	{
		return toAdd;
	}
	else if (root->GetId() == parent_id) 
	{
		root->AddChild(*toAdd);
	}
	else 
	{
		for (int i = 0; i < root->GetChildren()->size(); i++) 
		{
			AddNodeToTree(&root->GetChildren()->at(i), parent_id, id, toAdd);
		}
	}
	return root;
}

int treesize = 0;

SqlQueryPlanNode *ConstructTree(SqlQueryPlanNode *root, char *tree) 
{
	ifstream file(tree);

	int id = 0, parnet_id = 0;
	char *name = new char[255];
	
	while (file >> id >> parnet_id >> name) 
	{
		SqlQueryPlanNode *node1 = new SqlQueryPlanNode(name, id);
		root = AddNodeToTree(root, parnet_id, id, node1);
		treesize++;
	}
	return root;
}


extern "C"
{
	__declspec(dllexport) void DisplayVisualization()
	{

		SqlQueryPlanNode *root = NULL;

		root = ConstructTree(root, "query.txt");

		displayQueryPlan(root, treesize);
	}
}