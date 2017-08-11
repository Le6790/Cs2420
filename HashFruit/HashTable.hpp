#include <iostream>
#include <iomanip>
#include "cassert"
#include <string>
const int TABLESIZE = 10;

struct HashNode
{
	int key;
	std::string fruit;
	int removed = 0;
};

//class Node
//{
//public:
//	int key;
//	std::string fruit;
//	Node(int key, std::string fruit) :
//		key(key),
//		fruit(fruit)
//	{}
//};
class HashTable
{
public:
	HashTable();
	void insert(HashNode& node); //const
	void remove(HashNode& node);
	//void insert2(int key, std::string fruit);

	void rehash();

	void findIndex(int key, bool& found, int& i); //const
	void find(int key, bool& found, HashNode& result);// const outside
	int size(); // const outside
	void printTable();
	int hashing(int key); // const
private:

	HashNode htable[TABLESIZE];
	//Node *hNode[TABLESIZE];
	int used;
};

