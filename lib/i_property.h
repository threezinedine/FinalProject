#pragma once
#include <iostream>
#include <string.h>
#include "log_file.h"


/**
 * Interface for property.
 */
class IProperty {
    public: 
        /**
         * Getter for numByte attribute.
         */
        virtual int getNumByte() = 0;

        /**
         * Getter for value attribute.
         */
        virtual string getValue() = 0;

        /**
         * Getter for hexValue attribute.
         */
        virtual string getHexValue() = 0;

        /**
         * Getter for propertyName attribute.
         */
        virtual string getPropertyName() = 0;

        /**
         * Getter for logFile attribute.
         */
        virtual LogFile* getLogFile() = 0;

        /**
         * Setter for value attribute.
         */
        virtual void setValue(string) = 0; 

        /**
         * Setter for hexValue attribute.
         */
        virtual void setHexValue(string) = 0;

        /**
         * @return `true` if data is empty, vice versa.
         */
        virtual bool isEmpty() = 0;

        /**
         * @return 2nd of the sum of stored bytes.
         */
        virtual int getSumStoreByte() = 0;

        /**
         * Compare with another Iproperty.
         * 
         * @return `1` if greater, `0` if equal, and `-1` if less than.
         */
        virtual int compareTo(IProperty* obj) = 0;
};
