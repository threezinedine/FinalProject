#pragma once
#include<iostream>
#include<string>
#include "i_property.h"
#include "log_file.h"


/**
 * Abstract class implement IProperty interface
 */
class Property : public IProperty{
    protected:
        bool empty = true;
        string name;
        string value;
        string hexValue;
        string propertyName;
        LogFile* logFile;

        virtual void updateHexValue() = 0;
        virtual void updateValue() = 0;

    public:
        virtual int getNumByte() = 0;
        string getHexValue();
        string getValue();
        virtual string getPropertyName() = 0;
        LogFile* getLogFile();

        virtual void setValue(string) = 0; 
        virtual void setHexValue(string) = 0;

        bool isEmpty();
        virtual int getSumStoreByte() = 0;
        virtual int compareTo(IProperty* obj) = 0;
};