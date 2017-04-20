#pragma once

#include <vector>

using namespace std;

class SqlQueryPlanNode
{
	char *nodeName;
	int id;
	vector<SqlQueryPlanNode> *children;
public:
	SqlQueryPlanNode(char *nodeName, int id);
	char *GetNodeName();
	int GetId();
	void SetId(int id);
	~SqlQueryPlanNode();
	void AddChild(SqlQueryPlanNode &node);
	vector<SqlQueryPlanNode> *GetChildren();
};

