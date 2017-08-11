#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "wordLadder.hpp"

int main() 
{
    std::string file = "dictionary.txt";
    
    std::string beg = "cart";
    std::string end = "pull";
    WordLadder start(file);
    start.findPath(beg,end);

    return 0;
}