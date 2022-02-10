#include <iostream>
#include <data.h>
#include <data_row.h>
#include <log_file.h>
#include <string>
#include <sorting_algo.h>
#include <i_comparer.h>

using namespace std;


Data :: Data (LogFile *logFile) {
    this->logFile = logFile;
    dataRows = new DataRow*[10];
}

void Data :: appendDataRow(DataRow *dataRow) {
    dataRows[size++] = dataRow;
}

void Data :: sort(string sortType, bool ascendingOrder) {
    class SortByID : public IComparer<DataRow*> {
        int compareTo(DataRow* obj1, DataRow* obj2) {
            int index = 0;
            return obj1->getPropertyByIndex(index)->compareTo(obj2->getPropertyByIndex(index));
        }
    };
    IComparer<DataRow*>* compare = new SortByID();
    // swrap<DataRow*>(dataRows[0], dataRows[1]);
    // bubbleSort<DataRow*>(dataRows, size, ascendingOrder, compare);
    int swrapNum;
    int i, j;

    if (ascendingOrder) {
        swrapNum = 1;
    }
    else {
        swrapNum = -1;
    }

    for (i=0; i<size-1; i++) {
        for (j=i+1;j<size;j++){
            if (compare->compareTo(dataRows[i], dataRows[j]) == swrapNum){
                DataRow* temp = dataRows[i];
                dataRows[i] = dataRows[j];
                dataRows[j] = temp;
            }
        }
    }
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