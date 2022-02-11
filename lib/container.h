#pragma once
#include <iostream>
#include "command_line_handlder.h"
#include "i_data_file.h"
#include "data.h"
#include "log_file.h"

using namespace std;


/**
 *  The class contains all needed Part and provides 
 *      using interface 
 * 
 *  @param args: Number of input strings from command line input.
 *  @param argv: List of input strings from command line input.
 */
class Container {
    private:
        CommandLineHandler* commandLineHandler;
        IDataFile* input;
        IDataFile* output;
        Data* data;
        LogFile* logFile;
        bool error = false;

    public:
        Container(int args, char* argv[]);

        /**
         * @return `true` if there is exist a bug in the programe,
         *          `false` if there is no.
         */
        bool isError();

        /**
         *  @return `LogFile*` object that stores error messages.
         */
        LogFile* getLogFile();

        /**
         * Method converts the file to another format.
         */
        void transfer();
};