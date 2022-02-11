#pragma once
#include<iostream>
#include<string>
#include "i_file.h"
#include "my_time.h"
#include "i_message.h"
#include <vector>

using namespace std;


class LogFile: public IFile {
    private:
        string inputFileName;
        string outputFileName;
        string fileName;
        MyTime* logTime;
        vector<IMessage*> messages; 

        string getCompleteMessage();
    
    public:
        LogFile(string, string);
        string getFileName();
        void addMessage(IMessage*);
        string getMessage();
        void save();
};
