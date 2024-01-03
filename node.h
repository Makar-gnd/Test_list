#include <iostream>
#include <memory>
struct Node
{
    /**
     * @brief Node constructor.
     * @param data Data.
     * @param pNext Next element pointer.
    */
    Node(int data = 0, Node* pNext = nullptr);

    int data;

    std::unique_ptr<Node> pNext;
};

Node::Node(int data, Node* pNext):data(data),pNext(pNext)
{
    
};