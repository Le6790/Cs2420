#include <iostream>
#include <iomanip>
#include "cassert"
#include <string>
#include "HashTable.hpp"

HashTable::HashTable()
{
	used = 0;
	for (int i = 0; i < TABLESIZE; i++)
	{
		htable[i].key = -1;
		htable[i].fruit = "";
		htable[i].removed = 0;
	}
}

void HashTable::insert(HashNode& Node)
{
	bool alreadyThere = false;
	int index;

	//if key < 0 then stop
	if (Node.key < 0)
	{
		return;
	}
	//std::cout << "BOOL" <<alreadyThere << std::endl;
	findIndex(Node.key, alreadyThere, index);
	//std::cout << alreadyThere << std::endl;
	if (!alreadyThere)
	{
		if (size() < TABLESIZE)
		used++;
		if (size() > TABLESIZE)
		{
			std::cout << "No more room" << std::endl;
			return;
		}
		//check to see if used is >= half the table size
		if (used >= (TABLESIZE/2))
		{
			rehash();
		}
		htable[index] = Node;
		htable[index].removed = 0;
	}
	
	
}

void HashTable::rehash()
{
	const int newTableSize = TABLESIZE * 2;
	HashNode newHTable[newTableSize];
	for (int i = 0; i < TABLESIZE; i++)
	{

	}

}

void HashTable::remove(HashNode& Node)
{
	bool alreadyThere = false;
	int index;
	if (Node.key < 0)
	{
		return;
	}
	findIndex(Node.key, alreadyThere, index);
	if (alreadyThere)
	{
		htable[index].removed = 1;
	}
}


//void HashTable::insert2(int key, std::string fruit)
//{
//	Node *newNode = new Node(key, fruit);
//
//	bool alreadyThere = false;
//	int index;
//
//	//if key < 0 then stop
//	if (newNode->key < 0)
//	{
//		return;
//	}
//	//std::cout << "BOOL" <<alreadyThere << std::endl;
//	findIndex(newNode->key, alreadyThere, index);
//	//std::cout << alreadyThere << std::endl;
//	if (!alreadyThere)
//	{
//		if (size() < TABLESIZE)
//			used++;
//	}
//	if (used >= TABLESIZE)
//	{
//		std::cout << "No more room" << std::endl;
//		return;
//	}
//	hNode[index] = newNode;
//}



int HashTable::hashing(int key)
{
	return key%TABLESIZE;
}

int HashTable::size() 
{
	return used;
}

void HashTable::findIndex(int key, bool& found, int & i)
{
	int count = 0;
	i = hashing(key);

	while (count < TABLESIZE && htable[i].key != -1 && htable[i].key != key)
	{
		count++;
		i= ( i + 1) % TABLESIZE;
	}
	if (htable[i].key == key)
	{
		found = true;
	}
}

void HashTable::find(int key, bool& found, HashNode& result)
{
	int index;
	if (key < 0) return;
	findIndex(key, found, index);
	if (found)
	{
		result = htable[index]; 
		std::cout << "Found: " << htable[index].fruit << std::endl;
	}

}

void HashTable::printTable()
{
	std::cout << "*********Key: Fruit:**********" << std::endl;
	for (int i = 0; i < TABLESIZE; i++)
	{
		std::cout <<"[" <<htable[i].key << "] ";
		std::cout <<"[" <<htable[i].fruit << "]";
		std::cout << "[" << htable[i].removed << "]" << std::endl;

	}
}

