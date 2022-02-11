#pragma once
#include <iostream>
#include <string>
#include "property.h"


/**
 * Abstract class for 4-bit property.
 */
class FourByteProperty : public Property {
    protected:
        int numByte = 4;    // fix value for numByte
        
        virtual void updateValue() = 0;
        virtual void updateHexValue() = 0;

    public:
        int getNumByte();
        virtual void setValue(string) = 0;
        virtual void setHexValue(string) = 0;
        virtual string getPropertyName() = 0;

        int getSumStoreByte();
        virtual int compareTo(IProperty* obj) = 0;
};