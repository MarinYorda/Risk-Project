#include "CardsDriver.h"
#include <iostream>
#include <algorithm>
using namespace std;


void testCards() {

    // MAKING FICTIONAL PLAYER LIST
    string* p1Name = new string("Sarah");
    string* p2Name = new string("Tom");
    Player* p1 = new Player(p1Name);
    Player* p2 = new Player(p2Name);

    // Printing player info for reference
    p1->print();
    p2->print();

    // List of players used to create deck
    vector<Player*> players;
    players.push_back(p1);
    players.push_back(p2);

    // Making deck with players
    Deck* testDeck = new Deck(players);

    // Printing deck info
    cout << *testDeck << endl;

    // Making hand objects (using the player's hands)
    Hand* hand1 = p1->getHand();
    Hand* hand2 = p2->getHand();

    // Each hand will call the draw() method three times
    hand1->draw(p1, testDeck);
    hand1->draw(p1, testDeck);
    hand1->draw(p1, testDeck);

    hand2->draw(p2, testDeck);
    hand2->draw(p2, testDeck);
    hand2->draw(p2, testDeck);

    // Check status of deck and hands
    cout << *testDeck << endl;
    cout << *hand1 << endl;
    cout << *hand2 << endl;

    // Each hand will call the play() method on each of its cards
    hand1->playAllCards(p1, testDeck);
    hand2->playAllCards(p2, testDeck);

    // Print status of deck and hands
    cout << *testDeck << endl;
    cout << *hand1 << endl;
    cout << *hand2 << endl;
    cout << "" << endl;

    // Deleting all pointers
//    delete p1Name;
//    p1Name = nullptr;
//    delete p2Name;
//    p2Name = nullptr;
//
//    for (Player* p : players) {
//        delete p;
//        p = nullptr;
//    }
//
//    p1 = nullptr;
//    p2 = nullptr;
//    testDeck = nullptr;
//    hand1 = nullptr;
//    hand2 = nullptr;

}

int main() {
    testCards();
}