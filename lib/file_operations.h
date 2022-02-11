#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;


/**
 * Get file name that does not contain extion. For example, inputstring.txt -> inputstring
 * 
 * @return filename without the extension.
 */
string getFileNameNoEx(string);

/**
 * Read file and return vector<string>
 */
vector<string> readFile(string);

/**
 * Write string to a file.
 */
void writeFile(string, string);