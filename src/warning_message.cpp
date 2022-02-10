#include <iostream>
#include <warning_message.h>


WarningMessage :: WarningMessage(string messageName, string messageScript) {
    this->messsageName = messageName;
    this->messageScript = messageScript;
}

string WarningMessage :: getMessageName() {
    return messsageName;
}

string WarningMessage :: getMessageScript() {
    return messageScript;
}

string WarningMessage :: getMessage() {
    return "Warning " + getMessageName() + ": " + getMessageScript();
}