#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdio.h>

LinkedList::LinkedList()
{
    this->count = 0;
    this->head = NULL;
    this->tail = NULL;
}

Card* LinkedList::removeFront()
{
    if(this->count > 0)
    {
        Node* front = this->head;
        Card* temp = front->getPayload();
        this->head = front->getNextNode();
        this->count--;

        if(this->head)
        {
            this->head->setPrevNode(NULL);
        }

        if(this->tail == front)
        {
            this->tail = NULL;
        }

        front->setNextNode(NULL);
        front->setPrevNode(NULL);
        delete(front);
        return temp;
    }
}

Node* LinkedList::get(int index)
{
    Node* node2Return = this->head;
    for(int i = 0; i < index; i++)
    {
        node2Return = node2Return->getNextNode();
    }
    return node2Return;
}

void LinkedList::swap(int index1, int index2)
{
    Node* smallerNode = this->get(index1);
    Node* largerNode = this->get(index2);
    Card* temp = smallerNode->getPayload();
    smallerNode->setPayload(largerNode->getPayload());
    largerNode->setPayload(temp);
}

void LinkedList::insertionSortOnDefense()
{
    int theFollower;
    for(int currStart = 1; currStart < this->count; currStart++)
    {
        theFollower = currStart;
        while(theFollower > 0 && this->get(theFollower)->getPayload()->getDefense() <
                this->get(theFollower-1)->getPayload()->getDefense())
        {
            //I need to swap
            this->swap(theFollower, theFollower-1);
            theFollower--;
        }
    }
}

void LinkedList::addEnd(Card* c)
{
    Node* n = new Node(c);
    if(this->count == 0)
    {
        this->head = n;
        this->tail = n;
    }
    else
    {
        n->setPrevNode(this->tail);
        this->tail->setNextNode(n);
        this->tail = n;
    }
    this->count++;
}

int LinkedList::getCount()
{
    return this->count;
}

void LinkedList::display()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        currNode->getPayload()->display();
        currNode = currNode->getNextNode();
    }

    this->head->getPayload()->display();
    this->tail->getPayload()->display();
}
