#include <iostream>
#include <string>
#include <fstream>
#include <data_file.h>
#include <log_file.h>
#include <file_operations.h>
#include <sys/stat.h>


string DataFile :: getFileName() {
    return fileName;
}

bool DataFile :: warningFileExit() {
    cout << "The " + getFileName() + " exists. Do you wanna override: (y/n)";

    string userInput;
    cin >> userInput;

    if (userInput == "y") {
        return true;
    }
    else {
        return false;
    }
}

LogFile* DataFile :: getLogFile() {
    return logFile;
}

bool DataFile :: canReadData() {
    try {
        vector<string> data = readFile(getFileName());
        if (data.size() != 0) {
            return true;
        }
        else {
            return false;
        }
    }
    catch (int non){
        return false;
    }
}

bool DataFile :: isFileExist() {
    try {
        vector<string> data = readFile(getFileName());
        if (data.size() != 0) {
            return true;
        }
        else {
            return false;
        }
    }
    catch (int non){
        return false;
    }
}

void DataFile :: save() {
    writeFile(getFileName(), saveString);
}