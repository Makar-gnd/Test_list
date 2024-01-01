#include <iostream>
#include <memory>
struct Node
{
    Node(int data = 0, Node* pNext = nullptr);
    int data;
    std::unique_ptr<Node> pNext;
    /* data */
};

Node::Node(int data, Node* pNext):data(data),pNext(pNext)
{
    
};