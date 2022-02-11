#pragma once
#include<iostream>
#include<string>
#include "data_row.h"
#include "log_file.h"

/**
 * Class stores all data read from file
 * 
 * @param LogFile*: object to store error messages.
 */
class Data{
    private:
        DataRow **dataRows;
        LogFile *logFile;
        int size = 0;

    public:
        static int NumRow;      // store number of read data lines.
        Data(LogFile* logFile);

        /**
         * Add a `DataRow*` object to memory.
         */
        void appendDataRow(DataRow* dataRow);

        /**
         * Sorting data by property and order.
         * 
         * @param sortType: name of property that is used to sort.
         * @param ascendingOrder: `true` -> ascending order, `false` -> descending order.
         */
        void sort(string sortType, bool ascendingOrder);

        /**
         * @return `string` with .csv format. Example, 02,2020-12-31 17:00:00,19.1,45
         */
        string getSaveDataCSV();

        /**
         * @return `string` with form .txt format. Example, 00 0e 02 5f ed a1 20 41 99 5c 29 3b 49 ff
         */
        string getSaveDataTXT();
};