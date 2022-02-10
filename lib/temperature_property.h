#pragma once
#include <iostream>
#include <string>
#include <property.h>


class TemperatureProperty : public Property {
    private:
        int numByte = 4;
        float valueFloat;
        string propertyName = "Temperature";

        void setValueFloat(float valueFloat);

    protected:
        void updateHexValue();
        void updateValue();

    public:
        TemperatureProperty(LogFile* logFile);
        TemperatureProperty(float valueFloat, LogFile* logFile);

        int getNumByte();
        string getValue();
        string getHexValue();
        string getPropertyName();
        LogFile* getLogFile(); 

        void setValue(string valueStr);
        void setHexValue(string hexValueStr);

        bool isEmpty();
        int getSumStoreByte(); 
        int compareTo(IProperty* obj);
};