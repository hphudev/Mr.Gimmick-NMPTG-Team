#pragma once

#include <map>
#include "Camera.h"
#include "QuadtreeNode.h"

class Quadtree
{
private:
	QuadtreeNode* root;
	map<int, GameObj*> gameObjsInCamera;
public:
	Quadtree();
	Quadtree(float length, int numberOfTreeObjs, TreeObj* treeObjs);
	void BuildQuadtree(float length, QuadtreeNode* quadtreeNode);
	QuadtreeNode* GetRoot();
	map<int, QuadtreeNode*> InitQuadtreeNodeFromFile(map<int, GameObj*> gameObjs);
	void LinkQuadtreeNode(map<int, QuadtreeNode*> quadtreeNodes);
	void ListObjInCamera(Camera camera, QuadtreeNode* quadtreeNode); 
	void CallRecursionToListObjInCamera(Camera camera, QuadtreeNode* quadtreeNode, int key);
	map<int, GameObj*> GetGameObjsInCamera();
};