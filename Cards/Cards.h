#pragma once
#include "../Player/Player.h"
#include <iostream>
#include <vector>
using namespace std;

//Forward declarations
class Card;
class Hand;
class Player;

/////////////////////////////////////////////// DECK /////////////////////////////////////////////////

class Deck 
{
    private:
        vector<Card*> cards;

    public:

        // CONSTRUCTOR
        explicit Deck(const vector<Player*>& players);

        // COPY CONSTRUCTOR
        Deck(const Deck& copyDeck); //copy constructor

        // ASSIGNMENT OPERATOR
        Deck& operator=(const Deck& assignDeck); //assignment operator

        // STREAM INSERTION OPERATOR
        friend ostream& operator<<(ostream& os, Deck& deck); //stream insertion operator

        // GETTERS
        vector<Card*> getCards();
        int size();

        // SETTERS
        void setCards(vector<Card*> newCards);

        // OTHER
        void draw(Hand* player); // draw from deck
        void addToDeck(Card* cardToAdd); // place card in deck

        //DESTRUCTOR
        ~Deck(); //destructor

};


/////////////////////////////////////////////// HAND /////////////////////////////////////////////////
class Hand 
{
    private:
        vector<Card*> cards;

    public:
        // CONSTRUCTOR
        Hand();

        // COPY CONSTRUCTOR
        Hand(const Hand& copyHand); //copy constructor

        // ASSIGNMENT OPERATOR
        Hand& operator=(const Hand& assignHand); //assignment operator

        // STREAM INSERTION OPERATOR
        friend ostream& operator<<(ostream& os, const Hand& hand); //stream insertion operator


        // GETTERS
        vector<Card*> getCards();
        int getCardCount();

        // SETTERS
        void setCards(vector<Card*> newCards);

        // OTHER
        void addToHand(Card*);
        void deleteFromHand(Card*);

        // DESTRUCTOR
        ~Hand();

};

/////////////////////////////////////////////// CARD /////////////////////////////////////////////////

class Card {
    private:
        string* cardName;

    public:
        // CONSTRUCTOR
        explicit Card(int cardType);

        // COPY CONSTRUCTOR
        Card(const Card& copyCard);

        // ASSIGNMENT OPERATOR
        Card& operator=(const Card& assignCard);

        // STREAM INSERTION OPERATOR
        friend ostream& operator << (ostream& os, const Card& outputCard);

        //GETTERS 
        string* getCardName();

        //SETTERS
        void setCardName(string cardType);

        // OTHER
        void play(Player* p, Deck* d); //adds the card to player's order list and puts card back in Deck

        
        // DESTRUCTORS
        ~Card();
};


