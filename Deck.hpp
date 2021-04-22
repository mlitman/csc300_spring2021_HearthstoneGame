#ifndef LinkedList_HPP
#define LinkedList_HPP
#include "LinkedList.hpp"
#endif

class Deck
{
    private:
        LinkedList* theCards;

    public:
        Deck();
        void display();
        void shuffle();
        Card* dealCard();

    
};