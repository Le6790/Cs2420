#include <iostream>
#include "BST.hpp"
#include <vector>
#include <fstream>


int main()
{
	int line;
	std::vector<int> nums;
	std::ifstream fin("nums.txt");

	while (!fin.eof())
	{
		fin >> line;
		nums.push_back(line);
	}
	fin.close();
	std::cout << "Binary Search Tree." << std::endl;
	BinaryTree<int> Tree;
	for (auto i = 0; i < nums.size(); i++)
	{
		Tree.insert(nums[i]);
		std::cout << "--------" << std::endl;
		std::cout << "HEIGHT: " << Tree.getHeight() << std::endl;
	    Tree.prettyPrint();
		std::cout << "--------" << std::endl;
	}
	std::ofstream fout("tree.txt");

	return 0;
}
