#include <iostream>
#include "BST.hpp"
#include <vector>
#include <fstream>


int main () 
{
    std::cout << "Run the program: ./a.out \n hitting run will not run the full program due to buffer issues. Alternatively, ./a.out > textfile.txt works too. " << std::endl;
    int line;
    std::vector<int> nums;
    std::ifstream fin("nums.txt");
    
    while(!fin.eof())
    {
        fin >> line;
        nums.push_back(line);
    }
    std::cout << "Binary Search Tree." << std::endl;
    BinaryTree Tree;
	std::cout << "Nums size: " << nums.size() << std::endl;
	for (int i = 0; i < nums.size(); i++)
	{
		std::cout << "nums: " << nums[i] << std::endl; 
	}
	for (auto i = 0; i < nums.size(); i ++)
   {
	   std::cout << "-------------" << std::endl;
	   std::cout << "Inserting: " << nums[i] << std::endl;
	   Tree.insert(nums[i]);
       Tree.display();
	   std::cout << "HEIGHT: " << Tree.getHeight() << std::endl;
       //std::cout << "-------------" << std::endl;
   }
	/*Tree.insert(1);
	Tree.display();
	std::cout << "-------------------" << std::endl;
	Tree.insert(2);
	
	Tree.display();
	std::cout << "-------------------" << std::endl;
	Tree.insert(3);

	Tree.display();
	std::cout << "-------------------" << std::endl;*/

	//make a function in bst to print the tree. Will need a vector of the numbers, and make a tree object
    
    return 0;     
}
