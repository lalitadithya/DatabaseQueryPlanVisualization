#include <iostream>
#include <list>
#include "SqlQueryPlanNode.h"
#include "OpenGLMain.h"

using namespace std;

extern "C"
{
	__declspec(dllexport) void DisplayVisualization(char* queryPlan[], int numberOfElements)
	{
		list<SqlQueryPlanNode> node_list;

		for (int i = 0; i < numberOfElements; i++) {
			node_list.push_back(SqlQueryPlanNode(queryPlan[i]));
		}

		displayQueryPlan(node_list);
	}
}