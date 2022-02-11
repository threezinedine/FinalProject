#include <iostream>
#include <data.h>
#include <data_row.h>
#include <log_file.h>
#include <string>
#include <sorting_algo.h>
#include <i_comparer.h>
#include <warning_message.h>
#define MAX_ROWS 25000
using namespace std;


Data :: Data (LogFile *logFile) {
    this->logFile = logFile;
    dataRows = new DataRow*[MAX_ROWS];
}

void Data :: appendDataRow(DataRow *dataRow) {
    dataRows[size++] = dataRow;
}

void Data :: sort(string sortType, bool ascendingOrder) {
    if (size <= 0) {
        logFile->addMessage(new WarningMessage("11", "No data"));
        return;
    }


    DataRow *obj = dataRows[0];
    int i, j, index;
    for (i=0; i<obj->getNumProperties(); i++) {
        if (sortType == obj->getPropertyByIndex(i)->getPropertyName()){
            index = i;
            break;
        }
    }


    class SortByID : public IComparer<DataRow*> {
        private: 
            int index;
        public:
            SortByID(int index) {
                this->index = index;
            }
            int compareTo(DataRow* obj1, DataRow* obj2) {
                return obj1->getPropertyByIndex(index)->compareTo(obj2->getPropertyByIndex(index));
            }
    };
    IComparer<DataRow*>* compare = new SortByID(index);
    // swrap<DataRow*>(dataRows[0], dataRows[1]);
    // bubbleSort<DataRow*>(dataRows, size, ascendingOrder, compare);
    int swrapNum;


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
    /*
        Step 1: Get header line
        Step 2: Get .csv format data for each dataRow
    */
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
    /*
        Get .txt format for each dataRow
    */
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

int Data::NumRow = 1;   // intial Data row is 1 (exclude header line)