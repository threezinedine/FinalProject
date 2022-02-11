#include <iostream>
#include <string>
#include <command_line_handlder.h>
#include <string_operators.h>
#include <i_message.h>
#include <error_message.h>


CommandLineHandler :: CommandLineHandler(int args, char* argv[]) {
    /*
        Tracking isValid by the number of args.
    */
    if (args < 3 || args == 4 || args > 6) {    // The invalid number of args
        cout << "test";
        valid = false;
        return;
    }
    if (args >= 3){
        inputFile = string(argv[1]);
        outputFile = string(argv[2]);
    }
    if (args >= 5) {
        if (string(argv[3]) != "-s") {
            valid = false;
            return;
        }
        string orderStr = string(argv[4]);
        
        /*
            Convert orderStr to SortType
        */
        if (orderStr == "-hu") {
            sortType = "Humidity";
        }
        else if(orderStr == "-id"){
            sortType = "Sensor ID";
        }
        else if(orderStr == "-ti"){
            sortType = "Time";
        }
        else if(orderStr == "-te"){
            sortType = "Temperature";
        }
        else {
            valid = false;
            return;
        }
    }
    if (args == 6) {
        if (string(argv[5]) == "-asc"){
            sortingOrder = true;
        }
        else if (string(argv[5]) == "-des") {
            sortingOrder = false;
        }
        else{
            valid = false;
            return;
        }
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
    /*
        Tracking if the extension is .txt -> return true
            else return false
    */
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