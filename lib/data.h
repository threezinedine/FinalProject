#pragma once
#include<iostream>
#include<string>
#include "data_row.h"
#include "log_file.h"


class Data{
    private:
        DataRow **dataRows;
        LogFile *logFile;
        int size = 0;

    public:
        Data(LogFile* logFile);
        void appendDataRow(DataRow* dataRow);
        void sort();
        string getSaveDataCSV();
        string getSaveDataTXT();
};