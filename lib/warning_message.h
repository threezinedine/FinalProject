#pragma once
#include <iostream>
#include <i_message.h>
#include <string>


/**
 * Class stores warning messages.
 * 
 * @param messageName: name of the message
 * @param messageScript: the message's script.
 */
class WarningMessage : public IMessage {
    private:
        string messsageName;
        string messageScript;

    public:
        WarningMessage (string messageName, string messsageScript);

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