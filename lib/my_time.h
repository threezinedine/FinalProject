#pragma once
#include<iostream>
#include<string>
#include<time.h>

using namespace std;


class MyTime {
    private: 
        tm* time;

    public:
        MyTime();
        MyTime(long unix_num);
        MyTime(string fullTimeString);

        long getUnixLongNumber();

        string getDateString(string joinString);
        string getDayTimeString(string joinString);
        string getFullTimeString();

};
