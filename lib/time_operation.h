#pragma once
#include <iostream>
#include <time.h>
#include <string>

using namespace std;


tm* getCurrentTime();

tm* getTimeArr(int*);

int* stringToTimeData(string);

tm* getTimeString(string);

tm* unixToTm(long);