//
// Created by Marin on 11/6/2022.
//

#include "CommandProcessing.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


//---------------CONSTRUCTORS-------------------
Command::Command() {};
FileLineReader ::FileLineReader() {};

FileCommandProcessorAdapter ::FileCommandProcessorAdapter() {
    this->flr = new FileLineReader();
    this->flr->readLineFromFile();
};

Command::Command(std::string *command, std::string *effect) {
    this->command = command;
    this->effect = effect;
}


//----------------Getters & Setters -------------


//-----------------DESTRUCTORS-------------------
Command::~Command() {
    delete command;
    command = nullptr;

    delete effect;
    effect = nullptr;
}
//destructor
CommandProcessor::~CommandProcessor() {
    for (Command* command: commandsList) {
        delete command;
        command = nullptr;
    }
}
//destructor
FileCommandProcessorAdapter::~FileCommandProcessorAdapter() {
    delete flr;
    flr = nullptr;
}
//destructor
FileLineReader::~FileLineReader() {
    for (string* command: rawCommands) {
        delete command;
        command = nullptr;
    }
}

//Getting a string command from the user
string CommandProcessor::readCommand() {
    cout << "Enter your command: " <<endl;
    string command;
    cin >> command;
    return command;
};

//save the string of the command and puts in collection of Command
Command* CommandProcessor::saveCommand(string *com, string *effect) {
    Command* command  = new Command(com, effect );
    commandsList.push_back(command);

    return command;

}

//Called from Game Engine to receive command from user
//First reads a command from the user in readCommand
// saves the command as a Command object
Command* CommandProcessor::getCommand() {
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
            coms->saveEffect(new string ("invalid move"));
            continue;
        }
        return coms;
    }
}

//when command is executed, effect stored as string in Command object
Command* Command::saveEffect(string *effect) {
    this->effect = effect;
}

bool CommandProcessor::validate(string command) {
    GameEngine* trial = new GameEngine();
    int currentState = trial->userInputToInt(command);
    return trial->validateMove(currentState);
}

string FileCommandProcessorAdapter::readCommand() {
    string* cmd =  flr->getRawCommands().at(*counter);
    *counter += 1;
    return *cmd;
}

Command* FileCommandProcessorAdapter::passCommand() {
    bool loop = true;
    while (loop) {
        string c = FileCommandProcessorAdapter::readCommand();
        string effect = "";


        Command* coms = saveCommand(new string(c),new string (effect));

        if (validate(c)) {
            loop = false;
        }
        else
        {
            coms->saveEffect(new string ("invalid move"));
            continue;
        }
        return coms;
    }
}

string FileLineReader::readLineFromFile() {
    bool loopy = true;
    string text;

    while (loopy) {
    cout << "Enter the text file you wish to read commands from: " << endl;
    cin >> text;

    cout << "We are now reading commands from " << text << endl;

    //making sure the user has entered a text file
    string txt = text.substr (text.length()-4,text.length());
    if (txt != ".txt"){
        cout << "You have not entered a text file, please try again. " << endl;
    }
    else
        loopy = false;
    }

    //opening the file

    ifstream fileReading;
    fileReading.open (text);
    string lineCommand;

    while (!fileReading.eof()){
        getline(fileReading, lineCommand);
        {
            rawCommands.push_back(new string(lineCommand));
        }
    }
}







