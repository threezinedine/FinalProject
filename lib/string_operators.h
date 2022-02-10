#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std; 


vector<string> divideString(string inputStr, char divideChar);

int stringToInt(string);

float stringToFloat(string);

string getStringWithZero(string, unsigned int);

string joinString(vector<string>, char);

string intToHexString(int);

int hexStringToInt(string);

string floatToHexString(float);

float hexStringToFloat(vector<string>);