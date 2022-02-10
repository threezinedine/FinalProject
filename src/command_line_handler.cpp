#include <iostream>
#include <string>
#include <command_line_handlder.h>
#include <string_operators.h>
#include <i_message.h>
#include <error_message.h>


CommandLineHandler :: CommandLineHandler(int args, char* argv[], LogFile* logFile) {
    this->logFile = logFile;
    if (args < 3) {
        valid = false;
        IMessage *msg = new ErrorMessage("05", "Invalid Command");
        this->logFile->addMessage(msg);
    }
    else if (args == 3){
        inputFile = string(argv[1]);
        outputFile = string(argv[2]);
    }
    else{
        valid = false;
        IMessage *msg = new ErrorMessage("05", "Invalid Command");
        this->logFile->addMessage(msg);
    }
}

string CommandLineHandler :: getInputFileName() {
    return inputFile;
}

string CommandLineHandler :: getOputputFileName() {
    return outputFile;
}

string CommandLineHandler :: getSortType() {
    return sortType;
}

bool CommandLineHandler :: getSortOrder() {
    return sortingOrder;
}

bool CommandLineHandler :: isValidCommand() {
    return valid;
}

LogFile* CommandLineHandler :: getLogFile() {
    return logFile;
}

bool CommandLineHandler :: isInputTXT() {
    vector<string> inputFileNameParts = divideString(getInputFileName(), '.');
    if (inputFileNameParts.back() == "txt") {
        return true;
    }
    else {
        return false;
    }
}

bool CommandLineHandler :: onSortingMode() {
    if (sortType != "") {
        return true;
    }
    else {
        return false;
    }
}