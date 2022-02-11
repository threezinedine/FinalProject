#include <iostream>
#include <binary_packet_file.h>
#include <data.h>
#include <log_file.h>
#include <file_operations.h>


BinaryPacketFile :: BinaryPacketFile(string fileName, LogFile* logFile) {
    this->logFile = logFile;
    this->fileName = fileName;
}

string BinaryPacketFile :: getSaveString(Data* data) {
    saveString = data->getSaveDataTXT();
    return saveString;
}

Data* BinaryPacketFile :: readData() {
    /*
        Step 1: Read Data from fileName
        Step 2: Divide read data by '\n'
        Step 3: Check if data line is valid data row -> append to the data object.
        Step 4: Return data object
    */

    Data *returnData = new Data(logFile);
    vector<string> data = readFile(getFileName());
    int row = 0;

    for (string s: data) {
        if (s != ""){
            DataRow *dataRow = new DataRow(s, logFile);
            if (dataRow->isValidDataRow()) {
                returnData->appendDataRow(dataRow);
            }
            Data::NumRow ++;    // add one to the number of read row (not need be valid data row)
        }
    }
    return returnData;
}