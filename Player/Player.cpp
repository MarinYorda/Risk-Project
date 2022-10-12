#include "Player.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

///////////////////////////////// PLAYER /////////////////////////////////////

// Setting static variables
int zero = 0;
int* Player::playerCount = &zero;


// CONSTRUCTOR
Player::Player(string* pName) {
    this->name = new string(*pName);

    // Use the player count as the player's id then increment the count
    this->id = new int(*playerCount);
    *playerCount += 1;

    this->hand = new Hand();
    this->orders = new OrdersLists;

}

// COPY CONSTRUCTOR
Player::Player(const Player& copyPlayer) {
    cout << "Copy constructor of Player called" << endl;
    this->id = copyPlayer.id;
    this->name = copyPlayer.name;
    this->hand = copyPlayer.hand;
    this->deck = copyPlayer.deck;
    this->orders = copyPlayer.orders;
    this->territories = copyPlayer.territories;
}

// ASSIGNMENT OPERATOR
Player& Player::operator=(const Player& copyPlayer) {
    cout << "Copy assignment operator of Player" << endl;

    this->id = copyPlayer.id;
    this->name = copyPlayer.name;
    this->hand = copyPlayer.hand;
    this->deck = copyPlayer.deck;
    this->orders = copyPlayer.orders;
    this->territories = copyPlayer.territories;

    return *this;
}

// STREAM INSERTION OPERATOR
ostream &operator<<(ostream &out, const Player& p) {
    cout << "Player name: " << *p.name <<  endl;
    cout << "Player id: " << *p.id << endl;
    cout << *p.hand;

    if (p.orders->getListSize() == 0) {
        cout << "No orders yet" << endl;
    } else {
        cout << "Orders: " << endl;
        for(Order* order : p.orders->getOrders()) {
            cout << *order << endl;
        }
    }

    if (p.territories.empty()) {
        cout << "No territories yet" << endl;
    } else {
        cout << "Territories: " << endl;
        for(Territory* ter : p.territories) {
            cout << *ter << endl;
        }
    }

    cout << "" << endl;
    return out;
}

// GETTERS
int* Player::getId() {
    return id;
}

string* Player::getName() {
    return name;
}

Hand* Player::getHand() {
    return hand;
}

OrdersLists* Player::getOrders() {
    return orders;
}

vector<Territory*> Player::getTerritories() {
    return territories;
}

// SETTERS

void Player::setId(int newId) {
    *id = newId;
}

void Player::setName(string* newName) {
    name = newName;
}

void Player::setHand(Hand* newHand) {
    hand = newHand;
}

void Player::setDeck(Deck *newDeck) {
    deck = newDeck;
}

void Player::setOrders(OrdersLists* newOrders) {
    orders = newOrders;
}

void Player::setTerritories(vector<Territory*> newTerritories) {
    territories = newTerritories;
}

// OTHER

vector<Territory*> Player::toAttack() {
    vector<Territory*> attTerritories;
    attTerritories.push_back(new Territory(new string("India"),new Continent(new string("Africa"), new int(5))));
    attTerritories.push_back(new Territory(new string("Chile"),new Continent(new string("South America"), new int(5))));
    attTerritories.push_back(new Territory(new string("France"),new Continent(new string("Europe"), new int(5))));
    attTerritories.push_back(new Territory(new string("Poland"),new Continent(new string("Europe"), new int(5))));
    return attTerritories;
}

vector<Territory*> Player::toDefend() {
    vector<Territory*> defTerritories;
    defTerritories.push_back(territories[0]);
    defTerritories.push_back(territories[1]);
    return defTerritories;
}

void Player::issueOrder() {
    // for now the order will be picked from the front of the card list
    Card* firstCard = this->hand->getCards()[0];

    //play the card
    firstCard->play(this, this->deck);

    //create order
    Order* newOrder = Order::createSubtype(*(firstCard->getCardName()));

    //add to order list
    orders->add(newOrder);

    cout << "The order " << *(firstCard->getCardName()) << " was created " << endl;
}


Player::~Player() {
    delete id;
    id = nullptr;

    delete name;
    name = nullptr;

    delete hand;
    hand = nullptr;

    deck = nullptr;

    delete orders;
    orders = nullptr;

    for (Territory* ter : territories) {
        delete ter;
        ter = nullptr;
    }
}