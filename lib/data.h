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
        static int NumRow; 
        Data(LogFile* logFile);
        void appendDataRow(DataRow* dataRow);
        void sort(string sortType, bool ascendingOrder);
        string getSaveDataCSV();
        string getSaveDataTXT();
};