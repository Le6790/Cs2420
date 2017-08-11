#include <memory>
#include <sstream>

template <class T>
struct Node;

template <class T>
class LinkedList //doubly linked list 
{
    struct Node
    {
        Node(T k, std::shared_ptr<Node> n = nullptr, std::shared_ptr<Node> p = nullptr) : data(k), next(n), prev(p){}
        T data;
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> prev;
    };
    
private:
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    
    std::shared_ptr<Node> clone(std::shared_ptr<Node> curr, std::shared_ptr<Node> prev)
    {
        if(!curr) return nullptr;
        auto copy = std::make_shared<Node>(curr->data);
        copy->prev = prev;
        copy->next = clone(curr->next, copy);
        return copy;
    }
    int sizeR(std::shared_ptr<Node>);
    void clearR(std::shared_ptr<Node> curr);
public:
    LinkedList() :head(nullptr){}
    
    LinkedList(LinkedList const & other) : head(clone(other.head, nullptr)){}
    LinkedList(LinkedList const && other) : head(other.head){}
    
    void push_back(T);
    void push_front(T);
    T pop();
    T back();
    
    bool isEmpty();
    
    void clear() { clearR(head); head = tail = nullptr; }
    
    int size() {return sizeR(head); }
};

// insert back
template <class T>
void LinkedList<T>::push_back(T item)
{
    if (!head)
    {
        head = tail = std::make_shared<Node>(item);
        return;
    }
    
    tail->next = std::make_shared<Node>(item, nullptr, tail);
    tail = tail->next;
}

//insert front
template <class T>
void LinkedList<T>::push_front(T item)
{
    if (!head)
    {
        head = tail = std::make_shared<Node>(item);
        return;
    }
    
    head->prev = std::make_shared<Node>(item, head, nullptr);
    head = head->prev;
}

//remove top
template <class T>
T LinkedList<T>::pop()
{
    if(!head)
    {
        std::cout << "nothing in ladder" <<std::endl;
        
    }
    
    auto p = head;
    if (!head->next)
    {
        head = tail = nullptr;
        return p->data;
    }
    head = head->next;
    head->prev = nullptr;
    return p->data;
}

//remove b
template <class T>
T LinkedList<T>::back()
{
    if (!tail)
    {
        std::cout << "Ladder is nothing" << std::endl;
    }
	return tail->data;
}

template <typename T>
void LinkedList<T>::clearR(std::shared_ptr<Node> curr)
{
	if (!curr)
		return;
	curr->prev = nullptr;
	clearR(curr->next);
}

template <typename T>
int LinkedList<T>::sizeR(std::shared_ptr<Node> curr)
{
	if (!curr) return 0;
	return 1 + sizeR(curr->next);
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
	if (head == nullptr)
		return true;
	return false;
}