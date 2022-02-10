#pragma once
#include <iostream>
#include <string>
#include <property.h>


class HumidityProperty : public Property {
        int numByte = 1;
        int valueInt;
        string propertyName = "Humidity";

        void setValueInt(int newValueInt);

    protected:
        void updateHexValue();
        void updateValue();

    public:
        HumidityProperty(LogFile* logFile);
        HumidityProperty(int valueInt, LogFile* logFile);

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