#pragma once
#include<iostream>
#include<string>

using namespace std;


/**
 * Interface for messages.
 */
class IMessage{
    public:
        /**
         * Getter for messageName
         */
        virtual string getMessageName() = 0;

        /**
         * Getter for messageScript
         */
        virtual string getMessageScript() = 0;

        /**
         * @return the complete message.
         */
        virtual string getMessage() = 0;
};
