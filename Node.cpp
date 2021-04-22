#include "Node.hpp"
#include <stdlib.h>

Node::Node(Card* payload)
{
    this->payload = payload;
    this->prevNode = NULL;
    this->nextNode = NULL;
}

Card* Node::getPayload()
{
    return this->payload;
}

void Node::setPayload(Card* c)
{
    this->payload = c;
}

Node* Node::getNextNode()
{
    return this->nextNode;
}

Node* Node::getPrevNode()
{
    return this->prevNode;
}

void Node::setNextNode(Node* n)
{
    this->nextNode = n;
}

void Node::setPrevNode(Node* n)
{
    this->prevNode = n;
}