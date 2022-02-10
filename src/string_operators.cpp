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