#include "QuadtreeNode.h"

list<TreeObj> QuadtreeNode::GetTreeObjs()
{
	return this->treeObjs;
}

bool QuadtreeNode::IsLeafQuadtreeNode()
{
	return IsContainTreeObj();
}

bool QuadtreeNode::IsContainTreeObj()
{
	return !this->treeObjs.empty();
}

void QuadtreeNode::Export(string filename)
{
	string content = to_string(this->nodeID) + " " + to_string(this->point.GetFirstValue()) + " " +
		to_string(this->point.GetSecondValue()) + " " + to_string(this->dimension.GetFirstValue()) + " "
		+ to_string(this->dimension.GetSecondValue()) + " ";
	int size = this->treeObjs.size();
	list<TreeObj> treeObjs = this->treeObjs;

	for (int i = 0; i < size; i++)
	{
		content += to_string(treeObjs.front().GetID()) + " ";
		treeObjs.pop_front();
	}

	content += "\n";
	FileHandler().Write(filename, content);
}

void QuadtreeNode::AddObj(Box box, TreeObj treeObj)
{
	if (box.AABBCheck(GetBox()))
	{
		this->treeObjs.push_back(treeObj);
	}
}

void QuadtreeNode::Clip()
{
	int size = this->treeObjs.size();
	TreeObj treeObj;
	Box box;

	for (int i = 0; i < size; i++)
	{
		treeObj = this->treeObjs.front();
		box = treeObj.GetBox();
		this->topLeftChildNode->AddObj(box, treeObj);
		this->topRightChildNode->AddObj(box, treeObj);
		this->bottomLeftChildNode->AddObj(box, treeObj);
		this->bottomRightChildNode->AddObj(box, treeObj);
		this->treeObjs.pop_front();
	}
}

void QuadtreeNode::SetChild(int key, QuadtreeNode* childQuadtreeNode)
{
	switch (key)
	{
		case 1:
		{
			this->topLeftChildNode = childQuadtreeNode;
			break;
		}
		case 2:
		{
			this->topRightChildNode = childQuadtreeNode;
			break;
		}
		case 3:
		{
			this->bottomLeftChildNode = childQuadtreeNode;
			break;
		}
		case 4:
		{
			this->bottomRightChildNode = childQuadtreeNode;
			break;
		}
	}
}

int QuadtreeNode::GetParentID()
{
	return this->nodeID / 10;
}

int QuadtreeNode::GetID()
{
	return this->nodeID;
}

QuadtreeNode* QuadtreeNode::GetChild(int key)
{
	switch (key)
	{
		case 1:
		{
			return this->topLeftChildNode;
		}
		case 2:
		{
			return this->topRightChildNode;
		}
		case 3:
		{
			return this->bottomLeftChildNode;
		}
		case 4:
		{
			return this->bottomRightChildNode;
		}
	}
}

void QuadtreeNode::Divide()
{
	int tmp = this->nodeID * 10;
	float x = this->point.GetFirstValue(), y = this->point.GetSecondValue();
	float newLength = this->dimension.GetFirstValue() / 2;
	Dimension newDimension(newLength, newLength);
	this->topLeftChildNode = new QuadtreeNode(tmp + 1, x, y, newDimension);
	this->topRightChildNode = new QuadtreeNode(tmp + 2, x + newLength, y, newDimension);
	this->bottomLeftChildNode = new QuadtreeNode(tmp + 3, x, y + newLength, newDimension);
	this->bottomRightChildNode = new QuadtreeNode(tmp + 4, x + newLength, y + newLength, newDimension);
}

bool QuadtreeNode::IsDivided(float length)
{
	int size = this->treeObjs.size();
	TreeObj treeObj;
	list<TreeObj> treeObjs = this->treeObjs;

	if (this->dimension.GetFirstValue() < length / 4)
	{
		return 0;
	}

	Box box(this->point, this->dimension);

	for (int i = 0; i < size; i++)
	{
		treeObj = treeObjs.front();

		if (box.AABBCheck(treeObj.GetBox()))
		{
			return 1;
		}

		treeObjs.pop_front();
	}

	return 0;
}

QuadtreeNode::QuadtreeNode(int nodeID, float x, float y, Dimension dimension, list<TreeObj> treeObjs) :
	TwoDimensionObj(x, y)
{
	this->topLeftChildNode = this->topRightChildNode = this->bottomLeftChildNode =
		this->bottomRightChildNode = NULL;
	this->nodeID = nodeID;
	this->dimension = dimension;
	this->treeObjs = treeObjs;
}

QuadtreeNode::QuadtreeNode()
{
	this->topLeftChildNode = this->topRightChildNode = this->bottomLeftChildNode =
		this->bottomRightChildNode = NULL;
	this->nodeID = 0;
}