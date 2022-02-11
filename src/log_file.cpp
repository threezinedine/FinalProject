#include <iostream>
#include <error_message.h>
#include <i_message.h>
#include <string>
#include <vector>
#include <log_file.h>
#include <my_time.h>
#include <file_operations.h>


LogFile :: LogFile (string inputFileName, string outputFileName){
    this->inputFileName = inputFileName;
    this->outputFileName = outputFileName;
    logTime = new MyTime();
    this->getFileName();
}

string LogFile :: getFileName() {
    string date = logTime->getDateString("");
    string time = logTime->getDayTimeString("");
    
    // log file format
    return "logs/" + getFileNameNoEx(inputFileName) + "_" 
                + getFileNameNoEx(outputFileName) + "_" + 
                    date + "_" + time +".log";
}

void LogFile :: addMessage(IMessage* msg) {
    messages.push_back(msg);
}

string LogFile :: getCompleteMessage() {
    string saveString = "";
    if (messages.size() == 1){
        return messages.back()->getMessage();
    }

    while (messages.size() > 0) {
        saveString += messages.front()->getMessage();
        messages.erase(messages.begin());
    }
    return saveString;
}

void LogFile :: save() {
    string saveString = getCompleteMessage();
    if (saveString != "") {
        writeFile(getFileName(), saveString);
    }
}

