#pragma once
#include <iostream>
#include <string>
#include "data_file.h"
#include "data.h"
#include "log_file.h"


/**
 * Class to save Data to file name, or read Data from file name in CSV format.
 * 
 * @param name: file name of to save data
 */
class SensorDataFile : public DataFile {
    public:
        SensorDataFile(string name, LogFile* logFile);

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