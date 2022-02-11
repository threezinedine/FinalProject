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


class DataRow{
    private:
        LogFile* logFile;
        vector<IProperty*> properties = {};

        int numProperties;
        IProperty* length;
        IProperty* checkSum;

        bool isCSVData(string);
        void setPropertiesWithCSV(string);
        void setPropertiesWithTXT(string);

    public:
        DataRow(string input, LogFile* logFile);
        bool isValidDataRow(string inputStr);
        string getHeaderLine();
        string getSaveDataCSV();
        string getSaveDataTXT();
        IProperty* getLength();
        IProperty* getCheckSum();

        int getNumProperties();
        IProperty* getPropertyByIndex(int);
};