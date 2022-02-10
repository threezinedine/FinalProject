#pragma once
#include <iostream>
#include <property.h>


class SensorIDProperty : public Property {
    private:
        int numByte = 1;
        int valueInt;
        string propertyName = "Sensor ID";

        void setValueInt(int newValueInt);

    protected:
        void updateHexValue();
        void updateValue();

    public:
        SensorIDProperty(LogFile* logFile);
        SensorIDProperty(int valueInt, LogFile* logFile);

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