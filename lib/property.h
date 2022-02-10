#pragma once
#include<iostream>
#include<string>
#include "i_property.h"
#include "log_file.h"


class Property : public IProperty{
    protected:
        bool empty = true;
        string name;
        string value;
        string hexValue;
        LogFile* logFile;

        virtual void updateHexValue() = 0;
        virtual void updateValue() = 0;

    public:
        virtual int getNumByte() = 0;
        virtual string getHexValue() = 0;
        virtual string getPropertyName() = 0;
        virtual LogFile* getLogFile() = 0;

        virtual void setValue(string) = 0; 
        virtual void setHexValue(string) = 0;

        virtual bool isEmpty() = 0;
        virtual int getSumStoreByte() = 0;
};