#pragma once
#include <iostream>
#include "data_file.h"
#include "log_file.h"
#include "data.h"
#include <string>


class BinaryPacketFile : public DataFile{
    protected:
        string getSaveString(Data*);

    public:
        BinaryPacketFile(string name, LogFile* logFile);
        Data* readData();
};

