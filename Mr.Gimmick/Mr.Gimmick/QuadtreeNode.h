#pragma once

#include <list>
#include "TreeObj.h"
#include "TwoDimensionObj.h"
#include "Box.h"

class QuadtreeNode : public TwoDimensionObj
{
private:
	QuadtreeNode* topLeftChildNode, * topRightChildNode, * bottomLeftChildNode, * bottomRightChildNode;
	int nodeID;
	list<TreeObj> treeObjs;
public:
	void SetChild(int key, QuadtreeNode* childQuadtreeNode);
	int GetParentID();
	int GetID();
	QuadtreeNode* GetChild(int key);
	void Divide();
	bool IsDivided(float length);
	QuadtreeNode(int nodeID, float x, float y, Dimension dimension,
		list<TreeObj> treeObjs = list<TreeObj>());
	QuadtreeNode();
};