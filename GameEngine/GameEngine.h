
#pragma once
#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class GameEngine {
private:
    unordered_map<int,vector<int*>> allowedStates;
    unordered_map<int,string*> intToStringState;
    static int* state;

public:
    // CONSTRUCTOR
    GameEngine();

    // COPY CONSTRUCTOR
    GameEngine(const GameEngine& ge);

    // ASSIGNMENT OPERATOR
    GameEngine& operator=(const GameEngine& ge);

    // STREAM INSERTION OPERATOR
    friend ostream& operator <<(ostream& os, GameEngine& ge);

    // GETTERS
    int* getState();
    string* getStateAsString();
    unordered_map<int,string*> getIntToStringState();

    void gameFlow(string userInput);
    bool validateMove(int move);
    int userInputToInt(string userInput);

    // DESTRUCTOR
    ~GameEngine();
};
