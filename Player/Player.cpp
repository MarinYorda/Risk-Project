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
int* Player::getReinforcements(){
    return reinforcements;
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
void Player::setReinforcements(int *noOfReinforcements) {
    reinforcements = noOfReinforcements;
}


// OTHER

vector<Territory*> Player::toAttack() {
    //Part 3 Abdur & Nauar
    vector<Territory*> attTerritories;
    for (int i = 0; i < this->territories.size(); ++i) {
        for (int j = 0; j < this->territories[i]->getAdjacentTerritories().size(); ++j) {
            attTerritories.push_back(this->territories[i]->getAdjacentTerritories()[j]);
        }
    }
    return attTerritories;
}

vector<Territory*> Player::toDefend() {
    vector<Territory*> defTerritories;
    //Part 3 Abdur & Nauar
    for(int i = 0; i<this->territories.size();i++){
        defTerritories.push_back(this->territories[i]);
    }
    return defTerritories;
}

void Player::issueOrder(int orderNumber) {
    if(this->getReinforcements()!=0 && orderNumber!=0){
            cout << "You still have " << this->getReinforcements() << " troops in the reinforcement pool\n";
            cout << "You must exhaust all of them before any other order is done!";
            return;
    }
    switch(orderNumber) {
        case '0': {
            //deploy order
            cout << "You have: " << this->getReinforcements()
                 << " troops, please choose one of your territories to place them on!";
            vector<Territory *> territories = this->toDefend();
            for (int i = 0; i < territories.size(); ++i) {
                cout << i + 1 << territories[i] << "\n";
            }
            int armiesToPlace = *this->getReinforcements() / 2 + 1;
            break;
        }
        case '1': {
            //advance order
            //get a list of the users territories
            vector<Territory *> t = this->toDefend();
            //pick one of the territories you own to be the source territory
            //get a list of neighbouring territories to that source territory
            //pick one of the territories from the neighbouring territories
            //compare the selected target territory with the toAttack list and the toDefend list and determine if it's owned by player or not
        }
    }
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