#include <iostream>
#include "i_data_file.h"
#pragma once
#include "data.h"
#include "log_file.h"
#include <string>


/**
 * Abstract class inherits interface IDataFile.
 */
class DataFile : public IDataFile {
    protected:
        string fileName;
        string saveString;
        LogFile* logFile;

    public:
        virtual string getSaveString(Data*) = 0;

        /**
         * Getter of filename property.
         */
        string getFileName();

        /**
         * Save data to filename.
         */
        void save();

        virtual Data* readData() = 0;

        /**
         * Ask user for overriding output file if output file exists.
         * 
         * @return `true` if user answers 'y', vice versa.
         */
        bool warningFileExit();

        /**
         * Getter of logFile
         */
        LogFile* getLogFile();

        /**
         * @return `true` if file can be read, vice versa.
         */
        bool canReadData();

        /**
         * @return `true` if file exists, vice versa.
         */
        bool isFileExist();
};