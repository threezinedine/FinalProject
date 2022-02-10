#include <iostream>
#include <sstream>
#include <string>
#include <vector>   
#include <string_operators.h>

using namespace std;


vector<string> divideString(string inputStr, char divideChar) {
    vector<string> result;

    unsigned int i = 0;
    string elementStr = "";
    while (i < inputStr.size()){
        if (inputStr[i] == divideChar) {
            result.push_back(elementStr);
            elementStr = "";
        }
        else {
            elementStr += inputStr[i];
        }
        i ++;
    }

    result.push_back(elementStr);

    return result;
}

int stringToInt(string inputStr) {
    stringstream geek(inputStr);

    int result;
    geek >> result;
    return result;
}

string getStringWithZero(string input, unsigned int num) {
    while (input.size() < num) {
        input = "0" + input;
    }
    return input;
}

string joinString(vector<string> strings, char joinChar) {
    string result = "";
    int index = 0;
    int length = strings.size();

    for (string s: strings) {
        result += s;
        if (index < length - 1) {
            result += joinChar;
        }
    }
    return result;
}

float stringToFloat(string str) {
    return stof(str);
}

string intToHexString(int num) {
    char hex[2];
    sprintf(hex, "%x", num);

    string hexStr = string(hex);
    hexStr = getStringWithZero(hexStr, 2);
    return hexStr; 
}

int hexStringToInt(string hexValue) {
    unsigned int temp; 
    stringstream conv;
    conv << hex << hexValue;
    conv >> temp;
    return (int) temp;
}

string floatToHexString(float valueFloat) {
    union {
        unsigned long longValue;
        float floatValue;
    } value;

    value.floatValue = valueFloat;

    return longToHexString(value.longValue);
}

float hexStringToFloat(vector<string> hexVectorString) {
    string fullString = "";
    union {
        long longValue;
        float floatValue;
    } value;

    value.longValue = hexStringToLong(hexVectorString);
    return value.floatValue;
}

string longToHexString(long value) {
    char hex[8];
    sprintf(hex, "%lx", value);

    return getStringWithZero((string)hex, 8);
}

long hexStringToLong(vector<string> hexVectorString) {
    string fullString;
    for (string s:hexVectorString) {
        fullString += s;
    }

    unsigned long longValue;
    istringstream converter {fullString};
    converter >> hex >> longValue;
    return (long)longValue;
}