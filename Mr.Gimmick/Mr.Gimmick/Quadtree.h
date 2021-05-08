#pragma once

#include <map>
#include "FileHandler.h"
#include "QuadtreeNode.h"

class Quadtree
{
private:
	QuadtreeNode* root;
public:
	void LinkQuadtreeNode(map<int, QuadtreeNode*> quadtreeNodes);
	map<int, QuadtreeNode*> InitQuadtreeNodeFromFile(map<int, GameObj*> gameObjs);
	QuadtreeNode* GetRoot();
	void BuildQuadtree(float length, QuadtreeNode* quadtreeNode);
	Quadtree(float length, int numberOfTreeObjs, TreeObj* treeObjs);
	Quadtree();
};