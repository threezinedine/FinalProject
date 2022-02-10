#pragma once
#include <iostream>
#include "i_message.h"
#include <string>

using namespace std;


class ErrorMessage : public IMessage {
    private: 
        string messageName;
        string messageScript;

    public:
        ErrorMessage(string messageName, string messageScript);
        string getMessageName();
        string getMessageScript();
        string getMessage();
};