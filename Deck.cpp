#include "Deck.hpp"
#include "URL.hpp"
#include <string>
#include <stdlib.h>
#include "json.hpp"
#include <time.h>

using json = nlohmann::json;

Deck::Deck()
{
    this->theCards = new LinkedList();
    URL* u1 = new URL("https://api.hearthstonejson.com/v1/25770/enUS/cards.json");
    string jsonString = u1->getContents();
    json parsedJson = json::parse(jsonString);

    if(parsedJson.is_array())
    {
        for(int i = 0; i < parsedJson.size(); i++)
        {
            json currValue = parsedJson[i];
            if(currValue.is_object())
            {
                string type =  currValue.value("type", "N/A");
                if(type == "MINION")
                {
                    string name = currValue.value("name", "N/A");
                    int attack = currValue.value("attack", -1);
                    int defense = currValue.value("health", -1);
                    int manaCost = currValue.value("cost", -1);
                    theCards->addEnd(new Card(name, manaCost, attack, defense));
                }
            }
        }
    }
}

void Deck::shuffle()
{
    srand(time(NULL));

    for(int i = 0; i < 1000; i++)
    {
        int pos1 = rand() % this->theCards->getCount();
        int pos2 = rand() % this->theCards->getCount();
        while(pos1 == pos2)
        {
            pos2 = rand() % this->theCards->getCount();
        }
        this->theCards->swap(pos1, pos2);
    }
}

Card* Deck::dealCard()
{
    return this->theCards->removeFront();
}

void Deck::display()
{
    this->theCards->display();
}