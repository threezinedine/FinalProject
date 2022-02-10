#pragma once
#include <iostream>
#include "property.h"
#include "my_time.h"


class TimeProperty : public Property {
    private:
        int numByte = 4;
        long valueLong;
        string propertyName = "Time";
        MyTime* time;

        void setValueLong(long valueLong);
        
    protected:
        void updateHexValue();
        void updateValue();

    public:
        TimeProperty(LogFile* logFile);
        TimeProperty(long valueLong, LogFile* logFile);

        int getNumByte();
        long getValueLong();
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