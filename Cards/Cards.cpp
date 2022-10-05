
#include "Cards.h"
#include "../Player/Player.h"
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include<iterator>
#include <algorithm>
#include <random>
using namespace std;

Deck::Deck(vector<Player*> players) {

    //Make initial Deck (2 cards of each type)
    Card* bomb1 = new Card(0);
    Card* bomb2 = new Card(0);
    Card* reinforcement1 = new Card(1);
    Card* reinforcement2 = new Card(1);
    Card* blockade1 = new Card(2);
    Card* blockade2 = new Card(2);
    Card* airlift1 = new Card(3);
    Card* airlift2 = new Card(3);
    Card* diplomacy1 = new Card(4);
    Card* diplomacy2 = new Card(4);

    cards.push_back(bomb1);
    cards.push_back(bomb2);
    cards.push_back(reinforcement1);
    cards.push_back(reinforcement2);
    cards.push_back(blockade1);
    cards.push_back(blockade2);
    cards.push_back(airlift1);
    cards.push_back(airlift2);
    cards.push_back(diplomacy1);
    cards.push_back(diplomacy2);

    //Assign empty hands to players using the "hands" hashmap
    int numOfPlayers = players.size();
    for (int i = 0; i < numOfPlayers; i++) {
        Player* currentPlayer = players.at(i);

        //Add players to map of hands using player id
        int* playerId = currentPlayer->getId();
        hands[*playerId] = currentPlayer->getHand();

        //Assign this deck to each player
        currentPlayer->setDeck(this);
    }


}

Deck::Deck(const Deck& copyDeck) {

}

ostream& operator<<(ostream& os, Deck& deck)
{
    cout << "There are" << deck.size() << "cards left in the deck." << endl;

    //iterate through deck and print every card type
    for(Card* card : deck.getCards()) {
        cout << *card << endl;
    }
    return os;
}


vector<Card*> Deck::getCards() {
    return cards;
}

unordered_map<int, Hand*> Deck::getHands() {
    return hands;
}


void Deck::draw(Player* p1) {

    //Retrieve random card from the deck and delete
    int cardsInDeck = cards.size();
    int randomIndex = rand() % (cardsInDeck-1);
    Card* randomCard = cards.at(randomIndex);
    cards.erase(cards.begin()+randomIndex); //delete card from deck
    

    //Add Card to player's Hand
    p1->addToHand(randomCard);

}


void Deck::addToDeck(Card* card) {
    // After a player plays a card, it goes back into the deck
    cards.push_back(card);
}


int Deck::size() {
    // Return current size of deck
    return cards.size();
}

void Deck::print() {
    cout << "There are " << this->size() << " cards left in the deck." << endl;

    //iterate through deck and print every card type
    for(Card* card : this->getCards()) {
        cout << *card << endl;
    }
}

// Destructor
Deck::~Deck() {
    // delete hashmap values
    for (auto entry: hands) {
        delete entry.second;
        entry.second = nullptr;
    }
}


////////////////////////// HAND CLASS ///////////////////////////


//vector<Card>* cards;

Hand::Hand() {
}

Hand::Hand(const Hand&) {

}

ostream& operator <<(ostream& os, Hand& hand)
{
    cout << "This player has" << hand.getCardCount() << "cards." << endl;

    //iterate through deck and print every card type
    for(Card* card : hand.getHand()) {
        cout << *card << endl;
    }
    return os;
}

vector<Card*> Hand::getHand() {
    return cards;
}

int Hand::getCardCount() {
    return cards.size();
}

void Hand::playAllCards(Player* p, Deck* d) {
    for(Card* card : cards) {
        card->play(p,d);
    }
}

void Hand::draw(Player* p, Deck* d) {
    // Calls the deck draw method with current player
    d->draw(p);

}

void Hand::addToHand(Card* cardToAdd) {
    // Add card to hand and increment card count
    cards.push_back(cardToAdd);

}

void Hand::deleteFromHand(Card* cardToDelete) {
    // Remove card from player's hand and decrement count
    // auto it = std::find(cards->begin(), cards->end(), *cardToDelete);
    // if(it != cards->end()){
    //     cards->erase(it);
    // }
    

    //iterate through hand and find the card index
    for(int i = 0; i < cards.size(); i++) {
        Card* currentCard = cards.at(i);

        Card currCard = *currentCard;
        Card deleteCard = *cardToDelete;

        if (&currCard == &deleteCard) {
            cards.erase(cards.begin() + i);
            break;
        }
    }
    
}

void Hand::print()
{
    cout << "This player's hand has " << this->getCardCount() << " cards." << endl;

    //iterate through deck and print every card type
    if (cards.empty()) {
        return;
    } else {
        for(Card* card : cards) {
            cout << *card << endl;
        }
    }


}

//Destructor
Hand::~Hand() {
}

///////////////////////////////// CARD ///////////////////////////////////////

Card::Card(int cardType) {

    switch (cardType) {

        case 0: {
            cardName = new string("bomb");
            break;
        }
        case 1: {
            cardName = new string("reinforcement");
            break;
        }
        case 2: {
            cardName = new string("blockade");
            break;
        }
        case 3: {
            cardName = new string("airlift");
            break;
        }
        case 4: {
            cardName = new string("diplomacy");
            break;
        }
        default: {
            cout << "Invalid input" << endl;
        }

    }
}

Card::Card(const Card& copyCard) {

}

ostream& operator <<(ostream& os, const Card& card)
{
    cout << "This is a " << *card.cardName << " card.";
    return os;
}

string* Card::getCardName() {
    return cardName;
}

void Card::setCardName(string newCard) {
    *cardName = newCard;
}

void Card::play(Player* p1, Deck* deck) {
    //creates an order
    string* order = cardName;

    //add to player's list of orders
    p1->issueOrder(order);

    //remove card from player's hand
    p1->deleteFromHand(this);

    //return card to deck
    deck->addToDeck(this);
}

void Card::print(){
    cout << "This is a " << this->cardName << "card." << endl;
}

Card::~Card() {
    delete cardName;
    cardName = nullptr;
}






