#pragma once
#include <iostream>
#include <property.h>
#include <string>


class CheckSumProperty : public Property {
    private:
        int numByte = 1;
        int valueInt;
        string propertyName = "Check Sum";

        void setValueInt(int newValueInt);

    protected:
        void updateHexValue();
        void updateValue();

    public:
        CheckSumProperty(LogFile* logFile);
        CheckSumProperty(int valueInt, LogFile* logFile);

        int getNumByte();
        string getValue();
        string getHexValue();
        string getPropertyName();
        LogFile* getLogFile(); 

        void setValue(string valueStr);
        void setHexValue(string hexValueStr);

        bool isEmpty();
        int getSumStoreByte();
        int compareTo(IProperty*);
};