#pragma once
#include <iostream>
#include "command_line_handlder.h"
#include "i_data_file.h"
#include "data.h"
#include "log_file.h"

using namespace std;


class Container {
    private:
        CommandLineHandler* commandLineHandler;
        IDataFile* input;
        IDataFile* output;
        Data* data;
        LogFile* logFile;

    public:
        Container(int args, char* argv[]);
        LogFile* getLogFile();
        void transfer();
};