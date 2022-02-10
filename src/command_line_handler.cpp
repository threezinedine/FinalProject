#include <iostream>
#include <string>
#include <command_line_handlder.h>
#include <string_operators.h>
#include <i_message.h>
#include <error_message.h>


CommandLineHandler :: CommandLineHandler(int args, char* argv[]) {
    if (args < 3) {
        valid = false;
        msg = new ErrorMessage("05", "Invalid Command");
    }
    else if (args == 3){
        inputFile = string(argv[1]);
        outputFile = string(argv[2]);
    }
    else{
        valid = false;
        msg = new ErrorMessage("05", "Invalid Command");
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

IMessage* CommandLineHandler :: getMsg() {
    return msg;
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