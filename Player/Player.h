#pragma once

#include "../Cards/Cards.h"
#include <iostream>
#include <vector>
using namespace std;

// Forward declarations
class Deck;
class Hand;
class Card;

////////////////// PLAYER //////////////

class Player {
    private: 
        static int* playerCount; // player count AND id
        int* id;
        string* name;
        Hand* hand;
        Deck* deck;
        vector<string*> orders;
        vector<string*> territories;

    public:
        // CONSTRUCTORS
        Player(string* pName);
        Player(const Player& copyPlayer); //copy constructor
        // Player &operator=(const Player &e);
        friend ostream &operator<<(ostream &out, const Player &player);

        // GETTERS
        int* getId();
        string* getName();
        Hand* getHand();
        vector<string*> getOrders();
        vector<string*> getTerritories();

        // SETTERS
        // void setPlayerCount(int playerCount);
        void setId(int newId);
        void setName(string newName);
        void setHand(Hand* newHand);
        void setDeck(Deck* newDeck);
        void setOrders(vector<string*> newOrders);
        void setTerritories(vector<string*> newTerritories);

        void addToHand(Card*);
        void deleteFromHand(Card*);
        vector<string>* toAttack();
        vector<string>* toDefend();
        void issueOrder(string* order);
        void draw();
        void print();


        ~Player();
};