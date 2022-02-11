#include <iostream>
#include <property.h>
#include <log_file.h>


string Property :: getValue() {
    return value;
}

string Property :: getHexValue() {
    return hexValue;
}

LogFile* Property :: getLogFile() {
    return logFile;
}

bool Property :: isEmpty() {
    return empty;
}
