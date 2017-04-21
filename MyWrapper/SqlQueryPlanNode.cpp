#include "SqlQueryPlanNode.h"
#include <string>


SqlQueryPlanNode::SqlQueryPlanNode(char * nodeName, int id)
{
	this->nodeName = new char[strlen(nodeName)];
	strcpy(this->nodeName, nodeName);
	this->children = new vector<SqlQueryPlanNode>();
	this->id = id;
	display_x = display_y = 0;
}

SqlQueryPlanNode::~SqlQueryPlanNode()
{
}

void SqlQueryPlanNode::AddChild(SqlQueryPlanNode &node)
{
	this->children->push_back(node);
}

vector<SqlQueryPlanNode>* SqlQueryPlanNode::GetChildren()
{
	return children;
}

char *SqlQueryPlanNode::GetNodeName() {
	return this->nodeName;
}

int SqlQueryPlanNode::GetId()
{
	return id;
}

void SqlQueryPlanNode::SetId(int id)
{
	this->id = id;
}
