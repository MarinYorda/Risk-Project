#include "Player.h"
#include "../Cards/Cards.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//static int* playerCount; // player count AND id
//int* id;
//string* name;
//Hand* hand;
//vector<string>* orders;
//vector<string>* territories;
   
// CONSTRUCTORS
int zero = 0;
int* Player::playerCount = &zero;

Player::Player(string* pName) {
    this->name = new string(*pName);

    // Use the player count as the player's id then increment the count
    this->id = new int(*playerCount);
    *playerCount += 1;

    this->hand = new Hand();

}

Player::Player(const Player& copyPlayer) {

}


// Player::Player& operator=(const Player &e) {

// }

ostream &operator<<(ostream &out, const Player &p) {
    cout << "Player: " << p.name << endl;
    cout << *p.hand << endl;

    cout << "Orders: " << endl;
    for(string* str : p.orders) {
        cout << *str << endl;
    }

    cout << "Territories: " << endl;
    for(string* str : p.territories) {
        cout << *str << endl;
    }
    
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

void Player::addToHand(Card* newCard) {
    hand->addToHand(newCard);
}

void Player::deleteFromHand(Card* cardToDelete) {
    hand->deleteFromHand(cardToDelete);
}

vector<string>* Player::toAttack() {
    vector<string>* attTerritories;
    attTerritories->push_back("North-East");
    attTerritories->push_back("South-East");
    attTerritories->push_back("Western");
    attTerritories->push_back("Southern");

    return attTerritories;
}

vector<string>* Player::toDefend() {
    vector<string>* defTerritories;
    defTerritories->push_back("West");
    defTerritories->push_back("East");
    defTerritories->push_back("North");
    defTerritories->push_back("South");

    return defTerritories;
}

void Player::issueOrder(string* order) {
    orders.push_back(order);
}

void Player::draw() {
    hand->draw(this, deck);
}

void Player::print() {
    cout << "Player: " << *name <<  endl;
    cout << *hand;
    if (orders.empty()) {
        cout << "No orders yet" << endl;
    }else {
        cout << "Orders: " << endl;
        for(string* str : orders) {
            cout << *str << endl;
        }
    }



    if (territories.empty()) {
        cout << "No territories yet" << endl;
    } else {
        cout << "Territories: " << endl;
        for(string* str : territories) {
            cout << *str << endl;
        }
    }

    cout << "" << endl;

}


Player::~Player() {
    delete id;
    id = nullptr;

    delete name;
    name = nullptr;

    delete hand;
    hand = nullptr;

    delete deck;
    deck = nullptr;

    for(string* str : orders) {
        delete str;
        str = nullptr;
    }

    for (string* str : territories) {
        delete str;
        str = nullptr;
    }
}