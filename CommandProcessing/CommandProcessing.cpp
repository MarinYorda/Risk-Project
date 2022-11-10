//
// Created by Marin on 11/6/2022.
//

#include "CommandProcessing.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


//-----------------CONSTRUCTORS------------------
Command::Command() {};
Command::Command(std::string *command, std::string *effect) {
    this->command = command;
    this->effect = effect;
}
Command::Command(std::string *effect) {
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

        //modify saveCommand to only hold string?
        Command* coms = saveCommand(new string(c),new string (effect));

        //modify validate to return a string effect and saveCommand and saveEffect after validate method
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
Command* Command :: saveEffect (string *effect) {
    Command *comEffect = new Command (effect);
    effectsList.push_back(comEffect);
}

bool CommandProcessor :: validate(string command) {
    GameEngine* trial = new GameEngine();
    int currentState = trial->userInputToInt(command);
    return trial->validateMove(currentState);
}

void FileCommandProcessorAdapter::readCommand() {
    FileLineReader flr;

    string com = flr.readLineFromFile();
    string effect = "";
    Command* coms = saveCommand(new string(com),new string (effect));

}

string FileLineReader::readLineFromFile() {
//    bool txtfile = true;
//    while (txtfile) {
    cout << "Enter the text file you wish to read commands from: " << endl;
    string textfile;
    cin >> textfile;

    cout << "We are now reading commands from " << textfile << endl;

    //making sure the user has entered a text file
    string txt = textfile.substr (textfile.length()-4,textfile.length());
    if (txt != ".map"){
        cout << "You have not entered a text file, please try again. " << endl;
    }
    else
       // txtfile = false;
    //}

    //opening the file

    ifstream fileReading;
    fileReading.open (textfile);
    string lineCommand;

    while (!fileReading.eof()){
        getLine(fileReading, lineCommand);
            return lineCommand; //return line by line?
//        string effect = "";
//        Command* coms = saveCommand(new string(lineCommand,new string (effect)); //no access to saveCommand & saveEffect

    }






}





