#include "Quadtree.h"

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

QuadtreeNode* Quadtree::GetRoot()
{
	return this->root;
}

void Quadtree::BuildQuadtree(float length, QuadtreeNode* quadtreeNode)
{
	if (!quadtreeNode->IsDivided(length))
	{
		return;
	}

	quadtreeNode->Divide();

	for (int i = 1; i <= 4; i++)
	{
		BuildQuadtree(length, quadtreeNode->GetChild(i));
	}
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

Quadtree::Quadtree()
{
	this->root = NULL;
}