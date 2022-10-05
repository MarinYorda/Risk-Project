
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

/////////////////////////////////////////////// DECK /////////////////////////////////////////////////

// CONSTRUCTOR
Deck::Deck(vector<Player*> players) {

    //Make initial deck (2 cards of each type)
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

        // delete pointers
//        delete currentPlayer;
//        currentPlayer = nullptr;
//        delete playerId;
//        playerId = nullptr;
    }

    //delete card pointers
//    delete bomb1;
//    bomb1 = nullptr;
//    delete bomb2;
//    bomb2 = nullptr;
//    delete reinforcement1;
//    reinforcement1 = nullptr;
//    delete reinforcement2;
//    reinforcement2 = nullptr;
//    delete blockade1;
//    blockade1 = nullptr;
//    delete blockade2;
//    blockade2 = nullptr;
//    delete airlift1;
//    airlift1 = nullptr;
//    delete airlift2;
//    airlift2 = nullptr;
//    delete diplomacy1;
//    diplomacy1 = nullptr;
//    delete diplomacy2;
//    diplomacy2 = nullptr;

}

// COPY CONSTRUCTOR
Deck::Deck(const Deck& copyDeck) {
    cards = copyDeck.cards;
    hands = copyDeck.hands;
}

// ASSIGNMENT OPERATOR
Deck& Deck::operator=(const Deck& assignDeck)
{
    cout << "Copy assignment operator of Deck" << endl;
    for (int i = 0; i < assignDeck.cards.size(); i++)
    {
        this->cards.push_back(new Card(*(assignDeck.cards[i])));
    }
    return *this;
}

// STREAM INSERTION OPERATOR
ostream& operator<<(ostream& os, Deck& deck)
{
    cout << "There are " << deck.cards.size() << " cards left in the deck." << endl;

    //iterate through deck and print every card type
    for(Card* card : deck.cards) {
        cout << *card << "; ";
    }
    cout << "" << endl << endl;
    return os;
}

// GETTERS
vector<Card*> Deck::getCards() {
    return cards;
}

unordered_map<int, Hand*> Deck::getHands() {
    return hands;
}

int Deck::size() {
    // Return current size of deck
    return cards.size();
}

// SETTERS
void Deck::setCards(vector<Card*> newCards) {
    cards = newCards;
}
void Deck::setHands(unordered_map<int, Hand*> newHands) {
    hands = newHands;
}

// OTHER
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


// Destructor
Deck::~Deck() {

    //delete every card pointer in hand
    for (Card* card : cards) {
        delete card;
        card = nullptr;
    }

    // delete hashmap values
    for (auto entry: hands) {
        delete entry.second;
        entry.second = nullptr;
    }
}


/////////////////////////////////////////////// HAND /////////////////////////////////////////////////

// CONSTRUCTOR
Hand::Hand() {
}

// COPY CONSTRUCTOR
Hand::Hand(const Hand& copyHand) {
    this->cards = copyHand.cards;
}

// ASSIGNMENT OPERATOR
Hand& Hand::operator=(const Hand& assignHand)
{
    cout << "Copy assignment operator of Hand" << endl;
    for (int i = 0; i < assignHand.cards.size(); i++)
    {
        this->cards.push_back(new Card(*(assignHand.cards[i])));
    }
    return *this;
}

// STREAM INSERTION OPERATOR
ostream& operator <<(ostream& os, const Hand& hand)
{
    cout << "This player's hand has " << hand.cards.size() << " cards." << endl;

    //iterate through deck and print every card type
    for(Card* card : hand.cards) {
        cout << *card << "; ";
    }
    return os;
}

// GETTERS
vector<Card*> Hand::getHand() {
    return cards;
}

int Hand::getCardCount() {
    return cards.size();
}

// SETTERS
void Hand::setCards(vector<Card*> newCards) {
    cards = newCards;
}

// OTHER
void Hand::playAllCards(Player* p, Deck* d) {
    // calls play() on every card in hand
    int cardsSize = cards.size();
    for (int i = 0; i < cardsSize; i++) {
        cards[0]->play(p,d);
    }
}

void Hand::draw(Player* p, Deck* d) {
    // Calls the deck draw() method with current player
    d->draw(p);

}

void Hand::addToHand(Card* cardToAdd) {
    // Add card to hand
    cards.push_back(cardToAdd);

}

void Hand::deleteFromHand(Card* cardToDelete) {
    string* deleteCardName = cardToDelete->getCardName();

    //iterate through hand and find the card index
    for(int i = 0; i < cards.size(); i++) {
        Card* currentCard = cards.at(i);
        string* currCardName = currentCard->getCardName();

        // delete the card
        if (*deleteCardName == *currCardName) {
            cards.erase(cards.begin() + i);
            break;
        }

        //delete
//        delete currentCard;
//        currentCard = nullptr;
//        delete currCardName;
//        currCardName = nullptr;
    }

    //delete
//    delete deleteCardName;
//    deleteCardName = nullptr;

    
}


// DESTRUCTOR
Hand::~Hand() {
    //delete every card pointer in hand
    for (Card* card : cards) {
        delete card;
        card = nullptr;
    }

}

/////////////////////////////////////////////// CARD /////////////////////////////////////////////////

// CONSTRUCTOR
Card::Card(int cardType) {

    // assign card name based on integer parameter
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

// COPY CONSTRUCTOR
Card::Card(const Card& copyCard) {
    this->cardName = copyCard.cardName;
}

// ASSIGNMENT OPERATOR
Card& Card::operator=(const Card& assignCard)
{
    cout << "Copy assignment operator of Card" << endl;
    this->cardName = assignCard.cardName;
    return *this;
}

// STREAM INSERTION OPERATOR
ostream& operator <<(ostream& os, const Card& card)
{
    cout << *card.cardName;
    return os;
}

// GETTERS
string* Card::getCardName() {
    return cardName;
}

//SETTERS
void Card::setCardName(string newCard) {
    *cardName = newCard;
}

// OTHER
void Card::play(Player* p1, Deck* deck) {
    //creates an order
    string* order = cardName;

    //add to player's list of orders
    p1->issueOrder(order);

    //remove card from player's hand
    p1->deleteFromHand(this);

    //return card to deck
    deck->addToDeck(this);

    // delete pointers
//    delete order;
//    order = nullptr;
}

// DESTRUCTORS
Card::~Card() {
    delete cardName;
    cardName = nullptr;
}






