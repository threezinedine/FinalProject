#pragma once
#include <iostream>
#include <string>
#include "i_message.h"
#include "error_message.h"

/**
 * Class receives param from command line and extracts data to get user's requirments.
 * 
 * @param args: The number of input strings from command line.
 * @param argv: The list of input strings from command line.
 */
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

        /**
         * @return input file name.
         */
        string getInputFileName();

        /**
         * @return output file name.
         */
        string getOputputFileName();

        /**
         * @return property's name that user's wanna sort file by.
         */
        string getSortType();

        /**
         * @return `IMessage*` obejct that stores an error message.
         */
        IMessage* getMsg();

        /**
         * Method returns the order of sorting process.
         * 
         * @return `true` is ascending order, `false` is descending order.
         */
        bool getSortOrder();

        /**
         * @return `true` if user's input is a valid command, vice versa.
         */
        bool isValidCommand();

        /**
         * @return `true` if user's input file is .txt extension (binary packet), 
         *              `false` if the file is .csv extension (sensor data).
         */
        bool isInputTXT();

        /**
         * @return `true` if user's call sorting mode, and vice versa.
         */
        bool onSortingMode();
};