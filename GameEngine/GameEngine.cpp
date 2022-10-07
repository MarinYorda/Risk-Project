#include "GameEngine.h"
#include <vector>
//
// Created by Emma on 2022-10-06.
//

int zeroState = 0;
int* GameEngine::state = &zeroState;

GameEngine::GameEngine() {
    intToStringState[0] = new string("start");
    intToStringState[1] = new string("map loaded");
    intToStringState[2] = new string("map validated");
    intToStringState[3] = new string("players added");
    intToStringState[4] = new string("assign reinforcement");
    intToStringState[5] = new string("issue orders");
    intToStringState[6] = new string("execute orders");
    intToStringState[7] = new string("win");
    intToStringState[8] = new string("end");


    allowedStates[0].push_back(new int(1));

    allowedStates[1].push_back(new int(1)); // mapLoadedCommands
    allowedStates[1].push_back(new int(2)); // mapLoadedCommands

    allowedStates[2].push_back(new int(3)); // mapValidatedCommands

    allowedStates[3].push_back(new int(3)); // playersAddedCommands
    allowedStates[3].push_back(new int(4)); // playersAddedCommands

    allowedStates[4].push_back(new int(5)); // AssignReinforcementCommands

    allowedStates[5].push_back(new int(5)); // IssueOrdersCommands
    allowedStates[5].push_back(new int(10000)); // IssueOrdersCommands

    allowedStates[6].push_back(new int(6)); // executeOrdersCommands
    allowedStates[6].push_back(new int(1000)); // executeOrdersCommands
    allowedStates[6].push_back(new int(7)); // executeOrdersCommands

    allowedStates[7].push_back(new int(100)); // winCommands
    allowedStates[7].push_back(new int(8)); // winCommands

}

// COPY CONSTRUCTOR
GameEngine::GameEngine(const GameEngine& ge) {
    cout << "Copy constructor of Game Engine called" << endl;
    allowedStates = ge.allowedStates;
    intToStringState = ge.intToStringState;

}

// ASSIGNMENT OPERATOR
GameEngine& GameEngine::operator=(const GameEngine& ge)
{
    cout << "Copy assignment operator of Game Engine" << endl;
    this->state = ge.state;
    this->allowedStates = ge.allowedStates;
    this->intToStringState = ge.intToStringState;
    return *this;
    // TODO: make sure it's right shallow/deep copy
}

// STREAM INSERTION OPERATOR
ostream& operator <<(ostream& os, GameEngine& ge)
{
    cout << "current state: " << endl;
    cout << "<" + *(ge.intToStringState[*ge.state]) + ">"<< endl;
    return os;
}

void GameEngine::gameFlow(string userInput) {
    int moveInt = userInputToInt(userInput);

    if (validateMove(moveInt)) {
        int advance = moveInt - *state;
        int nextState = *state + advance;

        if (nextState == 10000) {
            *state = 6;
        } else if (nextState == 1000) {
            *state = 4;
        } else if (nextState == 100) {
            *state = 0;
        } else {
            *state = nextState;
        }

    } else {
        cout << "Invalid move! Try again" << endl << endl;
    }
}

bool GameEngine::validateMove(int move) {
    for (int* validMove: allowedStates[*state]) {
        if (move == *validMove) {
            return true;
        }
    }

    return false;
}

string *GameEngine::getStateAsString() {
    return intToStringState[*state];
}

int* GameEngine::getState() {
    return state;
}

unordered_map<int, string *> GameEngine::getIntToStringState() {
    return intToStringState;
}

//{
//{0 : loadmap}
//{1 : loadmap, validatemap}
//{2 : addplayer}
//{3 : addplayer, assigncountries}
//{4 : issueorder}
//{5 : issueorder, endissueorders}
//{6 : execorders, endexecorders, win}
//{7 : play, end}
//}

//{
//{0 : 1}
//{1 : 1, 2}
//{2 : 3}
//{3 : 3, 4}
//{4 : 5}
//{5 : 5, 10000} // if state == 10000, state = 6 to avoid endless loop
//{6 : 6, 1000, 7} // if state == 1000, state = 4
//{7 : 100, 8} // if state == 100, state = 0
//}
// if state == 8, exit game


int GameEngine::userInputToInt(string userInput) {
    if (userInput == "loadmap") {
        return 1;
    } else if (userInput == "validatemap") {
        return 2;
    } else if (userInput == "addplayer") {
        return 3;
    } else if (userInput == "assigncountries") {
        return 4;
    } else if (userInput == "issueorder") {
        return 5;
    } else if (userInput == "endissueorders") {
        return 10000; //edge case
    } else if (userInput == "execorder") {
        return 6;
    } else if (userInput == "endexecorders") {
        return 1000; //edge case
    } else if (userInput == "win") {
        return 7;
    } else if (userInput == "play") {
        return 100; //edge case
    } else if (userInput == "end") {
        return 8;
    } else {
        return -1;
    }
}

GameEngine::~GameEngine() {
    for (auto entry: allowedStates) {
        for (int* n : entry.second) {
            delete n;
            n = nullptr;
        }
    }

    for (auto entry: intToStringState) {
        delete entry.second;
        entry.second = nullptr;
    }
}


