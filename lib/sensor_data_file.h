#pragma once
#include <iostream>
#include <string>
#include "data_file.h"
#include "data.h"
#include "log_file.h"


class SensorDataFile : public DataFile {
    protected:
        string getSaveString(Data*);

    public:
        SensorDataFile(string name, LogFile* logFile);
        Data* readData();
};