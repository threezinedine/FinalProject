#pragma once
#include <iostream>
#include <string>
#include "log_file.h"


class CommandLineHandler {
    private:
        string inputFile;
        string outputFile;
        string sortType;
        bool sortingOrder;
        LogFile* logFile;
        bool valid = true;

    public:
        CommandLineHandler(int args, char **argv, LogFile* logFile);

        string getInputFileName();
        string getOputputFileName();
        string getSortType();
        bool getSortOrder();
        LogFile* getLogFile();
        bool isValidCommand();
        bool isInputTXT();
        bool onSortingMode();
};