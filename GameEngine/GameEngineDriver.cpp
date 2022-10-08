//
// Created by Emma on 2022-10-07.
//
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

//int main() {
//    testGameStates();
//}