#pragma once

#include <map>
#include "Camera.h"
#include "QuadtreeNode.h"

class Quadtree
{
private:
	map<int, GameObj*> gameObjsInCamera;
	QuadtreeNode* root;
public:
	map<int, GameObj*> GetGameObjsInCamera();
	void CallRecursionToListObjInCamera(Camera camera, QuadtreeNode* quadtreeNode, int key);
	void ListObjInCamera(Camera camera, QuadtreeNode* quadtreeNode);
	void LinkQuadtreeNode(map<int, QuadtreeNode*> quadtreeNodes);
	map<int, QuadtreeNode*> InitQuadtreeNodeFromFile(map<int, GameObj*> gameObjs);
	QuadtreeNode* GetRoot();
	void BuildQuadtree(float length, QuadtreeNode* quadtreeNode);
	Quadtree(float length, int numberOfTreeObjs, TreeObj* treeObjs);
	Quadtree();
};