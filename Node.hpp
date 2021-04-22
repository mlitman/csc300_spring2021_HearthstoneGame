#include "Card.hpp"

class Node
{
    private:
        Card* payload;
        Node* nextNode;
        Node* prevNode;

    public:
        Node(Card* payload);
        Card* getPayload();
        void setPayload(Card* c);
        Node* getNextNode();
        Node* getPrevNode();
        void setNextNode(Node* n);
        void setPrevNode(Node* n);
};