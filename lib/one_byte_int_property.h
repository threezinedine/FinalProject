#pragma once 
#include <iostream>
#include "property.h"


/**
 * Abstract class for 1-byte property (int)
 */
class OneByteIntProperty : public Property {
    protected:
        int numByte = 1;
        int valueInt;

        virtual void setValueInt(int newValueInt) = 0;
        void updateHexValue();
        void updateValue();
    
    public:
        int getNumByte();
        void setValue(string);
        void setHexValue(string);
        virtual string getPropertyName() = 0;

        int getSumStoreByte();
        int compareTo(IProperty* obj);
};