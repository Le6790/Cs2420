
#ifndef HEAP_HPP
#define HEAP_HPP
#include <iostream>
#include <vector>

class MinHeap
{
private:
	std::vector<int> vec;
	std::vector <int> sortedVec; //make a function that returns sortedVec
public:
	void bubbleDown(int index);
	void bubbleUp(int index);
	void heaper();
	void insert(int val);
	void deleteMin();
	MinHeap();
	MinHeap(int * array, int length);
	MinHeap(const std::vector<int>& vec);

	void display();
	void displaySorted();

	int getMin();

	int getSize();
};

#endif