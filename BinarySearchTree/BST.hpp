#ifndef BST_HPP
#define BST_HPP
#include <iomanip>
#include <fstream>
#include <string>
template <class T>
class BinaryTree
{
public:

	class TreeNode
	{
	public:

		TreeNode(T data) :
			data(data),
			left(nullptr),
			right(nullptr)
		{}
		T data;
		TreeNode * left;
		TreeNode * right;
	};

	BinaryTree() : m_root(nullptr)
	{}

	bool insert(T value);
	bool insert(TreeNode *& parent, TreeNode * newNode);
	bool search(T value);
	void print();
	void print(TreeNode* node);

	void prettyPrint();
	void prettyPrint(TreeNode * node, int indent);
	int getHeight();
	int getHeight(TreeNode * node);

protected:
	
	TreeNode * m_root;

};
template <class T>
bool BinaryTree<T>::search(T value)
{
	TreeNode * tree = m_root;

	while (tree)
	{
		if (tree->data == value)
		{
			return true;
		}
		else if (tree->data < value)
		{
			tree = tree->left;
		}
		else
		{
			tree = tree->right;
		}
	}
	return false;
}


template <class T>
bool BinaryTree<T>::insert(T value)
{
	if (search(value) == false)
	{
		TreeNode * newNode = new TreeNode(value);
		insert(m_root, newNode);
		return false;
	}

	return true;
}

template <class T>
bool BinaryTree<T>::insert(TreeNode *& node, TreeNode * newNode)
{
	if (node == nullptr)
	{
		node = newNode;
	}

	else if (newNode->data < node->data)
	{
		insert(node->left, newNode);
	}
	else
	{
		insert(node->right, newNode);
	}
	return true;
}

template <class T>
void BinaryTree<T>::print()
{
	print(m_root);
}

template<class T>
void BinaryTree<T>::print(TreeNode* node)
{
	if (node != nullptr)
	{
		print(node->left);
		std::cout << node->data << std::endl;
		print(node->right);
	}


}

template <class T>
void BinaryTree<T>::prettyPrint()
{
	prettyPrint(m_root, 0);
}
template <class T>

void BinaryTree<T>::prettyPrint(TreeNode * node, int indent)
{
	if (node != nullptr)
	{
		if (node->right)
		{
			prettyPrint(node->right, indent + 4);
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
			prettyPrint(node->left, indent + 4);
		}
	}
}




template <class T>

int BinaryTree<T>::getHeight()
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
template <class T>
int BinaryTree<T>::getHeight(TreeNode * node)
{

	if (node == nullptr)
	{
		return 0;
	}
	else
	{
		int lHeight = getHeight(node->left);
		int rHeight = getHeight(node->right);

		if (lHeight > rHeight)
		{
			return lHeight + 1;
		}
		else
		{
			return rHeight + 1;
		}

	}

}


#endif 