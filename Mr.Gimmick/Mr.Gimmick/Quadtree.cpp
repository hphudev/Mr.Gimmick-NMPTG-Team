#include "Quadtree.h"

Quadtree::Quadtree()
{
	this->root = NULL;
}

Quadtree::Quadtree(float length, int numberOfTreeObjs, TreeObj* treeObjs)
{
	list<TreeObj> treeObjList;

	for (int i = 0; i < numberOfTreeObjs; i++)
	{
		treeObjList.push_back(treeObjs[i]);
	}

	this->root = new QuadtreeNode(0, 0, 0, Dimension(length, length), treeObjList);
}

void Quadtree::BuildQuadtree(float length, QuadtreeNode* quadtreeNode)
{
	if (!quadtreeNode->IsDivided(length))
	{
		if (quadtreeNode->IsContainTreeObj())
		{
			quadtreeNode->Export();
		}

		return;
	}

	quadtreeNode->Divide();
	quadtreeNode->Clip();
	quadtreeNode->Export();

	BuildQuadtree(length, quadtreeNode->GetChild(1));
	BuildQuadtree(length, quadtreeNode->GetChild(2));
	BuildQuadtree(length, quadtreeNode->GetChild(3));
	BuildQuadtree(length, quadtreeNode->GetChild(4));
}

QuadtreeNode* Quadtree::GetRoot()
{
	return this->root;
}

map<int, QuadtreeNode*> Quadtree::InitQuadtreeNodeFromFile(map<int, GameObj*> gameObjs)
{
	map<int, QuadtreeNode*> quadtreeNodes;
	list<list<float>> dataInQuadtreeFile = FileHandler().ReadQuadtreeFile();
	list<float> dataInOneLine;
	int row = dataInQuadtreeFile.size(), column;
	float* data;
	list<TreeObj> treeObjs;

	for (int i = 0; i < row; i++)
	{
		dataInOneLine = dataInQuadtreeFile.front();
		dataInQuadtreeFile.pop_front();
		column = dataInOneLine.size();
		data = new float[column];

		for (int j = 0; j < column; j++)
		{
			data[j] = dataInOneLine.front();
			dataInOneLine.pop_front();
		}

		if (column > 5)
		{
			for (int j = 5; j < column; j++)
			{
				treeObjs.push_back(TreeObj(gameObjs[data[j]]));
			}
		}

		QuadtreeNode* quadtreeNode = new QuadtreeNode(data[0], data[1], data[2], Dimension(data[3],
			data[4]), treeObjs);
		quadtreeNodes.insert(pair<int, QuadtreeNode*>(quadtreeNode->GetID(), quadtreeNode));
		treeObjs.clear();
		delete[] data;
	}

	return quadtreeNodes;
}

void Quadtree::LinkQuadtreeNode(map<int, QuadtreeNode*> quadtreeNodes)
{
	map<int, QuadtreeNode*>::iterator it;

	for (it = quadtreeNodes.begin(); it != quadtreeNodes.end(); it++)
	{
		int nodeID = it->first;
		QuadtreeNode* quadtreeNode = it->second;

		if (nodeID == 0)
		{
			this->root = quadtreeNode;
		}
		else
		{
			int parentID = quadtreeNode->GetParentID();
			QuadtreeNode* parentQuadtreeNode = quadtreeNodes[parentID];
			int position = nodeID % 10;

			switch (position)
			{
				case 1:
				{
					parentQuadtreeNode->SetChild(1, quadtreeNode);
					break;
				}
				case 2:
				{
					parentQuadtreeNode->SetChild(2, quadtreeNode);
					break;
				}
				case 3:
				{
					parentQuadtreeNode->SetChild(3, quadtreeNode);
					break;
				}
				case 4:
				{
					parentQuadtreeNode->SetChild(4, quadtreeNode);
					break;
				}
			}
		}
	}
}

void Quadtree::CallRecursionToListObjInCamera(Camera camera, QuadtreeNode* quadtreeNode, int key)
{
	QuadtreeNode* childQuadtreeNode = quadtreeNode->GetChild(key);
	
	if (childQuadtreeNode != NULL && childQuadtreeNode->GetBox().AABBCheck(camera.GetBox()))
	{
		ListObjInCamera(camera, childQuadtreeNode);
	}
}

map<int, GameObj*> Quadtree::GetGameObjsInCamera()
{
	return this->gameObjsInCamera;
}

void Quadtree::ListObjInCamera(Camera camera, QuadtreeNode* quadtreeNode)
{
	if (quadtreeNode == this->root)
	{
		this->gameObjsInCamera.clear();
	}

	if (quadtreeNode != NULL)
	{
		if (quadtreeNode->IsLeafQuadtreeNode())
		{
			if (quadtreeNode->GetBox().AABBCheck(camera.GetBox()))
			{
				list<TreeObj> treeObjs = quadtreeNode->GetTreeObjs();
				TreeObj treeObj;

				while (!treeObjs.empty())
				{
					treeObj = treeObjs.front();
					treeObjs.pop_front();
					this->gameObjsInCamera[treeObj.GetID()] = treeObj.GetGameObj();
				}
			}
		}
		else
		{
			for (int i = 1; i <= 4; i++)
			{
				CallRecursionToListObjInCamera(camera, quadtreeNode, i);
			}
		}
	}
}