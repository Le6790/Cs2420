#include "Heap.hpp"

MinHeap::MinHeap()
{
	std::cout << "MINHEAP: " << std::endl;
}

MinHeap::MinHeap(int *arr, int length) : vec(length)
{
	for (int i = 0; i < length; i++)
	{
		vec[i] = arr[i];
	}
	heaper();
}

MinHeap::MinHeap(const std::vector<int>&  vect) : vec(vect)
{
	heaper();
}

void MinHeap::heaper()
{
	int length = vec.size();
	for (int i = length-1; i >= 0; i--)
	{
		bubbleDown(i);
	}
}

void MinHeap::bubbleDown(int index)
{
	int length = vec.size();
	int leftChild = (2 * index) + 1;
	int rightChild = (2 * index) + 2;
	
	if (leftChild >= length)
	{
		return; // index is a leaf
	}
	int minIndex = index;
	if (vec[index] > vec[leftChild])
	{
		minIndex = leftChild;
	}
	if (rightChild < length && (vec[minIndex] > vec[rightChild]))
	{
		minIndex = rightChild;
	}
	if (minIndex != index)
	{
		int temp = vec[index];
		vec[index] = vec[minIndex];
		vec[minIndex] = temp;	
		bubbleDown(minIndex);	
	}
}

void MinHeap::bubbleUp(int index)
{
	if (index == 0)
	{
		return;
	}

	int parent = (index - 1) / 2;
	if (vec[parent] > vec[index])
	{
		int temp = vec[parent];
		vec[parent] = vec[index];
		vec[index] = temp;
		bubbleUp(parent);
	}
}

void MinHeap::insert(int val)
{
	int length = vec.size();
	vec.push_back(val);
	bubbleUp(length);
}


int MinHeap::getMin()
{
	return vec[0];
}

int MinHeap::getSize()
{
	return vec.size();
}
void MinHeap::deleteMin()
{
	int length = vec.size();
	if (length == 0)
	{
		return;
	}
	sortedVec.push_back(vec[0]);
	vec[0] = vec[length - 1];
	//std::cout << "Deleting: " << vec[0] << std::endl;
	
	vec.pop_back();
	bubbleDown(0);
}

void MinHeap::display()
{
	int length = vec.size();
	for (int i = 0; i < length; i++)
	{
		std::cout << i;
		std::cout <<"["<< vec[i] << "] ";
	}
	std::cout << std::endl;
}

void MinHeap::displaySorted()
{
	for (int i = 0; i < sortedVec.size(); i++)
	{
		std::cout << "[" << sortedVec[i] << "] ";
	}
	std::cout << std::endl;
}
