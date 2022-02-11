#pragma once
#include <iostream>
#include <string>
#include "i_message.h"
#include "error_message.h"


class CommandLineHandler {
    private:
        string inputFile;
        string outputFile;
        string sortType;
        bool sortingOrder = true;
        IMessage* msg = new ErrorMessage("05", "Invalid Command");
        bool valid = true;

    public:
        CommandLineHandler(int args, char **argv);

        string getInputFileName();
        string getOputputFileName();
        string getSortType();
        IMessage* getMsg();
        bool getSortOrder();
        bool isValidCommand();
        bool isInputTXT();
        bool onSortingMode();
};