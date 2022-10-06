#include "Player.h"


void testPlayers() {
    cout << "" << endl;
    cout << "--- Player Test Function ---" << endl;
    cout << "" << endl;

    // MAKING PLAYER LIST
    Player* p1 = new Player(new string("Sarah"));

    // Printing player info for reference
    cout << "" << endl;
    cout << "--- Outputting Player's Current Info ---" << endl;
    cout << "" << endl;
    cout << *p1;

    // List of players used to create deck
    vector<Player*> players;
    players.push_back(p1);

    // Making deck with players
    Deck* testDeck = new Deck(players);

    cout << "--- Creating Defend List ---" << endl;
    cout << "" << endl;

    //Call toDefend()
    vector<string*> p1DefendList = p1->toDefend();

    //Outputting p1DefendList
    cout << "Player 1 will defend the following territories: " << endl;
    for (string* str : p1DefendList) {
        cout << *str << endl;
    }

    cout << "" << endl;
    cout << "--- Creating Attack List ---" << endl;
    cout << "" << endl;

    //Call toAttack()
    vector<string*> p1AttackList = p1->toAttack();

    //Outputting p1AttackList
    cout << "Player 1 will attack the following territories: " << endl;
    for (string* str : p1AttackList) {
        cout << *str << endl;
    }

    cout << "" << endl;
    cout << "--- Setting Player's Territory List ---" << endl;
    cout << "" << endl;

    // Creating arbitrary territories list
    vector<string*> playerTerritories;
    playerTerritories.push_back(new string("Sudan"));
    playerTerritories.push_back(new string("Chile"));
    playerTerritories.push_back(new string("Norway"));
    p1->setTerritories(playerTerritories);

    //TODO: replace orders & territories strings with actual objects

    cout << "--- Player Drawing 4 Cards ---" << endl;
    cout << "" << endl;

    // Player drawing 4 random cards
    testDeck->draw(p1->getHand());
    testDeck->draw(p1->getHand());
    testDeck->draw(p1->getHand());
    testDeck->draw(p1->getHand());

    cout << "--- Outputting Player's Current Info ---" << endl;
    cout << "" << endl;

    cout << *p1 << endl;

    cout << "--- Player playing all cards (Cards Are Returned To Deck + Orders Are Issued) ---" << endl;
    cout << "" << endl;

    // Player will play every one of his cards thus issue orders
    for (Card* card : p1->getHand()->getCards()) {
        card->play(p1, testDeck);
    }

    // Output player info
    cout << "--- Outputting Player's Current Info ---" << endl;
    cout << "" << endl;
    cout << *p1 << endl;

    // Deleting all pointers
    delete testDeck;
    testDeck = nullptr;

    delete p1;
    p1 = nullptr;

    for (string* str : p1DefendList) {
        delete str;
        str = nullptr;
    }

    for (string* str : p1AttackList) {
        delete str;
        str = nullptr;
    }

    for (string* ter : playerTerritories) {
        delete ter;
        ter = nullptr;
    }

    // TODO: change delete pointers to classes instead of strings

}

int main() {
    testPlayers();
}


//
// Created by Emma on 2022-10-05.
//
