#pragma once
#include<iostream>
#include<string>

using namespace std;


/**
 * Interface for a file.
 */
class IFile {
    public: 
        /**
         * Getter for filename.
         */
        virtual string getFileName() = 0;

        /**
         * Save file to the filename.
         */
        virtual void save() = 0;
};
