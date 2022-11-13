//
// Created by Marin on 11/12/2022.
//

#include "CommandProcessing.h"
#include "GameEngine.h"

void testCommandProcessor() {
    cout << "COMMAND PROCESSING TEST" << endl;
    GameEngine* g = new GameEngine();
    g->startupPhase();
}

//int main() {
//    testCommandProcessor();
//}