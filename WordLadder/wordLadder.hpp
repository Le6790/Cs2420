
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include "linkedList.hpp"

class WordLadder
{
    public:
    WordLadder(std::string dict)
    {
        dictionary.reserve(900000);
        importDict(dict);
    }
    
    void findPath(std::string, std::string);
    private:
    void importDict(std::string dict);
    LinkedList<std::vector<std::string>> queue;
    void smallerDict(int); //smaller dictionary with same word legnth as provided
    bool isWord(std::vector<std::string> &, std::string); //check to see if it is a word in the dictionary
    bool oneAway(std::vector<std::string>); // check to see if a word has only one letter that is one away
    std::string end;
    
    
    std::vector<std::string> dictionary;
    std::vector<std::string> smallerDictionary;
    
    template <class T>
    int binarySearch(std::vector<T> &, T, int, int); 
};

template <typename T>
std::ostream& operator<< (std::ostream& out, std::vector<T> const & Words) {
	for (auto & theWords : Words)
		out << theWords << std::endl;
	return out;
}




