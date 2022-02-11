#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std; 


/**
 * Divide String by `divideChar`. 
 *          Example, divideChar = ' ', "Hello World" -> vect<string> {"Hello", "World"}
 * 
 * @param inputStr: The source string
 * @param divideChar: The pivot character that is used for dividing
 */
vector<string> divideString(string inputStr, char divideChar);

/**
 * Convert the string to int
 */
int stringToInt(string);

/**
 * Convert the string to float.
 */
float stringToFloat(string);

/**
 * Fill the string with pre 0s. 
 *      For example, 1 -> 01
 * 
 * @param input: the source string.
 * @param num: The length of output string
 */
string getStringWithZero(string, unsigned int);

/**
 * Concat all strings into the final one, with the `char` is between 2 strings.
 * 
 * @param strings: vector of strings
 * @param joinChar: the character lies between 2 strings.
 */
string joinString(vector<string>, char);

/**
 * Convert int number to hex string.
 */
string intToHexString(int);

/**
 * Convert hex string to int number.
 */
int hexStringToInt(string);

/**
 * Convert float number to hex string.
 */
string floatToHexString(float);

/**
 * Convert hex string to float number.
 */
float hexStringToFloat(vector<string>);

/**
 * Convert long number to hex string.
 */
string longToHexString(long);

/**
 * Convert hex string to long number.
 */
long hexStringToLong(vector<string>);