#pragma once
#include "node.h"
#include <sstream>
#include <string>
#include <initializer_list>
class List
{
private:
    size_t size;
    std::unique_ptr<Node> head;
public:
    List(std::initializer_list<int> list);
    void PushBack(int& data);
    std::string ToString();
    void PopFront();
    List(/* args */);
    ~List();
};


List::~List()
{
}

List::List():size(0),head(nullptr)
{

};

List::List(std::initializer_list<int> list) : List()
{
    for (auto data:list)
    {
        this->PushBack(data);
    }
};

void List::PushBack(int& data)
{
    if (head.get() == nullptr)
    {
        head = std::make_unique<Node>(data);
    }
    else
    {
        Node* current = this->head.get();
        while(current->pNext.get()!=nullptr)
        {
            current = current->pNext.get();
        }
        current->pNext = std::make_unique<Node>(data);
    }
    size++;
}

std::string List::ToString()
{
    std::stringstream buffer;
    Node* current = this->head.get();
    for (size_t i = 0; i< size; i++)
    {
        buffer << current->data;
        current = current->pNext.get();
    }
    return buffer.str();
}

void List::PopFront()
{
    if (head.get() == nullptr)
    {
        throw std::out_of_range("empty list!");
    }
    else
    {
        head = std::move(head->pNext);
        size--;
    }
}