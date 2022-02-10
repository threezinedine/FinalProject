#include <iostream>
#include <string>
#include <time.h>
#include <my_time.h>
#include <string_operators.h>
#include <time_operation.h>
#include <chrono>


MyTime :: MyTime() {
    time = getCurrentTime();
}

MyTime :: MyTime(long unixTime) {
    time = unixToTm(unixTime);
}

MyTime :: MyTime(string fullTimeString) {
    time = getTimeString(fullTimeString);
}

long MyTime :: getUnixLongNumber() {
    long result = mktime(time);
    return result;
}

string MyTime :: getDateString(string joinString) {
    string yearStr = getStringWithZero(to_string(time->tm_year + 1900), 4);
    string monthStr = getStringWithZero(to_string(time->tm_mon + 1), 2);
    string dayStr = getStringWithZero(to_string(time->tm_mday), 2);
    return yearStr + joinString + monthStr + joinString + dayStr;
}

string MyTime :: getDayTimeString(string joinString) {
    string hourStr = getStringWithZero(to_string(time->tm_hour), 2);
    string minuteStr = getStringWithZero(to_string(time->tm_min), 2);
    string secondStr = getStringWithZero(to_string(time->tm_sec), 2);
    return hourStr + joinString + minuteStr + joinString + secondStr;
}

string MyTime :: getFullTimeString() {
    return getDateString("-") + " " + getDayTimeString(":");
}