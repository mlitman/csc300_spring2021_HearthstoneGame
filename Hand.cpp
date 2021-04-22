#include "Hand.hpp"

Hand::Hand()
{
    this->theCards = new LinkedList();
}

void Hand::addCard(Card* c)
{
    this->theCards->addEnd(c);
}

void Hand::display()
{
    printf("***** HAND *****\n\n");
    this->theCards->display();
    printf("\n****************\n");
}
