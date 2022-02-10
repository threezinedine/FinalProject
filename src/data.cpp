#include <iostream>
#include <data.h>
#include <data_row.h>
#include <log_file.h>
#include <string>

using namespace std;


Data :: Data (LogFile *logFile) {
    this->logFile = logFile;
    dataRows = new DataRow*[10];
}

void Data :: appendDataRow(DataRow *dataRow) {
    dataRows[size++] = dataRow;
}

void Data :: sort() {
    cout << "Sorted";
}

string Data :: getSaveDataCSV() {
    string result = "";
    int i = 0;
    for (i=0; i<size; i++) {
        if (i==0) {
            result += dataRows[i]->getHeaderLine() + '\n';
        }
        result += dataRows[i]->getSaveDataCSV();
        if (i != size - 1) {
            result += '\n';
        }
    }
    return result;
}

string Data :: getSaveDataTXT() {
    string result = "";
    int i = 0;
    for (i=0; i<size; i++) {
        result += dataRows[i]->getSaveDataTXT();
        if (i != size - 1) {
            result += '\n';
        }
    }
    return result;
}