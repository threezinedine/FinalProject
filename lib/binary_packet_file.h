#pragma once
#include <iostream>
#include "data_file.h"
#include "log_file.h"
#include "data.h"
#include <string>


/**
 * Class to save Data to file name, or read Data from file name in TXT format.
 * 
 * @param name: file name of to save data
 * @param logFile: the LogFile object store error messages.
 */
class BinaryPacketFile : public DataFile{
    public:
        BinaryPacketFile(string name, LogFile* logFile);

        /**
         * convert from `Data*` to save string.
         */
        string getSaveString(Data*);

        /**
         * get Data from filename.
         * 
         * @return `Data*` that stores all info.
         */
        Data* readData();
};

