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
    Data *returnData = new Data(logFile);
    vector<string> data = readFile(getFileName());
    int row = 0;

    for (string s: data) {
        if (s != ""){
            DataRow *dataRow = new DataRow(s, logFile);
            if (dataRow->isValidDataRow()) {
                returnData->appendDataRow(dataRow);
            }
            Data::NumRow ++;
        }
    }
    return returnData;
}