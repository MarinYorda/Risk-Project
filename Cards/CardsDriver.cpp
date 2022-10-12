#include "CardsDriver.h"
#include <iostream>
#include <algorithm>
using namespace std;

void testCards() {
    cout << "" << endl;
    cout << "--- Cards Test Function ---" << endl;
    cout << "" << endl;

    cout << "" << endl;
    cout << "--- Creating Player List ---" << endl;
    cout << "" << endl;

    // MAKING FICTIONAL PLAYER LIST
    Player* p1 = new Player(new string("Sarah"));
    Player* p2 = new Player(new string("Tom"));

    cout << "--- Outputting Player Info For Reference ---" << endl;
    cout << "" << endl;

    // Printing player info for reference
    cout << *p1;
    cout << *p2;

    // List of players used to create deck
    vector<Player*> players;
    players.push_back(p1);
    players.push_back(p2);

    cout << "" << endl;
    cout << "--- Creating Deck Of 10 Cards ---" << endl;
    cout << "" << endl;

    // Making deck with players
    Deck* testDeck = new Deck(players);

    cout << "--- Outputting Current Deck Info ---" << endl;
    cout << "" << endl;

    // Printing deck info
    cout << *testDeck << endl;

    cout << "--- Creating Hand Objects Using Player's Hands ---" << endl;
    cout << "" << endl;

    // Making hand objects (using the player's hands)
    Hand* hand1 = p1->getHand();
    Hand* hand2 = p2->getHand();

    cout << "--- Each Player Draws 3 Random Cards From Deck ---" << endl;
    cout << "" << endl;

    // Deck will call the draw() method three times per player's hand
    hand1->addToHand(testDeck->draw());
    hand1->addToHand(testDeck->draw());
    hand1->addToHand(testDeck->draw());

    hand2->addToHand(testDeck->draw());
    hand2->addToHand(testDeck->draw());
    hand2->addToHand(testDeck->draw());

    cout << "--- Outputting Current Deck Info ---" << endl;
    cout << "" << endl;

    // Check status of deck and hands
    cout << *testDeck << endl;

    cout << "--- Outputting Current Player Hands Info ---" << endl;
    cout << "" << endl;

    cout << *hand1 << endl;
    cout << *hand2 << endl;

    cout << "" << endl;
    cout << "--- Players Play All Cards (Cards Are Returned To Deck) ---" << endl;
    cout << "" << endl;

    // Each hand will call the play() method on each of its cards
    for (Card* card1 : hand1->getCards()) {
        card1->play(p1, testDeck);
    }

    for (Card* card1 : hand2->getCards()) {
        card1->play(p2, testDeck);
    }

    // Print status of deck and hands
    cout << "--- Outputting Current Deck Info ---" << endl;
    cout << "" << endl;

    // Check status of deck and hands
    cout << *testDeck << endl;

    cout << "--- Outputting Current Player Hands Info ---" << endl;
    cout << "" << endl;

    cout << "Player 1: " << endl;
    cout << *hand1 << endl;

    cout << "Player 2: " << endl;
    cout << *hand2 << endl;

}
