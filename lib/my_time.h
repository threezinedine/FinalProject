#pragma once
#include<iostream>
#include<string>
#include<time.h>

using namespace std;


/**
 * Time class with operation.
 */
class MyTime {
    private: 
        tm* time;

    public:
        MyTime();
        MyTime(long unix_num);
        MyTime(string fullTimeString);

        /**
         * @return `long` value of unix timestamp.
         */
        long getUnixLongNumber();

        /**
         * @return time with format YYYY{joinString}MM{joinString}DD HH:MM:SS
         */
        string getDateString(string joinString);

        /**
         * @return time with format HH{joinString}MM{joinString}SS
         */
        string getDayTimeString(string joinString);

        /**
         * @return time with format YYYY-MM-DD HH:MM:SS
         */
        string getFullTimeString();

};
