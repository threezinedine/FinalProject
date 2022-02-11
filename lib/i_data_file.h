#pragma once
#include<iostream>
#include<string.h>
#include "log_file.h"
#include "i_file.h"
#include "data.h"

/**
 * The interface for data files, that inherits from IFile interface.
 */
class IDataFile : public IFile{
    public:
        /**
         * Getter for file name property.
         */
        virtual string getFileName() = 0;

        /**
         * Method that is inherited from IFile interface. 
         *          This method saves data to file with the name is filename property.
         */
        virtual void save() = 0;

        /**
         * @param Data*: Pointer of Data object.
         * @return a `string` that will be saved in save() method.
         */
        virtual string getSaveString(Data*) = 0;

        /**
         *  @return `LogFile*` object that stores error messages.
         */
        virtual LogFile* getLogFile() = 0;

        /**
         * @return `true` if file can be read, vice versa.
         */
        virtual bool canReadData() = 0;

        /**
         * @return `true` if file exists, vice versa.
         */
        virtual bool isFileExist() = 0;

        /**
         * Method that asks user whether he/she wanna override the file if it already exists.
         * 
         * @return `true` if user enters 'y' answer, `false` otherwise.
         */
        virtual bool warningFileExit() = 0;

        /**
         * @return `Data*` that is read from filename(in .csv or .txt).
         */
        virtual Data* readData() = 0;
};
