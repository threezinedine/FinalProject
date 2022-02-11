#pragma once
#include <iostream>
#include "four_byte_property.h"
#include "my_time.h"


class TimeProperty : public FourByteProperty {
    private:
        MyTime* time;
        long valueLong;
        
    protected:
        string propertyName = "Time";

        void setValueLong(long valueLong);
        void updateHexValue();
        void updateValue();

    public:
        TimeProperty(LogFile* logFile);
        TimeProperty(long valueLong, LogFile* logFile);

        string getPropertyName();

        void setValue(string valueStr);
        void setHexValue(string hexValueStr);

        int compareTo(IProperty* obj);
};