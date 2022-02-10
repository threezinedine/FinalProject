#pragma once
#include<iostream>
#include<string>

using namespace std;


class IFile {
    public: 
        virtual string getFileName() = 0;
        virtual void save() = 0;
};
