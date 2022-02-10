#include <iostream>
#include <string>
#include <error_message.h>

using namespace std;


ErrorMessage :: ErrorMessage (string messageName, string messageScript) {
    this->messageName = messageName;
    this->messageScript = messageScript;
}

string ErrorMessage :: getMessageName() {
    return messageName;
}

string ErrorMessage :: getMessageScript() {
    return messageScript;
}

string ErrorMessage :: getMessage() {
    return "Error " + getMessageName() + ": " + getMessageScript();
}

