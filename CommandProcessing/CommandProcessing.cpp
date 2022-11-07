//
// Created by Marin on 11/6/2022.
//

#include "CommandProcessing.h"
#include <iostream>
#include <vector>
using namespace std;


//-----------------CONSTRUCTORS------------------
Command::Command() {};
Command::Command(std::string *command, std::string *effect) {
    this->command = command;
    this->effect = effect;
}

//----------------Getters & Setters -------------



//Getting a string command from the user
string CommandProcessor::readCommand () {
    cout << "Enter your command: " <<endl;
    string command;
    cin >> command;
    return command;
};

//save the string of the command and puts in collection of Command
Command* CommandProcessor :: saveCommand (string *com, string *effect) {
    Command* command  = new Command(com, effect );
    commandsList.push_back(command);

    return command;

}

//Called from Game Engine to receive command from user
//First reads a command from the user in readCommand
// saves the command as a Command object
Command* CommandProcessor :: getCommand() {
    bool loop = true;
    while (loop) {
        readCommand();
        string c = readCommand();
        string effect = "";
        Command* coms = saveCommand(new string(c),new string (effect));
        if (validate(c)) {
            loop = false;
        }
        else
        {
            continue;
        }

        return coms;

    }

}

//when command is executed, effect stored as string in Command object
void Command :: saveEffect () {

}

bool CommandProcessor :: validate(string command) {
    GameEngine* trial = new GameEngine();
    int currentState = trial->userInputToInt(command);
    return trial->validateMove(currentState);
}



