#pragma once

class SqlQueryPlanNode
{
	char *nodeName;
public:
	SqlQueryPlanNode(char *nodeName);
	char *GetNodeName();
	~SqlQueryPlanNode();
};

