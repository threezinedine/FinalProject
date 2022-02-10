#pragma once
#include<iostream>
#include<string.h>
#include "log_file.h"
#include "i_file.h"
#include "data.h"


class IDataFile : public IFile{
    public:
        virtual string getFileName() = 0;
        virtual void save() = 0;

        virtual string getSaveString(Data*) = 0;
        virtual LogFile* getLogFile() = 0;
        virtual bool canReadData() = 0;
        virtual bool isFileExist() = 0;
        virtual bool warningFileExit() = 0;
        virtual Data* readData() = 0;
};
