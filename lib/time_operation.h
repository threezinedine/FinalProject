#pragma once
#include <iostream>
#include <time.h>
#include <string>

using namespace std;


/**
 * Get current local time.
 */
tm* getCurrentTime();

/**
 * Get time with input data(array)
 * 
 * @param arr: int array with min 6 elements.
 */
tm* getTimeArr(int*);

/**
 * Convert time string to arr
 * 
 * @param timeStr: the string with format format YYYY:MM:DD HH:MM:SS
 */
int* stringToTimeData(string);


/**
 * Get time from string
 * 
 * @param timeStr: the string with format format YYYY:MM:DD HH:MM:SS
 */
tm* getTimeString(string);

/**
 * Convert long value (unix timestampe) to tm
 */
tm* unixToTm(long);