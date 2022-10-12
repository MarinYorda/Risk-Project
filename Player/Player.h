#pragma once
#include "Cards.h"
#include "map.h"
#include "Orders.h"
#include <iostream>
#include <vector>
using namespace std;

// Forward declarations
class Deck;
class Hand;
class Card;

///////////////////////////////// PLAYER /////////////////////////////////////

class Player {
private:
    static int* playerCount; // player count AND id
    int* id;
    string* name;
    Hand* hand;
    Deck* deck;
    OrdersLists* orders;
    vector<Territory*> territories;

public:
    // CONSTRUCTOR
    Player(string* pName);

    //COPY CONSTRUCTOR
    Player(const Player& copyPlayer);

    // ASSIGNMENT OPERATOR
    Player &operator=(const Player &e);

    // STREAM INSERTION OPERATOR
    friend ostream &operator<<(ostream &out, const Player &player);

    // GETTERS
    int* getId();
    string* getName();
    Hand* getHand();
    OrdersLists* getOrders();
    vector<Territory*> getTerritories();

    // SETTERS
    // void setPlayerCount(int playerCount);
    void setId(int newId);
    void setName(string* newName);
    void setHand(Hand* newHand);
    void setDeck(Deck* newDeck);
    void setOrders(OrdersLists* newOrders);
    void setTerritories(vector<Territory*> newTerritories);

    // OTHER
    vector<Territory*> toAttack();
    vector<Territory*> toDefend();
    void issueOrder();

    // DESTRUCTOR
    ~Player();
};