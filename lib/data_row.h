#pragma once
#include<iostream>
#include "log_file.h"
#include <string>
#include "i_property.h"
#include <vector>
#include "sensor_id_property.h"
#include "humidity_property.h"
#include "temperature_property.h"
#include "time_operation.h"

using namespace std;


/**
 * Class stores one line of data file.
 * 
 * @param input: input string -> data.
 * @param LogFile*: object stores error messages during converting process.
 */
class DataRow{
    private:
        LogFile* logFile;
        vector<IProperty*> properties = {};

        int numProperties;
        IProperty* length;
        IProperty* checkSum;

        bool isCSVData(string);             // return true if input string is .csv format
        void setPropertiesWithCSV(string);  // using to store string with .csv format.
        void setPropertiesWithTXT(string);  // using to store string with .txt format.

        // bool isValidDataRowCSV();
        // bool isValidDataRowTXT();

    public:
        DataRow(string input, LogFile* logFile);

        /**
         * @return `true` if data is valid, vice versa.
         */
        bool isValidDataRow();

        /**
         * @return header line with each property's name.
         */
        string getHeaderLine();

        /**
         * @return `string` with .csv format. Example, 02,2020-12-31 17:00:00,19.1,45
         */
        string getSaveDataCSV();

        /**
         * @return `string` with form .txt format. Example, 00 0e 02 5f ed a1 20 41 99 5c 29 3b 49 ff
         */
        string getSaveDataTXT();

        /**
         * @return `IProperty*` - store length byte of the data row.
         */
        IProperty* getLength();

        /**
         * @return `IProperty*` - store checkSum byte of the data row.
         */
        IProperty* getCheckSum();

        /**
         * @return number of properties in the data row.
         */
        int getNumProperties();

        /**
         * Get Propery by the index
         * 
         * @param index: the index of the property.
         * @return `IProperty` by index.
         */
        IProperty* getPropertyByIndex(int);
};