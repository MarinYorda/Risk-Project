#include "CardsDriver.h"
#include <iostream>
#include <algorithm>
using namespace std;

//A free function named testCards() that creates a deck of cards of all different kinds, 
//then creates a hand object that is filled by drawing cards from the deck by repeatedly calling its draw() method, 
//then calls the play() method of all cards in the hand, resulting in the cards being put back in the deck.



void testCards() {
    cout << "hello world" << endl;


    //MAKING FICTIONAL PLAYER LIST
    string sarah = "Sarah";
    string* p1Name = &sarah;
    cout << *p1Name << endl;

    string tom = "Tom";
    string* p2Name = &tom;
    cout << *p2Name << endl;


    Player* p1 = new Player(p1Name);
    p1->print();
    cout << "" << endl;

    Player* p2 = new Player(p2Name);
    p2->print();
    cout << "" << endl;

    vector<Player*> players;
    players.push_back(p1);
    players.push_back(p2);

    // Making deck with players
    Deck* testDeck = new Deck(players);
    testDeck->print();

    // Making hand objects (using the player's hands)
    Hand* hand1 = p1->getHand();
    Hand* hand2 = p2->getHand();

    // Each hand will call the draw() method twice
    hand1->draw(p1, testDeck);
    hand1->draw(p1, testDeck);
    hand2->draw(p2, testDeck);
    hand2->draw(p2, testDeck);

    // Check status of deck and hands
    testDeck->print();
    hand1->print();
    hand2->print();

    // Each hand will call the play() method on each of its cards
    hand1->playAllCards(p1, testDeck);
    hand2->playAllCards(p1, testDeck);

    // Check status of deck and hands
    testDeck->print();
    hand1->print();
    hand2->print();


}

int main() {
    cout << "hello" << endl;
    testCards();
}