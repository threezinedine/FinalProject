#pragma once
#include <iostream>
#include <i_message.h>
#include <string>


class WarningMessage : public IMessage {
    private:
        string messsageName;
        string messageScript;

    public:
        WarningMessage (string messageName, string messsageScript);
        string getMessageName();
        string getMessageScript();
        string getMessage();
};