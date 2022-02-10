#include <iostream>
#include <time.h>
#include <time_operation.h>
#include <vector>
#include <string_operators.h>


tm* getCurrentTime() {
    time_t t = time(0);
    tm *result = localtime(&t);
    return result;
}

tm* getTimeArr(int* arr) {
    tm* time = getCurrentTime();
    time->tm_year = arr[0] - 1900;
    time->tm_mon = arr[1] - 1;
    time->tm_mday = arr[2];
    time->tm_hour = arr[3];
    time->tm_min = arr[4];
    time->tm_sec = arr[5];
    return time;
}

int* stringToTimeData(string timeStr) {
    int* timeData = new int[6];
    vector<string> dateTime = divideString(timeStr, ' ');
    vector<string> date = divideString(dateTime.front(), '-');
    vector<string> time = divideString(dateTime.back(), ':');
    int i = 0;

    for (string s:date) {
        timeData[i++] = stringToInt(s);
    }

    for (string s:time) {
        timeData[i++] = stringToInt(s);
    }
    return timeData;
}

tm* getTimeString(string timeStr) {
    int* timeData = stringToTimeData(timeStr);
    return getTimeArr(timeData);
}

tm* unixToTm(long int seconds) {
    time_t num = seconds;
    time_t* numPtr = &num;
    char* timeStr = ctime(numPtr);
    string time = (string)timeStr;
    int* timeArr = new int[6];

    vector<string> timeData = divideString(time, ' ');
    timeData.erase(timeData.begin());

    int month;
    string monthString = timeData.front();
    if (monthString == "Jan") {
        month = 1;
    }
    else if (monthString == "Feb") {
        month = 2;
    } 
    else if (monthString == "Mar") {
        month = 3;
    }
    else if (monthString == "Apr") {
        month = 4;
    }
    else if (monthString == "May") {
        month = 5;
    }
    else if (monthString == "Jun") {
        month = 6;
    }
    else if (monthString == "Jul") {
        month = 7;
    }
    else if (monthString == "Aug") {
        month = 8;
    }
    else if (monthString == "Sep") {
        month = 9;
    }
    else if (monthString == "Oct") {
        month = 10;
    }
    else if (monthString == "Nov") {
        month = 11;
    }
    else if (monthString == "Dec") {
        month = 12;
    }

    timeData.erase(timeData.begin());
    timeArr[0] = stringToInt(timeData.back());
    timeArr[1] = month;
    timeArr[2] = stringToInt(timeData.front());
    timeData.erase(timeData.begin());

    string dayTimeStr = timeData.front();
    vector<string> dayTimeVector = divideString(dayTimeStr, ':');

    timeArr[3] = stringToInt(dayTimeVector.front());
    dayTimeVector.erase(dayTimeVector.begin());

    timeArr[4] = stringToInt(dayTimeVector.front());
    dayTimeVector.erase(dayTimeVector.begin());

    timeArr[5] = stringToInt(dayTimeVector.front());
    dayTimeVector.erase(dayTimeVector.begin());
 
    // Return the time
    return getTimeArr(timeArr);
}