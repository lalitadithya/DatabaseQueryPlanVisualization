#include "SqlQueryPlanNode.h"
#include <string>


SqlQueryPlanNode::SqlQueryPlanNode(char * nodeName)
{
	this->nodeName = new char[strlen(nodeName)];
	strcpy(this->nodeName, nodeName);
}

SqlQueryPlanNode::~SqlQueryPlanNode()
{
}
