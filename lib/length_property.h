#pragma once
#include <iostream>
#include <property.h>
#include <string>
#include <log_file.h>


class LengthProperty : public Property {
    private:
        int numByte = 1;
        int valueInt;
        string propertyName = "Length";

        void setValueInt(int newValueInt);

    protected:
        void updateHexValue();
        void updateValue();

    public:
        LengthProperty(LogFile* logFile);
        LengthProperty(int valueInt, LogFile* logFile);

        int getNumByte();
        string getValue();
        string getHexValue();
        string getPropertyName();
        LogFile* getLogFile(); 

        void setValue(string valueStr);
        void setHexValue(string hexValueStr);

        bool isEmpty();
        int getSumStoreByte(); 
};