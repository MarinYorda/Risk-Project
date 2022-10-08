#include "Player.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

///////////////////////////////// PLAYER /////////////////////////////////////

// Setting static variables
int zero = 0;
int* Player::playerCount = &zero;
// TODO: make sure it's right way to init static vars
// TODO: how to dealloc static vars?

// CONSTRUCTOR
Player::Player(string* pName) {
    this->name = new string(*pName);

    // Use the player count as the player's id then increment the count
    this->id = new int(*playerCount);
    *playerCount += 1;

    this->hand = new Hand();
    // TODO: GO THROUGH EVERY METHOD and replace all orders & territories strings with objects

}

// COPY CONSTRUCTOR
Player::Player(const Player& copyPlayer) {
    cout << "Copy constructor of Player called" << endl;
    this->id = new int(*(copyPlayer.id));
    this->name = new string(*(copyPlayer.name));
    this->hand = copyPlayer.hand;
    this->deck = copyPlayer.deck;
    this->orders = copyPlayer.orders;
    this->territories = copyPlayer.territories;

    //TODO: complete copy of OrdersList when class is ready
    //TODO: complete copy of Territory list when class is ready
    // TODO: make sure it's right shallow/deep copy

}

// ASSIGNMENT OPERATOR
 Player& Player::operator=(const Player& copyPlayer) {
    cout << "Copy assignment operator of Player" << endl;

    this->id = copyPlayer.id;
    this->hand = copyPlayer.hand;
    this->deck = copyPlayer.deck;
    this->orders = copyPlayer.orders;
    this->territories = copyPlayer.territories;

    //TODO: complete assignment of OrdersList when class is ready
    //TODO: complete assignment of Territory list when class is ready

    return *this;
    // TODO: make sure it's right shallow/deep copy
 }

 // STREAM INSERTION OPERATOR
ostream &operator<<(ostream &out, const Player& p) {
    cout << "Player name: " << *p.name <<  endl;
    cout << "Player id: " << *p.id << endl;
    cout << *p.hand;

    if (p.orders.empty()) {
        cout << "No orders yet" << endl;
    } else {
         cout << "Orders: " << endl;
         for(string* str : p.orders) {
             cout << *str << endl;
         }
    }

    if (p.territories.empty()) {
        cout << "No territories yet" << endl;
    } else {
         cout << "Territories: " << endl;
         for(string* str : p.territories) {
             cout << *str << endl;
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

vector<string*> Player::getOrders() {
    return orders;
}

vector<string*> Player::getTerritories() {
    return territories;
}

// SETTERS

void Player::setId(int newId) {
    *id = newId;
}

void Player::setName(string newName) {
    *name = newName;
}

void Player::setHand(Hand* newHand) {
    hand = newHand;
}

void Player::setDeck(Deck *newDeck) {
    deck = newDeck;
}

void Player::setOrders(vector<string*> newOrders) {
    orders = newOrders;
}

void Player::setTerritories(vector<string*> newTerritories) {
    territories = newTerritories;
}

// OTHER

vector<string*> Player::toAttack() {
    vector<string*> attTerritories;
    attTerritories.push_back(new string("North-East"));
    attTerritories.push_back(new string("South-East"));
    attTerritories.push_back(new string("Western"));
    attTerritories.push_back(new string("Southern"));
    return attTerritories;
}

vector<string*> Player::toDefend() {
    vector<string*> defTerritories;
    defTerritories.push_back(new string("West"));
    defTerritories.push_back(new string("East"));
    defTerritories.push_back(new string("North"));
    defTerritories.push_back(new string("South"));
    return defTerritories;
}

void Player::issueOrder(string* order) {
    orders.push_back(order);
}


Player::~Player() {
    delete id;
    id = nullptr;

    delete name;
    name = nullptr;

    delete hand;
    hand = nullptr;

//    delete deck;
    deck = nullptr;

    for(string* str : orders) {
//        delete str;
        str = nullptr;
    }

    for (string* str : territories) {
//        delete str;
        str = nullptr;
    }
}