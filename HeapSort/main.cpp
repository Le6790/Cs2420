#include <iostream>	
#include <vector>
#include "Heap.hpp"
#include <fstream>
int main() 
{
	/*int array[] = { 10,4,5,30,3,300 };
	MinHeap MinSort(array, 6);
	std::cout <<"SIZE:" << MinSort.getSize() << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << MinSort.getMin() << " ";	
		MinSort.deleteMin();
	}
	std::cout << "SIZE:" << MinSort.getSize() << std::endl;
	MinSort.insert(10000);

*/
	int line;
	std::vector<int> unsorted;
	std::ifstream fin("numbers.txt");
	while (!fin.eof())
	{
		fin >> line;
		unsorted.push_back(line);
	}
	std::cout << " unordered vector of inputs: ";
	for (int i = 0; i < unsorted.size(); i++)
	{
		std::cout << unsorted[i] << " ";
	}
	std::cout << std::endl;

	MinHeap sorting;
	std::cout << "----inserting into heapsort---- " << std::endl;
	for (int i = 0; i < unsorted.size(); i++)
	{
		sorting.insert(unsorted[i]);
		sorting.display();
	}
	std::cout << "----deletmin----" << std::endl;
	std::cout << "size " << sorting.getSize() << std::endl;
	for (int i = 0; i < 16 /*sorting.getSize()*/; i++)
	{
		sorting.deleteMin();
		sorting.display();
	}
	
	std::cout << "The sorted List: " << std::endl;
		sorting.displaySorted();
	

	std::cout << "--------------------" << std::endl;

/*
	MinHeap test1;
	test1.insert(2);
	test1.display();
	test1.insert(3);
	test1.display();
	test1.insert(7);
	test1.display();
	test1.insert(22);
	test1.display();
	test1.insert(5);
	test1.display();
	test1.insert(21);
	test1.display();
	test1.insert(1);
	test1.display();
	test1.insert(28);
	test1.display();
	test1.insert(4);
	test1.display();
	test1.insert(16);
	test1.display();
	test1.insert(0);
	test1.display();
	test1.insert(17);
	test1.display();
	test1.insert(12);
	test1.display();
	test1.insert(18);
	test1.display();
	test1.insert(20);
	test1.display();
	test1.insert(25);
	test1.display();*/

	/*
	std::cout <<test1.getMin()<< "\n";
	std::cout << test1.getSize() << std::endl;
	
	test1.display();
	*/
	//test1.insert(10);
	//test1.insert(4);
	//test1.insert(5);
	//test1.insert(30);
	//test1.insert(3);
	//test1.insert(300);
	//std::cout << "SIZE:" << test1.getSize() << std::endl;
	///*for (int i = 0; i < 3; i++)
	//{
	//	std::cout << test1.getMin() << " ";
	//	test1.deleteMin();
	//}*/
	//std::cout << "SIZE:" << test1.getSize() << std::endl;
	return 0;
}