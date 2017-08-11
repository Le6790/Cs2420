#include "wordLadder.hpp"

void WordLadder::findPath(std::string a, std::string b)
{
	//not same size
    if (a.size() != b.size())
    {

        std::cout << "The 2 words must be of the same size. Try again" << std::endl;
        return;
    }
	//bigger than one letter
	if (a.size() == 1) {
		std::cout << "word must be longer than 1 letter." << std::endl;
		return;
	}
    
    std::cout << "The ladder from : " << a << " to " << b << std::endl;
   
    
    smallerDict(a.size());
    
    end = b;
    std::vector<std::string> beginning;
    beginning.push_back(a);
    queue.push_back(beginning);
    
    
    while (!oneAway(queue.pop())){};
	std::cout << queue.back() << std::endl;
	queue.clear(); //at end?
}
// Import the dictinoary into a vector 
void WordLadder::importDict(std::string dict)
{
    std::ifstream fin(dict);
    std::string line;
	if (!fin)
	{
		std::cout << "error opening dictionary file." << std::endl;
		return;
	}
    while(!fin.eof())
    {
        fin >> line;
        
        dictionary.push_back(line);
    }
}
//used to make a dictionary of the same word length as the starting word
void WordLadder::smallerDict(int size)
{
    smallerDictionary.clear();
    
    for (auto&& i : dictionary)
    {
        if (i.size() == size)
        {
            smallerDictionary.push_back(i);
        }
    }
}
//searches the dictionary for any word that could be a match
template<class T>
int WordLadder::binarySearch(std::vector<T> & dict, T key, int start, int end)
{
    if (start > end)
    {
        return -1;
    }
    
    int mid = (start+end)/2;
    
    if (key == dict[mid]) 
    {
        return mid;
    }
    else if (key < dict[mid])
    {
        return binarySearch(dict, key, start, mid-1);
    }
    else 
    {
        return binarySearch(dict, key, mid+1, end);
    }
}

//checks if the word is indeed in the dictionary
bool WordLadder::isWord(std::vector<std::string> & dict, std:: string key)
{
    int isIn = binarySearch(dict, key, 0, dict.size() -1);
    if (isIn >=0)
    {
        if (smallerDictionary.size() >= dict.size())
        {
            smallerDictionary.erase(smallerDictionary.begin()+isIn);
            
        }
        return true;
    }
	return false;
}
//checks to see if a word is only one letter away from the previous word
bool WordLadder::oneAway(std::vector<std::string> current)
{
    for (auto i = 0; i < current.back().size(); i++)
    {
        auto nextWord = current.back();
        
        for (auto j = 97; j <=122; j++) // acii character numbers
        {
            auto nextRung = current;
            nextWord[i] = static_cast<char>(j);

            if (isWord(smallerDictionary,nextWord))
            {
                nextRung.push_back(nextWord);
                queue.push_back(nextRung);
                
                if (nextWord == end){
                    return true;
                }
            }
        }
    }
    return false;
}