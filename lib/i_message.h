#pragma once
#include<iostream>
#include<string>

using namespace std;


class IMessage{
    public:
        virtual string getMessageName() = 0;
        virtual string getMessageScript() = 0;
        virtual string getMessage() = 0;
};
