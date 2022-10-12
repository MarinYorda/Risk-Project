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
}

// STREAM INSERTION OPERATOR
ostream& operator <<(ostream& os, GameEngine& ge)
{
    cout << "current state: " << endl;
    cout << "<" + *(ge.intToStringState[*ge.state]) + ">"<< endl;
    return os;
}

// GETTERS
int* GameEngine::getState() {
    return state;
}

string *GameEngine::getStateAsString() {
    return intToStringState[*state];
}

unordered_map<int, string *> GameEngine::getIntToStringState() {
    return intToStringState;
}

// OTHER

void GameEngine::gameFlow(string userInput) {
    // this method handles state transitions

    // convert user input from string to int
    int moveInt = userInputToInt(userInput);

    // if user move is valid, transition state by incrementing the state variable by the appropriate amount
    if (validateMove(moveInt)) {
        int advance = moveInt - *state;
        int nextState = *state + advance;

        // edge cases: these special values handles the loop transitions
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
        // invalid move
        cout << "Invalid move! Try again" << endl << endl;
    }
}

bool GameEngine::validateMove(int move) {
    // check that the user's move is part of the allowed moves at a specific state
    for (int* validMove: allowedStates[*state]) {
        if (move == *validMove) {
            return true;
        }
    }

    return false;
}


int GameEngine::userInputToInt(string userInput) {
    // convert the user input from string to int
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

// DESTRUCTOR
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


