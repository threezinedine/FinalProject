#include <iostream>
#include "i_data_file.h"
#pragma once
#include "data.h"
#include "log_file.h"
#include <string>


class DataFile : public IDataFile {
    protected:
        string fileName;
        string saveString;
        LogFile* logFile;


    public:
        virtual string getSaveString(Data*) = 0;
        string getFileName();
        void save();

        virtual Data* readData() = 0;
        bool warningFileExit();
        LogFile* getLogFile();
        bool canReadData();
        bool isFileExist();
};