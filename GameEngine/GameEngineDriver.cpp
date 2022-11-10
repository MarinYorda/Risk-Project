#include "GameEngineDriver.h"
#include <iostream>
using namespace std;

void testGameStates() {
    cout << "Start of game" << endl << endl;
    GameEngine* g = new GameEngine();
    cout << *g << endl;


    while (*(g->getState()) < 8) {
        cout << "Enter command: " << endl;
        string input;
        cin >> input;
        g->gameFlow(input);
        cout << *g << endl;
    }

    cout << "End of game" << endl;

}

void testMainGameLoop() {

    //create players
    //give them a certain number of territories
    //calculate their number of reinforcements
    //display them
    //display that you can't call anything other than deploy while there are reinforcements still
    //display that the advance orders can be issued to either attack or defend, based on the toAttack() and toDefend() lists
    //display that a player can play cards to issue orders
    //display that a player with no territories is to be removed from the game
    //display that the game ends when someone controls all territories
}
