#include <iostream>
#include <string>
#include <time.h>
#include <my_time.h>
#include <string_operators.h>


MyTime :: MyTime() {
    time_t t;
    tm *now = localtime(&t); 
    setTimeByTimeT(now);
}

MyTime :: MyTime(long unixTime) {
    time_t t;
    tm *now = localtime(&t); 
    setTimeByTimeT(now);
}

MyTime :: MyTime(string fullTimeString) {
    time_t t;
    tm *now = localtime(&t); 
    setTimeByTimeT(now);
}

void MyTime :: setTimeByTimeT(tm *time) {
    year = 2022;
    month = 2;
    day = 9;

    hour = 22;
    minute = 20;
    second = 0;
}

string MyTime :: getDateString(string joinString) {
    string yearStr = getStringWithZero(to_string(year), 4);
    string monthStr = getStringWithZero(to_string(month), 2);
    string dayStr = getStringWithZero(to_string(day), 2);
    return yearStr + joinString + monthStr + joinString + dayStr;
}

string MyTime :: getDayTimeString(string joinString) {
    string hourStr = getStringWithZero(to_string(hour), 2);
    string minuteStr = getStringWithZero(to_string(minute), 2);
    string secondStr = getStringWithZero(to_string(second), 2);
    return to_string(hour) + joinString + to_string(minute) + joinString + to_string(second);
}

string MyTime :: getFullTimeString() {
    return getDateString("-") + " " + getDayTimeString(":");
}