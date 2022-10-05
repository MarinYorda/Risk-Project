#pragma once
#include "../Player/Player.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Forward declarations
class Card;
class Hand;
class Player;

//////////////////////////////// DECK //////////////////////////////

class Deck 
{
    private:
        vector<Card*> cards;
        unordered_map<int, Hand*> hands; //maps player name to their list of cards (hand)

    public:

        //CONSTRUCTORS
        Deck(vector<Player*> players); //constructor [takes in the list of players]
        Deck(const Deck& copyDeck); //copy constructor
        // Deck& operator=(const Deck& deck); //assignment operator
        //friend ostream& operator<<(ostream& os, Deck& deck); //stream insertion operator

        //GETTERS
        vector<Card*> getCards();
        unordered_map<int, Hand*> getHands();


        void draw(Player* player); // draw from deck
        void addToDeck(Card* cardToAdd); // place card in deck
        int size(); // size of deck
        void print();

        //DESTRUCTOR
        ~Deck(); //destructor

};


/////////////////////// HAND //////////////////////////
class Hand 
{
    private:
        vector<Card*> cards;

    public:
        // CONSTRUCTORS
        Hand();
        Hand(const Hand&); //copy constructor
        // Hand& operator=(const Hand&); //assignment operator
        //friend ostream& operator<<(ostream& os, const Hand& outputHand); //stream insertion operator


        // GETTERS
        vector<Card*> getHand();
        int getCardCount();


        void draw(Player* p, Deck* d);
        void playAllCards(Player* p, Deck* d);
        void addToHand(Card*);
        void deleteFromHand(Card*);
        void print();
        

        // DESTRUCTOR
        ~Hand();

};

class Card {
    private:
        string* cardName;

    public:
        //CONSTRUCTORS
        Card(int cardType); //name of card as parameter
        Card(const Card& copyCard); //copy constructor
        // Card& operator=(const Card& assignCard); //assignment operator
        friend ostream& operator << (ostream& os, const Card& outputCard); //stream insertion operator

        //GETTERS 
        string* getCardName();

        //SETTERS
        void setCardName(string cardType);


        void play(Player* p, Deck* d); //adds the card to player's order list and puts card back in Deck
        void print();
        
        // DESTRUCTORS
        ~Card();
};


