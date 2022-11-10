//
// Created by Marin on 11/6/2022.
//

#ifndef RISK_PROJECT_COMMANDPROCESSING_H
#define RISK_PROJECT_COMMANDPROCESSING_H
#include <stdio.h>
#include <iostream>
#include <string>
#include "GameEngine.h"
using namespace std;

class Command;
class FileLineReader;
class CommandProcessor

{
private:
        string readCommand();
        vector <Command*> commandsList;


public:
        Command* getCommand();
        Command* saveCommand(string* command, string* effect);
        bool validate(string command);
       ;
};

class Command
{
private:
    string* command;
    string* effect;
    vector <Command*> effectsList;

public:
    Command* saveEffect(string *effect);

    //Constructor for command object
    Command();
    Command(string *command, string *effect);
    Command(string *effect);

};

class FileCommandProcessorAdapter : public CommandProcessor
{
public:
    void readCommand ();
};

class FileLineReader
{
public:
    string readLineFromFile ();
    FileLineReader();

};


#endif //RISK_PROJECT_COMMANDPROCESSING_H

/*
 * Startup () :
 *   while stage != playStage:
 *      CommandPorcessing :: getCommand() -> return valid command
 *      execute command
 *      transition state
 *
 *
 * getCommand():
 * while (True)
 *      readCommand()
 *      saveCommand()
 *      validate()
 *             if not valid:
 *                  continue
 *             else:
 *                  send to startup()
 *                  saveEffect()
 *                  break
 *
 * */