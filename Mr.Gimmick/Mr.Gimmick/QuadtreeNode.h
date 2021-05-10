#pragma once

#include <list>
#include "TreeObj.h"
#include "TwoDimensionObj.h"
#include "Box.h"
#include "FileHandler.h"
#include "LevelOne.h"

class QuadtreeNode : public TwoDimensionObj
{
private:
	QuadtreeNode *topLeftChildNode, *topRightChildNode, *bottomLeftChildNode, *bottomRightChildNode;
	int nodeID;
	list<TreeObj> treeObjs;
public:
	QuadtreeNode();
	QuadtreeNode(int nodeID, float x, float y, Dimension dimension, 
		list<TreeObj> treeObjs = list<TreeObj>());
	bool IsDivided(float length);
	void Divide();
	QuadtreeNode* GetChild(int key);
	int GetID();
	int GetParentID();
	void SetChild(int key, QuadtreeNode* childQuadtreeNode);
	void Clip();
	void AddObj(Box box, TreeObj treeObj);
	void Export(string filename = FILE_QUADTREE_PATH_LEVEL_ONE);
	bool IsLeafQuadtreeNode();
	bool IsContainTreeObj();
	list<TreeObj> GetTreeObjs();
	Box GetBox();
};