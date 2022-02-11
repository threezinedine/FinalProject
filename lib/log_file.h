#pragma once
#include<iostream>
#include<string>
#include "i_file.h"
#include "my_time.h"
#include "i_message.h"
#include <vector>

using namespace std;

/**
 * Class stores all error messages during running process. 
 *         LogFile is inherited from IFile interface.
 * 
 * @param inputFileName: The name of the input file.
 * @param outputFileName: The name of the output file.
 */
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

        /**
         * @return filename in where log data will be saved.
         */
        string getFileName();

        /**
         * Add an `IMessage*` to log file.
         */
        void addMessage(IMessage*);

        /**
         * @return message string
         */
        string getMessage();

        /**
         * Save log messages.
         */
        void save();
};
