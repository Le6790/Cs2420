#ifndef BST_HPP
#define BST_HPP
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <iostream>
#define pow2(n) (1 <<(n))

class TreeNode
{
public:
	TreeNode(int data) :
		data(data),
		left(nullptr),
		right(nullptr)
	{}
	int data;
	TreeNode * left;
	TreeNode * right;
};

class BinaryTree 
{
public:
    
    BinaryTree () : m_root(nullptr)
    {}
    TreeNode *insert(int value);
    TreeNode *insert(TreeNode *& parent, TreeNode * newNode);

	int getHeight();
	int getHeight(TreeNode * node);
	int hDiff(TreeNode * node);

	void display();
	void display(TreeNode * node, float indent);

	bool binarySearch(int value);

	TreeNode * balance(TreeNode * node);
	TreeNode * rrRotation(TreeNode * node);
	TreeNode * llRotation(TreeNode * node);
	TreeNode * lrRotation(TreeNode * node);
	TreeNode * rlRotation(TreeNode * node);
protected:
    TreeNode * m_root;
};
void BinaryTree::display()
{
	display(m_root, 0);
}

void BinaryTree::display(TreeNode * node, float indent)
{

	if (node != nullptr)
	{
		if (node->right)
		{
			display(node->right, indent + 4);
		}
		if (indent)
		{
			std::cout << std::setw(indent) << ' ';
		}
		if (node->right)
		{
			std::cout << "  /\n" << std::setw(indent) << ' ';
		}
		std::cout << node->data << std::endl;
		if (node->left)
		{
			std::cout << std::setw(indent) << ' ' << " \\\n";
			display(node->left, indent + 4);
		}
	}
}

bool BinaryTree::binarySearch(int value)
{
	TreeNode * tree = m_root;
	while (tree)
	{
		if (tree->data == value)
		{
			return true;
		}
		else if(tree->data < value)
		{
			tree = tree->left;
		}
		else
		{
			tree - tree->right;
		}
	}
	return false;
}
TreeNode *BinaryTree::insert(int value)
{
	TreeNode * newNode = new TreeNode(value);
	insert(m_root, newNode);
	return newNode;
}

TreeNode *BinaryTree::insert(TreeNode *&node, TreeNode * newNode)
{
	if (node == NULL)
	{
		node = newNode;
		//node->left = nullptr;
		//node->right = nullptr;
		return node;
	}
	else if (newNode->data < node->data)
	{
		node->left = insert(node->left, newNode);
		node = balance(node);
	}
	else if (newNode->data >= node->data)
	{
		node->right = insert(node->right, newNode);
		node = balance(node);
	}
	return node;
}

int BinaryTree::getHeight()
{
	if (m_root != nullptr)
	{
		getHeight(m_root);
	}
	else
	{
		return 0;
	}
}
int BinaryTree::getHeight(TreeNode * node)
{
	int height = 0;
	if (node != NULL)
	{
		int lHeight = getHeight(node->left);
		int rHeight = getHeight(node->right);
		int max_height = std::max(lHeight, rHeight); //std::max return the largest out of a and b if equivelant return a
		height = max_height + 1;
	}
	return height;
}

int BinaryTree::hDiff(TreeNode * node)
{
	int lHeight = getHeight(node->left);
	int rHeight = getHeight(node->right);
	int bFactor = lHeight - rHeight;
	return bFactor;
}


TreeNode *BinaryTree::balance(TreeNode * node)
{
	int balFactor = hDiff(node);
	if (balFactor > 1)
	{
		if (hDiff(node->left) > 0)
		{
			node = llRotation(node);
		}
		else
		{
			node = lrRotation(node);
		}
	}
	else if (balFactor < -1)
	{
		if (hDiff(node->right) >0)
		{
			node = rlRotation(node);
		}
		else
		{
			node = rrRotation(node);
		}
	}
	return node;
}

TreeNode *BinaryTree::rrRotation(TreeNode * node)
{
	std::cout << "RR Rotation. " << std::endl;
	TreeNode * temp;
	
	temp = node->right;
	node->right = temp->left;
	temp->left = node;
	return temp;
}

TreeNode *BinaryTree::llRotation(TreeNode * node)
{
	std::cout << "LL Rotation. " << std::endl;
	TreeNode * temp;
	temp = node->left;
	node->left = temp->right;
	temp->right = node;
	return temp;
}

TreeNode *BinaryTree::lrRotation(TreeNode * node)
{
	std::cout << "LR Rotation. " << std::endl;
	TreeNode * temp;
	temp = node->left;
	node->left = rrRotation(temp);
	return llRotation(node);
}
TreeNode *BinaryTree::rlRotation(TreeNode * node)
{
	std::cout << "RL Rotation. " << std::endl;
	TreeNode * temp;
	temp = node->right;
	node->right = llRotation(temp);
	return rrRotation(node);
}
#endif 