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
    /**
     * @brief init_list constructor.
     * @param list init_list.
    */
    List(std::initializer_list<int> list);

    /**
     * @brief Add an element to the end of the list.
     * @param data The data we add.  
    */
    void PushBack(int& data);

    /**
     * @brief List to string conversion.
     * @return String.
    */
    std::string ToString();

    /**
     * @brief Delete first element.
    */
    void PopFront();

    /**
     * @brief Clear list.
    */
    void Clear();

    /**
     * @brief Delete last element.
    */
    void PopBack();

    /**
     * @brief List constructor
    */
    List(/* args */);

    /**
     * @brief List destructor.
    */
    ~List();
};


List::~List()
{
    Clear();
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
    buffer<<std::endl;
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

void List::Clear()
{
    if(size<=0)
    {
        throw std::out_of_range("empty list!");
    }
    else
    {
        while(size>0)
        {
            PopFront();
        }
    }
}

void List::PopBack()
{
    if(size<=0)
    {
        throw std::out_of_range("Empty list!");
    }
    Node* LastButOne = this->head.get();
    while (LastButOne->pNext->pNext != nullptr)
    {
        LastButOne = LastButOne->pNext.get();
    }
    LastButOne->pNext.reset();
    LastButOne->pNext = nullptr;
    size--;
}