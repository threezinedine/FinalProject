#pragma once
#include<iostream>
#include<string>

using namespace std;


class MyTime {
    private: 
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;

        void setTimeByTimeT(tm *time);

    public:
        MyTime();
        MyTime(long unix_num);
        MyTime(string fullTimeString);

        string getDateString(string joinString);
        string getDayTimeString(string joinString);
        string getFullTimeString();

};
