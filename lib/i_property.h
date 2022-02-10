#pragma once
#include <iostream>
#include <string.h>
#include "log_file.h"


class IProperty {
    public: 
        virtual int getNumByte() = 0;
        virtual string getValue() = 0;
        virtual string getHexValue() = 0;
        virtual string getPropertyName() = 0;
        virtual LogFile* getLogFile() = 0;

        virtual void setValue(string) = 0; 
        virtual void setHexValue(string) = 0;

        virtual bool isEmpty() = 0;
        virtual int getSumStoreByte() = 0;
};
