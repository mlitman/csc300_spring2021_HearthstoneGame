#include "Node.hpp"

class LinkedList
{
    private:
        Node* head;
        Node* tail;
        int count;
        Node* get(int index);

    public:
        LinkedList();
        void addEnd(Card* c);
        Card* removeFront();
        void display();
        int getCount();
        void insertionSortOnDefense();
        void swap(int index1, int index2);
};