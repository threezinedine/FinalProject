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
    logTime = MyTime();
    this->getFileName();
}

string LogFile :: getFileName() {
    string date = logTime.getDateString("");
    string time = logTime.getDayTimeString("");
    return inputFileName + "_" + outputFileName + "_" + date + "_" + time +".log";
}

void LogFile :: addMessage(IMessage* msg) {
    messages.push_back(msg);
}

string LogFile :: getCompleteMessage() {
    string saveString = "";

    for (IMessage *msg: messages){
        saveString += msg->getMessage();
        saveString += '\n';
    }
    return saveString;
}

void LogFile :: save() {
    string saveString = getCompleteMessage();
    writeFile(getFileName(), saveString);
}

