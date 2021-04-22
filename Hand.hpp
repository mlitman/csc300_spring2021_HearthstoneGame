#ifndef LinkedList_HPP
#define LinkedList_HPP
#include "LinkedList.hpp"
#endif

class Hand
{
    private:
        LinkedList* theCards;

    public:
        Hand();
        void addCard(Card* c);
        void display();
};

