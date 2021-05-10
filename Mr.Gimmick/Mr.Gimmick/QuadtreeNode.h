#pragma once

#include <list>
#include "FileHandler.h"
#include "LevelOne.h"
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
	list<TreeObj> GetTreeObjs();
	bool IsLeafQuadtreeNode();
	bool IsContainTreeObj();
	void Export(string filename = FILE_QUADTREE_PATH_LEVEL_ONE);
	void AddObj(Box box, TreeObj treeObj);
	void Clip();
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