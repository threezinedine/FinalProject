#pragma once
#include <iostream>
#include "i_message.h"
#include <string>

using namespace std;


/**
 * Class stores error messages.
 * 
 * @param messageName: name of the message
 * @param messageScript: the message's script.
 */
class ErrorMessage : public IMessage {
    private: 
        string messageName;
        string messageScript;

    public:
        ErrorMessage(string messageName, string messageScript);

        /**
         * Getter of message name
         */
        string getMessageName();

        /**
         * Getter of message's script
         */
        string getMessageScript();

        /**
         * @return full form of message.
         */
        string getMessage();
};