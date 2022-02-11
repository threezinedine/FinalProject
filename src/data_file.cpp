#include <iostream>
#include <string>
#include <fstream>
#include <data_file.h>
#include <log_file.h>
#include <file_operations.h>


string DataFile :: getFileName() {
    return fileName;
}

bool DataFile :: warningFileExit() {
    cout << "The " + getFileName() + " exists. Do you wanna override: (y/n)";

    string userInput = "n";
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
    if (isFileExist()){
        vector<string> data = readFile(getFileName());
        if (data.size() != 0) {
            return true;
        }
        else {
            return false;
        }
    }
    else{
        return false;
    }
    
}

bool DataFile :: isFileExist() {
    fstream file;
    file.open(getFileName());
    if(file.fail()){
        return false;
    }
    else{
        return true;
    }
    file.close();
}

void DataFile :: save() {
    writeFile(getFileName(), saveString);
}