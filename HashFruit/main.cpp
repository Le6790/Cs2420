#include <iostream>
#include "HashTable.hpp"

int main()
{
	HashNode node;
	HashTable table;
	bool found;
	int size;
	table.printTable();
	node.key = 4885;
	node.fruit = "basil";
	table.insert(node);
	table.printTable();
	node.key = 4562;
	node.fruit = "carrots";
	table.insert(node);
	table.printTable();
	node.key = 4225;
	node.fruit = "avocado large hass";
	table.insert(node);
	table.printTable();
	node.key = 4545;
	node.fruit = "bok choy";
	table.insert(node);
	table.printTable();
	node.key = 4874;
	node.fruit = "duritos";
	table.insert(node);
	table.printTable();
	node.key = 4896;
	node.fruit = "mint";
	table.insert(node);
	table.printTable();
	node.key = 4051;
	node.fruit = "mango";
	table.insert(node);
	table.remove(node);
	table.printTable();
	std::cout << "____________________" << std::endl;
	table.find(4225, found, node);
	return 0;
}