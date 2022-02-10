#include <iostream>
#include <string>
#include <sensor_data_file.h>
#include <log_file.h>
#include <data.h>
#include <data_row.h>
#include <vector>
#include <file_operations.h>

using namespace std;


SensorDataFile :: SensorDataFile(string inputFileName, LogFile *logFile) {
    this->logFile = logFile;
    this->fileName = inputFileName;
}

Data* SensorDataFile :: readData() {
    Data *returnData = new Data(logFile);
    vector<string> data = readFile(getFileName());

    //delete header line
    data.erase(data.begin());

    for (string s: data) {
        DataRow *dataRow = new DataRow(s, logFile);
        if (dataRow->isValidDataRow(s)) {
            returnData->appendDataRow(dataRow);
        }
    }
    return returnData;
}

string SensorDataFile :: getSaveString(Data* data) {
    saveString = data->getSaveDataCSV();
    return saveString;
}
